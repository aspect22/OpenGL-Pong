#include "ball.h"
bool up = true;
bool right = true;
float velocity = 0.01f;

DWORD WINAPI ballMovement(void* data)
{
	Sleep(3000);
	while (true)
	{
		if(right){
			// Ball is moving right by velocity speed
			// Ball Cords = [0] = x, [1] = y, [2] = z
			ball[0] += velocity;  // Update the y-coordinate of the top left point
			ball[3] += velocity;  // Update the y-coordinate of the top right point
			ball[6] += velocity;  // Update the y-coordinate of the bottom right point
			ball[9] += velocity; // Update the y-coordinate of the bottom left point
		}
		else {
			// Ball is moving left by velocity speed
			ball[0] -= velocity;  // Update the y-coordinate of the top left point
			ball[3] -= velocity;  // Update the y-coordinate of the top right point
			ball[6] -= velocity;  // Update the y-coordinate of the bottom right point
			ball[9] -= velocity; // Update the y-coordinate of the bottom left point
		}
		if(up)
		{
			// Ball is moving up by velocity speed
			ball[1] += velocity;  // Update the y-coordinate of the top left point
			ball[4] += velocity;  // Update the y-coordinate of the top right point
			ball[7] += velocity;  // Update the y-coordinate of the bottom right point
			ball[10] += velocity; // Update the y-coordinate of the bottom left point
		}
		else {
			// Ball is moving down by velocity speed
			ball[1] -= velocity;  // Update the y-coordinate of the top left point
			ball[4] -= velocity;  // Update the y-coordinate of the top right point
			ball[7] -= velocity;  // Update the y-coordinate of the bottom right point
			ball[10] -= velocity; // Update the y-coordinate of the bottom left point
		}


		// Collision detection with player 1 
		//if (ball[1] <=player1[4] && ball[10] >=player1[7] && ball[1] >= player1[3])
		if (ball[10] >= player1[7] && ball[1] <= player1[4] && ball[0] <= player1[3])
		{
			right = true;
			velocity += 0.001f;
		}

		// Collision detection with player 2
		if (ball[4] <= player2[1] && ball[7] >= player2[10] && ball[3] >= player2[0])
			//if (ball[1] <= player2[3] && ball[3] >= player2[1] && ball[0] >= player2[2] && ball[2] <= player2[0])
		{
			right = false;
			velocity += 0.001f;
		}

		// Check if ball is at the top of the screen
		if (ball[4] >= 1.00f)
		{
			up = false;
		}

		// Check if ball is at the bottom of the screen
		if (ball[7] <= -1.00f)
		{
			up = true;
		}

		Sleep(20);

	}
	return 0;
}