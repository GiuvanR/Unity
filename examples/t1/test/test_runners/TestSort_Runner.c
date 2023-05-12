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
  //RUN_TEST_CASE(Sort, LengthMaiorQueVetor);
  RUN_TEST_CASE(Sort, LengthMenorQueVetor);
 
  RUN_TEST_CASE(Sort, ListaVaziaCounting);
  RUN_TEST_CASE(Sort, ListaVaziaRadix);
  RUN_TEST_CASE(Sort, ListaVaziaBubble);
  RUN_TEST_CASE(Sort, ListaVaziaInsertion);
  RUN_TEST_CASE(Sort, ListaVaziaSelection);
  RUN_TEST_CASE(Sort, ListaVaziaHeap);
  RUN_TEST_CASE(Sort, ListaVaziaMerge);
  RUN_TEST_CASE(Sort, ListaVaziaQuick);

  RUN_TEST_CASE(Sort, ListaComValorRepetidoCounting);
  RUN_TEST_CASE(Sort, ListaComValorRepetidoRadix);
  RUN_TEST_CASE(Sort, ListaComValorRepetidoBubble);
  RUN_TEST_CASE(Sort, ListaComValorRepetidoInsertion);
  RUN_TEST_CASE(Sort, ListaComValorRepetidoSelection);
  RUN_TEST_CASE(Sort, ListaComValorRepetidoHeap);
  RUN_TEST_CASE(Sort, ListaComValorRepetidoMerge);
  RUN_TEST_CASE(Sort, ListaComValorRepetidoQuick);

  RUN_TEST_CASE(Sort, ListaComValorUnicoCounting);
  RUN_TEST_CASE(Sort, ListaComValorUnicoRadix);
  RUN_TEST_CASE(Sort, ListaComValorUnicoBubble);
  RUN_TEST_CASE(Sort, ListaComValorUnicoInsertion);
  RUN_TEST_CASE(Sort, ListaComValorUnicoSelection);
  RUN_TEST_CASE(Sort, ListaComValorUnicoHeap);
  RUN_TEST_CASE(Sort, ListaComValorUnicoMerge);
  RUN_TEST_CASE(Sort, ListaComValorUnicoQuick);

  
}
