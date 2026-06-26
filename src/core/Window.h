#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Window {
public:
    Window(int width, int height, const char* title);
    ~Window();

    bool shouldClose() const;
    void swapBuffers();
    void pollEvents();

    int getWidth() const;
    int getHeight() const;

    bool isKeyPressed(int glfwKey) const;

    bool isMouseButtonPressed(int glfwButton) const;

    void getMousePosition(double& x, double&y) const;

private:
    GLFWwindow* m_Window;
};