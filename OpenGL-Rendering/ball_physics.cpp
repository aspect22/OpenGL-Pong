#include "ball.h"

DWORD WINAPI ballMovement(void* data)
{
	bool up = false;
	bool right = true;
	Sleep(3000);
	while (true)
	{
		// Check if ball is at the top of the screen
		if (ball[1] <= 0.0f)
		{
			up = false;
			Sleep(20);
		}

		// Check if ball is at the bottom of the screen
		if (ball[10] >= 0.95f)
		{
			up = true;
			Sleep(20);
		}

		// Collision detection
		/* This is the old collision detection code used in SFML
		if (ball.getGlobalBounds().intersects(line.getGlobalBounds()))
		{
			right = true;
			ball.setPosition(ball.getPosition().x + velocity, ball.getPosition().y);
			velocity += random() % 2;
			movement += 1;
		}

		if (ball.getGlobalBounds().intersects(line2.getGlobalBounds()))
		{
			right = false;
			ball.setPosition(ball.getPosition().x - velocity, ball.getPosition().y);
			velocity += random() % -2;
			movement += 1;
		}
		*/
		// Collision detection with player 1
		if (ball[1] <= player1[7] && ball[1] >= player1[10])
		{
			right = true;
			Sleep(20);
		}
		if (ball[4] <= player1[7] && ball[4] >= player1[10])
		{
			right = true;
			Sleep(20);
		}

		// Collision detection with player 2
		if (ball[1] <= player2[7] && ball[1] >= player2[10])
		{
			right = false;
			Sleep(20);
		}
		if (ball[4] <= player2[7] && ball[4] >= player2[10])
		{
			right = false;
			Sleep(20);
		}

		switch (right)
		{
		case true:
			// Ball is moving right by velocity speed
			ball[1] += 0.05f;  // Update the y-coordinate of the top left point
			ball[4] += 0.05f;  // Update the y-coordinate of the top right point
			ball[7] += 0.05f;  // Update the y-coordinate of the bottom right point
			ball[10] += 0.05f; // Update the y-coordinate of the bottom left point
			break;
		case false:
			// Ball is moving left by velocity speed
			ball[1] -= 0.05f;  // Update the y-coordinate of the top left point
			ball[4] -= 0.05f;  // Update the y-coordinate of the top right point
			ball[7] -= 0.05f;  // Update the y-coordinate of the bottom right point
			ball[10] -= 0.05f; // Update the y-coordinate of the bottom left point
			break;
		}
		switch (up)
		{
		case true:
			// Ball is moving up by velocity speed
			break;
		case false:
			// Ball is moving down by velocity speed
			break;
		}
		Sleep(10);

	}
	return 0;
}