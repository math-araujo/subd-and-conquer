#include <exception>
#include <iostream>

#include "main_application.hpp"

int main()
{
    try
    {
        app::MainApp app{1024, 768, "SubD and Conquer"};
        app.run();
    }
    catch (const std::exception& exception)
    {
        std::cerr << exception.what() << std::endl;
    }

    return 0;
}