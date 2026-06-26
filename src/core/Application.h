#pragma once 

#include "Window.h"
#include "graphics/Shader.h"
#include "graphics/Renderer.h"
#include "graphics/VertexAttribute.h"
#include "scene/Mesh.h"
#include "scene/Camera.h"
#include "input/InputHandler.h"

#include <string>
#include <vector>

class Application{
    public:
        Application(
            const std::string& vertexPath,
            const std::string& fragmentPath
        );

        void run(); 

    private: 
        Window m_window;
        Renderer m_Renderer;
        Shader m_Shader;
        Camera m_camera;
        InputHandler m_input; 
};
