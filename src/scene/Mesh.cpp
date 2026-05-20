
#include "graphics/VertexAttribute.h"
#include "Mesh.h"

#include <glad/glad.h>

// one Mesh
// one VBO 
// multiple attributes for one VAO
Mesh::Mesh (const std::vector<float>& vertices, const VertexLayout& layout) :
    m_VAO(VertexArray()),
    m_VBO(VertexBuffer(vertices.data(), vertices.size()*sizeof(float))),
    m_vertexCount(vertices.size() / (layout.stride / sizeof(float))) 
    {
        // VAO record structure shared by all vertices in a currently bounded VBO
        m_VBO.bind();
        m_VAO.bind();
        m_VAO.addLayout(layout);
    }

VertexArray Mesh::getVAO() const{
    return m_VAO; 
}

unsigned int Mesh::getVertexCount()const {
    return m_vertexCount;
}

