#include "ToolInterface.h"

#include "raylib.h"
#include "imgui.h"
#include "rlImGui.h"

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
        mAttackpatternNumber++;
    }


    for (int i = 0; i < mAttackpatternNumber; i++)
    {
        if (ImGui::TreeNodeEx(TextFormat("Attack Pattern %d", i), ImGuiTreeNodeFlags_DefaultOpen))
        {
            //show all bullet already created
            const char* items[] = { "Orange", "Purple", "Blue" };
            static int everyBullet[100];
            ImGui::Combo("Bullets", &everyBullet[i], items, IM_ARRAYSIZE(items));

            //choose bullet count
            static int bulletCount[100];
            ImGui::InputInt("Bullet Count", &bulletCount[i]);

            //choose time between bullet
            static float fireRate[100] = { 0.5f };
            ImGui::SliderFloat("Fire Rate", &fireRate[i], 0.0f, 20.0f);

            //choose rotation speed
            static float dragRotSpeed[100] = { 6.0f };
            ImGui::DragFloat("Rotation Speed", &dragRotSpeed[i], 0.05f, 0.0f, 20.0f);

            //90 * (PI / 180.0f)
            //choose time between bullet
            static float rotateOffset[100] = { 0.0f };
            ImGui::SliderFloat("Rotation Offset", &rotateOffset[i], 0.0f, 360.0f);

            ImGui::TreePop();
        }
    }

    ImGui::End();
}
