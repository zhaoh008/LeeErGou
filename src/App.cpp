#include <iostream>
#include "Hello.h"
#include <windows.h>
#include "spdlog/spdlog.h"
#include "stb_impl.h"

#include <GLFW/glfw3.h>

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "LeeErGou Engine", nullptr, nullptr);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }
    spdlog::info("李二狗引擎启动中..");
    int width=36, height=36, channels;
    unsigned char* image = stbi_load("..\\resource\\Dog.png", &width, &height, &channels, 4);

    if (image) {
        GLFWimage icons[1];
        icons[0].width = width;
        icons[0].height = height;
        icons[0].pixels = image;

        glfwSetWindowIcon(window, 1, icons);

        stbi_image_free(image);
    } else {
        // Handle the error
        spdlog::error("没找到图片");
    }
    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    spdlog::info("李二狗引擎启动完成");
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}