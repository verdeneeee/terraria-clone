#pragma once
#include "../raylib/include/raylib.h"

using EntityID = int64_t;

struct entity
{




	

	
	
	
	std::vector<Vector2> placedBlocks;

	//Rectangle playerRect = { position.x, position.y, 20, 40 };

};

struct Position
{
	Vector2 position /* { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f }*/;
};

struct Velocity
{
	Vector2 velocity;
};

struct PlayerSize
{
	const float playerHeight;
	const float playerWidth;
};

struct BlockRectangle
{
	Rectangle blockRect;
};

struct Gravity
{
	const float gravity/* = 256.0f*/;
};

struct MaxSpeed
{
	const float maxSpeedX /*= 150.0f*/;
	const float maxSpeedY /*= -150.0f*/;
};

struct JumpForce
{
	const float jumpForce /*= 130.0f*/;
};

struct IsGrounded
{
	bool isGrounded /*= false*/;
};

struct Cellsize
{
	const float cellSize /*= 20.0f*/;
};

struct GroundLevel
{
	float groundLevel /*= GetScreenHeight() - 90.0f*/;
};

template <typename Type>
using ComponentMap = std::unordered_map<EntityID, Type>;

using Positions = ComponentMap<Position>;
using Velocities = ComponentMap<Velocity>;
using PlayerSizes = ComponentMap<PlayerSize>;
using blockRectangle = ComponentMap<BlockRectangle>;
using gravity = ComponentMap<Gravity>;
using MaxSpeeds = ComponentMap<MaxSpeed>;
using jumpForce = ComponentMap<JumpForce>;
using isGrounded = ComponentMap<isGrounded>;
using CellSize = ComponentMap<Cellsize>;
using groundLevel = ComponentMap<GroundLevel>;

struct Components
{
	Positions positions;
	Velocities velocities;
	PlayerSizes playersizes;
	blockRectangle BlockRect;
	gravity Gravity;
	MaxSpeeds maxSpeeds;
	jumpForce jumpforce;
	isGrounded IsGrounded;
	CellSize cellSize;
	groundLevel GroundLevel;
};
