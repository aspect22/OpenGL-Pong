#include "debug.h"

// debug functions

DWORD WINAPI debug(void* data) {
    while (true) {
        if (GetAsyncKeyState(VK_F1) & 1) {
            debugtoggle = !debugtoggle;
            if (debugtoggle)
                printf("Debug mode enabled\n");
            else
                printf("Debug mode disabled\n");
        }

        switch (debugtoggle) {
        case true:
            //Print player1 coordinates every 200ms
            printf("Player1 Top Left: %f\n", player1[1]);
            printf("Player1 Top Right: %f\n", player1[4]);
            printf("Player1 Bottom Right: %f\n", player1[7]);
            printf("Player1 Bottom Left: %f\n", player1[10]);
            //Print player2 coordinates every 200ms
            printf("Player2 Top Left: %f\n", player2[1]);
            printf("Player2 Top Right: %f\n", player2[4]);
            printf("Player2 Bottom Right: %f\n", player2[7]);
            printf("Player2 Bottom Left: %f\n", player2[10]);
            //Print ball coordinates every 200ms
            printf("Ball Top Left: %f\n", ball[1]);
            printf("Ball Top Right: %f\n", ball[4]);
            printf("Ball Bottom Right: %f\n", ball[7]);
            printf("Ball Bottom Left: %f\n", ball[10]);
            Sleep(200);
            // Clear Console
            system("cls");
            break;
        case false:
            break;
        }
    }
    return 0;
}