/*******************************************************************************************
*
*   Challenge 02:   DUNGEON GAME
*   Lesson 02:      shapes
*   Description:    Basic shapes definition and drawing (immediate mode style)
*
*   NOTE 1: This example requires the following single-file header-only modules:
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


    // LESSON 02: Init player 
    Rectangle player = { 100, 100, 32, 32 };

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

        // LESSON 02: Draw player and map shapes
        DrawRectangle(200, 100, 400, 250, (Color) { 0, 255, 0, 255 });
        DrawRectangleRec(player, (Color) { 255, 0, 0, 255 });

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();                  // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}