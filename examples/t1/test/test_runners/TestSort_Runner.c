#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP_RUNNER(Sort)
{
  RUN_TEST_CASE(Sort, LimiteInferiorDentro);
  RUN_TEST_CASE(Sort, LimiteInferiorFora);
  RUN_TEST_CASE(Sort, LimiteSuperiorDentro);
}
