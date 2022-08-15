# What's API hooking
- **API hooking** is a technique by which we can instrument and modify the behavior and flow of API calls.

## Instructions

1. Get memory address of the MessageBoxA function
2. Read the first 6 bytes of the MessageBoxA - will need these bytes for unhooking the function
3. Create a HookedMessageBox function that will be executed when the original MessageBoxA is called
4. Get memory address of the HookedMessageBox
5. Patch / redirect MessageBoxA to HookedMessageBox
6. Call MessageBoxA. Code gets redirected to HookedMessageBox
7. HookedMessageBox executes its code, prints the supplied arguments, unhooks the MessageBoxA and transfers the code control to the actual MessageBoxA



## DEMO

![](https://raw.githubusercontent.com/Z0rch3r/MessageBoxA-Hooking/main/hook.gif?token=GHSAT0AAAAAABVQVPFRX5HRKUHGUAE7VMTAYXZTJJQ)

