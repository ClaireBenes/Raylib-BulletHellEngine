#include "raylib.h"
#include "imgui.h"
#include "rlImGui.h"

#include "Bullet.h"
#include "BulletData.h"
#include "BulletSpawner.h"
#include "Player.h"

#include <iostream>
#include <vector>
#include <memory>
#include <math.h>


//Variable
int screenWidth = 1560;
//int screenWidth = 780;
int screenHeight = 960;

GameManager gameManager;


//Function
void Load();
void Update();
void Draw();
void Unload();
void CallImGui();

int main()
{
    //********** Variables **********//

    BulletData orangeBullet {};
    orangeBullet.mColor = ORANGE;
    orangeBullet.mSpeed = 200;
    orangeBullet.mSize = 10;
    orangeBullet.mAngularVelocity = 0.5f;

    BulletData purpleBullet {};
    purpleBullet.mColor = PURPLE;
    purpleBullet.mSpeed = 200;
    purpleBullet.mSize = 10;
    purpleBullet.mAngularVelocity = 0.5f;

    BulletData blueBullet {};
    blueBullet.mColor = BLUE;
    blueBullet.mSpeed = 100;
    blueBullet.mSize = 20;
    blueBullet.mAngularVelocity = 0.0f;

    AttackPatternData arthurPattern2 {};
    arthurPattern2.bulletData = orangeBullet;
    arthurPattern2.timeBetweenBullet = 0.15f;
    arthurPattern2.bulletCount = 2;
    arthurPattern2.rotationSpeed = 2;
    arthurPattern2.bulletRotationOffset = 0.0f;

    AttackPatternData arthurPattern {};
    arthurPattern.bulletData = purpleBullet;
    arthurPattern.timeBetweenBullet = 0.15f;
    arthurPattern.bulletCount = 2;
    arthurPattern.rotationSpeed = 2;
    //(PI / 180.0f) to convert in degrees
    arthurPattern.bulletRotationOffset = 90 * (PI / 180.0f);

    AttackPatternData clairePattern {};
    clairePattern.bulletData = blueBullet;
    clairePattern.timeBetweenBullet = 1.5f;
    clairePattern.bulletCount = 8;
    clairePattern.rotationSpeed = 6;
    clairePattern.bulletRotationOffset = 0.0f;

    //********** Variables **********//

    auto bulletSpawner = std::make_shared<BulletSpawner>(780 / 2.0f, screenHeight / 3.0f);
    //To erase later -- will be made in run time
    bulletSpawner->AddAttackPattern(arthurPattern);
    bulletSpawner->AddAttackPattern(arthurPattern2);
    bulletSpawner->AddAttackPattern(clairePattern);

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
    //ImGuiIO& io = ImGui::GetIO();
    //io.ConfigWindowsMoveFromTitleBarOnly;
    //ImGui::ImageButton(texId, ImGui::GetContentRegionAvail(), ImVec2(0.0f, 1.0f), ImVec2(1.0f, 0.0f), 0);
}

void Update() 
{
    float deltaTime = GetFrameTime();
    gameManager.Update(deltaTime);

    //ImGui::SetNextWindowSizeConstraints(ImVec2(1560, 960), ImVec2(1560, 960));
}

void Draw() 
{
    BeginDrawing();
    ClearBackground(BLACK);

    gameManager.Draw();
    CallImGui();

    EndDrawing();
}

void Unload() 
{
    rlImGuiShutdown();
    CloseWindow();
}

void CallImGui()
{
    rlImGuiBegin();

    ImGuiWindowFlags windowFlags
    {
        ImGuiWindowFlags_NoMove
        //ImGuiWindowFlags_NoBackground
    };

    //ImGui::Begin("BulletEditor");
    ImGui::Begin("BulletEditor", NULL, windowFlags);
    ImGui::Text("Going to have bullet editor there");
    ImGui::End();

    //ImGui::Begin("AttackPattern Editor");
    ImGui::Begin("AttackPattern Editor", NULL, windowFlags);
    ImGui::Text("Going to have Attack Pattern editor there");
    ImGui::End();

    //ImGui::ShowDemoWindow();

    rlImGuiEnd();
}


