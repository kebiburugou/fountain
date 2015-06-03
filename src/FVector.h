#ifndef FVECTOR_H
#define FVECTOR_H

#include <GL\glut.h>

#define PI 3.1415926535897932384626433832795f
#define PIdiv180 PI/180.0f

class FVector3 { //Float 3d-vect, normally used
public:
    FVector3(GLfloat x = 0.0, GLfloat y = 0.0, GLfloat z = 0.0) {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    GLfloat length() const;
    FVector3 normalize() const;

    FVector3 cross(const FVector3 &other) const;    
    FVector3 operator+ (const FVector3 &other) const;
    FVector3 operator- (const FVector3 &other) const;
    GLfloat operator* (const FVector3 &other) const;
    FVector3 operator* (const float r) const;
    FVector3 operator/ (const float r) const;

    void addBy(const FVector3 &other);
    FVector3 & operator= (const FVector3 &other);
    void set(GLfloat x = 0.0, GLfloat y = 0.0, GLfloat z = 0.0) {
        this->x = x;
        this->y = y;
        this->z = z;
    }
    GLfloat x, y, z;
};

#endif