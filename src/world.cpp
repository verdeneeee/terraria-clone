#include "../raylib/include/raylib.h"
#include "world.h"
#include "PerlinNoise.hpp"

World::World() { generateTerrain(500, 200); }

void World::drawWorld()
{
	for (Vector2 blockPos : placedBlocks) 
	{
		DrawRectangle(blockPos.x, blockPos.y + 30, cellSize, cellSize, GREEN);
	}
}


void World::generateTerrain(int width, int height)
{
	const siv::PerlinNoise::seed_type seed = 123456u;
	const siv::PerlinNoise perlin{ seed };

	for (int y = 0; y < height; ++y) 
	{
		for (int x = 0; x < width; ++x) 
		{
			const double noise = perlin.octave2D_01((x * 0.01), (y * 0.01), 4);

			if (noise > 0.5)
			{
				float gridX = x * cellSize;
				float gridY = y * cellSize;

				placedBlocks.push_back({ gridX, gridY + 30});
			}
		}
	}
}


void World::placeBlock(Vector2& mousePos, Camera2D cam)
{
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		float gridX = (int)(GetScreenToWorld2D(mousePos, cam).x / cellSize) * cellSize;
		float gridY = (int)(GetScreenToWorld2D(mousePos, cam).y / cellSize) * cellSize;

		placedBlocks.push_back({ gridX, gridY - 30.0f });
	}
}

void World::destroyBlock(Vector2& mousePos, Camera2D cam)
{
	if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON))
	{
		for (int i = 0; i < placedBlocks.size(); i++)
		{
			if (CheckCollisionPointRec(GetScreenToWorld2D(mousePos, cam), { placedBlocks[i].x, placedBlocks[i].y + 30, cellSize, cellSize }))
			{
				placedBlocks.erase(placedBlocks.begin() + i);
				break;
			}
		}
	}
}

void World::update(Vector2& mousePos, Camera2D cam)
{
	drawWorld();
	placeBlock(mousePos, cam);
	destroyBlock(mousePos, cam);
}