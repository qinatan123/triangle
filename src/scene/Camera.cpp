#include "Camera.h"
#include "math/Transform.h"

Camera::Camera(float x, float y, float z): m_x(x), m_y(y), m_z(z)
{ 

}

void Camera::moveLeft(float dt)     { m_x -= m_speed * dt; }
void Camera::moveRight(float dt)    { m_x += m_speed * dt; }
void Camera::moveUp(float dt)       { m_y += m_speed * dt; }
void Camera::moveDown(float dt)     { m_y -= m_speed * dt; }
void Camera::moveForward(float dt)  { m_z -= m_speed * dt; }  // -Z is into the scene
void Camera::moveBackward(float dt) { m_z += m_speed * dt; }

Mat4 Camera::getViewMatrix() const {
    return Transform::translate(Vec3(-m_x, -m_y, -m_z));
}

void Camera::update(InputHandler& input, float dt){
    if (input.cameraLeft())     moveLeft(dt);
    if (input.cameraRight())    moveRight(dt);
    if (input.cameraForward())  moveForward(dt);
    if (input.cameraBackward()) moveBackward(dt);
    if (input.cameraUp())       moveUp(dt);
    if (input.cameraDown())     moveDown(dt);
}
