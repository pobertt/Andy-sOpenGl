#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "Renderer.h"
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "Shader.h"
#include "Texture.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw_gl3.h"

#include "tests/TestClearColor.h"
#include "tests/TestMenu.h"


int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /*
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    */

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(960, 540, "Practice App", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* GLEW Init called after GL context is made */
    if (glewInit() != GLEW_OK)
    {
        std::cout << "error" << std::endl;
    };

    std::cout << glGetString(GL_VERSION) << std::endl;

    //glfwSwapInterval(1);
    
    /*
    std::cout << glGetString(GL_VERSION) << std::endl;

    {
        GLCall(glEnable(GL_BLEND));
        GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));

        Renderer renderer;

        ImGui::CreateContext();
        ImGui_ImplGlfwGL3_Init(window, true);
        ImGui::StyleColorsDark();
        
        test::TestClearColor test;
        test::TestMenu testMenu;

        /* Loop until the user closes the window */
        
    /*}
    */

    float positions[6] = {
        -0.5f, -0.5f,
         0.0f,  0.5f,
         0.5f, -0.5f
    };

    unsigned int buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);

    while (!glfwWindowShouldClose(window))
    {
        /* Render here */

        //drawing triangle
            
        glClear(GL_COLOR_BUFFER_BIT);

        /* Draws whatever array buffer is currently bound */

        glDrawArrays(GL_TRIANGLES, 0, 3);

            /*
            renderer.Clear();

            testMenu.OnUpdate(0.0f);
            test.OnUpdate(0.0f);

            test.OnRender();
            testMenu.OnRender();

            ImGui_ImplGlfwGL3_NewFrame();

            test.OnImGuiRender();
            testMenu.OnImGuiRender();

            ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);

            ImGui::Render();
            ImGui_ImplGlfwGL3_RenderDrawData(ImGui::GetDrawData());
            */

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    //Cleanup
    /*
    ImGui_ImplGlfwGL3_Shutdown();
    ImGui::DestroyContext();
    */

    glfwTerminate();
    return 0;
    
}