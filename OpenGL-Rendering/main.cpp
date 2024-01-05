#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <windows.h>
#include "shaders.h"
GLuint shader_programme;
GLuint shader_programme_pink;
GLuint vao;

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

    float points[] = {
    // x     y     z
    // x cordinate is how far left or right
    // y cordinate is how far up or down
    // z cordinate is how far forward or back
   -0.95f,  0.35f,  0.0f, // top left
   -0.90f,  0.35f,  0.0f, // top right
   -0.90f, -0.35f,  0.0f, // bottom right
   -0.95f, -0.35f,  0.0f  // bottom left
    };

    float points2[] = {
        // x     y     z
        // x cordinate is how far left or right
        // y cordinate is how far up or down
        // z cordinate is how far forward or back
        0.95f,  0.35f,  0.0f, // top left
        0.90f,  0.35f,  0.0f, // top right
        0.90f, -0.35f,  0.0f, // bottom right
        0.95f, -0.35f,  0.0f  // bottom left
    };

    
    // compile the shaders
    compile_Shaders();
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

    // main loop


    // close GL context and any other GLFW resources
    glfwTerminate();
    return 0;
}