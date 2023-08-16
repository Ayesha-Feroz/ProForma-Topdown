#ifndef PROFORMATERM_H
#define PROFORMATERM_H

#include <string>
#include <vector>
#include <list>
#include <unordered_set>
#include "ProFormaTagGroup.h" // Include the header for ProFormaTagGroup class

namespace TopDownProteomics {
namespace ProForma {

class ProFormaTag; // Forward declaration
class ProFormaDescriptor; // Forward declaration
class ProFormaUnlocalizedTag; // Forward declaration
class ProFormaGlobalModification; // Forward declaration

class ProFormaTerm {
public:
    ProFormaTerm(const std::string& sequence, const std::vector<ProFormaTag>* tags = nullptr,
        const std::vector<ProFormaDescriptor>* nTerminalDescriptors = nullptr,
        const std::vector<ProFormaDescriptor>* cTerminalDescriptors = nullptr,
        const std::vector<ProFormaDescriptor>* labileDescriptors = nullptr,
        const std::vector<ProFormaUnlocalizedTag>* unlocalizedTags = nullptr,
        const std::unordered_set<ProFormaTagGroup>* tagGroups = nullptr,
        const std::vector<ProFormaGlobalModification>* globalModifications = nullptr);

    const std::string& Sequence() const;
    const std::vector<ProFormaGlobalModification>* GlobalModifications() const;
    const std::vector<ProFormaDescriptor>* NTerminalDescriptors() const;
    const std::vector<ProFormaDescriptor>* CTerminalDescriptors() const;
    const std::vector<ProFormaDescriptor>* LabileDescriptors() const;
    const std::vector<ProFormaTag>* Tags() const;
    const std::vector<ProFormaUnlocalizedTag>* UnlocalizedTags() const;
    const std::unordered_set<ProFormaTagGroup>* TagGroups() const;

private:
    std::string m_Sequence;
    const std::vector<ProFormaGlobalModification>* m_GlobalModifications;
    const std::vector<ProFormaDescriptor>* m_NTerminalDescriptors;
    const std::vector<ProFormaDescriptor>* m_CTerminalDescriptors;
    const std::vector<ProFormaDescriptor>* m_LabileDescriptors;
    const std::vector<ProFormaTag>* m_Tags;
    const std::vector<ProFormaUnlocalizedTag>* m_UnlocalizedTags;
    const std::unordered_set<ProFormaTagGroup>* m_TagGroups;
};

} // namespace ProForma
} // namespace TopDownProteomics

#endif // PROFORMATERM_H
