#pragma once

#include "BulletData.h"

class AttackPatternData
{
public:
    BulletData bulletData;
    //int bulletDataIndex = 0;
    float timeBetweenBullet = 1;
    float rotationSpeed = 1;
    float bulletRotationOffset = 0;
    int bulletCount = 1;
};
