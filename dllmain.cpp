// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <stdio.h>
#include <windows.h>
#include <stdio.h>
#include <fcntl.h>
#include <io.h>
#include <iostream>
#include <fstream>
#define DllExport   __declspec( dllexport )

typedef struct test {
    int a;
    int b;
    int c;
    int d;
    int e;
    char* string;
} _unk_struct;

CONSOLE_SCREEN_BUFFER_INFO coninfo;
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    //For output console
    FILE* pFile = nullptr;
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
        //Alloc a new console and set the STDOUT to it
        AllocConsole();
        freopen_s(&pFile, "CONOUT$", "w", stdout);
        break;
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

extern "C" DllExport BOOL _cdecl CscCngOpen() {
    return 0;
}
extern "C" DllExport BOOL _cdecl CscCngStatusRead(_unk_struct *data){
    printf("Recieved status query\n");
    sprintf_s(data->string, 523, "1NDV=00009999,2NDV=00009999,3NDV=00009999,4NDV=00009999");
    return 0;
}
extern "C" DllExport BOOL _cdecl CscCngClose() {
    printf("Connection close\n");
    return 0;
}
extern "C" DllExport BOOL _cdecl CscCngDispense() {
    printf("Dispensing\n");
    return 0;
}
extern "C" DllExport BOOL _cdecl CscCngTransport() {
    return 0;
}
extern "C" DllExport BOOL _cdecl CscCngReset() {
    return 0;
}
