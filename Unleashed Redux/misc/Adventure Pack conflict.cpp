std::string apadabattype;
std::string apapotostype;
std::string apchinatype;
std::string apempiretype;
std::string apholoskatype;
std::string apmazuritype;
std::string apshamartype;
std::string apspagoniatype;
std::string apadabatextype;
std::string apapotosextype;
std::string apchinaextype;
std::string apempireextype;
std::string apholoskaextype;
std::string apmazuriextype;
std::string apshamarextype;
std::string apspagoniaextype;

     apadabattype = reader.Get("Main", "IncludeDir7", ".\\Adventure Pack\\Standalone\\Adabat\\");
	 apadabattype = reader.Get("Main", "IncludeDir7", ".\\Adventure Pack\\Standalone\\Apotos\\");
	 apadabattype = reader.Get("Main", "IncludeDir7", ".\\Adventure Pack\\Standalone\\China\\");
	 apadabattype = reader.Get("Main", "IncludeDir7", ".\\Adventure Pack\\Standalone\\Empire\\");
	 apadabattype = reader.Get("Main", "IncludeDir7", ".\\Adventure Pack\\Standalone\\Holoska\\");
	 apadabattype = reader.Get("Main", "IncludeDir7", ".\\Adventure Pack\\Standalone\\Mazuri\\");
	 apadabattype = reader.Get("Main", "IncludeDir7", ".\\Adventure Pack\\Standalone\\Shamar\\");
	 apadabattype = reader.Get("Main", "IncludeDir7", ".\\Adventure Pack\\Standalone\\Spagonia\\");	 
	 apadabatextype = reader.Get("Main", "IncludeDir5", ".\\Adventure Pack\\Extended\\AdabatEX\\");
	 apadabatextype = reader.Get("Main", "IncludeDir5", ".\\Adventure Pack\\Extended\\ApotosEX\\");
	 apadabatextype = reader.Get("Main", "IncludeDir5", ".\\Adventure Pack\\Extended\\ChinaEX\\");
	 apadabatextype = reader.Get("Main", "IncludeDir5", ".\\Adventure Pack\\Extended\\EmpireEX\\");
	 apadabatextype = reader.Get("Main", "IncludeDir5", ".\\Adventure Pack\\Extended\\HoloskaEX\\");
	 apadabatextype = reader.Get("Main", "IncludeDir5", ".\\Adventure Pack\\Extended\\MazuriEX\\");
	 apadabatextype = reader.Get("Main", "IncludeDir5", ".\\Adventure Pack\\Extended\\ShamarEX\\");
	 apadabatextype = reader.Get("Main", "IncludeDir5", ".\\Adventure Pack\\Extended\\SpagoniaEX\\");
	 
	 	if (!StringHelper::Compare(apadabatextype, ".\\Adventure Pack\\Extended\\AdabatEX\\") && (!StringHelper::Compare(apadabattype, "Off") || (!StringHelper::Compare(apadabattype, ".\\Adventure Pack\\Standalone\\Adabat\\")))) {
		MessageBoxA(nullptr, "Temp text.", "Sonic Unleashed: Reimagined", MB_ICONERROR);
		exit(-1);
	}
	 	if (!StringHelper::Compare(apapotosextype, ".\\Adventure Pack\\Extended\\ApotosEX\\") && (!StringHelper::Compare(apapotostype, "Off") ||  (!StringHelper::Compare(apapotostype, ".\\Adventure Pack\\Standalone\\Apotos\\")))) {
		MessageBoxA(nullptr, "Temp text.", "Sonic Unleashed: Reimagined", MB_ICONERROR);
		exit(-1);
	}
	 	if (!StringHelper::Compare(apchinaextype, ".\\Adventure Pack\\Extended\\ChinaEX\\") && (!StringHelper::Compare(apchinatype, "Off") ||  (!StringHelper::Compare(apchinatype, ".\\Adventure Pack\\Standalone\\China\\")))) {
		MessageBoxA(nullptr, "Temp text.", "Sonic Unleashed: Reimagined", MB_ICONERROR);
		exit(-1);
	}
	 	if (!StringHelper::Compare(apempireextype, ".\\Adventure Pack\\Extended\\EmpireEX\\") && (!StringHelper::Compare(apempiretype, "Off") ||  (!StringHelper::Compare(apempiretype, ".\\Adventure Pack\\Standalone\\Empire\\")))) {
		MessageBoxA(nullptr, "Temp text.", "Sonic Unleashed: Reimagined", MB_ICONERROR);
		exit(-1);
	}
	 	if (!StringHelper::Compare(apholoskaextype, ".\\Adventure Pack\\Extended\\HoloskaEX\\") && (!StringHelper::Compare(apholoskatype, "Off") ||  (!StringHelper::Compare(apholoskatype, ".\\Adventure Pack\\Standalone\\Holoska\\")))) {
		MessageBoxA(nullptr, "Temp text.", "Sonic Unleashed: Reimagined", MB_ICONERROR);
		exit(-1);
	}
	 	if (!StringHelper::Compare(apmazuriextype, ".\\Adventure Pack\\Extended\\MazuriEX\\") && (!StringHelper::Compare(apmazuritype, "Off") ||  (!StringHelper::Compare(apmazuritype, ".\\Adventure Pack\\Standalone\\Mazuri\\")))) {
		MessageBoxA(nullptr, "Temp text.", "Sonic Unleashed: Reimagined", MB_ICONERROR);
		exit(-1);
	}
	 	if (!StringHelper::Compare(apshamarextype, ".\\Adventure Pack\\Extended\\ShamarEX\\") && (!StringHelper::Compare(apshamartype, "Off") ||  (!StringHelper::Compare(apshamartype, ".\\Adventure Pack\\Standalone\\Shamar\\")))) {
		MessageBoxA(nullptr, "Temp text.", "Sonic Unleashed: Reimagined", MB_ICONERROR);
		exit(-1);
	}
	 	if (!StringHelper::Compare(apspagoniaextype, ".\\Adventure Pack\\Extended\\SpagoniaEX\\") && (!StringHelper::Compare(apspagoniatype, "Off") ||  (!StringHelper::Compare(apspagoniatype, ".\\Adventure Pack\\Standalone\\Spagonia\\")))) {
		MessageBoxA(nullptr, "Temp text.", "Sonic Unleashed: Reimagined", MB_ICONERROR);
		exit(-1);
	}