#pragma once

#include <stdint.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <chrono>
#include <queue>
#include <deque>
#include <stack>
#include <cassert>
#include <map>
#include <set>
#include <unordered_set>
#include <functional>
#include <chrono>

#include <Windows.h>

// Remove need for std namespace scope for very common datatypes
using std::vector;
using std::map;
using std::set;
using std::multiset;
using std::unordered_set;
using std::list;
using std::stack;
using std::deque;
using std::string;
using std::wstring;
using std::pair;

// Integer typedefs
typedef int8_t	int8;	typedef uint8_t	 uint8;
typedef int16_t int16;	typedef uint16_t uint16;
typedef int32_t int32;	typedef uint32_t uint32;
typedef int64_t int64;	typedef uint64_t uint64;
typedef uint8_t byte;

#define MAX(a, b) ((a > b) ? a : b)
#define MIN(a, b) ((a < b) ? a : b)

#define CLAMP(val, min, max) MIN(MAX(val, min), max)

#define STR(s) ([=]{ std::stringstream __macroStream; __macroStream << s; return __macroStream.str(); }())

// Returns sign of number (1 if positive, -1 if negative, and 0 if 0)
#define SGN(val) ((val > 0) - (val < 0))

#define LOG(s) {std::cout << std::dec << s << std::endl;}

// TODO: Why am I using macros instead of functions...

#define FATAL_ERROR(s) { \
	string errorStr = STR("FATAL ERROR: " << s << "\n\nGetLastError(): " << GetLastError()); \
	MessageBoxA(NULL, errorStr.c_str(), "RLArenaCollisionDumper", MB_ICONERROR); \
	exit(EXIT_FAILURE); \
}

#define READMEM(handle, address, outputBuffer, readSize) { \
	SIZE_T numBytesRead; \
	ReadProcessMemory(handle, (LPCVOID)address, outputBuffer, readSize, &numBytesRead);\
	if (numBytesRead < readSize) \
		FATAL_ERROR("Failed to read " << readSize << " byte(s) at " << (void*)address << "."); \
}

static_assert(sizeof(void*) == 8, "RLArenaCollisionDumper needs to be build as a 64-bit EXE.");