#include "SceneObject.h"
#include "math/Transform.h"

void SceneObject::setPosition(Vec3 position) {
    m_position = position;  
}

void SceneObject::setRotation(Vec3 rotation){
    m_rotation = rotation;
}

void SceneObject::setScale(Vec3 scale){
    m_scale = scale;
}

void SceneObject::translate(Vec3 offset) {
    m_position += offset;
}

void SceneObject::rotate(Vec3 angle) {
    m_rotation += angle;
}

void SceneObject::scale(Vec3 factor) {
    m_scale *= factor;
}

void SceneObject::update(const InputHandler& input, float dt){
    if (input.rotateLeft())     m_rotation.y -= 90.0f * dt;
    if (input.rotateRight())    m_rotation.y += 90.0f * dt;
    if (input.rotateUp())       m_rotation.x -= 90.0f * dt;
    if (input.rotateDown())     m_rotation.x += 90.0f * dt;

    if (input.moveLeft())       m_position.x -= 2.0f * dt;
    if (input.moveRight())      m_position.x += 2.0f * dt;
    if (input.moveUp())         m_position.y += 2.0f * dt;
    if (input.moveDown())       m_position.y -= 2.0f * dt;
    if (input.moveIn())         m_position.z += 2.0f * dt;
    if (input.moveOut())        m_position.z -= 2.0f * dt;
}

Mat4 SceneObject::getModelMatrix() const {
    return Transform::translate(m_position) 
          * Transform::rotate(m_rotation)  
          * Transform::scale(m_scale);
}
