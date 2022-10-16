/*******************************************************************************************
*
*   Challenge 02:   DUNGEON GAME
*   Lesson 04:      image and textures
*   Description:    Image data loading, texture creation and drawing
*
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


    // LESSON 02: Init player and map position
    Rectangle player = { 100, 100, 32, 32 };
    Rectangle map = { 200, 100, 400, 250 };

    // LESSON 03: old player position
    Rectangle oldPlayer = player;

    // LESSON 04: Load player texture
    Image imPlayer = LoadImage("resources/player.png");
    Texture2D texPlayer = LoadTextureFromImage(imPlayer);
    UnloadImage(imPlayer);

    if (!texPlayer.id)
        TraceLog(LOG_INFO, "Error texture not loaded correcly");


    // LESSON 04: Load tileset texture
    Image imTileset = LoadImage("resources/tileset.png");
    Texture2D texTileset = LoadTextureFromImage(imTileset);
    UnloadImage(imTileset);

    if (!texPlayer.id)
        TraceLog(LOG_INFO, "Error texture not loaded correcly");

    SetTargetFPS(60);

    //--------------------------------------------------------------------------------------    

    // Main game loop    
    while (!WindowShouldClose())
    {
        // Update
        //----------------------------------------------------------------------------------

        // LESSON 03: Player movement logic
        oldPlayer = player;

        if (IsKeyDown(KEY_DOWN)) player.y += 2;
        else if (IsKeyDown(KEY_UP)) player.y -= 2;

        if (IsKeyDown(KEY_RIGHT)) player.x += 2;
        else if (IsKeyDown(KEY_LEFT)) player.x -= 2;


        // LESSON 03: print the position of the player
        //TraceLog(LOG_INFO, "player pos: %.2f %.2f", player.x, player.y);


        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        ClearBackground(BLACK);             // Clear current framebuffer

        // LESSON 02: Draw player and map shapes
        //DrawRectangleRec(map, (Color) { 0, 255, 0, 255 });
        //DrawRectangleRec(player, (Color) { 255, 0, 0, 255 });


        // LESSON 04: Draw player and map shapes
        DrawTexture(texTileset, screenWidth / 2 - texTileset.width / 2, screenHeight / 2 - texTileset.height / 2, WHITE);   // Draw tileset texture
        DrawTexture(texPlayer, player.x, player.y, WHITE); // Draw player texture


        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------

    // LESSON 04: Unload player and tileset textures
    UnloadTexture(texPlayer);       // Unload player texture
    UnloadTexture(texTileset);      // Unload tileset texture

    CloseWindow();                  // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}