#ifndef PROFORMAUNLOCALIZEDTAG_H
#define PROFORMAUNLOCALIZEDTAG_H

#include <vector>
#include "ProFormaDescriptor.h" // Include the header for ProFormaDescriptor class

namespace TopDownProteomics {
namespace ProForma {

class ProFormaUnlocalizedTag {
public:
    ProFormaUnlocalizedTag(int count, const std::vector<ProFormaDescriptor>& descriptors);

    int Count() const;
    const std::vector<ProFormaDescriptor>& Descriptors() const;

private:
    int m_Count;
    std::vector<ProFormaDescriptor> m_Descriptors;
};

} // namespace ProForma
} // namespace TopDownProteomics

#endif // PROFORMAUNLOCALIZEDTAG_H
