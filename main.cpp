#include "raylib.h"

#include "Bullet.h"
#include "BulletData.h"
#include "BulletSpawner.h"

#include <iostream>
#include <vector>
#include <memory>
#include <math.h>

//Variable
int screenWidth = 780;
int screenHeight = 960;

GameManager gameManager;

//Function
void Load();
void Update();
void Draw();
void Unload();

int main()
{
    //********** Variables **********//

    BulletData orangeBullet {};
    orangeBullet.mColor = ORANGE;
    orangeBullet.mSpeed = 200;
    orangeBullet.mScale = 1.2;
    orangeBullet.mAngularVelocity = 0.7f;

    BulletData purpleBullet {};
    purpleBullet.mColor = PURPLE;
    purpleBullet.mSpeed = 200;
    purpleBullet.mScale = 1.2;
    purpleBullet.mAngularVelocity = 0.7f;

    AttackPatternData clairePattern {};
    clairePattern.bulletdata = orangeBullet;
    clairePattern.timeBetweenBullet = 0.15f;
    clairePattern.bulletCount = 2;
    clairePattern.rotationSpeed = 2;
    clairePattern.bulletRotationOffset = 0.0f;

    AttackPatternData arthurPattern {};
    arthurPattern.bulletdata = purpleBullet;
    arthurPattern.timeBetweenBullet = 0.15f;
    arthurPattern.bulletCount = 2;
    arthurPattern.rotationSpeed = 2;
    //(PI / 180.0f) to convert in degrees
    arthurPattern.bulletRotationOffset = 90 * (PI / 180.0f);

    //********** Variables **********//

    auto bulletSpawner = std::make_shared<BulletSpawner>(780 / 2.0f, 960 / 2.0f);
    bulletSpawner->AddAttackPattern(clairePattern);
    bulletSpawner->AddAttackPattern(arthurPattern);

    gameManager.ToAddObject(bulletSpawner);


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

    EndDrawing();
}

void Unload() 
{
    CloseWindow();
}


