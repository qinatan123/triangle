#pragma once

#include "graphics/VertexAttribute.h"
#include <vector>

struct Geometry {
    std::vector<float> vertices;
    VertexLayout layout;
};