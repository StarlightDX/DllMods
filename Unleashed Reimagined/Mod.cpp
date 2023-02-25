std::string hudtype;
std::string sonictype;
std::string upadd1type;
std::string upadd2type;
std::string upadd3type;
std::string egbadd1type;
std::string egbadd2type;
std::string setexadabattype; 
std::string stagepacktype;
std::string stageegbpacktype;
std::string customhudtype;
std::string customcharactertype;
//std::string apadabattype;
//std::string apapotostype;
//std::string apchinatype;
//std::string apempiretype;
//std::string apholoskatype;
//std::string apmazuritype;
//std::string apshamartype;
//std::string apspagoniatype;
//std::string apadabatextype;
//std::string apapotosextype;
//std::string apchinaextype;
//std::string apempireextype;
//std::string apholoskaextype;
//std::string apmazuriextype;
//std::string apshamarextype;
//std::string apspagoniaextype;

extern "C" __declspec(dllexport) void Init()
{
	INIReader reader("mod.ini");
     hudtype = reader.Get("Main", "IncludeDir9", "Off");
	 sonictype = reader.Get("Main", "IncludeDir8", "Off");
     upadd1type = reader.Get("Main", "IncludeDir1", ".\\Unleashed Project\\UPDeluxe\\");
     upadd2type = reader.Get("Main", "IncludeDir2", "Off");
     upadd3type = reader.Get("Main", "IncludeDir3", "Off");
	 egbadd1type = reader.Get("Main", "IncludeDir6", "Off");
	 egbadd2type = reader.Get("Main", "IncludeDir21", "Off");
	 setexadabattype = reader.Get("Main", "IncludeDir4", "Off");
     stagepacktype = reader.Get("Main", "IncludeDir7", ".\\Unleashed Project\\Unleashed Project\\");
	 stageegbpacktype = reader.Get("Main", "IncludeDir7", ".\\Extra\\STGEggmanLand\\");
	 upadd1type = reader.Get("Main", "IncludeDir1", ".\\Unleashed Project\\UPDeluxe\\");
	 customhudtype = reader.Get("Main", "IncludeDir17", ".\\HUD\\Extra\\Custom\\HUD\\");
	 customcharactertype = reader.Get("Main", "IncludeDir16", ".\\Character\\Custom\\Archive\\");
	 //apadabattype = reader.Get("Main", "IncludeDir7", ".\\Adventure Pack\\Standalone\\Adabat\\" "Off");
	 //apadabattype = reader.Get("Main", "IncludeDir7", ".\\Adventure Pack\\Standalone\\Apotos\\" "Off");
	 //apadabattype = reader.Get("Main", "IncludeDir7", ".\\Adventure Pack\\Standalone\\China\\" "Off");
	 //apadabattype = reader.Get("Main", "IncludeDir7", ".\\Adventure Pack\\Standalone\\Empire\\" "Off");
	 //apadabattype = reader.Get("Main", "IncludeDir7", ".\\Adventure Pack\\Standalone\\Holoska\\" "Off");
	 //apadabattype = reader.Get("Main", "IncludeDir7", ".\\Adventure Pack\\Standalone\\Mazuri\\" "Off");
	 //apadabattype = reader.Get("Main", "IncludeDir7", ".\\Adventure Pack\\Standalone\\Shamar\\" "Off");
	 //apadabattype = reader.Get("Main", "IncludeDir7", ".\\Adventure Pack\\Standalone\\Spagonia\\" "Off");
	 //apadabatextype = reader.Get("Main", "IncludeDir5", ".\\Adventure Pack\\Extended\\AdabatEX\\" "Off");
	 //apadabatextype = reader.Get("Main", "IncludeDir5", ".\\Adventure Pack\\Extended\\ApotosEX\\" "Off");
	 //apadabatextype = reader.Get("Main", "IncludeDir5", ".\\Adventure Pack\\Extended\\ChinaEX\\" "Off");
	 //apadabatextype = reader.Get("Main", "IncludeDir5", ".\\Adventure Pack\\Extended\\EmpireEX\\" "Off");
	 //apadabatextype = reader.Get("Main", "IncludeDir5", ".\\Adventure Pack\\Extended\\HoloskaEX\\" "Off");
	 //apadabatextype = reader.Get("Main", "IncludeDir5", ".\\Adventure Pack\\Extended\\MazuriEX\\" "Off");
	 //apadabatextype = reader.Get("Main", "IncludeDir5", ".\\Adventure Pack\\Extended\\ShamarEX\\" "Off");
	 //apadabatextype = reader.Get("Main", "IncludeDir5", ".\\Adventure Pack\\Extended\\SpagoniaEX\\" "Off");
	ArchiveTreePatcher::Install();
}
extern "C" __declspec(dllexport) void PostInit()
{
	
	if (!StringHelper::Compare(hudtype, "Off") && GetModuleHandle(TEXT("UnleashedHUD.dll")) == nullptr) {
		MessageBoxA(nullptr, "Sonic Unleashed HUD is required to be loaded under Reimagined to use Encore HUD.", "Encore HUD", MB_ICONERROR);	
		exit(-1);
	}
	if (!StringHelper::Compare(sonictype, "Off") && GetModuleHandle(TEXT("GenerationsD3D11.dll")) == nullptr) {
		MessageBoxA(nullptr, "Direct3D 11 is required to use Encore Sonic, please enable the Direct3D 11 mod and retry, alternatively enable Direct3D 9 support.", "Encore Sonic", MB_ICONERROR);
		exit(-1);
	}
	if (!StringHelper::Compare(stagepacktype, ".\\Unleashed Project\\Unleashed Project\\") && (!StringHelper::Compare(upadd1type, "Off") || !StringHelper::Compare(upadd2type, "Off") || !StringHelper::Compare(upadd3type, "Off") || !StringHelper::Compare(setexadabattype, "Off"))) {
		MessageBoxA(nullptr, "Unleashed Project mode is required for DX, Directors Cut, UP Encore & additional Layout options. Please disable this/these option(s) when using different stage packs.", "Sonic Unleashed: Reimagined", MB_ICONERROR);
		exit(-1);
	}
	if (!StringHelper::Compare(stageegbpacktype, ".\\Extra\\STGEggmanLand\\") && (!StringHelper::Compare(egbadd1type, "Off"))) {
		MessageBoxA(nullptr, "Please set EggmanLand's music to day when using different stage packs.", "Sonic Unleashed: Reimagined", MB_ICONERROR);
		exit(-1);
	}
	if (!StringHelper::Compare(stageegbpacktype, ".\\Extra\\STGEggmanLand\\") && (!StringHelper::Compare(egbadd2type, "Off"))) {
		MessageBoxA(nullptr, "Tornado Defence options require EggmanLand mode. Please set Tornado Defence options to off when using different stage packs.", "Sonic Unleashed: Reimagined", MB_ICONERROR);
		exit(-1);
	}
	if (!StringHelper::Compare(customhudtype, "Off") && (!StringHelper::Compare(hudtype, "Off"))) {
		MessageBoxA(nullptr, "Please disable Encore HUD options when using a custom imported HUD.", "Sonic Unleashed: Reimagined", MB_ICONERROR);
		exit(-1);
	}
	if (!StringHelper::Compare(customcharactertype, "Off") && (!StringHelper::Compare(sonictype, "Off"))) {
		MessageBoxA(nullptr, "Please disable Encore Sonic or Character options when using a custom imported Character.", "Sonic Unleashed: Reimagined", MB_ICONERROR);
		exit(-1);
	}
	//if (!StringHelper::Compare(apadabatextype, ".\\Adventure Pack\\Extended\\AdabatEX\\") && (!StringHelper::Compare(apadabattype, "Off") || (!StringHelper::Compare(apadabattype, ".\\Adventure Pack\\Standalone\\Adabat\\")))) {
	//	MessageBoxA(nullptr, "Temp text.", "Sonic Unleashed: Reimagined", MB_ICONERROR);
	//	exit(-1);
	//}
	//if (!StringHelper::Compare(apapotosextype, ".\\Adventure Pack\\Extended\\ApotosEX\\") && (!StringHelper::Compare(apapotostype, "Off") || (!StringHelper::Compare(apapotostype, ".\\Adventure Pack\\Standalone\\Apotos\\")))) {
	//	MessageBoxA(nullptr, "Temp text.", "Sonic Unleashed: Reimagined", MB_ICONERROR);
	//	exit(-1);
	//}
	//if (!StringHelper::Compare(apchinaextype, ".\\Adventure Pack\\Extended\\ChinaEX\\") && (!StringHelper::Compare(apchinatype, "Off") || (!StringHelper::Compare(apchinatype, ".\\Adventure Pack\\Standalone\\China\\")))) {
	//	MessageBoxA(nullptr, "Temp text.", "Sonic Unleashed: Reimagined", MB_ICONERROR);
	//	exit(-1);
	//}
	//if (!StringHelper::Compare(apempireextype, ".\\Adventure Pack\\Extended\\EmpireEX\\") && (!StringHelper::Compare(apempiretype, "Off") || (!StringHelper::Compare(apempiretype, ".\\Adventure Pack\\Standalone\\Empire\\")))) {
	//	MessageBoxA(nullptr, "Temp text.", "Sonic Unleashed: Reimagined", MB_ICONERROR);
	//	exit(-1);
	//}
	//if (!StringHelper::Compare(apholoskaextype, ".\\Adventure Pack\\Extended\\HoloskaEX\\") && (!StringHelper::Compare(apholoskatype, "Off") || (!StringHelper::Compare(apholoskatype, ".\\Adventure Pack\\Standalone\\Holoska\\")))) {
	//	MessageBoxA(nullptr, "Temp text.", "Sonic Unleashed: Reimagined", MB_ICONERROR);
	//	exit(-1);
	//}
	//if (!StringHelper::Compare(apmazuriextype, ".\\Adventure Pack\\Extended\\MazuriEX\\") && (!StringHelper::Compare(apmazuritype, "Off") || (!StringHelper::Compare(apmazuritype, ".\\Adventure Pack\\Standalone\\Mazuri\\")))) {
	//	MessageBoxA(nullptr, "Temp text.", "Sonic Unleashed: Reimagined", MB_ICONERROR);
	//	exit(-1);
	//}
	//if (!StringHelper::Compare(apshamarextype, ".\\Adventure Pack\\Extended\\ShamarEX\\") && (!StringHelper::Compare(apshamartype, "Off") || (!StringHelper::Compare(apshamartype, ".\\Adventure Pack\\Standalone\\Shamar\\")))) {
	//	MessageBoxA(nullptr, "Temp text.", "Sonic Unleashed: Reimagined", MB_ICONERROR);
	//	exit(-1);
	//}
	//if (!StringHelper::Compare(apspagoniaextype, ".\\Adventure Pack\\Extended\\SpagoniaEX\\") && (!StringHelper::Compare(apspagoniatype, "Off") || (!StringHelper::Compare(apspagoniatype, ".\\Adventure Pack\\Standalone\\Spagonia\\")))) {
	//	MessageBoxA(nullptr, "Temp text.", "Sonic Unleashed: Reimagined", MB_ICONERROR);
	//	exit(-1);
	//}
}