#include "movement.h"

// movement functions
DWORD WINAPI p1Movement(void* data)
{
    bool top = false;
    bool bottom = false;
    while (true)
    {
        if (GetKeyState(VK_UP) & 0x8000)
        {
            switch (top)
            {
            case false:
                Sleep(20);
                player1[1] += 0.05f;  // Update the y-coordinate of the top left point
                player1[4] += 0.05f;  // Update the y-coordinate of the top right point
                player1[7] += 0.05f;  // Update the y-coordinate of the bottom right point
                player1[10] += 0.05f; // Update the y-coordinate of the bottom left point
                // printf("UP\n"); // debug print
                bottom = false;
                break;
            case true:
                break;
            }
        }
        if (GetKeyState(VK_DOWN) & 0x8000)
        {
            switch (bottom)
            {
            case false:
                Sleep(20);
                player1[1] -= 0.05f;  // Update the y-coordinate of the top left point
                player1[4] -= 0.05f;  // Update the y-coordinate of the top right point
                player1[7] -= 0.05f;  // Update the y-coordinate of the bottom right point
                player1[10] -= 0.05f; // Update the y-coordinate of the bottom left point
                // printf("DOWN\n"); // debug print
                top = false;
                break;
            case true:
                break;
            }

        }
        /*---------- print debug positions ----------
        printf("Top Left: %f\n", player1[1]);
        printf("Top Right: %f\n", player1[4]);
        printf("Bottom Right: %f\n", player1[7]);
        printf("Bottom Left: %f\n", player1[10]);
        */

        // check if the paddle is at the bottom
        // TODO: this works but there must be a better way to do this
        if (player1[7] <= -1.0f)
        {
            bottom = true;
            player1[1] = -0.50f;
            player1[4] = -0.50f;
            player1[7] = -1.0f;
            player1[10] = -1.0f;
        }

        // check if the paddle is at the top
        // TODO: this works but there must be a better way to do this
        if (player1[1] >= 1.0f)
        {
            top = true;
            player1[1] = 1.0f;
            player1[4] = 1.0f;
            player1[7] = 0.50f;
            player1[10] = 0.50f;
        }
    }
    return 0;
}

DWORD WINAPI p2Movement(void* data)
{
    bool top = false;
    bool bottom = false;
    while (true)
    {
        if (GetKeyState(0x57) & 0x8000)
        {
            switch (top)
            {
            case false:
                Sleep(20);
                player2[1] += 0.05f;  // Update the y-coordinate of the top left point
                player2[4] += 0.05f;  // Update the y-coordinate of the top right point
                player2[7] += 0.05f;  // Update the y-coordinate of the bottom right point
                player2[10] += 0.05f; // Update the y-coordinate of the bottom left point
                // printf("UP\n"); // debug print
                bottom = false;
                break;
            case true:
                break;
            }
        }
        if (GetKeyState(0x53) & 0x8000)
        {
            switch (bottom)
            {
            case false:
                Sleep(20);
                player2[1] -= 0.05f;  // Update the y-coordinate of the top left point
                player2[4] -= 0.05f;  // Update the y-coordinate of the top right point
                player2[7] -= 0.05f;  // Update the y-coordinate of the bottom right point
                player2[10] -= 0.05f; // Update the y-coordinate of the bottom left point
                // printf("DOWN\n"); // debug print
                top = false;
                break;
            case true:
                break;
            }

        }
        /*---------- print debug positions ----------
        printf("Top Left: %f\n", player1[1]);
        printf("Top Right: %f\n", player1[4]);
        printf("Bottom Right: %f\n", player1[7]);
        printf("Bottom Left: %f\n", player1[10]);
        */

        // check if the paddle is at the bottom
        // TODO: this works but there must be a better way to do this
        if (player2[7] <= -1.0f)
        {
            bottom = true;
            player2[1] = -0.50f;
            player2[4] = -0.50f;
            player2[7] = -1.0f;
            player2[10] = -1.0f;
        }

        // check if the paddle is at the top
        // TODO: this works but there must be a better way to do this
        if (player2[1] >= 1.0f)
        {
            top = true;
            player2[1] = 1.0f;
            player2[4] = 1.0f;
            player2[7] = 0.50f;
            player2[10] = 0.50f;
        }
    }
    return 0;
}