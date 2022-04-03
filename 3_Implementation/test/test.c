#include "unity.h"
#include "canteen.h"

//Required by the test unity framework
void setUp() {}

//Required by the unity framework
void tearDown() {}

void testing_canteen(void)
{
    TEST_ASSERT_EQUAL(6, start(6));
    TEST_ASSERT_EQUAL(5, start(4));
    TEST_ASSERT_EQUAL(1,start(1));
}
void testing_loginpage(void)
{
    TEST_ASSERT_EQUAL(1, loginpage("LTTS","104694"));
    TEST_ASSERT_EQUAL(0, loginpage("LTTS","201459"));
}
void testing_editprice(void)
{
    TEST_ASSERT_EQUAL(1, editprice());
}
void testing_addquantity(void)
{
    TEST_ASSERT_EQUAL(1, addquantity());

}
void testing_viewinventory(void)
{
    TEST_ASSERT_EQUAL(1, viewinventory());
}

int main(void)
{
    //Initiating the unity framework
    UNITY_BEGIN();
    RUN_TEST(testing_canteen);
    RUN_TEST(testing_loginpage);
    RUN_TEST(testing_editprice);
    RUN_TEST(testing_addquantity);
    RUN_TEST(testing_viewinventory);
    return UNITY_END();
}
