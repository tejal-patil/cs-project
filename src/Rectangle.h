#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle {
    float x;
    float y;
    float width;
    float height;
    float r;
    float g;
    float b;

public:
    Rectangle();
    Rectangle(float x, float y, float width, float height, float r, float g, float b);
    
    float getX() const { return x; }
    float getY() const { return y; }
    float getWidth() const { return width; }
    float getHeight() const { return height; }
    

    void draw();

    friend struct AppTest;
};

#endif
