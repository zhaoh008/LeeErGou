#pragma once
#ifdef PLATFORM_WINDOWS
#ifdef BUILD_DLL
#define C_API __declspec(dllexport)
#else
#define C_API __declspec(dllimport)
#endif
#else
#error Only Windows Can Use Dll;
#endif