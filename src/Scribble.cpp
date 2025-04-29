#include "Scribble.h"
#include <GL/freeglut.h>

Scribble::Scribble(float r, float g, float b, int size) : r(r), g(g), b(b), size(size) {}

Scribble::~Scribble() {
    for (Point* point : points) {
        delete point;
    }
    points.clear();
}

void Scribble::addPoint(float x, float y) {
    points.push_back(new Point(x, y, r, g, b, size));
}

void Scribble::draw() const {
    glColor3f(r, g, b);
    glLineWidth(size);

    glBegin(GL_LINE_STRIP);
    for (Point* point : points) {
        glVertex2f(point->getX(), point->getY());
    }
    glEnd();
}

float Scribble::getR() const { return r; }
float Scribble::getG() const { return g; }
float Scribble::getB() const { return b; }
int Scribble::getSize() const { return size; }
