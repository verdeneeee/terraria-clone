#pragma once
#include "../raylib/include/raylib.h"
#include "world.h"
#include "entity.h"

struct Player
{
	static void updatePlayer(EntityID id, Components & c, World & world, float deltaTime);
};