#include "Application.h"
#include "math/Mat4.h"
#include "math/Transform.h"
#include <glad/glad.h>
#include <scene/geometry/Pyramid.h>
#include <scene/geometry/Sphere.h>
#include <scene/Mesh.h>
#include <scene/SceneObject.h>


Application::Application(
    const std::string& vertexPath, 
    const std::string& fragmentPath)
: m_window(800, 600, "Triangle"), 
  m_camera(0.0f, 0.0f, 4.0f),
  m_Shader(vertexPath, fragmentPath),
  m_input(m_window)
{
    glEnable(GL_DEPTH_TEST);
}

void Application::run() {
    float lastTime = 0.0f;

    Pyramid pyramid;
    Geometry pyramidGeometry = pyramid.buildGeometry();
    Mesh pyramidMesh(pyramidGeometry);
    SceneObject pyramidObject(&pyramidMesh);

    Sphere sphere;
    Geometry sphereGeometry = sphere.buildGeometry();
    Mesh sphereMesh(sphereGeometry);
    SceneObject sphereObject(&sphereMesh);
    sphereObject.setPosition({2.5f, 0.0f, 0.0f}); // offset so it doesn't overlap pyramid

    while (!m_window.shouldClose()) {

        // --- Time ---
        float now = (float)glfwGetTime();
        float dt  = now - lastTime;
        lastTime  = now;

        // --- Input ---
        m_input.update();

        // --- Update ---
        m_camera.update(m_input, dt);
        pyramidObject.update(m_input, dt);
        sphereObject.update(m_input, dt);

        // --- Matrices ---
        int width  = m_window.getWidth();
        int height = m_window.getHeight();
        float aspect = (float)width / (float)height;

        Mat4 projection = Transform::perspective(45.0f, aspect, 0.1f, 100.0f);
        Mat4 view = m_camera.getViewMatrix();

        // --- Render ---
        glViewport(0, 0, width, height);
        m_Renderer.clear();

        m_Shader.bind();
        m_Shader.setUniformMat4("view", view);
        m_Shader.setUniformMat4("projection", projection);

        m_Shader.setUniformMat4("model", pyramidObject.getModelMatrix());
        m_Renderer.draw(pyramidObject.getMesh(), m_Shader);

        m_Shader.setUniformMat4("model", sphereObject.getModelMatrix());
        m_Renderer.draw(sphereObject.getMesh(), m_Shader);

        // --- Present ---
        m_window.swapBuffers();
        m_window.pollEvents();
    }
}