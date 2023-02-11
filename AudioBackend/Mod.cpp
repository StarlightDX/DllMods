std::string hudtype;
std::string upadd1type;
std::string upadd2type;
std::string upadd3type;
std::string stagepacktype;

extern "C" __declspec(dllexport) void Init()
{
	INIReader reader("mod.ini");
     hudtype = reader.Get("Main", "IncludeDir6", "Off");
     upadd1type = reader.Get("Main", "IncludeDir0", "UPDeluxe");
     upadd2type = reader.Get("Main", "IncludeDir1", "Off");
     upadd3type = reader.Get("Main", "IncludeDir2", "Off");
     stagepacktype = reader.Get("Main", "IncludeDir4", "Unleashed Project");
	ArchiveTreePatcher::Install();
}
extern "C" __declspec(dllexport) void PostInit()
{
	
	if (!StringHelper::Compare(hudtype, "Off") && GetModuleHandle(TEXT("UnleashedHUD.dll")) == nullptr) {
		MessageBoxA(nullptr, "Sonic Unleashed HUD is required to be loaded under Reimagined to use Encore HUD.", "Encore HUD", MB_ICONERROR);	
		exit(-1);
	}
	if (!StringHelper::Compare(stagepacktype, "Unleashed Project") && (!StringHelper::Compare(upadd1type, "Off") || !StringHelper::Compare(upadd2type, "Off") || !StringHelper::Compare(upadd3type, "Off"))) {
		MessageBoxA(nullptr, "Unleashed Project mode is required for this option to be enabled, please disable this option when using different stage packs.", "Sonic Unleashed: Reimagined", MB_ICONERROR);
		exit(-1);
	}
}