#include "../raylib/include/raylib.h"
#include "entity.h"
#include "world.h"
#include "player.h"	

/**
struct Enemy {
    List<Component> components;
 
    components.add(Position);
    components.add(Gravity);
 
    for (Component c : this.components) {
       ....
    }

    for (Enemy e : enemies) {
        (e.component.get()).attack();
    }
}
 
*/

void updatePlayer(EntityID id, Components& c, World& world, float deltaTime)
{
    auto& position = c.positions[id].position;
    auto& velocity = c.velocities[id].velocity;
    auto& gravity = c.gravities[id].gravity;
    auto& IsGrounded = c.isGroundeds[id].isGrounded;
    auto& size = c.playerSizes[id];
    auto& maxSpeed = c.maxSpeeds[id].speed;
    auto& jumpForce = c.jumpForces[id].force;

    velocity.x = 0;

    if (IsKeyDown(KEY_D)) velocity.x = maxSpeed;
    if (IsKeyDown(KEY_A)) velocity.x = -maxSpeed;

    position.x += velocity.x * deltaTime;

    Rectangle playerRect = { position.x, position.y, size.width, size.height};

    for (Vector2 block : world.placedBlocks)
    {
        Rectangle blockRect = { block.x, block.y + 30, world.cellisze, world.cellisze };

        if (CheckCollisionRecs(playerRect, blockRect))
        {
            if (velocity.x > 0) position.x = blockRect.x - playerRect.width;
            else if (velocity.x < 0) position.x = blockRect.x + blockRect.width;
        }
    }

    if (IsKeyDown(KEY_SPACE) && IsGrounded) velocity.y = -jumpForce;

    position.y += velocity.y * deltaTime;
    if (!IsGrounded) velocity.y += gravity * deltaTime;

    IsGrounded = false;

    playerRect = { position.x, position.y, size.width, size.height };

    for (Vector2 block : world.placedBlocks)
    {
        Rectangle blockRect = { block.x, block.y + 30.0f, world.cellisze, world.cellisze };

        if (CheckCollisionRecs(playerRect, blockRect))
        {
            if (velocity.y > 0)
            {
                IsGrounded = true;
                position.y = blockRect.y - playerRect.height;
                velocity.y = 0;
            }
            else if (velocity.y < 0)
            {
                position.y = blockRect.y + blockRect.height;
                velocity.y = 0;
            }
        }
    }

    DrawRectangle(position.x, position.y, size.width, size.height, WHITE);
}