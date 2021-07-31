#include <iostream>
#include <string>
#include <GL/glut.h>

void displayMe(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
        glVertex3f(0.5, 0.0, 0.5);
        glVertex3f(0.5, 0.0, 0.0);
        glVertex3f(0.0, 0.5, 0.0);
        glVertex3f(0.0, 0.0, 0.5);
    glEnd();
    glFlush();
}

int main(int argc, char* argv[]) {
    std::cout << "The number of arguments: " << argc << std::endl;
    std::cout << "The arguments:" << std::endl;
    for (int i = 0; i < argc; i++) {
        std::string arg(argv[i]);
        std::cout << '\t' << arg;
    }
    std::cout << std::endl;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(400, 300);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Hello world!");
    glutDisplayFunc(displayMe);
    glutMainLoop();
    
    return 0;
}