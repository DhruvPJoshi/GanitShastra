#include "CppUTest/TestHarness.h"
#include "Vector3.hpp"

TEST_GROUP(InitVec3)
{
};

TEST(InitVec3, IntValue)
{
    gs::Vector3 vec(3, 4, 13);
    LONGS_EQUAL(3, vec.x);
    LONGS_EQUAL(4, vec.y);
    LONGS_EQUAL(13, vec.z);
};

TEST(InitVec3, FloatValue)
{
    gs::Vector3 vec(3.77, 4.55, 13.76);
    DOUBLES_EQUAL(3.77, vec.x, 0.0001);
    DOUBLES_EQUAL(4.55, vec.y, 0.0001);
    DOUBLES_EQUAL(13.76, vec.z, 0.0001);
};

TEST_GROUP(VecOperations)
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

TEST(VecOperations, AddVec)
{
    vec = *vec1 + *vec2;
    DOUBLES_EQUAL(vec1->x + vec2->x, vec.x, 0.0001);
    DOUBLES_EQUAL(vec1->y + vec2->y, vec.y, 0.0001);
    DOUBLES_EQUAL(vec1->z + vec2->z, vec.z, 0.0001);
};

TEST(VecOperations, SubtractVec)
{
    vec = *vec1 - *vec2;
    DOUBLES_EQUAL(vec1->x - vec2->x, vec.x, 0.0001);
    DOUBLES_EQUAL(vec1->y - vec2->y, vec.y, 0.0001);
    DOUBLES_EQUAL(vec1->z - vec2->z, vec.z, 0.0001);
};