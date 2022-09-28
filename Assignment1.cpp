// Assignment1.cpp : Defines the entry point for the application.
//
#include <iostream>
#include <exception>
#include <GLFW/glfw3.h> //OpenGl
#include "Assignment1.h"

using namespace std;

MyImageClass::MyImageClass() {
    width = 0;
    height = 0;
    pixel_map = new unsigned int[width * height];
}
MyImageClass::MyImageClass(const char* infilename) {
    //glRasterPos2i(0, 0);    //opens a blank image, pixel 0 scanline 0, TO BE DELETED
    FILE* infile;
    infile = fopen(infilename, "rb");
    string str;
    str = fgetc(infile);
    int ch;
    ch = fgetc(infile);
    if (ch == 'P2') { //greyscale ASCII
        ++ch;
        width = ch - '0';
        ++ch;
        height = ch - '0';
        pixel_map = new unsigned int[width * height];

        int blue, green, red, alpha;
        unsigned int pixel;
        /* packing */
        for (int i = 0; i < width * height; ++i) {
            pixel = 0xff << 24 | blue << 16 | green << 8 | red;
            pixel_map[i] = pixel;
        }
    }
    else if (ch == 'P3') { //full color ASCII
        ++ch;
        width = ch - '0';
        ++ch;
        height = ch - '0';
        pixel_map = new unsigned int[width * height];

        int blue, green, red, alpha;
        unsigned int pixel;
        /* packing */
        for (int i = 0; i < width * height; ++i) {
            pixel = 0xff << 24 | blue << 16 | green << 8 | red;
            pixel_map[i] = pixel;
        }
    }
    else if (ch == 'P5') { //greyscale 
        ++ch;
        width = ch;
        ++ch;
        height = ch;
        pixel_map = new unsigned int[width * height];

        int blue, green, red, alpha;
        unsigned int pixel;
        /* packing */
        for (int i = 0; i < width * height; ++i) {
            pixel = 0xff << 24 | blue << 16 | green << 8 | red;
            pixel_map[i] = pixel;
        }
    }
    else if (ch == 'P6') { //full-color 
        ++ch;
        width = ch;
        ++ch;
        height = ch;
        pixel_map = new unsigned int[width * height];

        int blue, green, red, alpha;
        unsigned int pixel;
        /* packing */
        for (int i = 0; i < width * height; ++i) {
            pixel = 0xff << 24 | blue << 16 | green << 8 | red;
            pixel_map[i] = pixel;
        }
    }
    else {
        cout << "Invalid Image Format Exception" << endl;
        exit(1);
    }
}
MyImageClass::~MyImageClass() {
    delete pixel_map;
}
MyImageClass MyImageClass::operator+(const MyImageClass& rhs) {
    MyImageClass temp;
    if (width >= rhs.width) {
        temp.width = width;
    }
    else {
        temp.width = rhs.width;
    }
    if (height >= rhs.height) {
        temp.height = height;
    }
    else {
        temp.height = rhs.height;
    }
    for (int i = 0; i < width * height; ++i) {
        temp.pixel_map[i] = pixel_map[i] + rhs.pixel_map[i];
    }
    return temp;
}
MyImageClass& MyImageClass::operator+=(const MyImageClass& rhs) {
    if (width <= rhs.width) {
        width = rhs.width;
    }
    if (height <= rhs.height) {
        height = rhs.height;
    }
    for (int i = 0; i < width * height; ++i) {
        pixel_map[i] += rhs.pixel_map[i];
    }
    return *this;
}
MyImageClass MyImageClass::operator-(const MyImageClass& rhs) {
    MyImageClass temp;
    if (width >= rhs.width) {
        temp.width = width;
    }
    else {
        temp.width = rhs.width;
    }
    if (height >= rhs.height) {
        temp.height = height;
    }
    else {
        temp.height = rhs.height;
    }
    for (int i = 0; i < width * height; ++i) {
        temp.pixel_map[i] = pixel_map[i] - rhs.pixel_map[i];
    }
    return temp;
}
MyImageClass& MyImageClass::operator-=(const MyImageClass& rhs) {
    if (width <= rhs.width) {
        width = rhs.width;
    }
    if (height <= rhs.height) {
        height = rhs.height;
    }
    for (int i = 0; i < width * height; ++i) {
        pixel_map[i] -= rhs.pixel_map[i];
    }
    return *this;
}
MyImageClass MyImageClass::operator*(const MyImageClass& rhs) {
    MyImageClass temp;
    if (width >= rhs.width) {
        temp.width = width;
    }
    else {
        temp.width = rhs.width;
    }
    if (height >= rhs.height) {
        temp.height = height;
    }
    else {
        temp.height = rhs.height;
    }
    for (int i = 0; i < width * height; ++i) {
        temp.pixel_map[i] = pixel_map[i] * rhs.pixel_map[i];
    }
    return temp;
}
const MyImageClass& MyImageClass::operator[](int index) const {
    return *pixel_map[index];
}