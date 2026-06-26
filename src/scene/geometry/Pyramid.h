#pragma once
#include "graphics/VertexAttribute.h"
#include "Geometry.h"

#include <vector>

struct Pyramid{
    std::vector<float> vertices = {
    // position            // color (RGB)
    // Front (orange)
     0.0f,  1.0f,  0.0f,  1.0f, 0.5f, 0.2f,
    -1.0f, -1.0f,  1.0f,  1.0f, 0.5f, 0.2f,
     1.0f, -1.0f,  1.0f,  1.0f, 0.5f, 0.2f,

    // Left (red)
     0.0f,  1.0f,  0.0f,  0.8f, 0.1f, 0.1f,
    -1.0f, -1.0f,  1.0f,  0.8f, 0.1f, 0.1f,
     0.0f, -1.0f, -1.0f,  0.8f, 0.1f, 0.1f,

    // Right (green)
     0.0f,  1.0f,  0.0f,  0.1f, 0.7f, 0.2f,
     1.0f, -1.0f,  1.0f,  0.1f, 0.7f, 0.2f,
     0.0f, -1.0f, -1.0f,  0.1f, 0.7f, 0.2f,

    // Bottom (blue)
    -1.0f, -1.0f,  1.0f,  0.2f, 0.3f, 0.9f,
     1.0f, -1.0f,  1.0f,  0.2f, 0.3f, 0.9f,
     0.0f, -1.0f, -1.0f,  0.2f, 0.3f, 0.9f
}; 

VertexAttribute positionAttr = { 0, 3, GL_FLOAT, false, 0 };

VertexAttribute colorAttr = { 1, 3, GL_FLOAT, false, 3 * sizeof(float) };

VertexLayout layout = { {positionAttr, colorAttr}, 6 * sizeof(float) };

Geometry buildGeometry(){
    return Geometry {vertices,layout};
    }
}; 

 