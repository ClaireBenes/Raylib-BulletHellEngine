#include "ToolInterface.h"

#include "raylib.h"
#include "imgui.h"
#include "rlImGui.h"

void ToolInterface::Update()
{

}

void ToolInterface::Draw()
{
	rlImGuiBegin();

	BulletEditor();
	AttackPatternEditor();

	rlImGuiEnd();
}

void ToolInterface::BulletEditor()
{
    ImGui::Begin("BulletEditor", NULL, ImGuiWindowFlags_NoMove);
    ImGui::SeparatorText("Creating a bullet");

    //create new bullet
    ImGui::Button("New Bullet +");

    //show all bullet already created
    const char* items[] = { "Orange", "Purple", "Blue" };
    static int item_current = 0;
    ImGui::Combo("Bullets", &item_current, items, IM_ARRAYSIZE(items));

    //choose Name
    static char str0[128] = "";
    ImGui::InputTextWithHint("Name", "Choose name of bullet", str0, IM_ARRAYSIZE(str0));

    if (ImGui::TreeNodeEx("Bullet data", ImGuiTreeNodeFlags_DefaultOpen))
    {
        //choose color
        static float color[3] = { 1.0f, 0.0f, 0.0f };
        ImGui::ColorEdit3("Color", color);

        //choose image

        //choose speed
        static float sliderSpeed = 100.0f;
        ImGui::SliderFloat("Speed", &sliderSpeed, 0.0f, 500.0f);

        //choose size
        static float sliderSize = 10.0f;
        ImGui::SliderFloat("Size", &sliderSize, 5.0f, 50.0f);

        //choose angular velocity
        static float dragVelocity = 0.5f;
        ImGui::DragFloat("Angular Velocity", &dragVelocity, 0.005f, 0.0f, 1.0f);

        ImGui::TreePop();
    }

    ImGui::End();
}

void ToolInterface::AttackPatternEditor()
{
    ImGui::Begin("AttackPattern Editor", NULL, ImGuiWindowFlags_NoMove);
    ImGui::SeparatorText("Creating an attack pattern");

    //create new attack pattern
    if (ImGui::Button("New Attack Pattern +"))
    {
        BulletData orangeBullet {};
        orangeBullet.mColor = ORANGE;
        orangeBullet.mSpeed = 200;
        orangeBullet.mSize = 10;
        orangeBullet.mAngularVelocity = 0.5f;

        AttackPatternData data {};
        data.bulletData = orangeBullet;

        mAllAttackPattern.push_back(data);
        UpdateBulletSpawner();
    }


    for (int i = 0; i < mAllAttackPattern.size(); i++)
    {
        AttackPatternData& attackPattern = mAllAttackPattern[i];

        if (ImGui::TreeNodeEx(TextFormat("Attack Pattern %d", i), ImGuiTreeNodeFlags_DefaultOpen))
        {
            //show all bullet already created
            const char* items[] = { "Orange", "Purple", "Blue" };
            static int everyBullet[100];
            if (ImGui::Combo("Bullets", &everyBullet[i], items, IM_ARRAYSIZE(items)))
            {
                UpdateBulletSpawner();
            }

            //choose bullet count
            //static int bulletCount[100];
            if (ImGui::InputInt("Bullet Count", &attackPattern.bulletCount))
            {
                UpdateBulletSpawner();
            }

            //choose time between bullet
            //static float fireRate[100] = { 0.5f };
            if (ImGui::DragFloat("Fire Rate", &attackPattern.timeBetweenBullet, 0.005f, 0.0f, 5.0f))
            {
                UpdateBulletSpawner();
            }

            //choose rotation speed
            //static float dragRotSpeed[100] = { 6.0f };
            if (ImGui::DragFloat("Rotation Speed", &attackPattern.rotationSpeed, 1.0f, -360.0f, 360.0f))
            {
                UpdateBulletSpawner();
            }

            //choose time between bullet
            //static float rotateOffset[100] = { 0.0f };
            if (ImGui::DragFloat("Rotation Offset", &attackPattern.bulletRotationOffset, 1.0f , 0.0f, 360.0f))
            {
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
