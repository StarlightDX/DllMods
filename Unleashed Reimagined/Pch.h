#pragma once

#define WIN32_LEAN_AND_MEAN

// Detours
#include <Windows.h>
#include <detours.h>

// Standard library
#include <cstdint>
#include <cstdio>
#include <string>
#include <sstream>
#include <vector>

// Dependencies
#include <blueblur.h>
#include <Helpers.h>
#include "ArchiveTreePatcher.h"
#include <INIReader.h>
#include <StringHelper.h>