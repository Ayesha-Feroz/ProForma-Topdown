#ifndef PROFORMATAG_H
#define PROFORMATAG_H

#include <vector>

namespace TopDownProteomics {
namespace ProForma {

class ProFormaDescriptor {
    // Implement ProFormaDescriptor class
};

class ProFormaTag {
public:
    ProFormaTag(int zeroBasedIndex, const std::vector<ProFormaDescriptor>& descriptors);
    ProFormaTag(int zeroBasedIndex, const std::vector<ProFormaDescriptor>& descriptors, bool hasAmbiguousSequence);
    ProFormaTag(int zeroBasedStartIndex, int zeroBasedEndIndex, const std::vector<ProFormaDescriptor>& descriptors);
    ProFormaTag(int zeroBasedStartIndex, int zeroBasedEndIndex, const std::vector<ProFormaDescriptor>& descriptors, bool hasAmbiguousSequence);

    int ZeroBasedStartIndex() const;
    int ZeroBasedEndIndex() const;
    const std::vector<ProFormaDescriptor>& Descriptors() const;
    bool HasAmbiguousSequence() const;

private:
    int m_ZeroBasedStartIndex;
    int m_ZeroBasedEndIndex;
    std::vector<ProFormaDescriptor> m_Descriptors;
    bool m_HasAmbiguousSequence;
};

} // namespace ProForma
} // namespace TopDownProteomics

#endif // PROFORMATAG_H
