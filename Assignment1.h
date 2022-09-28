// Assignment1.h : Include file for standard system include files,
// or project specific include files.
#ifndef ASSIGNMENT1_H
#define ASSIGNMENT1_H

#include <iostream>
#include <cstdio>   //reads .ppm files 
#include <GLFW/glfw3.h> //OpenGl

// TODO: Reference additional headers your program requires here.
class MyImageClass {
public:
    MyImageClass();
    MyImageClass(const char* infilename);
    ~MyImageClass();
    MyImageClass operator+(const MyImageClass& rhs);
    MyImageClass& operator+=(const MyImageClass& rhs);
    MyImageClass operator-(const MyImageClass& rhs);
    MyImageClass& operator-=(const MyImageClass& rhs);
    MyImageClass operator*(const MyImageClass& rhs);
    const MyImageClass& operator[](int index) const;
private:
    int width, height;
    unsigned int* pixel_map;
};
#endif 