#pragma once

struct Mat4{
    float data[16] = {0}; 

    static Mat4 identity(){
        Mat4 m;
        m.data[0] = 1.0f;
        m.data[5] = 1.0f;
        m.data[10] = 1.0f;
        m.data[15] = 1.0f;
        return m;
    }
    Mat4 operator*(const Mat4& rhs) const {
        Mat4 result;
        for (int col = 0; col < 4; col++) {
            for (int row = 0; row < 4; row++) {
                float sum = 0.0f;
                for (int k = 0; k < 4; k++) {
                    sum += data[k * 4 + row] * rhs.data[col * 4 + k];
                }
                result.data[col * 4 + row] = sum;
            }
        }
        return result;
    }
    const float* ptr() const { return data; }
}; 