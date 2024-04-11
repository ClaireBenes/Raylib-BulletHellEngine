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
#include <sstream>
#include <string.h>


//Variable
int screenWidth = 1700;
//int screenWidth = 780;
int screenHeight = 960;

GameManager gameManager;
//std::vector<BulletData> allBullets;


//Function
void Load();
void Update();
void Draw();
void Unload();
void CallImGui();
void BulletEditor();
void AttackPatternEditor();

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
}

void Update() 
{
    float deltaTime = GetFrameTime();
    gameManager.Update(deltaTime);
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

    BulletEditor();
    AttackPatternEditor();

    ImGui::ShowDemoWindow();
    rlImGuiEnd();
}

void BulletEditor()
{
    ImGui::Begin("BulletEditor", NULL, ImGuiWindowFlags_NoMove);
    ImGui::SeparatorText("Creating a bullet");

    //create new bullet
    ImGui::Button("New Bullet +");

    //show all bullet already created
    const char* items[] = { "Orange", "Purple", "Blue" };
    static int item_current = 0;
    ImGui::Combo("Bullets", &item_current, items, IM_ARRAYSIZE(items));

    //choose Name
    static char str0[128] = "";
    ImGui::InputTextWithHint("Name", "Choose name of bullet", str0, IM_ARRAYSIZE(str0));

    if (ImGui::TreeNodeEx("Bullet data", ImGuiTreeNodeFlags_DefaultOpen))
    {
        //choose color
        static float color[3] = { 1.0f, 0.0f, 0.0f };
        ImGui::ColorEdit3("Color", color);

        //choose image

        //choose speed
        static float sliderSpeed = 100.0f;
        ImGui::SliderFloat("Speed", &sliderSpeed, 0.0f, 500.0f);

        //choose size
        static float sliderSize = 10.0f;
        ImGui::SliderFloat("Size", &sliderSize, 5.0f, 50.0f);

        //choose angular velocity
        static float dragVelocity = 0.5f;
        ImGui::DragFloat("Angular Velocity", &dragVelocity, 0.005f, 0.0f, 1.0f);

        ImGui::TreePop();
    }

    ImGui::End();
}

int attackpatternNumber = 0;

void AttackPatternEditor()
{
    ImGui::Begin("AttackPattern Editor", NULL, ImGuiWindowFlags_NoMove);
    ImGui::SeparatorText("Creating an attack pattern");

    //create new attack pattern
    if (ImGui::Button("New Attack Pattern +"))
    {
        attackpatternNumber++;
    }

    //const char* items[] = { "AAAA", "BBBB", "CCCC", "DDDD", "EEEE", "FFFF", "GGGG", "HHHH", "IIII", "JJJJ", "KKKK", "LLLLLLL", "MMMM", "OOOOOOO" };
    

    for (int i = 0; i < attackpatternNumber; i++)
    {
        if (ImGui::TreeNodeEx(TextFormat("Attack Pattern %d", i), ImGuiTreeNodeFlags_DefaultOpen))
        {
            //show all bullet already created
            const char* items[] = { "Orange", "Purple", "Blue" };
            static int everyBullet[100];
            ImGui::Combo("Bullets", &everyBullet[i], items, IM_ARRAYSIZE(items));

            //choose bullet count
            static int bulletCount[1000];
            ImGui::InputInt("Bullet Count", &bulletCount[i]);

            //choose time between bullet
            static float fireRate[100] = { 0.5f };
            ImGui::SliderFloat("Fire Rate", &fireRate[i], 0.0f, 20.0f);

            //choose rotation speed
            static float dragRotSpeed[100] = { 6.0f };
            ImGui::DragFloat("Rotation Speed", &dragRotSpeed[i], 0.05f, 0.0f, 20.0f);

            ImGui::TreePop();
        }
    }

    ImGui::End();
}


