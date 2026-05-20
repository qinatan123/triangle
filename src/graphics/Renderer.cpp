#include "Renderer.h"
#include "Shader.h"
#include "scene/Mesh.h"
#include <glad/glad.h>

void Renderer::clear()const{
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::draw(const Mesh& mesh, const Shader& shader) const{
    shader.bind(); 
    VertexArray vao = mesh.getVAO(); 
    vao.bind(); 
    unsigned int vertexCount = mesh.getVertexCount(); 
    glDrawArrays(GL_TRIANGLES, 0, vertexCount);

}