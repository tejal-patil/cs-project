#ifndef POLYGON_H
#define POLYGON_H

class Polygon {
    float x;
    float y;
    int sides;
    float length;
    float r;
    float g;
    float b;

public:
    Polygon();
    Polygon(float x, float y, int sides, float length, float r, float g, float b);
    float getX() const { return x; }
    float getY() const { return y; }
    float getSideLength() const { return length; }

    void draw();

    friend struct AppTest;
};

#endif
