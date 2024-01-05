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
                points[1] += 0.05f;  // Update the y-coordinate of the top left point
                points[4] += 0.05f;  // Update the y-coordinate of the top right point
                points[7] += 0.05f;  // Update the y-coordinate of the bottom right point
                points[10] += 0.05f; // Update the y-coordinate of the bottom left point
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
                points[1] -= 0.05f;  // Update the y-coordinate of the top left point
                points[4] -= 0.05f;  // Update the y-coordinate of the top right point
                points[7] -= 0.05f;  // Update the y-coordinate of the bottom right point
                points[10] -= 0.05f; // Update the y-coordinate of the bottom left point
                // printf("DOWN\n"); // debug print
                top = false;
                break;
            case true:
                break;
            }

        }
        /*---------- print debug positions ----------
        printf("Top Left: %f\n", points[1]);
        printf("Top Right: %f\n", points[4]);
        printf("Bottom Right: %f\n", points[7]);
        printf("Bottom Left: %f\n", points[10]);
        */

        // check if the paddle is at the bottom
        // TODO: this works but there must be a better way to do this
        if (points[7] <= -1.0f)
        {
            bottom = true;
            points[1] = -0.50f;
            points[4] = -0.50f;
            points[7] = -1.0f;
            points[10] = -1.0f;
        }

        // check if the paddle is at the top
        // TODO: this works but there must be a better way to do this
        if (points[1] >= 1.0f)
        {
            top = true;
            points[1] = 1.0f;
            points[4] = 1.0f;
            points[7] = 0.50f;
            points[10] = 0.50f;
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
                points2[1] += 0.05f;  // Update the y-coordinate of the top left point
                points2[4] += 0.05f;  // Update the y-coordinate of the top right point
                points2[7] += 0.05f;  // Update the y-coordinate of the bottom right point
                points2[10] += 0.05f; // Update the y-coordinate of the bottom left point
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
                points2[1] -= 0.05f;  // Update the y-coordinate of the top left point
                points2[4] -= 0.05f;  // Update the y-coordinate of the top right point
                points2[7] -= 0.05f;  // Update the y-coordinate of the bottom right point
                points2[10] -= 0.05f; // Update the y-coordinate of the bottom left point
                // printf("DOWN\n"); // debug print
                top = false;
                break;
            case true:
                break;
            }

        }
        /*---------- print debug positions ----------
        printf("Top Left: %f\n", points[1]);
        printf("Top Right: %f\n", points[4]);
        printf("Bottom Right: %f\n", points[7]);
        printf("Bottom Left: %f\n", points[10]);
        */

        // check if the paddle is at the bottom
        // TODO: this works but there must be a better way to do this
        if (points2[7] <= -1.0f)
        {
            bottom = true;
            points2[1] = -0.50f;
            points2[4] = -0.50f;
            points2[7] = -1.0f;
            points2[10] = -1.0f;
        }

        // check if the paddle is at the top
        // TODO: this works but there must be a better way to do this
        if (points2[1] >= 1.0f)
        {
            top = true;
            points2[1] = 1.0f;
            points2[4] = 1.0f;
            points2[7] = 0.50f;
            points2[10] = 0.50f;
        }
    }
    return 0;
}