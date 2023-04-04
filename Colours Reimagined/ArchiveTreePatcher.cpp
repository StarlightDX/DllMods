std::vector<ArchiveDependency> ArchiveTreePatcher::archiveDependencies = 
{
{ "RainbowStage", { "ghz100", "ghz200", "ghz_cmn", "cpz100", "cpz200", "cpz_cmn","ssz100", "ssz200", "ssz_cmn","sph100", "sph200", "sph_cmn","cte100", "cte200", "cte_cmn","ssh100", "ssh200", "ssh_cmn","csc100", "csc200", "csc_cmn","euc100", "euc200", "euc_cmn","pla100", "pla200", "pla_cmn", "pam000", "pam_cmn" } },
{ "rsoload", { "ghz100", "ghz200", "ghz_cmn", "cpz100", "cpz200", "cpz_cmn","ssz100", "ssz200", "ssz_cmn","sph100", "sph200", "sph_cmn","cte100", "cte200", "cte_cmn","ssh100", "ssh200", "ssh_cmn","csc100", "csc200", "csc_cmn","euc100", "euc200", "euc_cmn","pla100", "pla200", "pla_cmn", "pam000", "pam_cmn" } },
{ "fctload", { "ghz100", "ghz200", "ghz_cmn", "cpz100", "cpz200", "cpz_cmn","ssz100", "ssz200", "ssz_cmn","sph100", "sph200", "sph_cmn","cte100", "cte200", "cte_cmn","ssh100", "ssh200", "ssh_cmn","csc100", "csc200", "csc_cmn","euc100", "euc200", "euc_cmn","pla100", "pla200", "pla_cmn", "pam000", "pam_cmn" } },
{ "shpload", { "ghz100", "ghz200", "ghz_cmn", "cpz100", "cpz200", "cpz_cmn","ssz100", "ssz200", "ssz_cmn","sph100", "sph200", "sph_cmn","cte100", "cte200", "cte_cmn","ssh100", "ssh200", "ssh_cmn","csc100", "csc200", "csc_cmn","euc100", "euc200", "euc_cmn","pla100", "pla200", "pla_cmn", "pam000", "pam_cmn" } },
{ "plaload", { "ghz100", "ghz200", "ghz_cmn", "cpz100", "cpz200", "cpz_cmn","ssz100", "ssz200", "ssz_cmn","sph100", "sph200", "sph_cmn","cte100", "cte200", "cte_cmn","ssh100", "ssh200", "ssh_cmn","csc100", "csc200", "csc_cmn","euc100", "euc200", "euc_cmn","pla100", "pla200", "pla_cmn", "pam000", "pam_cmn" } },
{ "quaload", { "ghz100", "ghz200", "ghz_cmn", "cpz100", "cpz200", "cpz_cmn","ssz100", "ssz200", "ssz_cmn","sph100", "sph200", "sph_cmn","cte100", "cte200", "cte_cmn","ssh100", "ssh200", "ssh_cmn","csc100", "csc200", "csc_cmn","euc100", "euc200", "euc_cmn","pla100", "pla200", "pla_cmn", "pam000", "pam_cmn" } },
{ "astload", { "ghz100", "ghz200", "ghz_cmn", "cpz100", "cpz200", "cpz_cmn","ssz100", "ssz200", "ssz_cmn","sph100", "sph200", "sph_cmn","cte100", "cte200", "cte_cmn","ssh100", "ssh200", "ssh_cmn","csc100", "csc200", "csc_cmn","euc100", "euc200", "euc_cmn","pla100", "pla200", "pla_cmn", "pam000", "pam_cmn" } },
{ "TitleSCR", { "Title" } }
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