std::vector<ArchiveDependency> ArchiveTreePatcher::archiveDependencies = 
{
    { "EncoreSkin", { "Sonic", "evSonic", "ev031", "ev041", "ev042", "ev091" } }, /*Additional Skin options*/
    { "evEncoreSkin", { "ev031", "ev041", "ev042", "ev091" } }, /*Additional Skin options for cutscenes*/
    { "EncoreChip", { "Sonic" } }, /*Chip Bracelet files*/
    { "EncoreBoard", { "Sonic" } }, /*Board Skin files*/
    { "EncoreGear", { "Sonic", "evSonic", "ev031", "ev041", "ev042", "ev091" } }, /*Gear Skin files*/
    { "evEncoreChip", { "evSonic" } }, /*Chip Bracelet files for cutscenes*/
    { "EncoreEffect", { "Sonic", "evSonic", "SonicActionCommon" } }, /*Boost, Spinball & Jump FX*/
    { "evEncore", { "evSonic" } }, 
    { "ev031add", { "ev031" } }, /*Files in Chip Bracelet that add the Bracelet to ev000*/
    { "ev041add", { "ev041" } }, /*Files in Chip Bracelet that add the Bracelet to ev000*/
    { "ev042add", { "ev042" } }, /*Files in Chip Bracelet that add the Bracelet to ev000*/
    { "ev091add", { "ev091" } }, /*Files in Chip Bracelet that add the Bracelet to ev000*/
    { "TitleEncore", { "Title" } }, /*Overwrites the title files for compatibility with other mods.*/
    { "AddSonic", { "Sonic" } },
    { "ref_ghz", { "ghz200", "ghz_cmn" } }
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