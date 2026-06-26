#pragma once

#include "math/Vec3.h"
#include "math/Mat4.h"
#include "scene/Mesh.h"
#include "input/InputHandler.h"

class SceneObject {
public: 
    SceneObject(Mesh* mesh) : 
        m_mesh(mesh),
        m_position(0.0f, 0.0f, 0.0f), 
        m_rotation(0.0f, 0.0f, 0.0f),
        m_scale(1.0f, 1.0f, 1.0f)
    {}

    void setPosition(Vec3 position);
    void setRotation(Vec3 rotation);
    void setScale(Vec3 scale);

    void translate(Vec3 offset);
    void rotate(Vec3 angle);
    void scale(Vec3 factor);

    void update(const InputHandler& input, float dt);

    const Mesh& getMesh() const { return *m_mesh; }
    Mat4 getModelMatrix() const;

private: 
    Mesh* m_mesh;

    Vec3 m_position; 
    Vec3 m_rotation; 
    Vec3 m_scale; 
}; 