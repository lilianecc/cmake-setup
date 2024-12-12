#include "multiply.h"
#include "addition.h"
#include "arh.h"
int main()
{
    Multiply testClass;
    testClass.multiplier(3, 4);
    int result = addition(1, 2);
    int *testPtr=testClass.testPtr(1);
    int msgNum=1;
    unsigned short arr[30]={0};
    unsigned short * arrPtr;
    // arrPtr=arr[30];
    testClass.Get_Msg(msgNum, arr);
    std::cout << "main finished!" << 12345 << std::endl;
    std::cout << "addition result: " << result << std::endl;
    //testing DPRAM stuff
    char *dpramBytes=nullptr;
    enum{
        DPRAM_OFFSET=0x0003FFFF, //decimal: 262143
        MSG_R_QUEUE_PTR_OFFSET=0X0003FF34 //

    };
    int DPRAM_SIZE=(DPRAM_OFFSET+1)*4;//1048576
    dpramBytes=new char[DPRAM_SIZE]; //0x0000023edf9b1040
    memset(dpramBytes, 0, DPRAM_SIZE);
    char greet[1048576];
    memset(greet, 0, 1048576);
    
    int base_addr=atoi(dpramBytes);//(uint_32)dpramBytes
    uint32_t IO_BASE_addr=base_addr;
    uint32_t* MSG_r_READ_PTR;
    MSG_r_READ_PTR=(uint32_t*)(IO_BASE_addr+MSG_R_QUEUE_PTR_OFFSET*4);

    std::cout<<"here"<<std::endl;

    return 0;
}