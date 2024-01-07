#include "handler.h"

void reset_Ball()
{
    ball[0] = -0.03f;
    ball[1] = 0.0f;
    ball[2] = 0.0f;

    ball[3] = 0.0f;
    ball[4] = 0.0f;
    ball[5] = 0.0f;

    ball[6] = 0.0f;
    ball[7] = -0.05f;
    ball[8] = 0.0f;

    ball[9] = -0.03f;
    ball[10] = -0.05f;
    ball[11] = 0.0f;
}

bool generateRandomBool() {
    // Seed the random number generator with the current time
    std::random_device rd;
    std::mt19937 gen(rd());

    // Create a distribution that produces true or false with equal probability
    std::uniform_int_distribution<> dis(0, 1);

    // Generate a random boolean value
    return dis(gen) == 1;
}

DWORD WINAPI game_Handler(void* data)
{
    while (true)
    {
        // this checks if the ball is hitting the left side of the screen
        if (ball[0] <= -1.00f && ball[9] <= -1.00f)
        {
            printf("Player 1 wins!\n");
            velocity = 0.00f;
            reset_Ball();
            up = generateRandomBool();
            right = generateRandomBool();
            printf("ball reset\n");
            Sleep(2000);
            velocity = 0.01f;
        }
        // this checks if the ball is hitting the right side of the screen
        if (ball[3] >= 1.00f && ball[6] >= 1.00f)
        {
            printf("Player 2 wins!\n");
            velocity = 0.00f;
            reset_Ball();
            up = generateRandomBool();
            right = generateRandomBool();
            printf("ball reset\n");
            Sleep(2000);
            velocity = 0.01f;
        }
    }
}