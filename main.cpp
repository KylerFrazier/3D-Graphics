#include <iostream>
#include <string>
#include <memory>
#include "Renderer.hpp"
#include "AnimateScript.hpp"

int main(int argc, char* argv[]) {

    std::cout << "The number of arguments: " << argc << std::endl;
    std::cout << "The arguments:" << std::endl;
    for (int i = 0; i < argc; i++) {
        std::string arg(argv[i]);
        std::cout << "    " << arg << std::endl;
    }

    std::shared_ptr<AnimateScript> script = std::make_shared<AnimateScript>();
    renderer::addRenderable(script);

    renderer::init(&argc, argv);
    return 0;
}