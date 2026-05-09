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

	if (!isGrounded)
	{
		if (position.y >= (GetScreenHeight() / 2))
		{
			position.y = GetScreenHeight() / 2;
			isGrounded = true;
		}

		velocity.y += gravity * deltaTime;
		position.y += velocity.y * deltaTime;
	}
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
	jump(deltaTime);
	move(deltaTime);
	DrawRectangle(position.x, position.y, 20, 40, WHITE);
}