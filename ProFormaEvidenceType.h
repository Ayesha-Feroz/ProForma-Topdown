#ifndef PROFORMA_EVIDENCE_TYPE_H
#define PROFORMA_EVIDENCE_TYPE_H

namespace TopDownProteomics::ProForma {
    // Evidence types to provide on a descriptor, typically an ontology identifier.
    enum class ProFormaEvidenceType {
        None = 0,
        Observed = 1,
        Unimod = 2,
        UniProt = 3,
        Resid = 4,
        PsiMod = 5,
        XlMod = 6,
        Gno = 7,
        Brno = 8
    };
}

#endif // PROFORMA_EVIDENCE_TYPE_H
