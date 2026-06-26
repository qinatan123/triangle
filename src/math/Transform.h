#pragma once

#include "Mat4.h"
#include "Vec3.h"
#include <cmath>

struct Transform {
    static Mat4 translate(Vec3 position) {
       Mat4 matrix = Mat4::identity();
       matrix.data[12] = position.x;
       matrix.data[13] = position.y;
       matrix.data[14] = position.z;
       return matrix;
    }

    static Mat4 scale(Vec3 scale) {
        Mat4 matrix = Mat4::identity();
        matrix.data[0] = scale.x;
        matrix.data[5] = scale.y;
        matrix.data[10] = scale.z;
        return matrix;
    }

    static Mat4 rotateY(float angle) {
        Mat4 matrix = Mat4::identity();
        float radians = angle * (3.14159265f / 180.0f);
        float cosA = std::cos(radians);
        float sinA = std::sin(radians);

        matrix.data[0] = cosA;
        matrix.data[2] = sinA;
        matrix.data[8] = -sinA;
        matrix.data[10] = cosA;

        return matrix;
    }

    static Mat4 rotateX(float angle) {
        Mat4 m = Mat4::identity();
        float radians = angle * (3.14159265f / 180.0f);
        m.data[5]  =  std::cos(radians);
        m.data[6]  =  std::sin(radians);
        m.data[9]  = -std::sin(radians);
        m.data[10] =  std::cos(radians);
        return m;
    }

    static Mat4 rotateZ(float angle) {
        Mat4 m = Mat4::identity();
        float radians = angle * (3.14159265f / 180.0f);
        float cosA = std::cos(radians);
        float sinA = std::sin(radians);

        m.data[0] = cosA;
        m.data[1] = sinA;
        m.data[4] = -sinA;
        m.data[5] = cosA;

        return m;
    }

    static Mat4 rotate(Vec3 angles) {
        return rotateZ(angles.z) * rotateY(angles.y) * rotateX(angles.x);
    }

    static Mat4 perspective(float fovDeg, float aspect, float near, float far) {
        float fov = fovDeg * (3.14159265f / 180.0f);
        float f = 1.0f / std::tan(fov / 2.0f);
        Mat4 m;
        m.data[0]  = f / aspect;
        m.data[5]  = f;
        m.data[10] = (far + near) / (near - far);
        m.data[11] = -1.0f;
        m.data[14] = (2.0f * far * near) / (near - far);
        return m;
    }
};