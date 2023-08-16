#ifndef PROFORMA_PROTEOFORM_MODIFICATION_H
#define PROFORMA_PROTEOFORM_MODIFICATION_H

#include "IProteoformModification.h"
#include "ProFormaDescriptor.h" // Include the header for ProFormaDescriptor

namespace TopDownProteomics::ProForma {
    // Forward declarations
    class ProFormaDescriptor;

    // A proteoform modification that is aware of ProForma notation
    class IProFormaProteoformModification : public IProteoformModification {
    public:
        // Gets the ProForma descriptor.
        virtual ProFormaDescriptor GetProFormaDescriptor() const = 0;
    };
}

#endif // PROFORMA_PROTEOFORM_MODIFICATION_H
