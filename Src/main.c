

#include <stdlib.h>
#include "cprocessing.h"
#include "splashscreen.h"
#include "mainmenu.h"

int main(void)
{
 

	// Initialize program parameters
	CP_System_SetWindowSize(1024, 1024);
	CP_System_SetFrameRate(60.0f);

	CP_Engine_SetNextGameState(InitializeSplashScreen, UpdateSplashScreen, ExitSplashScreen);
	CP_Engine_Run();
	return 0;
}
