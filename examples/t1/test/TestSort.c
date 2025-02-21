#include "../src/sort.h"
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

TEST(Sort, LimiteInferiorFora)
{
  int c[] = {13};
  int c1[] = {13};
  TEST_ASSERT_EQUAL(1, sort(c, 1, (char *)"On", COUNTING));
  TEST_ASSERT_EQUAL_INT32_ARRAY(c1, c, 1);
}

TEST(Sort, LimiteSuperiorDentro)
{
  int d[] = {7, 8, 20, 3, 19, 15, 17, 2, 6, 384, 495, 4, 1, 1000, 8945, 5, 0, 1968, 15000, 9};
  int d1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 15, 17, 19, 20, 384, 495, 1000, 1968, 8945, 15000};
  TEST_ASSERT_EQUAL(0, sort(d, 20, (char *)"On", COUNTING));
  TEST_ASSERT_EQUAL_INT32_ARRAY(d1, d, 20);
}


TEST(Sort, LimiteSuperiorFora)
{
  int e[] = {7, 8, 20, 3, 19, 15, 17, 2, 6, 384, 495, 4, 1, 1000, 8945, 5, 0, 1968, 15000, 9, 47};
  TEST_ASSERT_EQUAL(1, sort(e, 21, (char *)"On", COUNTING));
}

TEST(Sort, ValorIntermediarioLength)
{
  int a[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
  int a1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  TEST_ASSERT_EQUAL(0, sort(a, 10, (char *)"On", COUNTING));
  TEST_ASSERT_EQUAL_INT32_ARRAY(a1, a, 10);
}

TEST(Sort, TypeErradoCounting)
{
  int a[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
  TEST_ASSERT_EQUAL(1, sort(a, 10, (char *)"On2", COUNTING));
}

TEST(Sort, TestRadixCorreto)
{
  int a[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
  int a1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  TEST_ASSERT_EQUAL(0, sort(a, 10, (char *)"On", RADIX));
  TEST_ASSERT_EQUAL_INT32_ARRAY(a1, a, 10);
}

TEST(Sort, TypeErradoRadix)
{
  int a[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
  TEST_ASSERT_EQUAL(1, sort(a, 10, (char *)"Onlogn", RADIX));
}

TEST(Sort, TestBubbleCorreto)
{
  int d[] = {7, 8, 20, 3, 19, 15, 17, 2, 6, 384, 495, 4, 1, 1000, 8945, 5, 0, 1968, 15000, 9};
  int d1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 15, 17, 19, 20, 384, 495, 1000, 1968, 8945, 15000};
  TEST_ASSERT_EQUAL(0, sort(d, 20, (char *)"On2", BUBBLE));
  TEST_ASSERT_EQUAL_INT32_ARRAY(d1, d, 20);
}

TEST(Sort, TypeErradoBubble)
{
  int d[] = {7, 8, 20, 3, 19, 15, 17, 2, 6, 384, 495, 4, 1, 1000, 8945, 5, 0, 1968, 15000, 9};
  TEST_ASSERT_EQUAL(1, sort(d, 20, (char *)"On", BUBBLE));
}


TEST(Sort, TestInsertionCorreto)
{
  int a[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
  int a1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  TEST_ASSERT_EQUAL(0, sort(a, 10, (char *)"On2", INSERTION));
  TEST_ASSERT_EQUAL_INT32_ARRAY(a1, a, 10);
}

TEST(Sort, TypeErradoInsertion)
{
  int a[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
  TEST_ASSERT_EQUAL(1, sort(a, 10, (char *)"Onlogn", INSERTION));
}

TEST(Sort, TestSelectionCorreto)
{
  int a[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
  int a1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  TEST_ASSERT_EQUAL(0, sort(a, 10, (char *)"On2", SELECTION));
  TEST_ASSERT_EQUAL_INT32_ARRAY(a1, a, 10);
}

TEST(Sort, TypeErradoSelection)
{
  int a[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
  TEST_ASSERT_EQUAL(1, sort(a, 10, (char *)"On", SELECTION));
}

TEST(Sort, TestHeapCorreto)
{
  int a[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
  int a1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  TEST_ASSERT_EQUAL(0, sort(a, 10, (char *)"Onlogn", HEAP));
  TEST_ASSERT_EQUAL_INT32_ARRAY(a1, a, 10);
}

TEST(Sort, TypeErradoHeap)
{
  int a[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
  TEST_ASSERT_EQUAL(1, sort(a, 10, (char *)"On", HEAP));
}

TEST(Sort, TestMergeCorreto)
{
  int a[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
  int a1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  TEST_ASSERT_EQUAL(0, sort(a, 10, (char *)"Onlogn", MERGE));
  TEST_ASSERT_EQUAL_INT32_ARRAY(a1, a, 10);
}

TEST(Sort, TypeErradoMerge)
{
  int a[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
  TEST_ASSERT_EQUAL(1, sort(a, 10, (char *)"On2", MERGE));
}

TEST(Sort, TestQuickCorreto)
{
  int a[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
  int a1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  TEST_ASSERT_EQUAL(0, sort(a, 10, (char *)"Onlogn", QUICK));
  TEST_ASSERT_EQUAL_INT32_ARRAY(a1, a, 10);
}

TEST(Sort, TypeErradoQuick)
{
  int a[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
  TEST_ASSERT_EQUAL(1, sort(a, 10, (char *)"On", QUICK));
}

TEST(Sort, TestDefault)
{
  int a[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
  TEST_ASSERT_EQUAL(1, sort(a, 10, (char *)"On", 9));
}

TEST(Sort, LengthMaiorQueVetor)
{
  int b[] = {22, 17};
  int b1[] = {17, 22};
  TEST_ASSERT_EQUAL(0, sort(b, 15, (char *)"On", COUNTING));
  TEST_ASSERT_EQUAL_INT32_ARRAY(b1, b, 2);
}

TEST(Sort, LengthMenorQueVetor)
{
  int d[] = {7, 8, 20, 3, 19, 15, 17, 2, 6, 384, 495, 4, 1, 1000, 8945, 5, 0, 1968, 15000, 9};
  TEST_ASSERT_EQUAL(0, sort(d, 2, (char *)"On", COUNTING));
}

TEST(Sort, ListaVaziaCounting){
  int j[] = {};
  TEST_ASSERT_EQUAL(1, sort(j, 0, (char *)"On", COUNTING));
}

TEST(Sort, ListaVaziaRadix){
  int j[] = {};
  TEST_ASSERT_EQUAL(1, sort(j, 0, (char *)"On", RADIX));
}

TEST(Sort, ListaVaziaBubble){
  int j[] = {};
  TEST_ASSERT_EQUAL(1, sort(j, 0, (char *)"On2", BUBBLE));
}

TEST(Sort, ListaVaziaInsertion){
  int j[] = {};
  TEST_ASSERT_EQUAL(1, sort(j, 0, (char *)"On2", INSERTION));
}

TEST(Sort, ListaVaziaSelection){
  int j[] = {};
  TEST_ASSERT_EQUAL(1, sort(j, 0, (char *)"On2", SELECTION));
}

TEST(Sort, ListaVaziaHeap){
  int j[] = {};
  TEST_ASSERT_EQUAL(1, sort(j, 0, (char *)"Onlogn", HEAP));
}

TEST(Sort, ListaVaziaMerge){
  int j[] = {};
  TEST_ASSERT_EQUAL(1, sort(j, 0, (char *)"Onlogn", MERGE));
}

TEST(Sort, ListaVaziaQuick){
  int j[] = {};
  TEST_ASSERT_EQUAL(1, sort(j, 0, (char *)"Onlogn", QUICK));
}

TEST(Sort, ListaComValorRepetidoCounting){
  int l[] = {32000, 0, 0, 32000, 74};
  int l1[] = {0, 0, 74, 32000, 32000};
  TEST_ASSERT_EQUAL(0, sort(l, 5, (char *)"On", COUNTING));
  TEST_ASSERT_EQUAL_INT32_ARRAY(l1, l, 5);
}

TEST(Sort, ListaComValorRepetidoRadix){
  int l[] = {32000, 0, 0, 32000, 74};
  int l1[] = {0, 0, 74, 32000, 32000};
  TEST_ASSERT_EQUAL(0, sort(l, 5, (char *)"On", RADIX));
  TEST_ASSERT_EQUAL_INT32_ARRAY(l1, l, 5);
}

TEST(Sort, ListaComValorRepetidoBubble){
  int l[] = {32000, 0, 0, 32000, 74};
  int l1[] = {0, 0, 74, 32000, 32000};
  TEST_ASSERT_EQUAL(0, sort(l, 5, (char *)"On2", BUBBLE));
  TEST_ASSERT_EQUAL_INT32_ARRAY(l1, l, 5);
}

TEST(Sort, ListaComValorRepetidoInsertion){
  int l[] = {32000, 0, 0, 32000, 74};
  int l1[] = {0, 0, 74, 32000, 32000};
  TEST_ASSERT_EQUAL(0, sort(l, 5, (char *)"On2", INSERTION));
  TEST_ASSERT_EQUAL_INT32_ARRAY(l1, l, 5);
}

TEST(Sort, ListaComValorRepetidoSelection){
  int l[] = {32000, 0, 0, 32000, 74};
  int l1[] = {0, 0, 74, 32000, 32000};
  TEST_ASSERT_EQUAL(0, sort(l, 5, (char *)"On2", SELECTION));
  TEST_ASSERT_EQUAL_INT32_ARRAY(l1, l, 5);
}

TEST(Sort, ListaComValorRepetidoHeap){
  int l[] = {32000, 0, 0, 32000, 74};
  int l1[] = {0, 0, 74, 32000, 32000};
  TEST_ASSERT_EQUAL(0, sort(l, 5, (char *)"Onlogn", HEAP));
  TEST_ASSERT_EQUAL_INT32_ARRAY(l1, l, 5);
}

TEST(Sort, ListaComValorRepetidoMerge){
  int l[] = {32000, 0, 0, 32000, 74};
  int l1[] = {0, 0, 74, 32000, 32000};
  TEST_ASSERT_EQUAL(0, sort(l, 5, (char *)"Onlogn", MERGE));
  TEST_ASSERT_EQUAL_INT32_ARRAY(l1, l, 5);
}

TEST(Sort, ListaComValorRepetidoQuick){
  int l[] = {32000, 0, 0, 32000, 74};
  int l1[] = {0, 0, 74, 32000, 32000};
  TEST_ASSERT_EQUAL(0, sort(l, 5, (char *)"Onlogn", QUICK));
  TEST_ASSERT_EQUAL_INT32_ARRAY(l1, l, 5);
}

TEST(Sort, ListaComValorUnicoCounting){
  int m[] = {150, 150, 150, 150, 150};
  int m1[] = {150, 150, 150, 150, 150};
  TEST_ASSERT_EQUAL(0, sort(m, 5, (char *)"On", COUNTING));
  TEST_ASSERT_EQUAL_INT32_ARRAY(m1, m, 5);
}

TEST(Sort, ListaComValorUnicoRadix){
  int m[] = {150, 150, 150, 150, 150};
  int m1[] = {150, 150, 150, 150, 150};
  TEST_ASSERT_EQUAL(0, sort(m, 5, (char *)"On", RADIX));
  TEST_ASSERT_EQUAL_INT32_ARRAY(m1, m, 5);
}

TEST(Sort, ListaComValorUnicoBubble){
  int m[] = {150, 150, 150, 150, 150};
  int m1[] = {150, 150, 150, 150, 150};
  TEST_ASSERT_EQUAL(0, sort(m, 5, (char *)"On2", BUBBLE));
  TEST_ASSERT_EQUAL_INT32_ARRAY(m1, m, 5);
}

TEST(Sort, ListaComValorUnicoInsertion){
  int m[] = {150, 150, 150, 150, 150};
  int m1[] = {150, 150, 150, 150, 150};
  TEST_ASSERT_EQUAL(0, sort(m, 5, (char *)"On2", INSERTION));
  TEST_ASSERT_EQUAL_INT32_ARRAY(m1, m, 5);
}

TEST(Sort, ListaComValorUnicoSelection){
  int m[] = {150, 150, 150, 150, 150};
  int m1[] = {150, 150, 150, 150, 150};
  TEST_ASSERT_EQUAL(0, sort(m, 5, (char *)"On2", SELECTION));
  TEST_ASSERT_EQUAL_INT32_ARRAY(m1, m, 5);
}

TEST(Sort, ListaComValorUnicoHeap){
  int m[] = {150, 150, 150, 150, 150};
  int m1[] = {150, 150, 150, 150, 150};
  TEST_ASSERT_EQUAL(0, sort(m, 5, (char *)"Onlogn", HEAP));
  TEST_ASSERT_EQUAL_INT32_ARRAY(m1, m, 5);
}

TEST(Sort, ListaComValorUnicoMerge){
  int m[] = {150, 150, 150, 150, 150};
  int m1[] = {150, 150, 150, 150, 150};
  TEST_ASSERT_EQUAL(0, sort(m, 5, (char *)"Onlogn", MERGE));
  TEST_ASSERT_EQUAL_INT32_ARRAY(m1, m, 5);
}

TEST(Sort, ListaComValorUnicoQuick){
  int m[] = {150, 150, 150, 150, 150};
  int m1[] = {150, 150, 150, 150, 150};
  TEST_ASSERT_EQUAL(0, sort(m, 5, (char *)"Onlogn", QUICK));
  TEST_ASSERT_EQUAL_INT32_ARRAY(m1, m, 5);
}

TEST(Sort, ListaOrdenadaCounting){
  int n[] = {0, 1, 2, 3, 4};
  int n1[] = {0, 1, 2, 3, 4};
  TEST_ASSERT_EQUAL(0, sort(n, 5, (char *)"On", COUNTING));
  TEST_ASSERT_EQUAL_INT32_ARRAY(n1, n, 5);
}

TEST(Sort, ListaOrdenadaRadix){
  int n[] = {0, 1, 2, 3, 4};
  int n1[] = {0, 1, 2, 3, 4};
  TEST_ASSERT_EQUAL(0, sort(n, 5, (char *)"On", RADIX));
  TEST_ASSERT_EQUAL_INT32_ARRAY(n1, n, 5);
}

TEST(Sort, ListaOrdenadaBubble){
  int n[] = {0, 1, 2, 3, 4};
  int n1[] = {0, 1, 2, 3, 4};
  TEST_ASSERT_EQUAL(0, sort(n, 5, (char *)"On2", BUBBLE));
  TEST_ASSERT_EQUAL_INT32_ARRAY(n1, n, 5);
}

TEST(Sort, ListaOrdenadaInsertion){
  int n[] = {0, 1, 2, 3, 4};
  int n1[] = {0, 1, 2, 3, 4};
  TEST_ASSERT_EQUAL(0, sort(n, 5, (char *)"On2", INSERTION));
  TEST_ASSERT_EQUAL_INT32_ARRAY(n1, n, 5);
}

TEST(Sort, ListaOrdenadaSelection){
  int n[] = {0, 1, 2, 3, 4};
  int n1[] = {0, 1, 2, 3, 4};
  TEST_ASSERT_EQUAL(0, sort(n, 5, (char *)"On2", SELECTION));
  TEST_ASSERT_EQUAL_INT32_ARRAY(n1, n, 5);
}

TEST(Sort, ListaOrdenadaHeap){
  int n[] = {0, 1, 2, 3, 4};
  int n1[] = {0, 1, 2, 3, 4};
  TEST_ASSERT_EQUAL(0, sort(n, 5, (char *)"Onlogn", HEAP));
  TEST_ASSERT_EQUAL_INT32_ARRAY(n1, n, 5);
}

TEST(Sort, ListaOrdenadaMerge){
  int n[] = {0, 1, 2, 3, 4};
  int n1[] = {0, 1, 2, 3, 4};
  TEST_ASSERT_EQUAL(0, sort(n, 5, (char *)"Onlogn", MERGE));
  TEST_ASSERT_EQUAL_INT32_ARRAY(n1, n, 5);
}

TEST(Sort, ListaOrdenadaQuick){
  int n[] = {0, 1, 2, 3, 4};
  int n1[] = {0, 1, 2, 3, 4};
  TEST_ASSERT_EQUAL(0, sort(n, 5, (char *)"Onlogn", QUICK));
  TEST_ASSERT_EQUAL_INT32_ARRAY(n1, n, 5);
}