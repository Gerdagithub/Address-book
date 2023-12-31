/* AUTOGENERATED FILE. DO NOT EDIT. */

/*=======Automagically Detected Files To Include=====*/
#include "unity.h"

int GlobalExpectCount;
int GlobalVerifyOrder;
char* GlobalOrderError;

/*=======External Functions This Runner Calls=====*/
extern void setUp(void);
extern void tearDown(void);
extern void test_succesfullyInsertingPersonToTheBeginningOfEmptyList(void);
extern void test_succesfullyInsertingPersonToTheMiddleOfList(void);
extern void test_succesfullyInsertingPersonToTheEndOfList(void);
extern void test_unsuccessfullyInsertingPersonToNegativePosition(void);
extern void test_successfullyAddingPersonToTheEndOfEmptyList(void);
extern void test_successfullyAddingPersonToTheEndOfNotEmptyList(void);
extern void test_successfullyCreatingNode(void);
extern void test_successfullyCopyingNode(void);
extern void test_successfullyDeletingAddressFromTheBeginningOfFullList(void);
extern void test_successfullyDeletingTheOnlyElementOfList(void);
extern void test_successfullyDeletingAddressFromTheEndOfFullList(void);
extern void test_successfullyDeletingAddressFromTheMiddleOfList(void);
extern void test_unsuccessfullyDeletingAddressFromEmptyList(void);
extern void test_unsuccessfullyDeletingAddressFromNotExistingPos(void);
extern void test_unsuccessfullyDeletingAddressFromNegativePos(void);
extern void test_unsuccessfullyDeletingAddressFrom0Pos(void);
extern void test_deletingEmptyList(void);
extern void test_deletingListOf1Element(void);
extern void test_deletingFullList(void);
extern void test_successfullyFindingAddressByKeywordName(void);
extern void test_successfullyFindingAddressByKeywordSurname(void);
extern void test_successfullyFindingAddressByKeywordEmail(void);
extern void test_successfullyFindingAddressByKeywordNumber(void);
extern void test_searchingAddressByKeywordInEmptyList(void);
extern void test_successfullyFindingAddressByKeywordFrom1ElemList(void);
extern void test_unsuccessfullyFindingAddressByKeyword(void);
extern void test_successfullyFindingAddressByIndexFromTheMiddle(void);
extern void test_successfullyFindingAddressByIndexFromTheBeginning(void);
extern void test_successfullyFindingAddressByIndexFromTheEnd(void);
extern void test_unsuccessfullyFindingAddressByNegativeIndex(void);
extern void test_unsuccessfullyFindingAddressByPositiveIndex(void);
extern void test_unsuccessfullyFindingAddressByZeroIndex(void);
extern void test_sizeOfFullBook(void);
extern void test_sizeOfBookOf1Element(void);
extern void test_sizeOfEmptyBook(void);


/*=======Mock Management=====*/
static void CMock_Init(void)
{
  GlobalExpectCount = 0;
  GlobalVerifyOrder = 0;
  GlobalOrderError = NULL;
}
static void CMock_Verify(void)
{
}
static void CMock_Destroy(void)
{
}

/*=======Test Reset Options=====*/
void resetTest(void);
void resetTest(void)
{
  tearDown();
  CMock_Verify();
  CMock_Destroy();
  CMock_Init();
  setUp();
}
void verifyTest(void);
void verifyTest(void)
{
  CMock_Verify();
}

/*=======Test Runner Used To Run Each Test=====*/
static void run_test(UnityTestFunction func, const char* name, UNITY_LINE_TYPE line_num)
{
    Unity.CurrentTestName = name;
    Unity.CurrentTestLineNumber = line_num;
#ifdef UNITY_USE_COMMAND_LINE_ARGS
    if (!UnityTestMatches())
        return;
#endif
    Unity.NumberOfTests++;
    UNITY_CLR_DETAILS();
    UNITY_EXEC_TIME_START();
    CMock_Init();
    if (TEST_PROTECT())
    {
        setUp();
        func();
    }
    if (TEST_PROTECT())
    {
        tearDown();
        CMock_Verify();
    }
    CMock_Destroy();
    UNITY_EXEC_TIME_STOP();
    UnityConcludeTest();
}

/*=======MAIN=====*/
int main(void)
{
  UnityBegin("test_linkedList.c");
  run_test(test_succesfullyInsertingPersonToTheBeginningOfEmptyList, "test_succesfullyInsertingPersonToTheBeginningOfEmptyList", 33);
  run_test(test_succesfullyInsertingPersonToTheMiddleOfList, "test_succesfullyInsertingPersonToTheMiddleOfList", 61);
  run_test(test_succesfullyInsertingPersonToTheEndOfList, "test_succesfullyInsertingPersonToTheEndOfList", 136);
  run_test(test_unsuccessfullyInsertingPersonToNegativePosition, "test_unsuccessfullyInsertingPersonToNegativePosition", 212);
  run_test(test_successfullyAddingPersonToTheEndOfEmptyList, "test_successfullyAddingPersonToTheEndOfEmptyList", 264);
  run_test(test_successfullyAddingPersonToTheEndOfNotEmptyList, "test_successfullyAddingPersonToTheEndOfNotEmptyList", 290);
  run_test(test_successfullyCreatingNode, "test_successfullyCreatingNode", 342);
  run_test(test_successfullyCopyingNode, "test_successfullyCopyingNode", 365);
  run_test(test_successfullyDeletingAddressFromTheBeginningOfFullList, "test_successfullyDeletingAddressFromTheBeginningOfFullList", 387);
  run_test(test_successfullyDeletingTheOnlyElementOfList, "test_successfullyDeletingTheOnlyElementOfList", 420);
  run_test(test_successfullyDeletingAddressFromTheEndOfFullList, "test_successfullyDeletingAddressFromTheEndOfFullList", 442);
  run_test(test_successfullyDeletingAddressFromTheMiddleOfList, "test_successfullyDeletingAddressFromTheMiddleOfList", 506);
  run_test(test_unsuccessfullyDeletingAddressFromEmptyList, "test_unsuccessfullyDeletingAddressFromEmptyList", 571);
  run_test(test_unsuccessfullyDeletingAddressFromNotExistingPos, "test_unsuccessfullyDeletingAddressFromNotExistingPos", 587);
  run_test(test_unsuccessfullyDeletingAddressFromNegativePos, "test_unsuccessfullyDeletingAddressFromNegativePos", 638);
  run_test(test_unsuccessfullyDeletingAddressFrom0Pos, "test_unsuccessfullyDeletingAddressFrom0Pos", 689);
  run_test(test_deletingEmptyList, "test_deletingEmptyList", 740);
  run_test(test_deletingListOf1Element, "test_deletingListOf1Element", 757);
  run_test(test_deletingFullList, "test_deletingFullList", 777);
  run_test(test_successfullyFindingAddressByKeywordName, "test_successfullyFindingAddressByKeywordName", 806);
  run_test(test_successfullyFindingAddressByKeywordSurname, "test_successfullyFindingAddressByKeywordSurname", 840);
  run_test(test_successfullyFindingAddressByKeywordEmail, "test_successfullyFindingAddressByKeywordEmail", 874);
  run_test(test_successfullyFindingAddressByKeywordNumber, "test_successfullyFindingAddressByKeywordNumber", 908);
  run_test(test_searchingAddressByKeywordInEmptyList, "test_searchingAddressByKeywordInEmptyList", 942);
  run_test(test_successfullyFindingAddressByKeywordFrom1ElemList, "test_successfullyFindingAddressByKeywordFrom1ElemList", 955);
  run_test(test_unsuccessfullyFindingAddressByKeyword, "test_unsuccessfullyFindingAddressByKeyword", 973);
  run_test(test_successfullyFindingAddressByIndexFromTheMiddle, "test_successfullyFindingAddressByIndexFromTheMiddle", 996);
  run_test(test_successfullyFindingAddressByIndexFromTheBeginning, "test_successfullyFindingAddressByIndexFromTheBeginning", 1030);
  run_test(test_successfullyFindingAddressByIndexFromTheEnd, "test_successfullyFindingAddressByIndexFromTheEnd", 1062);
  run_test(test_unsuccessfullyFindingAddressByNegativeIndex, "test_unsuccessfullyFindingAddressByNegativeIndex", 1094);
  run_test(test_unsuccessfullyFindingAddressByPositiveIndex, "test_unsuccessfullyFindingAddressByPositiveIndex", 1117);
  run_test(test_unsuccessfullyFindingAddressByZeroIndex, "test_unsuccessfullyFindingAddressByZeroIndex", 1140);
  run_test(test_sizeOfFullBook, "test_sizeOfFullBook", 1163);
  run_test(test_sizeOfBookOf1Element, "test_sizeOfBookOf1Element", 1189);
  run_test(test_sizeOfEmptyBook, "test_sizeOfEmptyBook", 1210);

  return UnityEnd();
}
