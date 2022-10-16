/*******************************************************************************************
*
*   Challenge 02:   DUNGEON GAME
*   Lesson 01:      window creation
*   Description:    window creation and management
*
*   NOTE 1: This example requires OpenGL 3.3 or ES2 for shaders support,
*       OpenGL 1.1 does not support shaders but it can also be used.
*
*   NOTE 2: This example requires the following single-file header-only modules:
*       raylib.h        - Raylib library
*
*   Copyright (c) 2017-2022 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#pragma once

#include "raylib.h"             // raylib library

#include <stdio.h>              // Standard input-output C library
#include <stdlib.h>             // Memory management functions: malloc(), free()
#include <string.h>             // String manipulation functions: strrchr(), strcmp()

//----------------------------------------------------------------------------------
// Types and Structures Definition
//----------------------------------------------------------------------------------

//----------------------------------------------------------------------------------
// Global Variables Declaration
//----------------------------------------------------------------------------------


//----------------------------------------------------------------------------------
// Main Entry point
//----------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    // LESSON 01: Window and graphic device initialization and management
    InitWindow(screenWidth, screenHeight, "CHALLENGE 02: DUNGEON GAME");          // Initialize Window using GLFW3

    //--------------------------------------------------------------------------------------    

    SetTargetFPS(60);

    // Main game loop    
    while (!WindowShouldClose())
    {
        // Update
        //----------------------------------------------------------------------------------
        // ...
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        ClearBackground(BLACK);             // Clear current framebuffer

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();                  // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}