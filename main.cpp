#include "raylib.h"
#include "Bullet.h"
#include "BulletData.h"
#include "BulletSpawner.h"

#include <iostream>
#include <vector>
#include <memory>

//Variable
int screenWidth = 780;
int screenHeight = 960;

GameManager gameManager;

//Function
void Load();
void Update();
void Draw();
void Unload();

bool Collision(Rectangle a, Rectangle b);

int main()
{
    BulletData pinkBullet {};
    pinkBullet.mColor = PINK;
    pinkBullet.mSpeed = 20;
    pinkBullet.mScale = 2;

    Bullet bullet {};
    bullet.ChangeBulletData(pinkBullet);
    //bullet.mX = 780 / 2.0f;
    //bullet.mY = 960 / 2.0f;
    //bullet.mBulletData = pinkBullet;

    //std::shared_ptr<Bullet> newbulelt = bullet;

    //gameManager.ToAddObject(std::make_shared <bullet>);

    BulletSpawner bulletSpawner { 780 / 2.0f, 960 / 2.0f };



    gameManager.ToAddObject(std::make_shared<BulletSpawner>(780 / 2.0f, 960 / 2.0f));

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

bool Collision(Rectangle a, Rectangle b)
{
    int xMinA = a.x;
    int yMinA = a.y;
    int xMaxA = a.x + a.width;
    int yMaxA = a.y + a.height;

    int xMinB = b.x;
    int yMinB = b.y;
    int xMaxB = b.x + b.width;
    int yMaxB = b.y + b.height;

    return ( !(xMinB > xMaxA || yMinB > yMaxA
        || xMaxB < xMinA || yMaxB < yMinA) );
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


