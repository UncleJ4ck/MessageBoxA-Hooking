#pragma once 

#include <Windows.h>
#include <iostream>


class Hooking {
    private:
        char MessageBoxAfirstBytes[6];
        FARPROC MessageBoxAddress;
        HANDLE Process = GetCurrentProcess();
    public:
        int __stdcall JumpFuncAfterHook(HWND hWnd, LPCSTR lpText, LPCSTR lpCaption, UINT uType) {

            // ReWrite The First Bytes
            WriteProcessMemory(Process, (LPVOID)MessageBoxAddress, MessageBoxAfirstBytes, sizeof(MessageBoxAfirstBytes), 0);

            return MessageBoxA(NULL, "Hooked", "From Z0rch3r", MB_OK);
        }
        void PutTheHook() {
            // Getting The Memory Address Of MessageBoxA()
            HINSTANCE lib = LoadLibraryA("user32.dll");
            MessageBoxAddress = GetProcAddress(lib, "MessageBoxA");

            // Saving The First 6 Bytes  Of MessageBoxAfirstBytes
            BOOL SaveOrigBytes = ReadProcessMemory(Process, MessageBoxAddress, MessageBoxAfirstBytes, 6, 0);

            // Address Of JumpFuncAfterHook 
            void* JumpFuncAfterHookAddress = &JumpFuncAfterHook;

            // x68 = push
            // xC3 = ret

            // push JumpFuncAfterHookAddress
            // ret

            char patch[6] = { 0 };
            memcpy_s(patch, 1, "\x68", 1);

            memcpy_s(patch + 1, 4, &JumpFuncAfterHookAddress, 4);

            memcpy_s(patch + 5, 1, "\xC3", 1);

            // Patching The Function
            WriteProcessMemory(GetCurrentProcess(), (LPVOID)MessageBoxAddress, patch, sizeof(patch), 0);
        }
};







