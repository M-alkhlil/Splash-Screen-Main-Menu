//---------------------------------------------------------
// file:	main.c
// author:	[NAME]
// email:	[ EMAIL ADDRESS]
//
// brief:	Main entry point for the sample project
//			of the CProcessing library
//
// documentation link:
// https://github.com/DigiPen-Faculty/CProcessing/wiki
//
// Copyright © 2020 DigiPen, All rights reserved.
//---------------------------------------------------------

#include "cprocessing.h"

// use CP_Engine_SetNextGameState to specify this function as the initialization function
// this function will be called once at the beginning of the program
void game_init(void)
{
    CP_System_SetWindowSize(1920, 1080);
}
void game_update(void)
{

    CP_Graphics_ClearBackground(CP_Color_Create(135, 206, 235, 255));
    CP_Settings_Fill(CP_Color_Create(19, 133, 16, 255));
    CP_Graphics_DrawRect(0, 950, 1920, 200);
    CP_Settings_Fill(CP_Color_Create(255, 228, 132, 255));
    CP_Graphics_DrawCircle(1080, 100, 100);
    CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
    CP_Graphics_DrawRect(500, 750, 100, 200);

}
void game_exit(void)
{
    // Nothing to clean up in this example
}
int main(void)
{
    CP_Engine_SetNextGameState(game_init, game_update, game_exit);
    CP_Engine_Run();
}
