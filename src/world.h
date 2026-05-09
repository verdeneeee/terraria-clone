#pragma once
#include "../raylib/include/raylib.h"
#include <vector>

struct World
{
	World();

	std::vector<Vector2> placedBlocks;
	float cellSize = 20.0f;

	void drawWorld();
	void generateTerrain(int width, int height);
	void placeBlock(Vector2 &mousePos);
	void destroyBlock(Vector2& mousePos);
	void update(Vector2& mousePos);
};