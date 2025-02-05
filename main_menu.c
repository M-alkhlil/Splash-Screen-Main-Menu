
#include "cprocessing.h"
#include "splashscreen.h"
#include "mainmenu.h"
#include <stdbool.h>
#include <stdlib.h> // For rand()

// Cached variables
static CP_Image g_digipenLogo = NULL;
static CP_Image Splash_screen = NULL;
// Background image
static CP_Image menuBackground = NULL;

// Button dimensions and positions
#define BUTTON_WIDTH 200
#define BUTTON_HEIGHT 50
#define BUTTON_PADDING 40


// Button states
typedef enum {
    BUTTON_START,
    BUTTON_OPTIONS,
    BUTTON_EXIT
} ButtonType;

// Function prototypes
void DrawButton(float x, float y, const char* text);
//ButtonType CheckButtonClick(float x, float y, float width, float height);

enum SplashScreenState g_splashScreenState = DIGIPENLOGO;



void InitializeSplashScreen(void)
{
    g_digipenLogo = CP_Image_Load("Assets/DigiPen_BLACK.png");
    Splash_screen = CP_Image_Load("Assets/splash-screen.png");
}

void UpdateSplashScreen(void)
{
    // Advance state on any key press or mouse click
    if (CP_Input_KeyTriggered(KEY_ANY) || CP_Input_MouseTriggered(MOUSE_BUTTON_1))
    {
        g_splashScreenState++;
    }

    // Clear background
    CP_Graphics_ClearBackground(CP_Color_Create(0, 0, 0, 255));

    // Display logos based on state
    switch (g_splashScreenState)
    {
    case DIGIPENLOGO:
        CP_Image_Draw(g_digipenLogo, (float)CP_System_GetWindowWidth() / 2.0f, (float)CP_System_GetWindowHeight() / 2.0f, 762.5f, 222.5f, 255);
        break;
    case SPLASH_SCREEN:
        CP_Image_Draw(Splash_screen, (float)CP_System_GetWindowWidth() / 2.0f, (float)CP_System_GetWindowHeight() / 2.0f, 512.f, 512.f, 255);
        break;
    default:
        // Transition to the main menu or next game state
        CP_Engine_SetNextGameState(InitializeMainMenu, UpdateMainMenu, ExitMainMenu);
        break;
    }
}

void ExitSplashScreen(void)
{
    CP_Image_Free(&g_digipenLogo);
    CP_Image_Free(&Splash_screen);
}

void InitializeMainMenu(void)
{
    // Load the background image
    menuBackground = CP_Image_Load("Assets/Background_Menu_NoClouds.png");
}

void UpdateMainMenu(void)
{
    // Clear background
    CP_Graphics_ClearBackground(CP_Color_Create(0, 0, 0, 255));

    // Draw the background image
    if (menuBackground != NULL) {
        CP_Image_Draw(menuBackground,
            (float)CP_System_GetWindowWidth() / 2.0f,  // Center X
            (float)CP_System_GetWindowHeight() / 2.0f, // Center Y
            (float)CP_System_GetWindowWidth(),         // Width of the window
            (float)CP_System_GetWindowHeight(),        // Height of the window
            255);                                      // Fully opaque
    }

    // Calculate button positions
    float centerX = (float)CP_System_GetWindowWidth() / 2.0f;
    float startY = (float)CP_System_GetWindowHeight() / 2.0f - (BUTTON_HEIGHT + BUTTON_PADDING) * 1.5f;

    // Draw buttons
    DrawButton(centerX - BUTTON_WIDTH / 2, startY, "Start Game");
    DrawButton(centerX - BUTTON_WIDTH / 2, startY + BUTTON_HEIGHT + BUTTON_PADDING, "Options");
    DrawButton(centerX - BUTTON_WIDTH / 2, startY + 2 * (BUTTON_HEIGHT + BUTTON_PADDING), "Exit");
  
}
void ExitMainMenu(void)
{
    // Free the background image
    CP_Image_Free(&menuBackground);
}
// Helper function to draw a button
void DrawButton(float x, float y, const char* text)
{
    // Draw button rectangle
    CP_Settings_Fill(CP_Color_Create(100, 100, 100, 255)); // Gray color
    CP_Graphics_DrawRect(x, y, BUTTON_WIDTH, BUTTON_HEIGHT);

    // Draw button text
    CP_Settings_Fill(CP_Color_Create(255, 255, 255, 255)); // White color
    CP_Font_DrawText(text, x + BUTTON_WIDTH / 2 - strlen(text) * 4, y + BUTTON_HEIGHT / 2 );
}
