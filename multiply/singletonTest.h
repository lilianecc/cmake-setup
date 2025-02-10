#ifndef SINGLETONTEST_H
#define SINGLETONTEST_H
class singletonTest
{
public:
    singletonTest(const singletonTest &obj) = delete;//Prevent copy construction
    singletonTest& operator=(const singletonTest&)=delete; // Prevent assignment
    static singletonTest &getInstance()  // if want to do it in the pointer way, then it's singletonTest* getInstance()
    {
        // if (instancePtr == nullptr)
        // {
        //     instancePtr = new singletonTest();
        // }
        static singletonTest instance;
        return instance;
    };
    void multiplier(int a, int b);
    int getLocalValue();

private:
    
    singletonTest() ;//{};
    int localValue;
};

#endif