

extern "C" __declspec(dllexport) void PostInit()
{
	
	if (GetModuleHandle(TEXT("UnleashedHUD.dll")) == nullptr) {
		MessageBoxA(nullptr, "Sonic Unleashed HUD is required to be loaded below Encore HUD.", "Encore HUD", MB_ICONERROR);
		exit(-1);
	}
	if (GetModuleHandle(TEXT("UnleashedHUD.dll")) == nullptr) {
		MessageBoxA(nullptr, "Sonic Unleashed HUD is required to be loaded below Encore HUD.", "Encore HUD", MB_ICONERROR);
		exit(-1);
	}
}