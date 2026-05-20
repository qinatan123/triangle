#pragma once

class VertexBuffer {
public:
    VertexBuffer(const void* data, unsigned int size);
    void bind() const;

private:
    unsigned int m_ID;
};