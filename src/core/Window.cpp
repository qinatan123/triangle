#include "Window.h"
#include <iostream>

Window::Window(int width, int height, const char* title) {
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    m_Window = glfwCreateWindow(width, height, title, nullptr, nullptr);
    glfwMakeContextCurrent(m_Window);

    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
}

Window::~Window() {
    glfwTerminate();
}

bool Window::shouldClose() const {
    return glfwWindowShouldClose(m_Window);
}

void Window::swapBuffers() {
    glfwSwapBuffers(m_Window);
}

void Window::pollEvents() {
    glfwPollEvents();
}

int Window::getWidth() const {
    int width, height;
    glfwGetFramebufferSize(m_Window, &width, &height);
    return width;
}

int Window::getHeight() const {
    int width, height;
    glfwGetFramebufferSize(m_Window, &width, &height);
    return height;
}

bool Window::isKeyPressed(int glfwKey) const {
        return glfwGetKey(m_Window, glfwKey) == GLFW_PRESS;
}

bool Window::isMouseButtonPressed(int glfwButton) const {
    return glfwGetMouseButton(m_Window, glfwButton) == GLFW_PRESS;
}

void Window::getMousePosition(double& x, double& y) const {
    glfwGetCursorPos(m_Window, &x, &y);
}