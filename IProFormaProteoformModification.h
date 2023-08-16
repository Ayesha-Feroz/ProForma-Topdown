#include "Proteomics.h"  // Include the necessary header for IProteoformModification

namespace TopDownProteomics {
    namespace ProForma {
        // Forward declaration of ProFormaDescriptor class
        class ProFormaDescriptor;

        // Declare the IProFormaProteoformModification interface
        class IProFormaProteoformModification : public IProteoformModification {
        public:
            virtual ProFormaDescriptor GetProFormaDescriptor() const = 0;

            virtual ~IProFormaProteoformModification() {}
        };
    }
}
