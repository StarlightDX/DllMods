std::vector<ArchiveDependency> ArchiveTreePatcher::archiveDependencies = 
{
    { "SoundEggmanLand", { "ghz200", "cpz200" } },
    { "EncoreSonic", { "Sonic" } },
    { "EncoreShoe", { "Sonic" } },
    { "pamcustom", { "pam000" } },
    { "gatecustom", { "StageGate" } },
    { "TitleR", { "Title" } },
    { "SSHEncore", { "SSH200" } },
    { "MYK100", { "GHZ100", "PLA100", "PLA200" } },
    { "MYK200", { "GHZ200" } },
    { "AFR200", { "CPZ200" } },
    { "EU200", { "SSZ200" } },
    { "CHN200", { "SPH200" } },
    { "SNW200", { "CTE200" } },
    { "PTR200", { "SSH200" } },
    { "NYC200", { "CSC200" } },
    { "SEA200", { "EUC200" } }
};

HOOK(bool, __stdcall, ParseArchiveTree, 0xD4C8E0, void* a1, char* pData, const size_t size, void* pDatabase)
{
    std::string str;
    {
        std::stringstream stream;

        for (ArchiveDependency const& node : ArchiveTreePatcher::archiveDependencies)
        {
            stream << "  <Node>\n";
            stream << "    <Name>" << node.archive << "</Name>\n";
            stream << "    <Archive>" << node.archive << "</Archive>\n";
            stream << "    <Order>" << 0 << "</Order>\n";
            stream << "    <DefAppend>" << node.archive << "</DefAppend>\n";

            for (std::string const& dependency : node.dependencies)
            {
                stream << "    <Node>\n";
                stream << "      <Name>" << dependency << "</Name>\n";
                stream << "      <Archive>" << dependency << "</Archive>\n";
                stream << "      <Order>" << 0 << "</Order>\n";
                stream << "    </Node>\n";
            }

            stream << "  </Node>\n";
        }

        str = stream.str();
    }

    const size_t newSize = size + str.size();
    const std::unique_ptr<char[]> pBuffer = std::make_unique<char[]>(newSize);

    memcpy(pBuffer.get(), pData, size);

    char* pInsertionPos = strstr(pBuffer.get(), "<Include>");

    memmove(pInsertionPos + str.size(), pInsertionPos, size - (size_t)(pInsertionPos - pBuffer.get()));
    memcpy(pInsertionPos, str.c_str(), str.size());

    return originalParseArchiveTree(a1, pBuffer.get(), newSize, pDatabase);
}

void ArchiveTreePatcher::Install()
{

    INSTALL_HOOK(ParseArchiveTree);
}