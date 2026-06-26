#pragma once

#include "core/Window.h"

class InputHandler {
public: 
    InputHandler(const Window& window);
    void update();

    // Camera movement (WASD + E/Q)
    bool cameraLeft() const;
    bool cameraRight() const;
    bool cameraForward() const;
    bool cameraBackward() const;
    bool cameraUp() const;
    bool cameraDown() const;

    // Object rotation (J/L/U/O)
    bool rotateLeft() const;
    bool rotateRight() const;
    bool rotateUp() const;
    bool rotateDown() const;

    // Object movement (arrow keys + I/K)
    bool moveLeft() const;
    bool moveRight() const;
    bool moveUp() const;
    bool moveDown() const;
    bool moveIn() const;
    bool moveOut() const;

    // Mouse delta for camera rotation
    void getMouseDelta(double& dx, double& dy);

private: 
    const Window& m_window;
    double m_lastMouseX, m_lastMouseY;
    double m_dx, m_dy;
};


