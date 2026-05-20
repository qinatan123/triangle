#pragma once 

#include "Window.h"
#include "graphics/Shader.h"
#include "graphics/Renderer.h"
#include "scene/Mesh.h"

class Application{
    public:
        Application(); 

        void run(); 

    private: 
        Window m_window;
        Renderer m_Renderer;
        Mesh m_Mesh;
        Shader m_Shader;
}
