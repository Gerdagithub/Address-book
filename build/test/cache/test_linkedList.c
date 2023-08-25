#include "src/src/additional.h"
#include "src/lib/linkedList.h"
#include "/var/lib/gems/3.0.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"






void setUp(void)

{

}



void tearDown(void)

{

}



void TEST_ASSERT_EQUAL_PERSON(struct Person *expected, struct Person *actual) {

    UnityAssertEqualString((const char*)((expected->name)), (const char*)((actual->name)), (

   ((void *)0)

   ), (UNITY_UINT)(16));

    UnityAssertEqualString((const char*)((expected->surname)), (const char*)((actual->surname)), (

   ((void *)0)

   ), (UNITY_UINT)(17));

    UnityAssertEqualString((const char*)((expected->email)), (const char*)((actual->email)), (

   ((void *)0)

   ), (UNITY_UINT)(18));

    UnityAssertEqualString((const char*)((expected->number)), (const char*)((actual->number)), (

   ((void *)0)

   ), (UNITY_UINT)(19));

}



void TEST_ASSERT_NOT_EQUAL_PTR(struct Person *person1, struct Person *person2)

{

    if (person1 != person2)

        longjmp(Unity.AbortFrame, 1);

    else

        UnityFail( (

       ((void *)0)

       ), (UNITY_UINT)(27));

}









void test_succesfullyInsertingPersonToTheBeginningOfEmptyList(void)

{

    struct Person *list = 

                         ((void *)0)

                             ;

    int actualRet;



    int expectedRet = 0, expectedSize = 1;







    struct Person* person1 = &(struct Person) {

        .name = "John",

        .surname = "Doe",

        .email = "john@example.com",

        .number = "123-456-7890",

        .next = 

               ((void *)0)

    

   };







    actualRet = insert_to_the_list(&list, person1, 1);







    TEST_ASSERT_EQUAL_PERSON(person1, list);

    UnityAssertEqualNumber((UNITY_INT)((expectedRet)), (UNITY_INT)((actualRet)), (

   ((void *)0)

   ), (UNITY_UINT)(57), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((expectedSize)), (UNITY_INT)((size_of_the_book(list))), (

   ((void *)0)

   ), (UNITY_UINT)(58), UNITY_DISPLAY_STYLE_INT);

}



void test_succesfullyInsertingPersonToTheMiddleOfList(void)

{

    struct Person *list = 

                         ((void *)0)

                             , *temp = 

                                       ((void *)0)

                                           ;

    int ret = 0;



    int expectedRet = 0, expectedSize = 5;







    struct Person* person1 = &(struct Person) {

        .name = "John",

        .surname = "Doe",

        .email = "john@example.com",

        .number = "123-456-7890",

        .next = 

               ((void *)0)

    

   };



    struct Person* person2 = &(struct Person) {

        .name = "Jane",

        .surname = "Smith",

        .email = "jane@example.com",

        .number = "987-654-3210",

        .next = 

               ((void *)0)

    

   };



    struct Person* person3 = &(struct Person) {

        .name = "Alice",

        .surname = "Johnson",

        .email = "alice@example.com",

        .number = "555-123-4567",

        .next = 

               ((void *)0)

    

   };



    struct Person* person4 = &(struct Person) {

        .name = "Bob",

        .surname = "Williams",

        .email = "bob@example.com",

        .number = "111-222-3333",

        .next = 

               ((void *)0)

    

   };



    add_to_the_end_of_the_list(&list, person1);

    add_to_the_end_of_the_list(&list, person2);

    add_to_the_end_of_the_list(&list, person3);

    add_to_the_end_of_the_list(&list, person4);



    temp = list;



    struct Person* person5 = &(struct Person) {

        .name = "Eva",

        .surname = "Brown",

        .email = "eva@example.com",

        .number = "444-555-6666",

        .next = 

               ((void *)0)

    

   };







    ret = insert_to_the_list(&list, person5, 3);







    TEST_ASSERT_EQUAL_PERSON(person1, temp);

    temp = temp->next;

    TEST_ASSERT_EQUAL_PERSON(person2, temp);

    temp = temp->next;

    TEST_ASSERT_EQUAL_PERSON(person5, temp);

    temp = temp->next;

    TEST_ASSERT_EQUAL_PERSON(person3, temp);

    temp = temp->next;

    TEST_ASSERT_EQUAL_PERSON(person4, temp);

    UnityAssertEqualNumber((UNITY_INT)((expectedRet)), (UNITY_INT)((ret)), (

   ((void *)0)

   ), (UNITY_UINT)(132), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((expectedSize)), (UNITY_INT)((size_of_the_book(list))), (

   ((void *)0)

   ), (UNITY_UINT)(133), UNITY_DISPLAY_STYLE_INT);

}



void test_succesfullyInsertingPersonToTheEndOfList(void)

{

    struct Person *list = 

                         ((void *)0)

                             , *temp = 

                                       ((void *)0)

                                           ;

    int ret = 0;



    int expectedRet = 0, expectedSize = 5;







    struct Person* person1 = &(struct Person) {

        .name = "John",

        .surname = "Doe",

        .email = "john@example.com",

        .number = "123-456-7890",

        .next = 

               ((void *)0)

    

   };



    struct Person* person2 = &(struct Person) {

        .name = "Jane",

        .surname = "Smith",

        .email = "jane@example.com",

        .number = "987-654-3210",

        .next = 

               ((void *)0)

    

   };



    struct Person* person3 = &(struct Person) {

        .name = "Alice",

        .surname = "Johnson",

        .email = "alice@example.com",

        .number = "555-123-4567",

        .next = 

               ((void *)0)

    

   };



    struct Person* person4 = &(struct Person) {

        .name = "Bob",

        .surname = "Williams",

        .email = "bob@example.com",

        .number = "111-222-3333",

        .next = 

               ((void *)0)

    

   };





    add_to_the_end_of_the_list(&list, person1);

    add_to_the_end_of_the_list(&list, person2);

    add_to_the_end_of_the_list(&list, person3);

    add_to_the_end_of_the_list(&list, person4);



    temp = list;



    struct Person* person5 = &(struct Person) {

        .name = "Eva",

        .surname = "Brown",

        .email = "eva@example.com",

        .number = "444-555-6666",

        .next = 

               ((void *)0)

    

   };







    ret = insert_to_the_list(&list, person5, 5);







    TEST_ASSERT_EQUAL_PERSON(person1, temp);

    temp = temp->next;

    TEST_ASSERT_EQUAL_PERSON(person2, temp);

    temp = temp->next;

    TEST_ASSERT_EQUAL_PERSON(person3, temp);

    temp = temp->next;

    TEST_ASSERT_EQUAL_PERSON(person4, temp);

    temp = temp->next;

    TEST_ASSERT_EQUAL_PERSON(person5, temp);

    UnityAssertEqualNumber((UNITY_INT)((expectedRet)), (UNITY_INT)((ret)), (

   ((void *)0)

   ), (UNITY_UINT)(208), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((expectedSize)), (UNITY_INT)((size_of_the_book(list))), (

   ((void *)0)

   ), (UNITY_UINT)(209), UNITY_DISPLAY_STYLE_INT);

}



void test_unsuccessfullyInsertingPersonToNegativePosition(void)

{

    struct Person *list = 

                         ((void *)0)

                             , *temp = 

                                       ((void *)0)

                                           ;

    int ret = 0;



    int expectedRet = 1, expectedSize = 2;







    struct Person* person1 = &(struct Person) {

        .name = "John",

        .surname = "Doe",

        .email = "john@example.com",

        .number = "123-456-7890",

        .next = 

               ((void *)0)

    

   };



    struct Person* person2 = &(struct Person) {

        .name = "Jane",

        .surname = "Smith",

        .email = "jane@example.com",

        .number = "987-654-3210",

        .next = 

               ((void *)0)

    

   };



    add_to_the_end_of_the_list(&list, person1);

    add_to_the_end_of_the_list(&list, person2);



    temp = list;



    struct Person* person3 = &(struct Person) {

        .name = "Eva",

        .surname = "Brown",

        .email = "eva@example.com",

        .number = "444-555-6666",

        .next = 

               ((void *)0)

    

   };







    ret = insert_to_the_list(&list, person3, -1);







    TEST_ASSERT_EQUAL_PERSON(person1, temp);

    temp = temp->next;

    TEST_ASSERT_EQUAL_PERSON(person2, temp);

    UnityAssertEqualNumber((UNITY_INT)((expectedRet)), (UNITY_INT)((ret)), (

   ((void *)0)

   ), (UNITY_UINT)(259), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((expectedSize)), (UNITY_INT)((size_of_the_book(list))), (

   ((void *)0)

   ), (UNITY_UINT)(260), UNITY_DISPLAY_STYLE_INT);

}





void test_successfullyAddingPersonToTheEndOfEmptyList(void)

{

    struct Person *list = 

                         ((void *)0)

                             ;



    int expectedSize = 1;







    struct Person* person = &(struct Person) {

        .name = "Eva",

        .surname = "Brown",

        .email = "eva@example.com",

        .number = "444-555-6666",

        .next = 

               ((void *)0)

    

   };







    add_to_the_end_of_the_list(&list, person);







    TEST_ASSERT_EQUAL_PERSON(person, list);

    UnityAssertEqualNumber((UNITY_INT)((expectedSize)), (UNITY_INT)((size_of_the_book(list))), (

   ((void *)0)

   ), (UNITY_UINT)(287), UNITY_DISPLAY_STYLE_INT);

}



void test_successfullyAddingPersonToTheEndOfNotEmptyList(void)

{

    struct Person *list = 

                         ((void *)0)

                             , *temp = 

                                       ((void *)0)

                                           ;



    int expectedSize = 3;







    struct Person* person1 = &(struct Person) {

        .name = "John",

        .surname = "Doe",

        .email = "john@example.com",

        .number = "123-456-7890",

        .next = 

               ((void *)0)

    

   };



    struct Person* person2 = &(struct Person) {

        .name = "Jane",

        .surname = "Smith",

        .email = "jane@example.com",

        .number = "987-654-3210",

        .next = 

               ((void *)0)

    

   };



    add_to_the_end_of_the_list(&list, person1);

    add_to_the_end_of_the_list(&list, person2);



    temp = list;



    struct Person* person3 = &(struct Person) {

        .name = "Eva",

        .surname = "Brown",

        .email = "eva@example.com",

        .number = "444-555-6666",

        .next = 

               ((void *)0)

    

   };







    add_to_the_end_of_the_list(&list, person3);







    TEST_ASSERT_EQUAL_PERSON(person1, temp);

    temp = temp->next;

    TEST_ASSERT_EQUAL_PERSON(person2, temp);

    temp = temp->next;

    TEST_ASSERT_EQUAL_PERSON(person3, temp);

    UnityAssertEqualNumber((UNITY_INT)((expectedSize)), (UNITY_INT)((size_of_the_book(list))), (

   ((void *)0)

   ), (UNITY_UINT)(338), UNITY_DISPLAY_STYLE_INT);

}





void test_successfullyCreatingNode(void)

{





    struct Person* expectedPerson = &(struct Person) {

        .name = "Eva",

        .surname = "Brown",

        .email = "eva@example.com",

        .number = "444-555-6666",

        .next = 

               ((void *)0)

    

   };







    struct Person *actualPerson = create_node(expectedPerson->name, expectedPerson->surname,

                                              expectedPerson->email, expectedPerson->number);







    TEST_ASSERT_EQUAL_PERSON(expectedPerson, actualPerson);

    TEST_ASSERT_NOT_EQUAL_PTR(expectedPerson, actualPerson);

}



void test_successfullyCopyingNode(void)

{





    struct Person* expectedPerson = &(struct Person) {

        .name = "Eva",

        .surname = "Brown",

        .email = "eva@example.com",

        .number = "444-555-6666",

        .next = 

               ((void *)0)

    

   };







    struct Person *actualPerson = copy_node(expectedPerson);







    TEST_ASSERT_EQUAL_PERSON(expectedPerson, actualPerson);

    TEST_ASSERT_NOT_EQUAL_PTR(expectedPerson, actualPerson);

}



void test_successfullyDeletingAddressFromTheBeginningOfFullList(void)

{

    struct Person *list = 

                         ((void *)0)

                             ;

    int ret = 0;



    struct Person *expectedPerson = &(struct Person) {

        .name = "Jane",

        .surname = "Smith",

        .email = "jane@example.com",

        .number = "987-654-3210",

        .next = 

               ((void *)0)

    

   };

    int expectedRet = 0;







    struct Person *person1 = create_node("John", "Doe", "john@example.com", "123-456-7890");

    struct Person *person2 = create_node(expectedPerson->name, expectedPerson->surname,

                                         expectedPerson->email, expectedPerson->number);



    add_to_the_end_of_the_list(&list, person1);

    add_to_the_end_of_the_list(&list, person2);







    ret = delete_addr_at_pos(&list, 1);







    TEST_ASSERT_EQUAL_PERSON(expectedPerson, list);

    UnityAssertEqualNumber((UNITY_INT)((expectedRet)), (UNITY_INT)((ret)), (

   ((void *)0)

   ), (UNITY_UINT)(417), UNITY_DISPLAY_STYLE_INT);

}



void test_successfullyDeletingTheOnlyElementOfList(void)

{

    struct Person *list = 

                         ((void *)0)

                             ;

    int ret = 0;



    int expectedRet = 0, expectedSize = 0;







    struct Person *person = create_node("John", "Doe", "john@example.com", "123-456-7890");

    add_to_the_end_of_the_list(&list, person);







    ret = delete_addr_at_pos(&list, 1);







    UnityAssertEqualNumber((UNITY_INT)((expectedRet)), (UNITY_INT)((ret)), (

   ((void *)0)

   ), (UNITY_UINT)(438), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((expectedSize)), (UNITY_INT)((size_of_the_book(list))), (

   ((void *)0)

   ), (UNITY_UINT)(439), UNITY_DISPLAY_STYLE_INT);

}



void test_successfullyDeletingAddressFromTheEndOfFullList(void)

{

    struct Person *list = 

                         ((void *)0)

                             , *temp;

    int ret = 0;



    struct Person *expectedPerson1 = &(struct Person) {

        .name = "John",

        .surname = "Doe",

        .email = "john@example.com",

        .number = "123-456-7890",

        .next = 

               ((void *)0)

    

   };

    struct Person *expectedPerson2 = &(struct Person) {

        .name = "Jane",

        .surname = "Smith",

        .email = "jane@example.com",

        .number = "987-654-3210",

        .next = 

               ((void *)0)

    

   };

    struct Person *expectedPerson3 = &(struct Person) {

        .name = "Alice",

        .surname = "Johnson",

        .email = "alice@example.com",

        .number = "555-555-5555",

        .next = 

               ((void *)0)

    

   };



    int expectedRet = 0, expectedSize = 3;







    struct Person *person1 = create_node(expectedPerson1->name, expectedPerson1->surname,

                                         expectedPerson1->email, expectedPerson1->number);



    struct Person *person2 = create_node(expectedPerson2->name, expectedPerson2->surname,

                                         expectedPerson2->email, expectedPerson2->number);



    struct Person *person3 = create_node(expectedPerson3->name, expectedPerson3->surname,

                                         expectedPerson3->email, expectedPerson3->number);



    struct Person *person4 = create_node("Bob", "Brown", "bob@example.com", "888-888-8888");



    add_to_the_end_of_the_list(&list, person1);

    add_to_the_end_of_the_list(&list, person2);

    add_to_the_end_of_the_list(&list, person3);

    add_to_the_end_of_the_list(&list, person4);



    temp = list;







    ret = delete_addr_at_pos(&list, 4);







    TEST_ASSERT_EQUAL_PERSON(expectedPerson1, temp);

    temp = temp->next;

    TEST_ASSERT_EQUAL_PERSON(expectedPerson2, temp);

    temp = temp->next;

    TEST_ASSERT_EQUAL_PERSON(expectedPerson3, temp);

    UnityAssertEqualNumber((UNITY_INT)((expectedRet)), (UNITY_INT)((ret)), (

   ((void *)0)

   ), (UNITY_UINT)(502), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((expectedSize)), (UNITY_INT)((size_of_the_book(list))), (

   ((void *)0)

   ), (UNITY_UINT)(503), UNITY_DISPLAY_STYLE_INT);

}



void test_successfullyDeletingAddressFromTheMiddleOfList(void)

{

    struct Person *list = 

                         ((void *)0)

                             , *temp;

    int ret = 0;



    struct Person *expectedPerson1 = &(struct Person) {

        .name = "John",

        .surname = "Doe",

        .email = "john@example.com",

        .number = "123-456-7890",

        .next = 

               ((void *)0)

    

   };

    struct Person *expectedPerson2 = &(struct Person) {

        .name = "Jane",

        .surname = "Smith",

        .email = "jane@example.com",

        .number = "987-654-3210",

        .next = 

               ((void *)0)

    

   };

    struct Person *expectedPerson3 = &(struct Person) {

        .name = "Alice",

        .surname = "Johnson",

        .email = "alice@example.com",

        .number = "555-555-5555",

        .next = 

               ((void *)0)

    

   };

    int expectedRet = 0;

    int expectedSize = 3;







    struct Person *person1 = create_node(expectedPerson1->name, expectedPerson1->surname,

                                         expectedPerson1->email, expectedPerson1->number);



    struct Person *person2 = create_node(expectedPerson2->name, expectedPerson2->surname,

                                         expectedPerson2->email, expectedPerson2->number);



    struct Person *person3 = create_node("Bob", "Brown", "bob@example.com", "888-888-8888");



    struct Person *person4 = create_node(expectedPerson3->name, expectedPerson3->surname,

                                         expectedPerson3->email, expectedPerson3->number);





    add_to_the_end_of_the_list(&list, person1);

    add_to_the_end_of_the_list(&list, person2);

    add_to_the_end_of_the_list(&list, person3);

    add_to_the_end_of_the_list(&list, person4);



    temp = list;







    ret = delete_addr_at_pos(&list, 3);







    TEST_ASSERT_EQUAL_PERSON(expectedPerson1, temp);

    temp = temp->next;

    TEST_ASSERT_EQUAL_PERSON(expectedPerson2, temp);

    temp = temp->next;

    TEST_ASSERT_EQUAL_PERSON(expectedPerson3, temp);

    UnityAssertEqualNumber((UNITY_INT)((expectedRet)), (UNITY_INT)((ret)), (

   ((void *)0)

   ), (UNITY_UINT)(567), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((expectedSize)), (UNITY_INT)((size_of_the_book(list))), (

   ((void *)0)

   ), (UNITY_UINT)(568), UNITY_DISPLAY_STYLE_INT);

}



void test_unsuccessfullyDeletingAddressFromEmptyList(void)

{

    struct Person *list = 

                         ((void *)0)

                             ;

    int ret = 0;



    int expectedRet = 1;







    ret = delete_addr_at_pos(&list, 3);







    UnityAssertEqualNumber((UNITY_INT)((expectedRet)), (UNITY_INT)((ret)), (

   ((void *)0)

   ), (UNITY_UINT)(584), UNITY_DISPLAY_STYLE_INT);

}



void test_unsuccessfullyDeletingAddressFromNotExistingPos(void)

{

    struct Person *list = 

                         ((void *)0)

                             , *temp;

    int ret = 0;



    struct Person *expectedPerson1 = &(struct Person) {

        .name = "John",

        .surname = "Doe",

        .email = "john@example.com",

        .number = "123-456-7890",

        .next = 

               ((void *)0)

    

   };

    struct Person *expectedPerson2 = &(struct Person) {

        .name = "Jane",

        .surname = "Smith",

        .email = "jane@example.com",

        .number = "987-654-3210",

        .next = 

               ((void *)0)

    

   };



    int expectedRet = 1;

    int expectedSize = 2;







    struct Person *person1 = create_node(expectedPerson1->name, expectedPerson1->surname,

                                         expectedPerson1->email, expectedPerson1->number);



    struct Person *person2 = create_node(expectedPerson2->name, expectedPerson2->surname,

                                         expectedPerson2->email, expectedPerson2->number);





    add_to_the_end_of_the_list(&list, person1);

    add_to_the_end_of_the_list(&list, person2);



    temp = list;







    ret = delete_addr_at_pos(&list, 3);







    TEST_ASSERT_EQUAL_PERSON(expectedPerson1, temp);

    temp = temp->next;

    TEST_ASSERT_EQUAL_PERSON(expectedPerson2, temp);



    UnityAssertEqualNumber((UNITY_INT)((expectedRet)), (UNITY_INT)((ret)), (

   ((void *)0)

   ), (UNITY_UINT)(634), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((expectedSize)), (UNITY_INT)((size_of_the_book(list))), (

   ((void *)0)

   ), (UNITY_UINT)(635), UNITY_DISPLAY_STYLE_INT);

}



void test_deletingEmptyList(void)

{

    struct Person *list = 

                         ((void *)0)

                             ;



    int expectedSize = 0;







    delete_list(&list);







    UnityAssertEqualNumber((UNITY_INT)((expectedSize)), (UNITY_INT)((size_of_the_book(list))), (

   ((void *)0)

   ), (UNITY_UINT)(650), UNITY_DISPLAY_STYLE_INT);



}





void test_deletingListOf1Element(void)

{

    struct Person *list = 

                         ((void *)0)

                             ;



    int expectedSize = 0;







    struct Person *person = create_node("Bob", "Brown", "bob@example.com", "888-888-8888");

    add_to_the_end_of_the_list(&list, person);







    delete_list(&list);







    UnityAssertEqualNumber((UNITY_INT)((expectedSize)), (UNITY_INT)((size_of_the_book(list))), (

   ((void *)0)

   ), (UNITY_UINT)(672), UNITY_DISPLAY_STYLE_INT);

}



void test_deletingFullList(void)

{

    struct Person *list = 

                         ((void *)0)

                             ;



    int expectedSize = 0;







    struct Person *person1 = create_node("Alice", "Johnson", "alice@example.com", "555-555-5555");

    struct Person *person2 = create_node("Bob", "Brown", "bob@example.com", "888-888-8888");

    struct Person *person3 = create_node("Charlie", "Smith", "charlie@example.com", "123-456-7890");

    struct Person *person4 = create_node("David", "Williams", "david@example.com", "987-654-3210");

    struct Person *person5 = create_node("Emily", "Davis", "emily@example.com", "111-222-3333");



    add_to_the_end_of_the_list(&list, person1);

    add_to_the_end_of_the_list(&list, person2);

    add_to_the_end_of_the_list(&list, person3);

    add_to_the_end_of_the_list(&list, person4);

    add_to_the_end_of_the_list(&list, person5);







    delete_list(&list);







    UnityAssertEqualNumber((UNITY_INT)((expectedSize)), (UNITY_INT)((size_of_the_book(list))), (

   ((void *)0)

   ), (UNITY_UINT)(701), UNITY_DISPLAY_STYLE_INT);

}



void test_successfullyFindingAddressByKeywordName(void)

{

    struct Person *list = 

                         ((void *)0)

                             ;



    struct Person *expectedPerson = &(struct Person) {

        .name = "Jane",

        .surname = "Smith",

        .email = "jane@example.com",

        .number = "987-654-3210",

        .next = 

               ((void *)0)

    

   };







    struct Person *person1 = create_node("Bob", "Brown", "bob@example.com", "888-888-8888");



    struct Person *person2 = create_node(expectedPerson->name, expectedPerson->surname,

                                         expectedPerson->email, expectedPerson->number);



    struct Person *person3 = create_node("Charlie", "Smith", "charlie@example.com", "123-456-7890");



    add_to_the_end_of_the_list(&list, person1);

    add_to_the_end_of_the_list(&list, person2);

    add_to_the_end_of_the_list(&list, person3);







    struct Person *actualPerson = find_address_by_keyword(list, "Smith");







    TEST_ASSERT_EQUAL_PERSON(expectedPerson, actualPerson);

}



void test_unsuccessfullyFindingAddressByKeyword(void)

{

    struct Person *list = 

                         ((void *)0)

                             ;







    struct Person *person1 = create_node("Bob", "Brown", "bob@example.com", "888-888-8888");

    struct Person *person2 = create_node("David", "Williams", "david@example.com", "987-654-3210");

    struct Person *person3 = create_node("Charlie", "Smith", "charlie@example.com", "123-456-7890");



    add_to_the_end_of_the_list(&list, person1);

    add_to_the_end_of_the_list(&list, person2);

    add_to_the_end_of_the_list(&list, person3);







    struct Person *actualPerson = find_address_by_keyword(list, "------");







    do {if ((((actualPerson)) == 

   ((void *)0)

   )) {} else {UnityFail( (((" Expected NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(758))));}} while(0);

}



void test_successfullyFindingAddressByIndexFromTheMiddle(void)

{

    struct Person *list = 

                         ((void *)0)

                             ;



    struct Person *expectedPerson = &(struct Person) {

        .name = "Jane",

        .surname = "Smith",

        .email = "jane@example.com",

        .number = "987-654-3210",

        .next = 

               ((void *)0)

    

   };







    struct Person *person1 = create_node("Bob", "Brown", "bob@example.com", "888-888-8888");



    struct Person *person2 = create_node(expectedPerson->name, expectedPerson->surname,

                                         expectedPerson->email, expectedPerson->number);



    struct Person *person3 = create_node("Charlie", "Smith", "charlie@example.com", "123-456-7890");



    add_to_the_end_of_the_list(&list, person1);

    add_to_the_end_of_the_list(&list, person2);

    add_to_the_end_of_the_list(&list, person3);







    struct Person *actualPerson = find_address(&list, 2);







    TEST_ASSERT_EQUAL_PERSON(expectedPerson, actualPerson);

}



void test_successfullyFindingAddressByIndexFromTheBeginning(void)

{

    struct Person *list = 

                         ((void *)0)

                             ;



    struct Person *expectedPerson = &(struct Person) {

        .name = "Jane",

        .surname = "Smith",

        .email = "jane@example.com",

        .number = "987-654-3210",

        .next = 

               ((void *)0)

    

   };







    struct Person *person1 = create_node(expectedPerson->name, expectedPerson->surname,

                                         expectedPerson->email, expectedPerson->number);

    struct Person *person2 = create_node("Bob", "Brown", "bob@example.com", "888-888-8888");

    struct Person *person3 = create_node("Charlie", "Smith", "charlie@example.com", "123-456-7890");



    add_to_the_end_of_the_list(&list, person1);

    add_to_the_end_of_the_list(&list, person2);

    add_to_the_end_of_the_list(&list, person3);







    struct Person *actualPerson = find_address(&list, 1);







    TEST_ASSERT_EQUAL_PERSON(expectedPerson, actualPerson);

}



void test_successfullyFindingAddressByIndexFromTheEnd(void)

{

    struct Person *list = 

                         ((void *)0)

                             ;



    struct Person *expectedPerson = &(struct Person) {

        .name = "Jane",

        .surname = "Smith",

        .email = "jane@example.com",

        .number = "987-654-3210",

        .next = 

               ((void *)0)

    

   };







    struct Person *person1 = create_node("Bob", "Brown", "bob@example.com", "888-888-8888");

    struct Person *person2 = create_node("Charlie", "Smith", "charlie@example.com", "123-456-7890");

    struct Person *person3 = create_node(expectedPerson->name, expectedPerson->surname,

                                         expectedPerson->email, expectedPerson->number);



    add_to_the_end_of_the_list(&list, person1);

    add_to_the_end_of_the_list(&list, person2);

    add_to_the_end_of_the_list(&list, person3);







    struct Person *actualPerson = find_address(&list, 3);







    TEST_ASSERT_EQUAL_PERSON(expectedPerson, actualPerson);

}



void test_unsuccessfullyFindingAddressByNegativeIndex(void)

{

    struct Person *list = 

                         ((void *)0)

                             ;







    struct Person *person1 = create_node("Bob", "Brown", "bob@example.com", "888-888-8888");

    struct Person *person2 = create_node("David", "Williams", "david@example.com", "987-654-3210");

    struct Person *person3 = create_node("Charlie", "Smith", "charlie@example.com", "123-456-7890");



    add_to_the_end_of_the_list(&list, person1);

    add_to_the_end_of_the_list(&list, person2);

    add_to_the_end_of_the_list(&list, person3);







    struct Person *actualPerson = find_address(&list, -1);







    do {if ((((actualPerson)) == 

   ((void *)0)

   )) {} else {UnityFail( (((" Expected NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(879))));}} while(0);

}



void test_unsuccessfullyFindingAddressByPositiveIndex(void)

{

    struct Person *list = 

                         ((void *)0)

                             ;







    struct Person *person1 = create_node("Bob", "Brown", "bob@example.com", "888-888-8888");

    struct Person *person2 = create_node("David", "Williams", "david@example.com", "987-654-3210");

    struct Person *person3 = create_node("Charlie", "Smith", "charlie@example.com", "123-456-7890");



    add_to_the_end_of_the_list(&list, person1);

    add_to_the_end_of_the_list(&list, person2);

    add_to_the_end_of_the_list(&list, person3);







    struct Person *actualPerson = find_address(&list, 5);







    do {if ((((actualPerson)) == 

   ((void *)0)

   )) {} else {UnityFail( (((" Expected NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(902))));}} while(0);

}



void test_unsuccessfullyFindingAddressByZeroIndex(void)

{

    struct Person *list = 

                         ((void *)0)

                             ;







    struct Person *person1 = create_node("Bob", "Brown", "bob@example.com", "888-888-8888");

    struct Person *person2 = create_node("David", "Williams", "david@example.com", "987-654-3210");

    struct Person *person3 = create_node("Charlie", "Smith", "charlie@example.com", "123-456-7890");



    add_to_the_end_of_the_list(&list, person1);

    add_to_the_end_of_the_list(&list, person2);

    add_to_the_end_of_the_list(&list, person3);







    struct Person *actualPerson = find_address(&list, 0);







    do {if ((((actualPerson)) == 

   ((void *)0)

   )) {} else {UnityFail( (((" Expected NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(925))));}} while(0);

}



void test_sizeOfFullBook(void)

{

    struct Person *list = 

                         ((void *)0)

                             ;

    int actualSize;



    int expectedSize = 3;







    struct Person *person1 = create_node("David", "Williams", "david@example.com", "987-654-3210");

    struct Person *person2 = create_node("Bob", "Brown", "bob@example.com", "888-888-8888");

    struct Person *person3 = create_node("Charlie", "Smith", "charlie@example.com", "123-456-7890");



    add_to_the_end_of_the_list(&list, person1);

    add_to_the_end_of_the_list(&list, person2);

    add_to_the_end_of_the_list(&list, person3);







    actualSize = size_of_the_book(list);







    UnityAssertEqualNumber((UNITY_INT)((expectedSize)), (UNITY_INT)((actualSize)), (

   ((void *)0)

   ), (UNITY_UINT)(951), UNITY_DISPLAY_STYLE_INT);

}



void test_sizeOfBookOf1Element(void)

{

    struct Person *list = 

                         ((void *)0)

                             ;

    int actualSize;



    int expectedSize = 1;







    list = create_node("David", "Williams", "david@example.com", "987-654-3210");







    actualSize = size_of_the_book(list);







    UnityAssertEqualNumber((UNITY_INT)((expectedSize)), (UNITY_INT)((actualSize)), (

   ((void *)0)

   ), (UNITY_UINT)(971), UNITY_DISPLAY_STYLE_INT);

}





void test_sizeOfEmptyBook(void)

{

    struct Person *list = 

                         ((void *)0)

                             ;

    int actualSize;



    int expectedSize = 0;







    actualSize = size_of_the_book(list);







    UnityAssertEqualNumber((UNITY_INT)((expectedSize)), (UNITY_INT)((actualSize)), (

   ((void *)0)

   ), (UNITY_UINT)(988), UNITY_DISPLAY_STYLE_INT);

}
