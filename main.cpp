#include "raylib/include/raylib.h"
#include "src/player.h"
#include "src/world.h"

int main()
{
    InitWindow(1800, 900, "hello world");
    SetTargetFPS(60);

    Player player({ GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f });
    World world;

    Camera2D cam = { 0 };
    cam.target = { player.position.x, player.position.y - 30.0f};
    cam.offset = { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f };
    cam.rotation = 0.0f;
    cam.zoom = 1.0f;


    while (!WindowShouldClose())
    {
        float deltaTime = GetFrameTime();
        Vector2 mousePos = GetMousePosition();
        Vector2 worldMousePos = GetScreenToWorld2D(mousePos, cam);

        cam.target = { player.position.x, player.position.y - 30.0f };

        BeginDrawing();
            ClearBackground(SKYBLUE);
                BeginMode2D(cam);

                player.update(deltaTime);
                world.update(worldMousePos);

            EndMode2D();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}