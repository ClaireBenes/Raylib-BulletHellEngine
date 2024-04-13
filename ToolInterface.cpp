#include "ToolInterface.h"

#include "raylib.h"
#include "imgui.h"
#include "rlImGui.h"
#include <string>

void ToolInterface::Init()
{
    //Instantiate some Bullet and Attack Pattern
    auto orangeBullet = std::make_shared<BulletData>();
    orangeBullet->mName = "Orange";
    orangeBullet->mColor = ORANGE;
    orangeBullet->mSpeed = 200;
    orangeBullet->mSize = 16;
    orangeBullet->mAngularVelocity = 20.0f;
    mAllBullets.push_back(orangeBullet);

    auto purpleBullet = std::make_shared<BulletData>();
    purpleBullet->mName = "Purple";
    purpleBullet->mColor = PURPLE;
    purpleBullet->mSpeed = 200;
    purpleBullet->mSize = 16;
    purpleBullet->mAngularVelocity = 20.0f;
    mAllBullets.push_back(purpleBullet);

    auto blueBullet = std::make_shared<BulletData>();
    blueBullet->mInnerImage = LoadTexture("resources/gear-bullet-inner.png");
    blueBullet->mOuterImage = LoadTexture("resources/gear-bullet-outer.png");
    blueBullet->mImageName = "Gear Bullet";
    blueBullet->mName = "Blue";
    blueBullet->mColor = BLUE;
    blueBullet->mSpeed = 100;
    blueBullet->mSize = 32;
    blueBullet->mAngularVelocity = 15.0f;
    mAllBullets.push_back(blueBullet);

    AttackPatternData arthurPattern2 {};
    arthurPattern2.bulletData = orangeBullet;
    arthurPattern2.timeBetweenBullet = 0.100f;
    arthurPattern2.bulletCount = 2;
    arthurPattern2.rotationSpeed = 65;
    arthurPattern2.bulletRotationOffset = 0.0f;
    mAllAttackPattern.push_back(arthurPattern2);

    AttackPatternData arthurPattern {};
    arthurPattern.bulletData = purpleBullet;
    arthurPattern.timeBetweenBullet = 0.100f;
    arthurPattern.bulletCount = 2;
    arthurPattern.rotationSpeed = 65;
    arthurPattern.bulletRotationOffset = 90;
    mAllAttackPattern.push_back(arthurPattern);

    AttackPatternData clairePattern {};
    clairePattern.bulletData = blueBullet;
    clairePattern.timeBetweenBullet = 1.5f;
    clairePattern.bulletCount = 8;
    clairePattern.rotationSpeed = 0;
    clairePattern.bulletRotationOffset = 0.0f;
    mAllAttackPattern.push_back(clairePattern);

    //Load Texture
    mBulletSpawner->mTexture = LoadTexture("resources/black-hole.png");

    mBulletInnerTextures = { LoadTexture("resources/simple-bullet-inner.png"), LoadTexture("resources/simple2-bullet-inner.png"),
        LoadTexture("resources/sharp-bullet-inner.png"), LoadTexture("resources/gear-bullet-inner.png") };

    mBulletOuterTextures = { LoadTexture("resources/simple-bullet-outer.png"), LoadTexture("resources/simple2-bullet-outer.png"),
        LoadTexture("resources/sharp-bullet-outer.png"), LoadTexture("resources/gear-bullet-outer.png") };

    mBulletTexturesName = { "Basic Bullet", "Simple Bullet", "Sharp Bullet", "Gear Bullet" };

    UpdateBulletSpawner();

    mBulletRenderTexture = LoadRenderTexture(100, 100);
    UpdateBulletRenderTexture();
}

void ToolInterface::Draw()
{
	rlImGuiBegin();

    mBulletNames.clear();
    for (auto& bullet : mAllBullets)
    {
        mBulletNames.push_back(bullet->mName.c_str());
    }

	BulletEditor();
	AttackPatternEditor();

    //ImGui::ShowDemoWindow();

	rlImGuiEnd();
}


void ToolInterface::BulletEditor()
{
    ImGui::Begin("BulletEditor", NULL, { ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize });
    ImGui::SeparatorText("Creating a bullet");

    //create new bullet
    if (ImGui::Button("New Bullet +"))
    {
        auto newBullet = std::make_shared<BulletData>();
        newBullet->mName = "New Elaine's Bullet";

        mAllBullets.push_back(newBullet);
        mCurrentBulletIndex = mAllBullets.size() - 1;

        UpdateBulletRenderTexture();
    }

    //show all bullet already created
    if (ImGui::Combo("Bullets", &mCurrentBulletIndex, mBulletNames.data(), mBulletNames.size()))
    {
        UpdateBulletRenderTexture();
    }

    auto& bullet = mAllBullets[mCurrentBulletIndex];

    //choose Name
    char newBulletName[64] = "";
    strcpy_s(newBulletName, bullet->mName.c_str());
    if (ImGui::InputTextWithHint("Name", "Choose name of bullet", newBulletName, IM_ARRAYSIZE(newBulletName)))
    {
        bullet->mName = newBulletName;
    }

    if (ImGui::TreeNodeEx("Bullet Data", ImGuiTreeNodeFlags_DefaultOpen))
    {
        //choose color
        float color[4] = {
            bullet->mColor.r / 255.0f,
            bullet->mColor.g / 255.0f,
            bullet->mColor.b / 255.0f,
            bullet->mColor.a / 255.0f
        };
        if (ImGui::ColorEdit4("Color", color))
        {
            bullet->mColor.r = (unsigned char) (color[0] * 255);
            bullet->mColor.g = (unsigned char) (color[1] * 255);
            bullet->mColor.b = (unsigned char) (color[2] * 255);
            bullet->mColor.a = (unsigned char) (color[3] * 255);

            UpdateBulletRenderTexture();
        }

        //choose image
        ImGui::SeparatorText("Bullet Image");
        rlImGuiImageRenderTexture(&mBulletRenderTexture);

        int pos = 0;

        for (int i = 0; i < mBulletTexturesName.size(); i++)
        {
            if (mBulletTexturesName[i] == bullet->mImageName)
            {
                pos = i;
            }
        }

        if (ImGui::Combo("Images", &pos, mBulletTexturesName.data(), mBulletTexturesName.size()))
        {
            bullet->mInnerImage = mBulletInnerTextures[pos];
            bullet->mOuterImage = mBulletOuterTextures[pos];
            bullet->mImageName = mBulletTexturesName[pos];

            UpdateBulletRenderTexture();
        }

        ImGui::SeparatorText("");

        //choose speed
        ImGui::DragFloat("Speed", &bullet->mSpeed, 1.0f, 0.0f, 500.0f);

        //choose size
        ImGui::DragFloat("Size", &bullet->mSize, 1.0f, 5.0f, 64.0f);

        //choose angular velocity
        ImGui::DragFloat("Angular Velocity", &bullet->mAngularVelocity, 1.0f, -90.0f, 90.0f);


        //delete bullet
        static bool isBulletUsed = false;
        static bool isLastBullet = false;

        if (ImGui::Button("Delete Bullet"))
        {
            isBulletUsed = false;
            isLastBullet = false;

            //check if bullet is not used by any attack pattern
            for (int i = 0; i < mAllAttackPattern.size(); i++)
            {
                if (mAllAttackPattern[i].bulletData == bullet)
                {
                    isBulletUsed = true;
                    break;
                }
            }

            //if bullet is not used
            if (!isBulletUsed)
            {
                //if there is more than 1 bullet left
                if (mAllBullets.size() > 1)
                {
                    isLastBullet = false;

                    //check if we want to delete the last bullet or not
                    if (bullet == mAllBullets.back())
                    {
                        mCurrentBulletIndex = 0;
                        //delete last bullet
                        mAllBullets.pop_back();
                        UpdateBulletRenderTexture();
                    }
                    else
                    {
                        //delete current bullet
                        mAllBullets.erase(mAllBullets.begin() + mCurrentBulletIndex);
                        UpdateBulletSpawner();
                        UpdateBulletRenderTexture();
                    }
                }
                else
                {
                    isLastBullet = true;
                }
            }
        }
        //if the bullet is being used --> can't delete
        if (isBulletUsed)
        {
            ImGui::SameLine();
            ImGui::Text("Stop using this bullet so you can delete it.");
        }
        //if only one bullet is left --> can't delete
        else if (isLastBullet)
        {
            ImGui::SameLine();
            ImGui::Text("You need to keep at least one bullet.");
        }

        ImGui::TreePop();
    }

    ImGui::End();
}

void ToolInterface::AttackPatternEditor()
{
    ImGui::Begin("AttackPattern Editor", NULL, { ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize });
    ImGui::SeparatorText("Creating an attack pattern");

    //create new attack pattern
    if (ImGui::Button("New Attack Pattern +"))
    {
        AttackPatternData data {};
        data.bulletData = mAllBullets[mCurrentBulletIndex];

        mAllAttackPattern.push_back(data);
        UpdateBulletSpawner();
    }

    // for every attack pattern
    for (int i = 0; i < mAllAttackPattern.size(); i++)
    {
        AttackPatternData& attackPattern = mAllAttackPattern[i];
        attackPattern.currentAttackPatternIndex = i;

        //create a tree with all datas
        if (ImGui::TreeNodeEx(TextFormat("Attack Pattern %d", i), ImGuiTreeNodeFlags_DefaultOpen))
        {
            int bulletIndex = 0;
            for (int j = 0; j < mAllBullets.size(); j++)
            {
                if (attackPattern.bulletData == mAllBullets[j])
                {
                    bulletIndex = j;
                    break;
                }
            }

            //show all bullet already created
            if (ImGui::Combo("Bullets", &bulletIndex, mBulletNames.data(), mBulletNames.size()))
            {
                attackPattern.bulletData = mAllBullets[bulletIndex];
                UpdateBulletSpawner();
            }

            //choose bullet count
            if (ImGui::InputInt("Bullet Count", &attackPattern.bulletCount))
            {
                UpdateBulletSpawner();
            }

            //choose time between bullet
            if (ImGui::DragFloat("Fire Rate", &attackPattern.timeBetweenBullet, 0.005f, 0.0f, 5.0f))
            {
                UpdateBulletSpawner();
            }

            //choose rotation speed
            if (ImGui::DragFloat("Rotation Speed", &attackPattern.rotationSpeed, 1.0f, -360.0f, 360.0f))
            {
                UpdateBulletSpawner();
            }

            //choose time between bullet
            if (ImGui::DragFloat("Rotation Offset", &attackPattern.bulletRotationOffset, 1.0f , 0.0f, 360.0f))
            {
                UpdateBulletSpawner();
            }

            //delete attack pattern
            if (ImGui::Button("Delete Attack Pattern"))
            {
                mAllAttackPattern.erase(mAllAttackPattern.begin() + attackPattern.currentAttackPatternIndex);
                UpdateBulletSpawner();
            }

            ImGui::TreePop();
        }
    }

    ImGui::End();
}

void ToolInterface::SetBulletSpawner(std::shared_ptr<BulletSpawner> bulletSpawner)
{
    mBulletSpawner = bulletSpawner;
}

void ToolInterface::UpdateBulletSpawner()
{
    printf("Update of bullet spawner \n");

    mBulletSpawner->ClearAttackPatterns();

    for (int pattern = 0; pattern < mAllAttackPattern.size(); pattern++)
    {
        mBulletSpawner->AddAttackPattern(mAllAttackPattern[pattern]);
    }
}

void ToolInterface::UpdateBulletRenderTexture()
{
    const auto& bullet = mAllBullets[mCurrentBulletIndex];

    BeginTextureMode(mBulletRenderTexture);
    ClearBackground({29, 47, 73, 255});

    DrawTextureEx(bullet->mInnerImage, { 0, 0 }, 0, mBulletRenderTexture.texture.width / bullet->mInnerImage.width, WHITE);
    DrawTextureEx(bullet->mOuterImage, { 0, 0 }, 0, mBulletRenderTexture.texture.width / bullet->mOuterImage.width, bullet->mColor);

    EndTextureMode();
}
