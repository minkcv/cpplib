#include "memstack.h"
#include <stdio.h>
#include <new>

// These are meaningless containers
// for demonstration purposes.
class TestClass
{
    public:
        TestClass();
        int testInt;
        double testDouble;
        int* testPointer;
        ~TestClass();
};
TestClass::TestClass(){};

class TestClass2 : public TestClass
{
    public:
        TestClass2();
        short testShort;
        ~TestClass2();
};
TestClass2::TestClass2(){};

int main()
{
    MemStack m;
    printf("size of TestClass: %zu bytes\n", sizeof(TestClass));
    void* testObjAddress = m.push(sizeof(TestClass));
    printf("address of test object: %p\n", testObjAddress);
    TestClass* testObj = new(testObjAddress) TestClass();
    testObj->testInt = 5;
    testObj->testPointer = &(testObj->testInt);
    printf("test object int: %d\n", *(testObj->testPointer));
    printf("size of TestClass2: %zu bytes\n", sizeof(TestClass2));
    void* testObjAddress2 = m.push(sizeof(TestClass2));
    TestClass2* testObj2 = new(testObjAddress2) TestClass2();
    printf("pop test object 2\n");
    m.pop();
    testObj2 = nullptr;
    testObjAddress = nullptr;

    printf("allocating space for 10 TestClass2s (%zu bytes)\n", 10 * sizeof(TestClass2));
    for (int i = 0; i < 10; i++)
    {
        TestClass2* t2 = new(m.push(sizeof(TestClass2))) TestClass2();
        t2->testShort = i;
        printf("test short of test object in loop: %d\n", t2->testShort);
    }
    printf("letting the garbage collector pop the remaining data\n");
}
