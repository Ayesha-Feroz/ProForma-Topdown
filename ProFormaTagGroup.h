#ifndef PROFORMATAGGROUP_H
#define PROFORMATAGGROUP_H

#include <vector>

namespace TopDownProteomics {
namespace ProForma {

class ProFormaMembershipDescriptor {
    // Implement ProFormaMembershipDescriptor class
};

enum class ProFormaKey {
    // Implement ProFormaKey enum
};

enum class ProFormaEvidenceType {
    // Implement ProFormaEvidenceType enum
};

class ProFormaTagGroup {
public:
    ProFormaTagGroup(const std::string& name, ProFormaKey key, const std::string& value,
        const std::vector<ProFormaMembershipDescriptor>& members);
    ProFormaTagGroup(const std::string& name, ProFormaKey key, ProFormaEvidenceType evidenceType,
        const std::string& value, const std::vector<ProFormaMembershipDescriptor>& members);
    ProFormaTagGroup(const std::string& name, ProFormaKey key, const std::string& value,
        const std::vector<ProFormaMembershipDescriptor>& members, int preferredLocation);
    ProFormaTagGroup(const std::string& name, ProFormaKey key, ProFormaEvidenceType evidenceType,
        const std::string& value, const std::vector<ProFormaMembershipDescriptor>& members, int preferredLocation);

    const std::string& Name() const;
    ProFormaKey Key() const;
    ProFormaEvidenceType EvidenceType() const;
    const std::string& Value() const;
    const std::vector<ProFormaMembershipDescriptor>& Members() const;
    int PreferredLocation() const;

private:
    std::string m_Name;
    ProFormaKey m_Key;
    ProFormaEvidenceType m_EvidenceType;
    std::string m_Value;
    std::vector<ProFormaMembershipDescriptor> m_Members;
    int m_PreferredLocation;
};

} // namespace ProForma
} // namespace TopDownProteomics

#endif // PROFORMATAGGROUP_H
