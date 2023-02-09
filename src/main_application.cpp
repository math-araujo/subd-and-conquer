#include "main_application.hpp"
#include "geometry/io.hpp"

#include <glm/gtx/string_cast.hpp>
#include <iostream>

#include "control_mesh.hpp"
#include "geometry/indexed_mesh.hpp"

namespace app
{

MainApp::MainApp(int window_width, int window_height, std::string_view title) :
    Application{window_width, window_height, title}
{
    auto meshes = geometry::read_wavefront_file("assets/models/cube.obj");
    auto& mesh = meshes.front();
    auto [halfedge, halfedge_positions] = geometry::to_halfedge(mesh);

    flat_color_shader_ = std::make_unique<gl::ShaderProgram>(
        std::initializer_list<gl::ShaderInfo>{{"assets/shaders/flat_color/vertex.glsl", gl::Shader::Type::Vertex},
                                              {"assets/shaders/flat_color/fragment.glsl", gl::Shader::Type::Fragment}});
    control_mesh_ = std::make_unique<app::ControlMesh>(mesh);
    cube_ = std::make_unique<gl::IndexedMesh>(
        // clang-format off
        std::vector<float>{
             1.0,  1.0, -1.0,
             1.0, -1.0, -1.0,
             1.0,  1.0,  1.0,
             1.0, -1.0,  1.0,
            -1.0,  1.0, -1.0,
            -1.0, -1.0, -1.0,
            -1.0,  1.0,  1.0,
            -1.0, -1.0,  1.0
        },
        std::vector<std::uint32_t>{
            4, 2, 0,
            2, 7, 3,
            6, 5, 7,
            1, 7, 5,
            0, 3, 1,
            4, 1, 5,
            4, 6, 2,
            2, 6, 7,
            6, 4, 5,
            1, 3, 7,
            0, 2, 3,
            4, 0, 1
        },
        std::vector<int>{3});
    // clang-format on
}

void MainApp::render()
{
    glGetIntegerv(GL_VIEWPORT, current_viewport_.data());

    // Clear window with specified color
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    flat_color_shader_->use();
    flat_color_shader_->set_vec3_uniform("color", glm::vec3{1.0f, 0.0f, 0.0f});
    cube_->render();
    flat_color_shader_->set_mat4_uniform("mvp", camera().view_projection());
    flat_color_shader_->set_vec3_uniform("color", glm::vec3{1.0f, 1.0f, 1.0f});
    control_mesh_->render();

    render_imgui_editor();
}

void MainApp::render_imgui_editor()
{
    Application::render_imgui_editor();
}

} // namespace app