#ifndef MAIN_APPLICATION_HPP
#define MAIN_APPLICATION_HPP

#include <memory>
#include <string_view>

#include "gl/application.hpp"
#include "gl/mesh.hpp"
#include "gl/shader.hpp"

namespace app
{

class MainApp : public gl::Application
{
public:
    MainApp(int window_width, int window_height, std::string_view title);
    MainApp(const MainApp&) = delete;
    MainApp(MainApp&&) = delete;
    MainApp& operator=(const MainApp&) = delete;
    MainApp& operator=(MainApp&&) = delete;
    ~MainApp() override = default;

    void render() override;
    void render_imgui_editor() override;

private:
    std::unique_ptr<gl::ShaderProgram> flat_color_shader_{};
    std::unique_ptr<gl::IndexedMesh> cube_{};
};

} // namespace app

#endif // MAIN_APPLICATION