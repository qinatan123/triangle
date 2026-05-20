#pragma once

#include <vector>

struct VertexAttribute {
    unsigned int index;
    int size;
    unsigned int type;
    bool normalized;
    unsigned int stride;
    unsigned int offset; 
};

class VertexArray{
    public:
        VertexArray(); 

        void bind() const; 
        void addLayout(const VertexLayout& layout); 
        void enableAttribute(unsigned int index); 

    private: 
        unsigned int m_ID; 
}; 