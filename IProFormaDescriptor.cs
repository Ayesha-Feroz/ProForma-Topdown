namespace TopDownProteomics {
    namespace ProForma {
        enum class ProFormaKey {
            Formula,
            Glycan,
            Info,
            Name,
            Mass,
            Identifier
            // ... other enum values
        };

        enum class ProFormaEvidenceType {
            None,
            Observed,
            Unimod,
            Resid,
            PsiMod,
            XlMod,
            Gno,
            Brno
            // ... other enum values
        };

        class IProFormaDescriptor {
        public:
            virtual ProFormaKey GetKey() const = 0;
            virtual ProFormaEvidenceType GetEvidenceType() const = 0;
            virtual std::string GetValue() const = 0;

            virtual ~IProFormaDescriptor() {}
        };
    }
}
