#include "multiply.h"
#include "addition.h"
#include "arh.h"
int main()
{
    Multiply testClass;
    testClass.multiplier(3, 4);
    int result = addition(1, 2);
    int msgNum=1;
    unsigned short arr[30]={0};
    unsigned short * arrPtr;
    // arrPtr=arr[30];
    testClass.Get_Msg(msgNum, arr);
    std::cout << "main finished!" << testClass.result << std::endl;
    std::cout << "addition result: " << result << std::endl;
    return 0;
}