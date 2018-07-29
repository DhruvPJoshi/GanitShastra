#include <iostream>
#include "Vector3.hpp"

int main()
{
    gs::Vector3 vec1(1.0, 2.0, 3.0);
    std::cout << "Vector1: ";
    vec1.Show();
    gs::Vector3 vec2(4.0, 5.0, 6.0);
    std::cout << "Vector2: ";
    vec2.Show();

    std::cout << "===== Addition =====" << std::endl;
    gs::Vector3 vec3 = vec1 + vec2;
    std::cout << "Vector3: ";
    vec3.Show();

    vec1 += vec2;
    std::cout << "Vector1: ";
    vec1.Show();

    std::cout << "===== Subtraction =====" << std::endl;
    vec3 -= vec2;
    std::cout << "Vector3: ";
    vec3.Show();

    vec2 = vec3 - vec1;
    std::cout << "Vector2: ";
    vec2.Show();
    
    std::cout << "===== Multiplication =====" << std::endl;
    vec1 = gs::Vector3(3, 2, 1);
    vec2 = gs::Vector3(1, 2, 0);

    vec3 = vec2 * 5.0;
    std::cout << "Vector3: ";
    vec3.Show();

    vec1 *= 7.0;
    std::cout << "Vector1: ";
    vec1.Show();

    std::cout << "===== Division =====" << std::endl;
    gs::Vector3 vec4 = vec2 / 5.0;
    std::cout << "Vector4: ";
    vec4.Show();

    vec2 /= 7.0;
    std::cout << "Vector2: ";
    vec2.Show();

    std::cout << "===== Dot product =====" << std::endl;
    vec1 = gs::Vector3(2, 3, 1);
    vec2 = gs::Vector3(1, 2, 0);
    float dotProduct = vec1.dot(vec2);
    std::cout << dotProduct << std::endl;
    dotProduct = vec1 * vec2;
    std::cout << dotProduct << std::endl;

    std::cout << "===== Cross product =====" << std::endl;
    vec3 = vec1.cross(vec2);
    std::cout << "Vector3: ";
    vec3.Show();
    vec4 = vec1 % vec2;
    std::cout << "Vector4: ";
    vec4.Show();
    vec1 %= vec2;
    std::cout << "Vector1: ";
    vec1.Show();

    return 0;
}