#include "player.h"
#include "../raylib/include/raylib.h"

Player::Player(Vector2 startPos) {}

void Player::jump(float& deltaTime)
{
	if (IsKeyDown(KEY_SPACE) && isGrounded)
	{
		isGrounded = 0;
		velocity.y = -jumpForce;
	}

	if (!isGrounded) velocity.y += gravity * deltaTime;
}

void Player::move(float& deltaTime)
{
	velocity.x = 0;

	if (IsKeyDown(KEY_D)) velocity.x = maxSpeed;
	if (IsKeyDown(KEY_A)) velocity.x = -maxSpeed;

	position.x += velocity.x * deltaTime;
}

void Player::update(float& deltaTime, World& world)
{
	move(deltaTime);
	playerRect = { position.x, position.y, 20, 40 };

	for (Vector2 block : world.placedBlocks)
	{
		Rectangle blockRect = { block.x, block.y + 30, world.cellSize, world.cellSize };

		if (CheckCollisionRecs(playerRect, blockRect))
		{
			if (velocity.x > 0) position.x = blockRect.x - playerRect.width;
			else if (velocity.x < 0) position.x = blockRect.x + blockRect.width;
		}
	}

	jump(deltaTime);
	position.y += velocity.y * deltaTime;
	isGrounded = false;

	playerRect = { position.x, position.y, 20, 40 };

	for (Vector2 block : world.placedBlocks)
	{
		Rectangle blockRect = { block.x, block.y + 30, world.cellSize, world.cellSize };

		if (CheckCollisionRecs(playerRect, blockRect))
		{
			if (velocity.y > 0)
			{
				isGrounded = true;
				position.y = blockRect.y - playerRect.height;
				velocity.y = 0;
			}
			else if (velocity.y < 0)
			{
				position.y = blockRect.y + blockRect.height;
			}
		}
	}
	DrawRectangle(position.x, position.y, 20, 40, WHITE);
}