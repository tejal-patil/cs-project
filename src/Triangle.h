#ifndef TRIANGLE_H
#define TRIANGLE_H

class Triangle {
    float x;
    float y;
    float base;
    float height;
    float r;
    float g;
    float b;

public:
    Triangle();
    Triangle(float x, float y, float base, float height, float r, float g, float b);
    float getX() const { return x; }
    float getY() const { return y; }
    float getBase() const { return base; }
    float getHeight() const { return height; }

    void draw();

    friend struct AppTest;
};

#endif
