#include <iostream>
#include <string>
#include <memory>
#include "Renderer.hpp"
#include "Cube.hpp"

int main(int argc, char* argv[]) {

    std::cout << "The number of arguments: " << argc << std::endl;
    std::cout << "The arguments:" << std::endl;
    for (int i = 0; i < argc; i++) {
        std::string arg(argv[i]);
        std::cout << "    " << arg << std::endl;
    }

    std::shared_ptr<Cube> cube = std::make_shared<Cube>(20);
    renderer::addRenderable(cube);

    renderer::init(&argc, argv);
    return 0;
}