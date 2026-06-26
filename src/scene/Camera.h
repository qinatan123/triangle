#pragma once
#include "math/Mat4.h"
#include "input/InputHandler.h"
class Camera {
public:
    Camera(float x, float y, float z);

    void moveLeft(float dt);
    void moveRight(float dt);
    void moveUp(float dt);
    void moveDown(float dt);
    void moveForward(float dt);
    void moveBackward(float dt);

    Mat4 getViewMatrix() const;

    void update(InputHandler& input, float dt);

private:
    float m_x, m_y, m_z;   // position in world space
    float m_speed = 2.0f;   // units per second
};