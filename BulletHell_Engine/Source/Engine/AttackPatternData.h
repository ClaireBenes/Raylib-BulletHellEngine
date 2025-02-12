#pragma once
#include <memory>

#include "Engine/Bullet/BulletData.h"

class AttackPatternData
{
public:
    std::shared_ptr<BulletData> bulletData;
    int currentAttackPatternIndex = 0;
    float timeBetweenBullet = 1;
    float rotationSpeed = 1;
    float bulletRotationOffset = 0;
    int bulletCount = 1;
};
