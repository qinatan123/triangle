#include "InputHandler.h"
#include <GLFW/glfw3.h>

InputHandler::InputHandler(const Window& window): 
    m_window(window), m_lastMouseX(0), m_lastMouseY(0),
    m_dx(0), m_dy(0)
{

}

bool InputHandler::cameraLeft() const {
    return m_window.isKeyPressed(GLFW_KEY_A);
}

bool InputHandler::cameraRight() const {
    return m_window.isKeyPressed(GLFW_KEY_D);
}

bool InputHandler::cameraForward() const {
    return m_window.isKeyPressed(GLFW_KEY_W);
}

bool InputHandler::cameraBackward() const {
    return m_window.isKeyPressed(GLFW_KEY_S);
}

bool InputHandler::cameraUp() const {
    return m_window.isKeyPressed(GLFW_KEY_E);
}

bool InputHandler::cameraDown() const {
    return m_window.isKeyPressed(GLFW_KEY_Q);
}


bool InputHandler::rotateLeft() const {
    return m_window.isKeyPressed(GLFW_KEY_J);
}

bool InputHandler::rotateRight() const {
    return m_window.isKeyPressed(GLFW_KEY_L);
}

bool InputHandler::rotateUp() const {
    return m_window.isKeyPressed(GLFW_KEY_U);
}

bool InputHandler::rotateDown() const {
    return m_window.isKeyPressed(GLFW_KEY_O);
}

bool InputHandler::moveLeft() const {
    return m_window.isKeyPressed(GLFW_KEY_LEFT);
}

bool InputHandler::moveRight() const {
    return m_window.isKeyPressed(GLFW_KEY_RIGHT);
}

bool InputHandler::moveUp() const {
    return m_window.isKeyPressed(GLFW_KEY_UP);
}

bool InputHandler::moveDown() const {
    return m_window.isKeyPressed(GLFW_KEY_DOWN);
}

bool InputHandler::moveIn() const {
    return m_window.isKeyPressed(GLFW_KEY_I);
}

bool InputHandler::moveOut() const {
    return m_window.isKeyPressed(GLFW_KEY_K);
}

void InputHandler::update(){
    double currentX = 0;
    double currentY = 0;
    m_window.getMousePosition(currentX, currentY);
    m_dx = currentX - m_lastMouseX;
    m_dy = currentY - m_lastMouseY;
    
    m_lastMouseX = currentX; 
    m_lastMouseY = currentY;
}

void InputHandler::getMouseDelta(double& dx, double& dy){
    dx = m_dx;
    dy = m_dy;
}

