#include "Shader.h"

#include <string>
#include <fstream>
#include <sstream>

#include <glad/glad.h>

std::string Shader::readFile(const std::string& path) {
    std::ifstream file(path);

    std::stringstream buffer;
    buffer << file.rdbuf();

    return buffer.str();
}



Shader::Shader(const std::string& vertexPath, const std::string& fragmentPath){
    std::string vertexSourceString = readFile(vertexPath);
    std::string fragmentSourceString = readFile(fragmentPath);
    const char* vertexSource = vertexSourceString.c_str(); 
    const char* fragmentSource = fragmentSourceString.c_str(); 
    
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    
    
    glShaderSource(vertexShader, 1, &vertexSource, nullptr);
    glCompileShader(vertexShader);

    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentSource, nullptr);
    glCompileShader(fragmentShader); 

    m_ID = glCreateProgram(); 
    glAttachShader(m_ID, vertexShader);
    glAttachShader(m_ID, fragmentShader);
    glLinkProgram(m_ID);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

void Shader::bind()const{
    glUseProgram(m_ID);
}
