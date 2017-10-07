# A memory stack in C++

This data structure allows for using pre allocated memory for dynamically allocated objects.

Instead of doing:

    TestClass* t = new TestClass();

Which would slowly go to the operating system for memory,
We can use placement new to do this:

    void* addr = memstack.push(sizeof(TestClass));
    TestClass* t = new(addr) TestClass();

Which will be much faster. 

You will still need to be careful with your pointers and can only reclaim your
used memory in the reverse of the order that you reserved it.
