std::string titletype;

extern "C" __declspec(dllexport) void Init()
{
	INIReader reader("mod.ini");
	titletype = reader.Get("Main", "IncludeDir1", ".\\Blur\\Off\\");
	ArchiveTreePatcher::Install();
}
extern "C" __declspec(dllexport) void PostInit()
{

	if (!StringHelper::Compare(titletype, ".\\Blur\\Off\\") && GetModuleHandle(TEXT("ColorsHUD.dll")) == nullptr) {
		MessageBoxA(nullptr, "Sonic Colours HUD is required to use the Reimagined title screen.", "Sonic Colours: Reimagined", MB_ICONERROR);
		exit(-1);
	}

}