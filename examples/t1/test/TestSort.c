#include "sort.h"
#include "unity.h"
#include "unity_fixture.h"


TEST_GROUP(Sort);

TEST_SETUP(Sort)
{
}

TEST_TEAR_DOWN(Sort)
{
}

TEST(Sort, LimiteInferiorDentro)
{
    int b[] = {22, 17};
    int b1[] = {17, 22};
    TEST_ASSERT_EQUAL(0, sort(b, 2, (char *)"On", COUNTING));
    TEST_ASSERT_EQUAL_INT32_ARRAY(b1, b, 2);
}