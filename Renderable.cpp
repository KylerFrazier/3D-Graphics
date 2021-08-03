#ifdef __APPLE_CC__
    #include <GLUT/glut.h>
#else
    #include <GL/glut.h>
#endif

#include "Renderable.hpp"

void Renderable::render() const {
    glPointSize(5.0f);
    glColor3f(1.0f, 1.0, 1.0f);
    
    glBegin(GL_POINTS);
        for (Vector3 v : vertices)
            glVertex2f(v.x, v.y);
    glEnd(); 
}