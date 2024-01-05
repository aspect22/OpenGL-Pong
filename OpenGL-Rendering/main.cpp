#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <windows.h>
#include "shaders.h"
GLuint shader_programme;
GLuint shader_programme_pink;
GLuint vao;

// Items to draw
float points[] = {
    // x     y     z
    // x cordinate is how far left or right
    // y cordinate is how far up or down
    // z cordinate is how far forward or back
   -0.95f,  0.25f,  0.0f, // top left
   -0.90f,  0.25f,  0.0f, // top right
   -0.90f, -0.25f,  0.0f, // bottom right
   -0.95f, -0.25f,  0.0f  // bottom left
};

float points2[] = {
    // x     y     z
    // x cordinate is how far left or right
    // y cordinate is how far up or down
    // z cordinate is how far forward or back
    0.95f,  0.25f,  0.0f, // top left
    0.90f,  0.25f,  0.0f, // top right
    0.90f, -0.25f,  0.0f, // bottom right
    0.95f, -0.25f,  0.0f  // bottom left
};

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


// shader compiler
void compile_Shaders()
{
    printf("Compiling shaders...\n");
    // create buffer
    GLuint vbo = 0;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    // create vertex array object
    vao = 0;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

    // Create purple shader
    GLuint vs = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vs, 1, &vertex_shader, NULL);
    glCompileShader(vs);

    GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fs, 1, &color1, NULL);
    glCompileShader(fs);
    shader_programme = glCreateProgram();
    glAttachShader(shader_programme, fs);
    glAttachShader(shader_programme, vs);
    glLinkProgram(shader_programme);

    // Create pink shader
    GLuint vs_pink = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vs_pink, 1, &vertex_shader, NULL);
    glCompileShader(vs_pink);
    GLuint fs_pink = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fs_pink, 1, &color2, NULL);
    glCompileShader(fs_pink);
    shader_programme_pink = glCreateProgram();
    glAttachShader(shader_programme_pink, vs_pink);
    glAttachShader(shader_programme_pink, fs_pink);
    glLinkProgram(shader_programme_pink);

    printf("Shaders compiled.\n");
}


int main() {
    // start GL context and O/S window using the GLFW helper library
    if (!glfwInit()) {
        fprintf(stderr, "ERROR: could not start GLFW3\n");
        return 1;
    }

    GLFWwindow* window = glfwCreateWindow(1920, 1080, "Pong", NULL, NULL);
    if (!window) {
        fprintf(stderr, "ERROR: could not open window with GLFW3\n");
        glfwTerminate();
        return 1;
    }
    glfwMakeContextCurrent(window);

    // start GLEW extension handler
    glewExperimental = GL_TRUE;
    glewInit();

    // get version info
    const GLubyte* renderer = glGetString(GL_RENDERER); // get renderer string
    const GLubyte* version = glGetString(GL_VERSION); // version as a string
    printf("Renderer: %s\n", renderer);
    printf("OpenGL version supported %s\n", version);

    // tell GL to only draw onto a pixel if the shape is closer to the viewer
    glEnable(GL_DEPTH_TEST); // enable depth-testing
    glDepthFunc(GL_LESS); // depth-testing interprets a smaller value as "closer"
    
    // compile the shaders
    compile_Shaders();

    //Create movement thread for player 1
    printf("Movement thread starting...\n");
    CreateThread(NULL, 0, p1Movement, NULL, 0, NULL);
    printf("Movement thread created. Player 1\n");

    //Create movement thread for player 2
    printf("Movement thread starting...\n");
    CreateThread(NULL, 0, p2Movement, NULL, 0, NULL);
    printf("Movement thread created. Player 2\n");



    // main loop
    while (!glfwWindowShouldClose(window)) {

        // wipe the drawing surface clear
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Draw with the first shader (purple)
        glUseProgram(shader_programme);
        glBindVertexArray(vao);
        glBufferData(GL_ARRAY_BUFFER, sizeof(points), points, GL_STATIC_DRAW);
        glDrawArrays(GL_TRIANGLE_FAN, 0, 4);

        // Change to pink shader and draw the other square
        glUseProgram(shader_programme_pink);
        glBindVertexArray(vao);
        glBufferData(GL_ARRAY_BUFFER, sizeof(points2), points2, GL_STATIC_DRAW);
        glDrawArrays(GL_TRIANGLE_FAN, 0, 4);


        // Update other events like input handling 
        glfwPollEvents();

        // Put the stuff we've been drawing onto the display
        glfwSwapBuffers(window);
    }

    // close GL context and any other GLFW resources
    glfwTerminate();
    return 0;
}