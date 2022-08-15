#include "resource.hpp"



int main(void) {
    // Obj Creation
    Hooking HK;
    
    // Testing If The Function Hooked Successfully
    HK.MessageBoxA(NULL, "Hello World", "Error!", MB_OK);
    
    // puting the hook
    HK.PutTheFuckingHook();

    // Testing If The Function Hooked Successfully
    HK.MessageBoxA(NULL, "hi", "hi", MB_OK);
}
