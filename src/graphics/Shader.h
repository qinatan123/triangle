#pragma once

#include <string>
#include "math/Mat4.h"


class Shader{
    public: 
        Shader(const std::string& vertexPath, const std::string& fragmentPath);
        
        std::string readFile(const std::string& path);

        void bind() const { glUseProgram(m_ID); }
        bool isValid() const { return m_ID != 0; }

        void setUniformMat4(const std::string& name, const Mat4& matrix) const;
    
    private:
        unsigned int m_ID;
};