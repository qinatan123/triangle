#include "VertexArray.h"
#include "VertexAttribute.h"
#include <glad/glad.h>

VertexArray::VertexArray(){
    glGenVertexArrays(1, &m_ID);
}

void VertexArray::bind() const{
    glBindVertexArray(m_ID);
}

void VertexArray::addLayout(const VertexLayout& layout){
    for (const auto& attr: layout.attributes){
        glEnableVertexAttribArray(attr.index);

        glVertexAttribPointer(
            attr.index,
            attr.size,
            attr.type, 
            attr.normalized? GL_TRUE : GL_FALSE,
            layout.stride,
            (const void*) attr.offset
        );
    }
}

void VertexArray::enableAttribute(unsigned index){
    glEnableVertexAttribArray(index);
}

