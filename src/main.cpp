#include<glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream> 

int g_WindowSize_X = 640;
int g_WindowSize_Y = 480;

void glfwWindowSizeCallback(GLFWwindow* pWindow, int width, int height)
{
    g_WindowSize_X = width;
    g_WindowSize_Y = height;

    glViewport(0, 0, g_WindowSize_X, g_WindowSize_Y);
}

void glfwKeyCallback(GLFWwindow* pWindow, int key, int scandcode, int action, int mode)
{
    if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(pWindow, GL_TRUE);
    }
}

int main(void)
{

    if (!glfwInit())
    {
        std::cout << "Can't call the glfwInit function " << std::endl;
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    /* Create a windowed mode window and its OpenGL context */
   GLFWwindow* pWindow = glfwCreateWindow(g_WindowSize_X, g_WindowSize_Y, "Battle city", nullptr, nullptr); 
   if (!pWindow) 
    {
        std::cout << "Can't call the glfwCreateWindow function" << std::endl; 
        glfwTerminate();
        return -1;
    }


    glfwSetWindowSizeCallback(pWindow, glfwWindowSizeCallback);

    glfwSetKeyCallback(pWindow, glfwKeyCallback);
    /* Make the window's context current */
    glfwMakeContextCurrent(pWindow);
    
    if(!gladLoadGL())
    {
        std::cout << "Cant load glad" << std::endl;
        return -1; 
    }

    std::cout << "Render: " << glGetString(GL_RENDERER) << std::endl;
    std::cout << "OpenGL version: " << glGetString(GL_VERSION);
    
    glClearColor(1, 1, 0, 0);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(pWindow))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(pWindow);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
