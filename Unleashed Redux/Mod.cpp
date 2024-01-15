#include "ModLoader.h"
extern "C" __declspec(dllexport) void PostInit()
{
	
	if (GetModLoaderAPI()->FindMod(“sonic.aventurepack.adabat”))
		using namespace std;
		int main() {
		// Create and open a text file
		ofstream MyFile("mod.ini");

		// Write to the file
		MyFile << "adventurepack_adabat.ini";

		// Close the file
		MyFile.close();
	}