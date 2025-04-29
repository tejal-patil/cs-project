#ifndef SCRIBBLE_H
#define SCRIBBLE_H

#include <vector>
#include "Point.h"

class Scribble {
private:
    std::vector<Point*> points; // Store all the points in a single scribble
    float r, g, b; // Scribble color
    int size; // Scribble size (thickness)

public:
    Scribble(float r, float g, float b, int size);
    ~Scribble();
    

    // Add a point to the scribble
    void addPoint(float x, float y);

    // Draw the scribble on the canvas
    void draw() const;

    // Getters for color and size
    float getR() const;
    float getG() const;
    float getB() const;
    int getSize() const;

    std::vector<Point*>& getPoints() { return points; }
};

#endif
