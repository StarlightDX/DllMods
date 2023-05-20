#include <string_view>
std::string suhudtype;
std::string sgd3d11type;
extern "C" __declspec(dllexport) void Init()
{
	INIReader reader("mod.ini");
	   suhudtype = reader.Get("Main", "IncludeDir0", ".\\Deluxe\\disabled\\");
	   sgd3d11type = reader.Get("Main", "IncludeDir0", ".\\Deluxe\\disabled\\");
	ArchiveTreePatcher::Install();
}
extern "C" __declspec(dllexport) void PostInit()
{

	if (!StringHelper::Compare(suhudtype, ".\\Deluxe\\disabled\\") && GetModuleHandle(TEXT("UnleashedHUD.dll")) == nullptr) {
		MessageBoxA(nullptr, "Sonic Unleashed HUD is required to be loaded under Reimagined to use the Deluxe option.", "HE1 - The Trilogy", MB_ICONERROR);	
		exit(-1);
	}
	if (!StringHelper::Compare(sgd3d11type, ".\\Deluxe\\disabled\\") && GetModuleHandle(TEXT("GenerationsD3D11.dll")) == nullptr) {
		MessageBoxA(nullptr, "Generations Direct3D 11 is required use the Deluxe option.", "HE1 - The Trilogy", MB_ICONERROR);
		exit(-1);
	}
}