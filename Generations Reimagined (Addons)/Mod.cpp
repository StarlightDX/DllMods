
extern "C" __declspec(dllexport) void Init()
{
	INIReader reader("mod.ini");
    
	ArchiveTreePatcher::Install();
}
extern "C" __declspec(dllexport) void PostInit()
{
	
}