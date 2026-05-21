#include "raylib/include/raylib.h"
//#include "src/player.h"
#include "src/world.h"
#include "src/entity.h"

void updatePlayer(EntityID id, Components& c, World& world, float deltaTime); //как оно работает

int main()
{
    InitWindow(800, 450, "hello world");
    SetTargetFPS(60);

    EntityID playerID = 1;
    Components c;

    c.positions[playerID] = { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f };
    c.velocities[playerID] = { 0,0 };
    c.playerSizes[playerID] = { 20.0f, 40.0f };
    c.gravities[playerID] = { 256.0f };
    c.jumpForces[playerID] = { 130.0f };
    c.maxSpeeds[playerID] = { 150.0f };
    c.isGroundeds[playerID] = { false };


    World world{};

    Camera2D cam = { 0 };
    cam.target = { c.positions[playerID].position.x, c.positions[playerID].position.y - 30.0f};
    cam.offset = { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f };
    cam.rotation = 0.0f;
    cam.zoom = 1.0f;


    while (!WindowShouldClose())
    {
        float deltaTime = GetFrameTime();
        Vector2 mousePos = GetMousePosition();

        cam.target = { c.positions[playerID].position.x, c.positions[playerID].position.y - 30.0f };

        BeginDrawing();
            ClearBackground(SKYBLUE);
            DrawFPS(10, 10);
                BeginMode2D(cam);
                 
                updatePlayer(playerID, c, world, deltaTime);
                world.update(mousePos, cam);

            EndMode2D();
        EndDrawing();
     }

    CloseWindow();

    return 0;
}