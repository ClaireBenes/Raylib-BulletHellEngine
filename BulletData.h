#pragma once
#include "raylib.h"

#include <string.h>

class BulletData
{
public:
    Color mColor = RED;
    const char* mName = "Elaine";
    float mSpeed = 50;
    float mAngularVelocity = 0;
    float mSize = 10;
};