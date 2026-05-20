#pragma once

class Mesh;
class Shader;

class Renderer{
    public:
    void clear()const; 
    void draw(const Mesh& mesh, const Shader& shader) const;
}; 