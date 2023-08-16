#ifndef PROFORMA_PARSER_H
#define PROFORMA_PARSER_H

#include <string>
#include <vector>
#include <unordered_map>
#include <stdexcept>
#include "ProFormaTerm.h" // You would need to include the header for ProFormaTerm

namespace TopDownProteomics::ProForma {

    class ProFormaParser {
    public:
        ProFormaParser() = default;

        ProFormaTerm ParseString(const std::string& proFormaString);

    private:
        void HandleGlobalModification(
            std::unordered_map<std::string, ProFormaTagGroup>*& tagGroups,
            std::vector<ProFormaGlobalModification>*& globalModifications,
            std::string& sequence, int startRange, int endRange,
            const std::string& tagText);

        void ProcessTag(std::string tag, int startIndex, int index, bool inSequenceAmbiguity,
            std::vector<ProFormaTag>*& tags, std::unordered_map<std::string, ProFormaTagGroup>*& tagGroups);

        std::vector<ProFormaDescriptor>* ProcessTag(std::string tag, int startIndex, int index,
            std::unordered_map<std::string, ProFormaTagGroup>*& tagGroups);

        std::tuple<ProFormaKey, ProFormaEvidenceType, std::string, std::string, double>
        ParseDescriptor(const std::string& text);

    };

}

#endif // PROFORMA_PARSER_H
