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
  RUN_TEST_CASE(Sort, TestRadixCorreto);
  RUN_TEST_CASE(Sort, TypeErradoRadix);
  RUN_TEST_CASE(Sort, TestBubbleCorreto);
  RUN_TEST_CASE(Sort, TypeErradoBubble);
  RUN_TEST_CASE(Sort, TestInsertionCorreto);
  RUN_TEST_CASE(Sort, TypeErradoInsertion);
  RUN_TEST_CASE(Sort, TestSelectionCorreto);
  RUN_TEST_CASE(Sort, TypeErradoSelection);
  RUN_TEST_CASE(Sort, TestHeapCorreto);
  RUN_TEST_CASE(Sort, TypeErradoHeap);
  RUN_TEST_CASE(Sort, TestMergeCorreto);
  RUN_TEST_CASE(Sort, TypeErradoMerge);
  RUN_TEST_CASE(Sort, TestQuickCorreto);
  RUN_TEST_CASE(Sort, TypeErradoQuick);
  RUN_TEST_CASE(Sort, TestDefault);
}
