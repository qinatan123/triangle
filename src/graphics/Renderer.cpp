#include "Renderer.h"
#include "Shader.h"
#include "scene/Mesh.h"
#include <glad/glad.h>

void Renderer::clear()const{
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::draw(const Mesh& mesh, const Shader& shader) const{
    if (!shader.isValid()) return;
    shader.bind(); // activate the shader program

    const VertexArray& vao = mesh.getVAO();
    if (!vao.isValid()) return;
    vao.bind(); // bind the mesh's vertex array object
    
    unsigned int vertexCount = mesh.getVertexCount(); 
    
    glDrawArrays(GL_TRIANGLES, 0, vertexCount);

}