#include <addition.h>
#include <gtest/gtest.h>

class AdditionTest : public ::testing::Test
{
public:
};
// test internal member value
TEST_F(AdditionTest, testone)
{
    const auto expected = 6;
    // const auto actual = 1;
    int temp=addition(3,4);
    int res=3+4;
    EXPECT_EQ(res,temp);
    std::cout << "additional test complete: " << std::endl;
}