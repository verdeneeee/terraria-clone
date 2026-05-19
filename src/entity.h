#pragma once
#include "../raylib/include/raylib.h"

using EntityID = int64_t;

struct entity
{
	
	
	

	//Rectangle playerRect = { position.x, position.y, 20, 40 };

};

struct Position
{
	Vector2 position = { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f };
};

struct Velocity
{
	Vector2 velocity = { 0, 0 };
};

struct PlayerSize
{
	const float playerHeight = 40.0f;
	const float playerWidth = 20.0f;
};

struct BlockRectangle
{
	Rectangle blockRect = { 0 };
};

struct Gravity
{
	const float gravity = 256.0f;
};

struct MaxSpeed
{
	const float maxSpeed = 150.0f;
};

struct JumpForce
{
	const float jumpForce = 130.0f;
};

struct IsGrounded
{
	bool isGrounded = false;
};

struct Cellsize
{
	const float cellSize = 20.0f;
};

struct GroundLevel
{

};