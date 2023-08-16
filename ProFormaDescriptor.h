#ifndef PROFORMA_DESCRIPTOR_H
#define PROFORMA_DESCRIPTOR_H

#include "IProFormaDescriptor.h" // Include the header for IProFormaDescriptor
#include "ProFormaKey.h" // Include the header for ProFormaKey
#include "ProFormaEvidenceType.h" // Include the header for ProFormaEvidenceType

namespace TopDownProteomics::ProForma {
    class ProFormaDescriptor : public IProFormaDescriptor {
    public:
        // Constructor initializes descriptor without value only
        ProFormaDescriptor(const std::string& value)
            : ProFormaDescriptor(ProFormaKey::Name, ProFormaEvidenceType::None, value) {}

        // Constructor initializes with key and value
        ProFormaDescriptor(ProFormaKey key, const std::string& value)
            : ProFormaDescriptor(key, ProFormaEvidenceType::None, value) {}

        // Constructor initializes with key, evidence type, and value
        ProFormaDescriptor(ProFormaKey key, ProFormaEvidenceType evidenceType, const std::string& value)
            : Key(key), EvidenceType(evidenceType), Value(value) {}

        // The key.
        ProFormaKey Key;

        // The type of the evidence.
        ProFormaEvidenceType EvidenceType;

        // The value.
        std::string Value;

        // String representation of ProFormaDescriptor
        std::string ToString() const {
            return KeyToString(Key) + ":" + EvidenceTypeToString(EvidenceType) + ":" + Value;
        }
    };
}

#endif // PROFORMA_DESCRIPTOR_H
