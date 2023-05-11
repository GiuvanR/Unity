#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP_RUNNER(Sort)
{
  RUN_TEST_CASE(Sort, LimiteInferiorDentro);
  RUN_TEST_CASE(Sort, LimiteInferiorFora);
  RUN_TEST_CASE(Sort, LimiteSuperiorDentro);
  RUN_TEST_CASE(Sort, LimiteSuperiorFora);
  RUN_TEST_CASE(Sort, ValorIntermediarioLength);
  RUN_TEST_CASE(Sort, TypeErradoCounting);
}
