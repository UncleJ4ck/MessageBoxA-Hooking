#include "resources.h"


int main(void) {
	MessageBoxA(NULL, "Hello World", "Error!", MB_OK);

	PutTheHook();

	MessageBoxA(NULL, "Hello World", "Error!", MB_OK);

	return 0;
}