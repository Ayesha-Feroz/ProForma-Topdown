#ifndef PROFORMA_GLOBAL_MODIFICATION_H
#define PROFORMA_GLOBAL_MODIFICATION_H

#include <vector>
#include <set>
#include "ProFormaDescriptor.h" // Include the header for ProFormaDescriptor

namespace TopDownProteomics::ProForma {
    class ProFormaGlobalModification {
    public:
        // Constructor initializes a new instance of ProFormaGlobalModification
        ProFormaGlobalModification(const std::vector<ProFormaDescriptor>& descriptors, const std::set<char>* targetAminoAcids)
            : Descriptors(descriptors), TargetAminoAcids(targetAminoAcids) {}

        // The descriptors for this global modification.
        std::vector<ProFormaDescriptor> Descriptors;

        // The amino acids targeted by this global modification (nullptr if representing isotopes).
        const std::set<char>* TargetAminoAcids;
    };
}

#endif // PROFORMA_GLOBAL_MODIFICATION_H
