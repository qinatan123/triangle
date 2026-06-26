#include "Shader.h"

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include <glad/glad.h>

std::string Shader::readFile(const std::string& path) {
    std::ifstream file(path);
    if (!file.is_open()) {
        std::cerr << "[Shader] ERROR: Could not open file: " << path << std::endl;
        return "";
    }
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}


Shader::Shader(const std::string& vertexPath, const std::string& fragmentPath){
    std::string vertexSourceString = readFile(vertexPath);
    std::string fragmentSourceString = readFile(fragmentPath);

    std::cout << "[Shader] Vertex source:\n" << vertexSourceString << std::endl;
    std::cout << "[Shader] Fragment source:\n" << fragmentSourceString << std::endl;

    const char* vertexSource = vertexSourceString.c_str(); 
    const char* fragmentSource = fragmentSourceString.c_str(); 
    
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexSource, nullptr);
    glCompileShader(vertexShader);

    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertexShader, 512, nullptr, infoLog);
        std::cerr << "[Shader] Vertex compile error: " << infoLog << std::endl;
    }

    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentSource, nullptr);
    glCompileShader(fragmentShader);

    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragmentShader, 512, nullptr, infoLog);
        std::cerr << "[Shader] Fragment compile error: " << infoLog << std::endl;
    }

    m_ID = glCreateProgram(); 
    glAttachShader(m_ID, vertexShader);
    glAttachShader(m_ID, fragmentShader);
    glLinkProgram(m_ID);

    glGetProgramiv(m_ID, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(m_ID, 512, nullptr, infoLog);
        std::cerr << "[Shader] Link error: " << infoLog << std::endl;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

void Shader::setUniformMat4(const std::string& name, const Mat4& matrix) const {
    int location = glGetUniformLocation(m_ID, name.c_str());
    if (location == -1) {
        std::cerr << "[Shader] WARNING: uniform '" << name << "' not found" << std::endl;
    }
    glUniformMatrix4fv(location, 1, GL_FALSE, matrix.ptr());
}


