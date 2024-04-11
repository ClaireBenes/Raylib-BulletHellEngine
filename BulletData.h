#pragma once
#include "raylib.h"

#include <string>

class BulletData
{
public:
    Color mColor = RED;
    std::string mName = "Elaine";
    float mSpeed = 50;
    float mAngularVelocity = 0;
    float mSize = 10;
};