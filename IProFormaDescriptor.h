#ifndef PROFORMA_DESCRIPTOR_H
#define PROFORMA_DESCRIPTOR_H

#include <string>

namespace TopDownProteomics::ProForma {
    // Forward declarations
    enum class ProFormaKey;
    enum class ProFormaEvidenceType;

    // Anything that describes a modification.
    class IProFormaDescriptor {
    public:
        // The key.
        virtual ProFormaKey getKey() const = 0;

        // The type of the evidence.
        virtual ProFormaEvidenceType getEvidenceType() const = 0;

        // The value.
        virtual std::string getValue() const = 0;
    };
}

#endif // PROFORMA_DESCRIPTOR_H
