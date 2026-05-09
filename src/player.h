#pragma once
#include "../raylib/include/raylib.h"
#include "world.h"

struct Player
{
	float gravity = 256.0f;
	float jumpForce = 80.0f;
	float maxSpeed = 50.0f;
	bool isGrounded = false;

	float groundLevel = GetScreenHeight() - 90.0f;

	float playerHeight = 40.0f;
	float playerWidth = 20.0f;

	Vector2 velocity = { 0, 0 };
	Vector2 position = { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f };

	Player(Vector2 startPos);

	void jump(float& deltaTime);
	void move(float& deltaTime);
	void update(float& deltaTime, World& world);
};