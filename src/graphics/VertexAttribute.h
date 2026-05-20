#include "VertexBuffer.h"
#include <vector>


// A VertexAttribute describes one field inside a vertex 
struct VertexAttribute {
    unsigned int index; // input variable in the vertex shader coonnects to
    int size;   // number of components this attribute. example: (x, y, z)
    unsigned int type; // data type of each component
    bool normalized; // should integer data be mapped into [-1, 1] or [0,1] range
    unsigned int offset; // how many bytes into the vertex this attribute starts
};

// description of the structure shared by all vertices in a mesh
// A mesh is a list of vertices, each vertex has the same structure
// mesh memory looks like this: 
// [v0: px py pz r g b]
// [v1: px py pz r g b]
// [v2: px py pz r g b]
struct VertexLayout{
    std::vector<VertexAttribute> attributes; // a vertice field (ex: position, color, normal, etc)
    int stride; // total size of one vertex in bytes
};

struct AttributeBinding{
    VertexBuffer buffer();
    VertexAttribute attribute;
}; 