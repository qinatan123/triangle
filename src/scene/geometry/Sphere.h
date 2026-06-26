// src/scene/geometry/Sphere.h
#pragma once
#include "Geometry.h"
#include "graphics/VertexAttribute.h"
#include <vector>
#include <cmath>

struct Sphere {
    std::vector<float> vertices;

    Sphere(int stacks = 16, int slices = 16, float radius = 1.0f) {
        const float PI = 3.14159265f;

        for (int i = 0; i <= stacks; ++i) {
            float phi = PI * i / stacks;          // 0 → π  (top to bottom)

            for (int j = 0; j <= slices; ++j) {
                float theta = 2.0f * PI * j / slices; // 0 → 2π (around)

                // Position
                float x = radius * std::sin(phi) * std::cos(theta);
                float y = radius * std::cos(phi);
                float z = radius * std::sin(phi) * std::sin(theta);

                // Color — use normalized position as RGB (a common trick)
                float r = (x / radius + 1.0f) / 2.0f;
                float g = (y / radius + 1.0f) / 2.0f;
                float b = (z / radius + 1.0f) / 2.0f;

                vertices.insert(vertices.end(), { x, y, z, r, g, b });
            }
        }
    }

    // Build triangle list from the grid of vertices above
    std::vector<float> buildTriangles() {
        int slices = 16;
        int stacks = 16;
        std::vector<float> tris;

        for (int i = 0; i < stacks; ++i) {
            for (int j = 0; j < slices; ++j) {
                int row1 = i * (slices + 1);
                int row2 = (i + 1) * (slices + 1);

                // Two triangles per quad
                auto push = [&](int idx) {
                    for (int k = 0; k < 6; ++k)
                        tris.push_back(vertices[idx * 6 + k]);
                };

                push(row1 + j);     push(row2 + j);     push(row1 + j + 1);
                push(row1 + j + 1); push(row2 + j);     push(row2 + j + 1);
            }
        }
        return tris;
    }

    Geometry buildGeometry() {
        VertexAttribute posAttr = { 0, 3, GL_FLOAT, false, 0 };
        VertexAttribute colAttr = { 1, 3, GL_FLOAT, false, 3 * sizeof(float) };
        VertexLayout layout = { {posAttr, colAttr}, 6 * sizeof(float) };

        return Geometry{ buildTriangles(), layout };
    }
};