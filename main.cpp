#include "core/Application.h"


int main(){
float triangleVertices[] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
};

VerexAtrribute positionAttr = {
    0, 
    3,
    GL_FLOAT,
    false, 
    0
}; 

const VertexAttribute triangle_layout {
    {positionAttr},
    3*size(float)
}


Application app()

}


