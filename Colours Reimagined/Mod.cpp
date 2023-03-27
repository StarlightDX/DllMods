std::string hudtype;
std::string sonictype;

extern "C" __declspec(dllexport) void Init()
{
	INIReader reader("mod.ini");
     hudtype = reader.Get("Main", "IncludeDir6", "Off");
	 sonictype = reader.Get("Main", "IncludeDir5", "Off");
	ArchiveTreePatcher::Install();
}
extern "C" __declspec(dllexport) void PostInit()
{
	
	if (!StringHelper::Compare(hudtype, "Off") && GetModuleHandle(TEXT("UnleashedHUD.dll")) == nullptr) {
		MessageBoxA(nullptr, "Sonic Unleashed HUD is required to be loaded under Reimagined to use Encore HUD.", "Encore HUD", MB_ICONERROR);	
		exit(-1);
	}
	if (!StringHelper::Compare(sonictype, "Off") && GetModuleHandle(TEXT("GenerationsD3D11.dll")) == nullptr) {
		MessageBoxA(nullptr, "Direct3D 11 is required to use Encore Sonic, please enable Direct3D 11 and retry, or disable Encore Sonic.", "Encore Sonic", MB_ICONERROR);
		exit(-1);
	}
}