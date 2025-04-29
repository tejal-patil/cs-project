
#include "Canvas.h"
#include <GL/freeglut.h>

Canvas::Canvas(int x, int y, int w, int h) : Canvas_(x, y, w, h) {
    // 
}

void Canvas::startScribble(float r, float g, float b, int size) {
    // Create a new scribble and add it to the container
    Scribble* scribble = new Scribble(r, g, b, size);
    scribbles.push_back(scribble);
}

void Canvas::addPointToScribble(float x, float y) {
    if (!scribbles.empty()) {
        scribbles.back()->addPoint(x, y);
    }
}

void Canvas::addPoint(float x, float y, float r, float g, float b, int size) {
    points.push_back(new Point(x, y, r, g, b, size));
    shapes.push_back(PENCIL);
}

void Canvas::addCircle(float x, float y, float radius, float r, float g, float b) {
    circles.push_back(new Circle(x, y, radius, r, g, b));
    shapes.push_back(CIRCLE);
}

void Canvas::addTriangle(float x, float y, float base, float height, float r, float g, float b) {
    triangles.push_back(new Triangle(x, y, base, height, r, g, b));
    shapes.push_back(TRIANGLE);
}

void Canvas::addRectangle(float x, float y, float width, float height, float r, float g, float b) {
    rectangles.push_back(new Rectangle(x, y, width, height, r, g, b));
    shapes.push_back(RECTANGLE);
}

void Canvas::addPolygon(float x, float y, int sides, float length, float r, float g, float b) {
    polygons.push_back(new Polygon(x, y, sides, length, r, g, b));
    shapes.push_back(POLYGON);
}

void Canvas::undo() {
     if (!scribbles.empty()) {
        // Delete the last scribble and remove it from the container
        delete scribbles.back();
        scribbles.pop_back();
    }
    
    if (shapes.empty()) {
        return; // No shapes to undo
    }
    
    // Get the last shape type and remove it from the shapes vector
    TOOL lastShape = shapes.back();
    shapes.pop_back();

    // Remove the last shape from the corresponding vector and delete it
    if (lastShape == PENCIL && !points.empty()) {
        delete points.back();
        points.pop_back();
    }
    
    
    else if (lastShape == CIRCLE && !circles.empty()) {
        delete circles.back();
        circles.pop_back();
    }
    else if (lastShape == TRIANGLE && !triangles.empty()) {
        delete triangles.back();
        triangles.pop_back();
    }
    else if (lastShape == RECTANGLE && !rectangles.empty()) {
        delete rectangles.back();
        rectangles.pop_back();
    }
    else if (lastShape == POLYGON && !polygons.empty()) {
        delete polygons.back();
        polygons.pop_back();
    }

}

void Canvas::clear() {
     
    for (Scribble* scribble : scribbles) {
        delete scribble;
    }
    scribbles.clear();

    for (unsigned int i = 0 ; i < points.size(); i++) {
        delete points[i];
    }
    points.clear();

    for (unsigned int i = 0 ; i < circles.size(); i++) {
        delete circles[i];
    }
    circles.clear();

    for (unsigned int i = 0 ; i < triangles.size(); i++) {
        delete triangles[i];
    }
    triangles.clear();

    for (unsigned int i = 0 ; i < rectangles.size(); i++) {
        delete rectangles[i];
    }
    rectangles.clear();

    for (unsigned int i = 0 ; i < polygons.size(); i++) {
        delete polygons[i];
    }
    polygons.clear();
    
    shapes.clear();
}

void Canvas::render() {
    for (Scribble* scribble : scribbles) {
        scribble->draw();
    }
    for (unsigned int i = 0 ; i < points.size(); i++) {
        points[i]->draw();
    }

    for (unsigned int i = 0 ; i < circles.size(); i++) {
        circles[i]->draw();
    }

    for (unsigned int i = 0 ; i < triangles.size(); i++) {
        triangles[i]->draw();
    }

    for (unsigned int i = 0 ; i < rectangles.size(); i++) {
        rectangles[i]->draw();
    }

    for (unsigned int i = 0 ; i < polygons.size(); i++) {
        polygons[i]->draw();
    }
}
void Canvas::eraseAt(float x, float y, float eraserSize) {
    // Check scribbles
    for (auto it = scribbles.begin(); it != scribbles.end(); ++it) {
        Scribble* scribble = *it;

        for (Point* point : scribble->getPoints()) {
            float dx = point->getX() - x;
            float dy = point->getY() - y;
            float distance = sqrt(dx * dx + dy * dy);

            if (distance <= eraserSize) {
                delete scribble;
                scribbles.erase(it);
                return;
            }
        }
    }

    // Check circles
    for (auto it = circles.begin(); it != circles.end(); ++it) {
        Circle* circle = *it;

        float dx = circle->getX() - x;
        float dy = circle->getY() - y;
        float distance = sqrt(dx * dx + dy * dy);

        if (distance <= eraserSize + circle->getRadius()) {
            delete circle;
            circles.erase(it);
            return;
        }
    }
}
