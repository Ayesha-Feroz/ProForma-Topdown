#ifndef PROFORMA_MEMBERSHIP_DESCRIPTOR_H
#define PROFORMA_MEMBERSHIP_DESCRIPTOR_H

namespace TopDownProteomics::ProForma {
    class ProFormaMembershipDescriptor {
    public:
        // Initializes a new instance of ProFormaMembershipDescriptor with a single index and weight
        ProFormaMembershipDescriptor(int zeroBasedIndex, double weight = 0.0)
            : ZeroBasedStartIndex(zeroBasedIndex), ZeroBasedEndIndex(zeroBasedIndex), Weight(weight) {}

        // Initializes a new instance of ProFormaMembershipDescriptor with a start and end index, and weight
        ProFormaMembershipDescriptor(int zeroBasedStartIndex, int zeroBasedEndIndex, double weight = 0.0)
            : ZeroBasedStartIndex(zeroBasedStartIndex), ZeroBasedEndIndex(zeroBasedEndIndex), Weight(weight) {}

        // Gets the zero-based start index in the sequence.
        int ZeroBasedStartIndex;

        // Gets the zero-based end index in the sequence.
        int ZeroBasedEndIndex;

        // The weight this member has on the group.
        double Weight;
    };
}

#endif // PROFORMA_MEMBERSHIP_DESCRIPTOR_H
