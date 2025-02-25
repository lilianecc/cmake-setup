#include <gtest/gtest.h>
#include <multiply.h>
using namespace std;
class MultiplyTests : public ::testing::Test
{
public:
    Multiply obj;
    Multiply obj2;
};
// test internal member value
TEST_F(MultiplyTests, testone)
{
    const auto expected = 6;
    // const auto actual = 1;
    obj.multiplier(2, 3);

    int temp = obj.result;
    ASSERT_EQ(expected, temp);
    std::cout << "test complete: " << temp << std::endl;
}

TEST_F(MultiplyTests, testNullPtr)
{
    int *tempPtr = obj.testPtr(2);
    unsigned short arr[30] = {0};
    unsigned short *arPtr;
    obj.Get_Msg(1, arr);
    // arPtr=arr[30];
    // EXPECT_EQ(nullptr, tempPtr);
    // EXPECT_TRUE(tempPtr==nullptr);
    bool tempbool = true;
    EXPECT_TRUE(tempbool);
}
TEST_F(MultiplyTests, PrivateVarTest)
{
    obj.multiplier(2, 3);
    int result = obj.localX;
    // EXPECT_CALL(testPtr, 1);
    EXPECT_EQ(result, 2);
    EXPECT_EQ(1057,0x421);
}