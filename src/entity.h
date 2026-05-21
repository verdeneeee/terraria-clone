#pragma once
#include <vector>
#include <unordered_map>
#include <cstdint>
#include "../raylib/include/raylib.h"

using EntityID = int64_t;

struct WorldData
{
    std::vector<Vector2> placedBlocks;
    float cellSize = 20.0f;
};

struct Position { Vector2 position; };
struct Velocity { Vector2 velocity; };
struct PlayerSize { float width; float height; };
struct Gravity { float gravity = 256.0f; };
struct MaxSpeed { float speed = 150.0f; };
struct JumpForce { float force = 130.0f; };
struct IsGrounded { bool isGrounded = false; };

template <typename Type>
using ComponentMap = std::unordered_map<EntityID, Type>;

struct Components
{
    ComponentMap<Position> positions;
    ComponentMap<Velocity> velocities;
    ComponentMap<PlayerSize> playerSizes;
    ComponentMap<Gravity> gravities;
    ComponentMap<MaxSpeed> maxSpeeds;
    ComponentMap<JumpForce> jumpForces;
    ComponentMap<IsGrounded> isGroundeds;
};
