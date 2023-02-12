std::vector<ArchiveDependency> ArchiveTreePatcher::archiveDependencies = 
{
    { "SoundAfrica", { "cpz200", "ssz200", "cte200", "ssh200", "csc200" } },
    { "SoundBeach", { "cte200", "ssh200", "csc200", "euc200" } },
    { "SoundChina", { "sph200", "cte200", "ssh200", "csc200", "euc200", "pla100", "pla200" } },
    { "SoundEggmanLand", { "ghz200", "cpz200" } },
    { "SoundEU", { "ghz100", "ghz200", "cpz200", "ssz200", "cte200", "euc200", "pla200" } },
    { "SoundMykonos", { "ghz100", "ghz200", "cpz200", "ssz200", "cte200", "csc200", "euc200", "pla100", "pla200" } },
    { "SoundNY", { "ghz100", "ghz200", "cpz200", "csc100", "csc200", "euc200" } },
    { "SoundPetra", { "ghz200", "ghz201", "ssz200", "ssh200", "pla200" } },
    { "SoundSnow", { "ghz100", "ghz200", "cpz101", "cpz200", "ssz200", "cte100", "cte200", "csc200", "pla200" } }
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