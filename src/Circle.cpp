#ifndef CIRCLE_H
#define CIRCLE_H

class Circle {
    float x;
    float y;
    float radius;
    float r;
    float g;
    float b;

public:
    Circle();
    Circle(float x, float y, float radius, float r, float g, float b);

    void draw();

    float getX() const { return x; } 

    float getY() const { return y; }   
       
    float getRadius() const { return radius; }

    friend struct AppTest;
};

#endif
