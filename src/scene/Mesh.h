#pragma once

#include "graphics/VertexArray.h"
#include "graphics/VertexBuffer.h"
#include "graphics/VertexAttribute.h"

#include <vector>

class Mesh {
    public:
        Mesh::Mesh (const std::vector<float>& vertices, const VertexLayout& layout);
        VertexArray getVAO() const;
        unsigned int getVertexCount() const; 
    
    private:
        VertexArray m_VAO;
        VertexBuffer m_VBO;
        std::vector<AttributeBinding> m_binding;

        unsigned int m_vertexCount;
}; 
