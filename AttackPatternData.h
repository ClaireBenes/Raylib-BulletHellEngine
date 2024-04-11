#pragma once
#include <memory>

#include "BulletData.h"

class AttackPatternData
{
public:
    std::shared_ptr<BulletData> bulletData;
    float timeBetweenBullet = 1;
    float rotationSpeed = 1;
    float bulletRotationOffset = 0;
    int bulletCount = 1;
};
