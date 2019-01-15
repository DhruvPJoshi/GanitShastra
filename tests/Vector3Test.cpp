#include <cmath>

#include "CppUTest/TestHarness.h"
#include "Vector3.hpp"

#define THRESHOLD 0.0001

TEST_GROUP(InitVec3)
{
};

TEST(InitVec3, IntValue)
{
    int x = 3, y = 4, z = 13;
    gs::Vector3 vec(x, y, z);
    LONGS_EQUAL(x, vec.x);
    LONGS_EQUAL(y, vec.y);
    LONGS_EQUAL(z, vec.z);
};

TEST(InitVec3, FloatValue)
{
    float x = 3.77, y = 4.55, z = 13.76;
    gs::Vector3 vec(x, y, z);
    DOUBLES_EQUAL(x, vec.x, THRESHOLD);
    DOUBLES_EQUAL(y, vec.y, THRESHOLD);
    DOUBLES_EQUAL(z, vec.z, THRESHOLD);
};

TEST_GROUP(VectorOperations)
{
    gs::Vector3 *vec1, *vec2;
    gs::Vector3 vec;

    void setup()
    {
        vec1 = new gs::Vector3(3.77, 4.55, 13.76);
        vec2 = new gs::Vector3(2.23, 3.45, 6.24);
    }

    void teardown()
    {
        delete vec1;
        delete vec2;
    }
};

TEST(VectorOperations, AdditionVec)
{
    vec = *vec1 + *vec2;
    DOUBLES_EQUAL(vec1->x + vec2->x, vec.x, THRESHOLD);
    DOUBLES_EQUAL(vec1->y + vec2->y, vec.y, THRESHOLD);
    DOUBLES_EQUAL(vec1->z + vec2->z, vec.z, THRESHOLD);
};

TEST(VectorOperations, SubtractVec)
{
    vec = *vec1 - *vec2;
    DOUBLES_EQUAL(vec1->x - vec2->x, vec.x, THRESHOLD);
    DOUBLES_EQUAL(vec1->y - vec2->y, vec.y, THRESHOLD);
    DOUBLES_EQUAL(vec1->z - vec2->z, vec.z, THRESHOLD);
};

TEST(VectorOperations, DivideVec)
{
    float divisor = 7.38;
    vec = *vec1 / divisor;
    DOUBLES_EQUAL(vec1->x / divisor, vec.x, THRESHOLD);
    DOUBLES_EQUAL(vec1->y / divisor, vec.y, THRESHOLD);
    DOUBLES_EQUAL(vec1->z / divisor, vec.z, THRESHOLD);
};

TEST_GROUP(VectorOperationsShortHand)
{
    gs::Vector3 *vec1, *vec2;
    gs::Vector3 vec;

    void setup()
    {
        vec1 = new gs::Vector3();
        vec2 = new gs::Vector3(12.3, 93.2, 102.89);
        vec = *vec1;
    }

    void teardown()
    {
        delete vec1;
        delete vec2;
    }
};

TEST(VectorOperationsShortHand, AdditionShortHand)
{
    *vec1 += *vec2;
    DOUBLES_EQUAL(vec.x + vec2->x, vec1->x, THRESHOLD);
    DOUBLES_EQUAL(vec.y + vec2->y, vec1->y, THRESHOLD);
    DOUBLES_EQUAL(vec.z + vec2->z, vec1->z, THRESHOLD);
};

TEST(VectorOperationsShortHand, SubtractShortHand)
{
    *vec1 -= *vec2;
    DOUBLES_EQUAL(vec.x - vec2->x, vec1->x, THRESHOLD);
    DOUBLES_EQUAL(vec.y - vec2->y, vec1->y, THRESHOLD);
    DOUBLES_EQUAL(vec.z - vec2->z, vec1->z, THRESHOLD);
};

TEST(VectorOperationsShortHand, DivideShortHand)
{
    float divisor = 2.12;
    vec = *vec2;
    *vec2 /= divisor;
    DOUBLES_EQUAL(vec.x / divisor, vec2->x, THRESHOLD);
    DOUBLES_EQUAL(vec.y / divisor, vec2->y, THRESHOLD);
    DOUBLES_EQUAL(vec.z / divisor, vec2->z, THRESHOLD);
};

TEST_GROUP(VectorOperationsScalarProduct)
{
    gs::Vector3 vec, *vec1;

    void setup() {
        vec1 = new gs::Vector3(23.40, 39.942, 251.8993);
    }

    void teardown() {
        delete vec1;
    }
};

TEST(VectorOperationsScalarProduct, ScalarMultiplicationBinary)
{
    float multiplicant = 12.83;
    vec = *vec1 * multiplicant;
    DOUBLES_EQUAL(vec1->x * multiplicant, vec.x, THRESHOLD);
    DOUBLES_EQUAL(vec1->y * multiplicant, vec.y, THRESHOLD);
    DOUBLES_EQUAL(vec1->z * multiplicant, vec.z, THRESHOLD);
};

TEST(VectorOperationsScalarProduct, ScalarMultiplicationShortHand)
{
    float multiplicant = 4.82;
    vec = *vec1;
    *vec1 *= multiplicant;
    DOUBLES_EQUAL(vec.x * multiplicant, vec1->x, THRESHOLD);
    DOUBLES_EQUAL(vec.y * multiplicant, vec1->y, THRESHOLD);
    DOUBLES_EQUAL(vec.z * multiplicant, vec1->z, THRESHOLD);
};

TEST_GROUP(VectorOperationsDotProduct)
{
    gs::Vector3 *vec1, *vec2;
    float result;

    void setup() {
        vec1 = new gs::Vector3(14.48, 23.81, 32.92);
        vec2 = new gs::Vector3(3, 1.323, 24.21);
    }

    void teardown() {
        delete vec1;
        delete vec2;
    }
};

TEST(VectorOperationsDotProduct, UsingDotOperator)
{
    result = *vec1 * *vec2;
    DOUBLES_EQUAL(result, (vec1->x * vec2->x
                         + vec1->y * vec2->y
                         + vec1->z * vec2->z), THRESHOLD);
};

TEST(VectorOperationsDotProduct, UsingMethodCall)
{
    result = vec1->dot(*vec2);
    DOUBLES_EQUAL(result, (vec1->x * vec2->x
                         + vec1->y * vec2->y
                         + vec1->z * vec2->z), THRESHOLD);
};

TEST_GROUP(VectorOperationsCrossProduct)
{
    gs::Vector3 *vec1, *vec2, vec;

    void setup() {
        vec1 = new gs::Vector3(4.8, 2.1, 9.36);
        vec2 = new gs::Vector3(2, 9, 7);
    }

    void teardown() {
        delete vec1;
        delete vec2;
    }
};

TEST(VectorOperationsCrossProduct, WithCrossProductOperator)
{
    vec = *vec1 % *vec2;
    DOUBLES_EQUAL((vec1->y * vec2->z) - (vec1->z * vec2->y), vec.x, THRESHOLD);
    DOUBLES_EQUAL((vec1->z * vec2->x) - (vec1->x * vec2->z), vec.y, THRESHOLD);
    DOUBLES_EQUAL((vec1->x * vec2->y) - (vec1->y * vec2->x), vec.z, THRESHOLD);
};

TEST(VectorOperationsCrossProduct, WithShortHandCrossProduct)
{
    vec = *vec1;
    *vec1 %= *vec2;
    DOUBLES_EQUAL((vec.y * vec2->z) - (vec.z * vec2->y), vec1->x, THRESHOLD);
    DOUBLES_EQUAL((vec.z * vec2->x) - (vec.x * vec2->z), vec1->y, THRESHOLD);
    DOUBLES_EQUAL((vec.x * vec2->y) - (vec.y * vec2->x), vec1->z, THRESHOLD);
};

TEST(VectorOperationsCrossProduct, WithCrossProductMethod)
{
    vec = vec1->cross(*vec2);
    DOUBLES_EQUAL((vec1->y * vec2->z) - (vec1->z * vec2->y), vec.x, THRESHOLD);
    DOUBLES_EQUAL((vec1->z * vec2->x) - (vec1->x * vec2->z), vec.y, THRESHOLD);
    DOUBLES_EQUAL((vec1->x * vec2->y) - (vec1->y * vec2->x), vec.z, THRESHOLD);
};

TEST_GROUP(VectorOperationsSpecial)
{
    gs::Vector3 vec, *vec1;

    void setup() {
        vec1 = new gs::Vector3(94.33, 18.324, 814.3);
    }

    void teardown() {
        delete vec1;
    }
};

TEST(VectorOperationsSpecial, FindVectorMagnitude)
{
    float magnitude = vec1->magnitude();
    DOUBLES_EQUAL(std::sqrt(vec1->x * vec1->x
                          + vec1->y * vec1->y
                          + vec1->z * vec1->z), magnitude, THRESHOLD);
};

TEST(VectorOperationsSpecial, NormalizeVector)
{
    vec = *vec1;
    vec1->normalize();
    float oneOverMagnitude = 1.0f / vec.magnitude();
    DOUBLES_EQUAL(vec.x * oneOverMagnitude, vec1->x, THRESHOLD);
    DOUBLES_EQUAL(vec.y * oneOverMagnitude, vec1->y, THRESHOLD);
    DOUBLES_EQUAL(vec.z * oneOverMagnitude, vec1->z, THRESHOLD);
};