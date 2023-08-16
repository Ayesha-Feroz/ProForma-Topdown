#ifndef PROFORMA_KEY_H
#define PROFORMA_KEY_H

namespace TopDownProteomics::ProForma {
    // Possible keys for a descriptor.
    enum class ProFormaKey {
        None = 0,
        Name = 1,
        Identifier = 2,
        Mass = 3,
        Formula = 4,
        Glycan = 5,
        Info = 6
    };
}

#endif // PROFORMA_KEY_H
