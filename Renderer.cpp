#ifdef __APPLE_CC__
    #include <GLUT/glut.h>
#else
    #include <GL/glut.h>
#endif

#include "Renderer.hpp"

const float renderer::DELTA_TIME = 1000/60;
std::vector<std::shared_ptr<Renderable>> renderer::renderables;

void renderer::init(int* argc, char* argv[]) {
    glutInit(argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    glutInitWindowPosition(80, 80);
    glutInitWindowSize(1280, 720);
    glutCreateWindow("Render");

    glutDisplayFunc(display);

    glutTimerFunc(0, update, 0);

    glutMainLoop();
}

void renderer::display() {

    // Render things
    glClear(GL_COLOR_BUFFER_BIT);
    
    for (auto r : renderables)
        r->render();

    glFlush();

    // Update things
    float time = glutGet(GLUT_ELAPSED_TIME) / 1000.0f; // seconds
    for (auto r : renderables)
        r->update(time); 

    // Display
    glutSwapBuffers();
}

void renderer::update(int) {
    glutPostRedisplay();
    glutTimerFunc(DELTA_TIME, update, 0);
}

void renderer::addRenderable(std::shared_ptr<Renderable> r) {
    renderables.push_back(r);
}