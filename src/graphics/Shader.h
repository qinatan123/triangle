#pragma once

class Shader{
    public: 
        Shader(const std::string& vertexPath, const std::string& fragmentPath);
        
        std::string Shader::readFile(const std::string& path);

        void bind() const;
    private:
        unsigned int m_ID;
};