#include <stdio.h>

#include "vector3.h"

int main()
{
    Vector3<float> v1(3.0f, 3.0f, 3.0f);
    Vector3<float> v2(-3.0f, -3.0f, -3.0f);
    Vector3<float> v3 = Vector3<float>::add(v1, v2);
    printf("v3: %f, %f, %f\n", v3.getX(), v3.getY(), v3.getZ());
}
