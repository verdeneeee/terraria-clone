#pragma once
#include "../raylib/include/raylib.h"
#include <vector>
#include "entity.h"

struct World
{
	World();

	std::vector<Vector2> placedBlocks;
	float cellisze = 20.0f;

	void drawWorld();
	void generateTerrain(int width, int height);
	void placeBlock(Vector2& mousePos, Camera2D cam);
	void destroyBlock(Vector2& mousePos, Camera2D cam);
	void update(Vector2& mousePos, Camera2D cam);
};