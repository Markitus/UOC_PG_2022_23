/*******************************************************************************************
*
*   Challenge 02:   DUNGEON GAME
*   Lesson 05:      tilemap
*   Description:    Tilemap loading and drawing
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


// LESSON 05: Tile struct
typedef struct Tile {
    int value;                  // Tile index value (in tileset)
    bool collider;              // Tile collider (0 -> walkable)
    Color color;                // Tile color (could be useful)
} Tile;

// LESSON 05: Tilemap struct
typedef struct Tilemap {
    Tile* tiles;                // Tiles data
    int tileCountX;             // Tiles counter X
    int tileCountY;             // Tiles counter Y
    int tileSize;               // Tile size (XY)
    Vector2 position;           // Tilemap position in screen
} Tilemap;
//----------------------------------------------------------------------------------
// Global Variables Declaration
//----------------------------------------------------------------------------------

// LESSON 05: Tilemap data loading and drawing
#define TILESET_TILES  32

// NOTE: Tileset rectangles are directly provided in this array but
// they can also be loaded from a file... usually generated with
// a tilemap editor software
static Rectangle tilesetRecs[TILESET_TILES] = {
    { 0, 0, 32, 32 }, { 32, 0, 32, 32 },        // 1, 2
    { 64, 0, 32, 32 }, { 0, 32, 32, 32 },       // 3, 4
    { 32, 32, 32, 32 }, { 64, 32, 32, 32 },     // 5, 6
    { 0, 64, 32, 32 }, { 32, 64, 32, 32 },      // 7, 8
    { 64, 64, 32, 32 }, { 96, 0, 32, 32 },      // 9, 10
    { 128, 0, 32, 32 }, { 96, 32, 32, 32 },     // 11, 12
    { 128, 32, 32, 32 }, { 96, 64, 32, 32 },    // 13, 14
    { 128, 64, 32, 32 }, { 128, 96, 32, 32 },   // 15, 16
    { 0, 96, 32, 32 }, { 32, 96, 32, 32 },      // 17, 18
    { 64, 96, 32, 32 }, { 96, 96, 32, 32 },     // 19, 20
    { 160, 96, 32, 32 }, { 160, 0, 32, 32 },    // 21, 22
    { 160, 32, 32, 32 }, { 160, 64, 32, 32 },   // 23, 24
    { 192, 0, 32, 32 }, { 224, 0, 32, 32 },     // 25, 26
    { 192, 32, 32, 32 }, { 224, 32, 32, 32 },   // 27, 28
    { 192, 64, 32, 32 }, { 224, 64, 32, 32 },   // 29, 30
    { 192, 96, 32, 32 }, { 224, 96, 32, 32 }    // 31, 32
};


// LESSON 05: Tilemap data loading and drawing
//----------------------------------------------------------------------------------
static Tilemap LoadTilemap(const char* valuesMap, const char* collidersMap);// Load tilemap data from file
static void UnloadTilemap(Tilemap map);                   // Unload tilemap data
static void DrawTilemap(Tilemap map, Texture2D tileset);  // Draw tilemap using tileset



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
    //Rectangle player = { 100, 100, 32, 32 };
    //Rectangle map = { 200, 100, 400, 250 };

    // LESSON 04: Load player texture
    Image imPlayer = LoadImage("resources/player.png");
    Texture2D texPlayer = LoadTextureFromImage(imPlayer);
    UnloadImage(imPlayer);

    if (!texPlayer.id)
        TraceLog(LOG_INFO, "Error texture not loaded correcly");


    // LESSON 05: Load tilemap data: tile values (tileset index) and tile colliders
    Tilemap tilemap = LoadTilemap("resources/tilemap.txt", "resources/tilemap_colliders.txt");

    tilemap.tileSize = 32;
    tilemap.position = (Vector2){ screenWidth / 2 - tilemap.tileCountX * tilemap.tileSize / 2,
                                  screenHeight / 2 - tilemap.tileCountY * tilemap.tileSize / 2 };

    // LESSON 04: Load tileset texture
    Image imTileset = LoadImage("resources/tileset.png");
    Texture2D texTileset = LoadTextureFromImage(imTileset);
    UnloadImage(imTileset);

    if (!texPlayer.id)
        TraceLog(LOG_INFO, "Error texture not loaded correcly");


    // LESSON 05: Init player position in the tilemap
    Rectangle player = { tilemap.position.x + 1 * tilemap.tileSize + 8, tilemap.position.y + 1 * tilemap.tileSize + 8, 8, 8 };

    // LESSON 03: old player position
    Rectangle oldPlayer = player;

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

        // LESSON 05: Draw player and map shapes
        DrawTilemap(tilemap, texTileset);   // Draw tilemap using provide tileset

        // LESSON 04: Draw player and map shapes
        //DrawTexture(texTileset, screenWidth / 2 - texTileset.width / 2, screenHeight / 2 - texTileset.height / 2, WHITE);   // Draw tileset texture
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



// LESSON 05: Tilemap data loading and drawing
//----------------------------------------------------------------------------------
// Load tilemap data from file (text/image)
static Tilemap LoadTilemap(const char* valuesMap, const char* collidersMap)
{
    Tilemap map = { 0 };
    const char* fileExt;

    if ((fileExt = strrchr(valuesMap, '.')) != NULL)
    {
        // Check if file extension is supported
        if (strcmp(fileExt, ".txt") == 0)
        {
            int counter = 0;
            int temp = 0;

            // Read values from text file
            FILE* valuesFile = fopen(valuesMap, "rt");

            while (!feof(valuesFile))
            {
                fscanf(valuesFile, "%i", &temp);
                counter++;
            }

            rewind(valuesFile);        // Return to the beginning of the file, to read again

            map.tiles = (Tile*)malloc(counter * sizeof(Tile));

            map.tileCountX = 12;
            map.tileCountY = 8;
            counter = 0;

            while (!feof(valuesFile))
            {
                fscanf(valuesFile, "%i", &map.tiles[counter].value);
                counter++;
            }

            fclose(valuesFile);

            // Read values from text file
            // NOTE: Colliders map data MUST match values data, 
            // or we need to do a previous check like done with values data
            FILE* collidersFile = fopen(collidersMap, "rt");
            counter = 0;
            temp = 0;

            while (!feof(collidersFile))
            {
                fscanf(collidersFile, "%i", &temp);
                map.tiles[counter].collider = temp;

                counter++;
            }

            fclose(collidersFile);

#if DEBUG   // print tilemap information loaded
            for (int j = 0; j < map.tileCountY; j++)
            {
                for (int i = 0; i < map.tileCountX; i++)
                {
                    printf("%i ", map.tiles[j * map.tileCountX + i].collider);
                }

                printf("\n");
            }
#endif
        }
    }

    return map;
}


// Unload tilemap data from memory
static void UnloadTilemap(Tilemap map)
{
    if (map.tiles != NULL) free(map.tiles);
}

// Draw tilemap using tileset
static void DrawTilemap(Tilemap map, Texture2D tileset)
{
    for (int y = 0; y < map.tileCountY; y++)
    {
        for (int x = 0; x < map.tileCountX; x++)
        {
            // Draw each piece of the tileset in the right position to build map
            DrawTextureRec(tileset, tilesetRecs[map.tiles[y * map.tileCountX + x].value - 1],
                (Vector2) {
                map.position.x + x * map.tileSize, map.position.y + y * map.tileSize
            }, WHITE);
        }
    }

}
