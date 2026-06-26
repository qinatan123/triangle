#pragma once

#include "graphics/VertexArray.h"
#include "graphics/VertexBuffer.h"
#include "graphics/VertexAttribute.h"
#include "scene/geometry/Geometry.h"


#include <vector>

class Mesh {
    public:
        Mesh(Geometry geometry);
        
        VertexArray getVAO() const;
        
        unsigned int getVertexCount() const; 
    
    private:
        Geometry m_geometry;
        VertexArray m_VAO;
        VertexBuffer m_VBO;

        unsigned int m_vertexCount;
}; 
