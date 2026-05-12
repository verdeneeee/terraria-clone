#include "raylib/include/raylib.h"
#include "src/player.h"
#include "src/world.h"

int main()
{
    InitWindow(800, 450, "hello world");
    SetTargetFPS(60);

    Player player({ GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f });
    World world{};

    Camera2D cam = { 0 };
    cam.target = { player.position.x, player.position.y - 30.0f};
    cam.offset = { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f };
    cam.rotation = 0.0f;
    cam.zoom = 1.0f;


    while (!WindowShouldClose())
    {
        float deltaTime = GetFrameTime();
        Vector2 mousePos = GetMousePosition();

        cam.target = { player.position.x, player.position.y - 30.0f };

        BeginDrawing();
            ClearBackground(SKYBLUE);
            DrawFPS(10, 10);
                BeginMode2D(cam);


                player.update(deltaTime, world);
                world.update(mousePos, cam);

            EndMode2D();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}