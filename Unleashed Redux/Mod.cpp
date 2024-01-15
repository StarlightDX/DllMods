#include "ModLoader.h"
#include <iostream>
#include <fstream>

extern "C" __declspec(dllexport) void PostInit()

//{
//	if (GetModLoaderAPI()->FindMod("sonic.aventurepack.adabat"))
//	{
//		// Create and open a text file
//		std::ofstream MyFile("cpk.ini");
//
//		// Write to the file
//		MyFile << "advenuturepack_adabat.txt";
//
//		// Close the file
//		MyFile.close();
//	}
//	else if (GetModLoaderAPI()->FindMod("sonic.aventurepack.apotos"))
//	{
//		// Create and open a text file
//		std::ofstream MyFile("cpk.ini");
//
//		// Write to the file
//		MyFile << "advenuturepack_apotos.txt";
//
//		// Close the file
//		MyFile.close();
//	}
//}

auto api = GetModLoaderAPI();
auto adabat = api->FindMod("sonic.adventurepack.adabat");
auto apotos = api->FindMod("sonic.adventurepack.apotos");

if (adabat)
{
	auto path = adabat->Path;
}

if (apotos)
{
	auto path = apotos->Path;
}

//if (FindMod())
//{
//	std::ofstream MyFile("adventurepack_adabat.txt");
//	MyFile << "cpk.ini";
//	MyFile.close();
//}