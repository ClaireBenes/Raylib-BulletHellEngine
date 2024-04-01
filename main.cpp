#include "raylib.h"

//Variable
int screenWidth = 780;
int screenHeight = 960;


//Function
void Load();
void Update();
void Draw();
void Unload();

bool Collision(Rectangle a, Rectangle b);

int main()
{
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
   //
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

    //

    EndDrawing();
}

void Unload() 
{
    CloseWindow();
}


