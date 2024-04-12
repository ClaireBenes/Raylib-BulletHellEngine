#pragma once
#include "raylib.h"

#include <string>

class BulletData
{
public:
    Color mColor = RED;
    Texture2D mInnerImage = LoadTexture("resources/simple2-bullet-inner.png");
    Texture2D mOuterImage = LoadTexture("resources/simple2-bullet-outer.png");
    std::string mName = "Elaine";
    float mSpeed = 50;
    float mAngularVelocity = 0;
    float mSize = 16;
};