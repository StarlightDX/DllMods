
extern "C" __declspec(dllexport) void Init()
{
	INIReader reader("mod.ini");

	ArchiveTreePatcher::Install();
}
extern "C" __declspec(dllexport) void PostInit()
{
	
	//if (GetModuleHandle(TEXT("GenerationsD3D11.dll")) == nullptr) {
	//	MessageBoxA(nullptr, "Direct3D 11 is required to use Encore Sonic, please enable Direct3D 11 and retry, or disable Encore Sonic.", "Encore Sonic", MB_ICONERROR);
	//	exit(-1);
	//}
}