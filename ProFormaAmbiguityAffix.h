#ifndef PROFORMA_AMBIGUITY_AFFIX_H
#define PROFORMA_AMBIGUITY_AFFIX_H

#include <string>

namespace TopDownProteomics::ProForma {
    class ProFormaAmbiguityAffix {
    public:
        // Marks a possible site at which a modification may be localized
        static const std::string PossibleSite;

        // Marks the left boundary of the range over which a modification may be localized.
        static const std::string LeftBoundary;

        // Marks the right boundary of the range over which a modification may be localized.
        static const std::string RightBoundary;
    };

    // Definition of the static member variables
    const std::string ProFormaAmbiguityAffix::PossibleSite = "#";
    const std::string ProFormaAmbiguityAffix::LeftBoundary = "->";
    const std::string ProFormaAmbiguityAffix::RightBoundary = "<-";
}

#endif // PROFORMA_AMBIGUITY_AFFIX_H
