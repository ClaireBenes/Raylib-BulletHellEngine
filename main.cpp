#include "raylib.h"
#include "imgui.h"
#include "rlImGui.h"

#include "Bullet.h"
#include "BulletSpawner.h"
#include "Player.h"
#include "ToolInterface.h"

#include <iostream>
#include <vector>
#include <memory>
#include <math.h>
#include <sstream>
#include <string.h>


//Variable
int screenWidth = 1700;
//int screenWidth = 780;
int screenHeight = 960;

GameManager gameManager;
ToolInterface toolInterface;


//Function
void Load();
void Update();
void Draw();
void Unload();

int main()
{
    //********** Variables **********//

    auto bulletSpawner = std::make_shared<BulletSpawner>(780 / 2.0f, screenHeight / 3.0f);
    toolInterface.SetBulletSpawner(bulletSpawner);
    //toolInterface.SetGameManager(gameManager);

    auto player = std::make_shared<Player>(780 / 2.0f, screenHeight / 1.1f);

    gameManager.ToAddObject(bulletSpawner);
    gameManager.ToAddObject(player);


    Load();

    while (!WindowShouldClose())
    {
        Update();
        Draw();
    }

    Unload();
    return 0;
}

void Load() 
{
    InitWindow(screenWidth, screenHeight, "TouhouEngine");
    SetTargetFPS(60);

    rlImGuiSetup(true);

    toolInterface.Init();
}

void Update() 
{
    float deltaTime = GetFrameTime();
    gameManager.Update(deltaTime);
}

void Draw() 
{
    BeginDrawing();
    ClearBackground({ 7, 10, 25, 255 });

    gameManager.Draw();
    toolInterface.Draw();

    DrawText(TextFormat("FPS : %d", GetFPS()), 10, 10, 20, RED);

    EndDrawing();
}

void Unload() 
{
    rlImGuiShutdown();
    CloseWindow();
}