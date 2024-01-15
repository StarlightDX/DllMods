//#include "ModLoader.h"
//#include <iostream>
//#include <fstream>
//
//extern "C" __declspec(dllexport) void PostInit()
//
////{
////	if (GetModLoaderAPI()->FindMod("sonic.aventurepack.adabat"))
////	{
////		// Create and open a text file
////		std::ofstream MyFile("cpk.ini");
////
////		// Write to the file
////		MyFile << "advenuturepack_adabat.txt";
////
////		// Close the file
////		MyFile.close();
////	}
////	else if (GetModLoaderAPI()->FindMod("sonic.aventurepack.apotos"))
////	{
////		// Create and open a text file
////		std::ofstream MyFile("cpk.ini");
////
////		// Write to the file
////		MyFile << "advenuturepack_apotos.txt";
////
////		// Close the file
////		MyFile.close();
////	}
////}
//{
//auto api = GetModLoaderAPI();
//auto adabat = api->FindMod("sonic.adventurepack.adabat");
//auto apotos = api->FindMod("sonic.adventurepack.apotos");
//auto chunnan = api->FindMod("sonic.adventurepack.chunnan");
//auto empirecity = api->FindMod("sonic.adventurepack.empireicity");
//auto holoska = api->FindMod("sonic.adventurepack.holoska");
//auto mazuri = api->FindMod("sonic.adventurepack.mazuri");
//auto shamar = api->FindMod("sonic.adventurepack.shamar");
//auto spagonia = api->FindMod("sonic.adventurepack.spagonia");
//
//if (adabat)
//{
//	auto path = adabat->Path;
//}
//
//if (apotos)
//{
//	auto path = apotos->Path;
//}
//}

#include <filesystem>
#include <fstream>
#include "ModLoader.h"

void writeCpkIni(std::filesystem::path in_path)
{
    std::ofstream ini(in_path / "cpk.ini");

    ini << "stuff";

    ini.close();
}

extern "C" __declspec(dllexport) void PostInit()
{
    auto api = GetModLoaderAPI();
    auto adabat = api->FindMod("sonic.adventurepack.adabat");
    auto apotos = api->FindMod("sonic.adventurepack.apotos");

    if (adabat)
    {
        writeCpkIni(std::filesystem::path(adabat->Path));
    }

    if (apotos)
    {
        writeCpkIni(std::filesystem::path(apotos->Path));
    }
}