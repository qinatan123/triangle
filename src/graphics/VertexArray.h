#pragma once

#include "VertexAttribute.h"
#include <vector>

class VertexArray{
    public:
        VertexArray(); 

        void bind() const; 
        void addLayout(const VertexLayout& layout); 
        void enableAttribute(unsigned int index);
        bool isValid() const { return m_ID != 0; }

    private: 
        unsigned int m_ID; 
}; 