#include "ProFormaWriter.h" // Include the header for ProFormaWriter class
#include "ProFormaParseException.h" // Include the header for ProFormaParseException class

namespace TopDownProteomics {
namespace ProForma {

std::string ProFormaWriter::WriteString(const ProFormaTerm& term) const {
    auto WriteTagOrGroup = [&](const ObjectVariant& obj, std::string& sb, bool displayValue, double weight) {
        if (std::holds_alternative<ProFormaTag>(obj)) {
            const ProFormaTag& tag = std::get<ProFormaTag>(obj);
            if (!tag.Descriptors.empty())
                sb += "[" + CreateDescriptorsText(tag.Descriptors) + "]";
        } else if (std::holds_alternative<ProFormaTagGroup>(obj)) {
            const ProFormaTagGroup& group = std::get<ProFormaTagGroup>(obj);
            if (displayValue)
                sb += "[" + CreateDescriptorText(group) + "#" + group.Name;
            else
                sb += "[#" + group.Name;

            if (weight > 0.0)
                sb += "(" + std::to_string(weight) + ")]";
            else
                sb += "]";
        }
    };

    std::string sb;

    // Check global modifications
    if (term.GlobalModifications) {
        for (const auto& globalMod : *term.GlobalModifications) {
            if (globalMod.TargetAminoAcids)
                sb += "<[" + CreateDescriptorsText(globalMod.Descriptors) + "]@" +
                      StringJoin(*globalMod.TargetAminoAcids, ",") + ">";
            else
                sb += "<" + CreateDescriptorsText(globalMod.Descriptors) + ">";
        }
    }

    // Check labile modifications
    if (term.LabileDescriptors) {
        sb += "{" + CreateDescriptorsText(*term.LabileDescriptors) + "}";
    }

    // Check unlocalized modifications
    if (term.UnlocalizedTags && !term.UnlocalizedTags->empty()) {
        for (const auto& tag : *term.UnlocalizedTags) {
            if (!tag.Descriptors.empty())
                sb += "[" + CreateDescriptorsText(tag.Descriptors) + "]";

            if (tag.Count != 1)
                sb += "^" + std::to_string(tag.Count);
        }

        // Only write out a single question mark
        sb += '?';
    }

    // Check N-terminal modifications
    if (term.NTerminalDescriptors && !term.NTerminalDescriptors->empty()) {
        sb += "[" + CreateDescriptorsText(*term.NTerminalDescriptors) + "]-";
    }

    std::vector<std::tuple<ObjectVariant, int, int, bool, double>> tagsAndGroups;

    if (term.Tags) {
        for (const auto& tag : *term.Tags) {
            tagsAndGroups.emplace_back(tag, tag.ZeroBasedStartIndex, tag.ZeroBasedEndIndex, true, 0.0);
        }
    }

    if (term.TagGroups) {
        for (const auto& group : *term.TagGroups) {
            for (const auto& member : group.Members) {
                tagsAndGroups.emplace_back(group, member.ZeroBasedStartIndex, member.ZeroBasedEndIndex, member == group.Members[group.PreferredLocation], member.Weight);
            }
        }
    }

    // Check indexed modifications
    if (!tagsAndGroups.empty()) {
        // Sort by start index
        std::sort(tagsAndGroups.begin(), tagsAndGroups.end(), [](const auto& lhs, const auto& rhs) {
            return std::get<1>(lhs) < std::get<1>(rhs);
        });

        int currentIndex = 0;
        for (const auto& [obj, startIndex, endIndex, displayValue, weight] : tagsAndGroups) {
            bool hasAmbiguousSequence = std::holds_alternative<ProFormaTag>(obj) && std::get<ProFormaTag>(obj).HasAmbiguousSequence;

            if (startIndex == endIndex && !hasAmbiguousSequence) {
                // Write sequence up to tag
                sb += term.Sequence.substr(currentIndex, startIndex - currentIndex + 1);
                currentIndex = startIndex + 1;
            } else { // Handle ambiguity range
                // Write sequence up to range (checking for internal tags)
                sb += term.Sequence.substr(currentIndex, startIndex - currentIndex);
                currentIndex = startIndex;

                // Start sequence in range
                sb += "(";

                if (hasAmbiguousSequence)
                    sb += '?';

                // Check for other tags that might be inside this range
                int j = 0;
                while (j < tagsAndGroups.size() && std::get<1>(tagsAndGroups[j]) <= endIndex) {
                    const auto& [internalTagObj, internalStartIndex, internalEndIndex, internalDisplayValue, internalWeight] = tagsAndGroups[j];

                    if (internalStartIndex != internalEndIndex)
                        throw ProFormaParseException("Can't nest ranges within each other.");

                    sb += term.Sequence.substr(currentIndex, internalStartIndex - currentIndex + 1);
                    currentIndex = internalEndIndex + 1;

                    WriteTagOrGroup(internalTagObj, sb, internalDisplayValue, internalWeight);

                    j++;
                }

                sb += term.Sequence.substr(currentIndex, endIndex - currentIndex + 1) + ")";
                currentIndex = endIndex + 1;
            }

            WriteTagOrGroup(obj, sb, displayValue, weight);
        }

        // Write the rest of the sequence
        sb += term.Sequence.substr(currentIndex);
    } else {
        sb += term.Sequence;
    }

    // Check C-terminal modifications
    if (term.CTerminalDescriptors && !term.CTerminalDescriptors->empty()) {
        sb += "-[" + CreateDescriptorsText(*term.CTerminalDescriptors) + "]";
    }

    return sb;
}

std::string ProFormaWriter::CreateDescriptorsText(const std::vector<ProFormaDescriptor>& descriptors) const {
    std::string sb;
    for (size_t i = 0; i < descriptors.size(); i++) {
        sb += CreateDescriptorText(descriptors[i]);

        if (i < descriptors.size() - 1)
            sb += '|';
    }

    return sb;
}

std::string ProFormaWriter::CreateDescriptorText(const IProFormaDescriptor& descriptor) const {
    switch (descriptor.Key()) {
        case ProFormaKey::Formula:
            return "Formula:" + descriptor.Value();
        case ProFormaKey::Glycan:
            return "Glycan:" + descriptor.Value();
        case ProFormaKey::Info:
            return "Info:" + descriptor.Value();
        case ProFormaKey::Name:
        case ProFormaKey::Mass:
            switch (descriptor.EvidenceType()) {
                case ProFormaEvidenceType::None:
                    return descriptor.Value(); // We assume the name is enough
                case ProFormaEvidenceType::Observed:
                    return "Obs:" + descriptor.Value();
                case ProFormaEvidenceType::Unimod:
                    return "U:" + descriptor.Value();
                case ProFormaEvidenceType::Resid:
                    return "R:" + descriptor.Value();
                case ProFormaEvidenceType::PsiMod:
                    return "M:" + descriptor.Value();
                case ProFormaEvidenceType::XlMod:
                    return "X:" + descriptor.Value();
                case ProFormaEvidenceType::Gno:
                    return "G:" + descriptor.Value();
                case ProFormaEvidenceType::Brno:
                    return "B:" + descriptor.Value();
                default:
                    throw std::runtime_error("Can't handle " + std::to_string(static_cast<int>(descriptor.Key())) + " with evidence type: " + std::to_string(static_cast<int>(descriptor.EvidenceType())));
            }
        case ProFormaKey::Identifier:
            switch (descriptor.EvidenceType()) {
                case ProFormaEvidenceType::Observed:
                    return "Obs:" + descriptor.Value();
                case ProFormaEvidenceType::Unimod:
                    return descriptor.Value();
                default:
                    return descriptor.Value();
            }
        default:
            return descriptor.Value();
    }
}

} // namespace ProForma
} // namespace TopDownProteomics
