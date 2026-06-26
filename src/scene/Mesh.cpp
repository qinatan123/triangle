
#include "graphics/VertexAttribute.h"
#include "Mesh.h"

#include <glad/glad.h>

// one Mesh
// one VBO 
// multiple attributes for one VAO
Mesh::Mesh (Geometry geometry): 
    m_geometry(geometry),
    m_VAO(VertexArray()),
    m_VBO(VertexBuffer(geometry.vertices.data(), geometry.vertices.size()*sizeof(float))),
    m_vertexCount(geometry.vertices.size() / (geometry.layout.stride / sizeof(float))) 
    {
        m_VAO.addLayout(geometry.layout);
    }

VertexArray Mesh::getVAO() const{
    return m_VAO; 
}

unsigned int Mesh::getVertexCount()const {
    return m_vertexCount;
}

