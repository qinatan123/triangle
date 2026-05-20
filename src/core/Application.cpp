#include "Application.h"

Application::Application(
    const std::string& vertexPath, 
    const std::string& fragmentPath
    const std::vector<float>& vertices,
    const VertexLayout& layout)

: m_Window(800, 600, "Triangle"), 
  m_Shader(vertexPath, fragmentPath),
  m_Mesh(vertices, layout)
{

}

void Application::run() {
    while (!m_Window.shouldClose()) {
        m_Renderer.clear();

        m_Renderer.draw(m_Mesh, m_Shader);

        m_Window.swapBuffers();
        m_Window.pollEvents();
    }
}