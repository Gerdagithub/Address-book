#ifdef TEST

#include "unity.h"
#include "linkedList.h"
#include "additional.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void TEST_ASSERT_EQUAL_PERSON(struct Person *expected, struct Person *actual) {
    TEST_ASSERT_EQUAL_STRING(expected->name, actual->name);
    TEST_ASSERT_EQUAL_STRING(expected->surname, actual->surname);
    TEST_ASSERT_EQUAL_STRING(expected->email, actual->email);
    TEST_ASSERT_EQUAL_STRING(expected->number, actual->number);
}

void TEST_ASSERT_NOT_EQUAL_PTR(struct Person *person1, struct Person *person2)
{
    if (person1 != person2)
        TEST_PASS();
    else
        TEST_FAIL();
}




void test_succesfullyInsertingPersonToTheBeginningOfEmptyList(void)
{
    struct Person *list = NULL;
    int actualRet;

    int expectedRet = 0, expectedSize = 1;

    // Arrange

    struct Person* person1 = &(struct Person) {
        .name = "John",
        .surname = "Doe",
        .email = "john@example.com",
        .number = "123-456-7890",
        .next = NULL
    };

    // Act

    actualRet = insert_to_the_list(&list, person1, 1);

    // Assert

    TEST_ASSERT_EQUAL_PERSON(person1, list);
    TEST_ASSERT_EQUAL_INT(expectedRet, actualRet);
    TEST_ASSERT_EQUAL_INT(expectedSize, size_of_the_book(list));
}

void test_succesfullyInsertingPersonToTheMiddleOfList(void)
{
    struct Person *list = NULL, *temp = NULL;
    int ret = 0;

    int expectedRet = 0, expectedSize = 5;
    
    // Arrange

    struct Person* person1 = &(struct Person) {
        .name = "John",
        .surname = "Doe",
        .email = "john@example.com",
        .number = "123-456-7890",
        .next = NULL
    };

    struct Person* person2 = &(struct Person) {
        .name = "Jane",
        .surname = "Smith",
        .email = "jane@example.com",
        .number = "987-654-3210",
        .next = NULL
    };

    struct Person* person3 = &(struct Person) {
        .name = "Alice",
        .surname = "Johnson",
        .email = "alice@example.com",
        .number = "555-123-4567",
        .next = NULL
    };

    struct Person* person4 = &(struct Person) {
        .name = "Bob",
        .surname = "Williams",
        .email = "bob@example.com",
        .number = "111-222-3333",
        .next = NULL
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
        .next = NULL
    };

    // Act

    ret = insert_to_the_list(&list, person5, 3);

    // Assert

    TEST_ASSERT_EQUAL_PERSON(person1, temp);
    temp = temp->next;
    TEST_ASSERT_EQUAL_PERSON(person2, temp);
    temp = temp->next;
    TEST_ASSERT_EQUAL_PERSON(person5, temp);
    temp = temp->next;
    TEST_ASSERT_EQUAL_PERSON(person3, temp);
    temp = temp->next;
    TEST_ASSERT_EQUAL_PERSON(person4, temp);
    TEST_ASSERT_EQUAL_INT(expectedRet, ret);
    TEST_ASSERT_EQUAL_INT(expectedSize, size_of_the_book(list));
}

void test_succesfullyInsertingPersonToTheEndOfList(void)
{
    struct Person *list = NULL, *temp = NULL;
    int ret = 0;

    int expectedRet = 0, expectedSize = 5;
    
    // Arrange

    struct Person* person1 = &(struct Person) {
        .name = "John",
        .surname = "Doe",
        .email = "john@example.com",
        .number = "123-456-7890",
        .next = NULL
    };

    struct Person* person2 = &(struct Person) {
        .name = "Jane",
        .surname = "Smith",
        .email = "jane@example.com",
        .number = "987-654-3210",
        .next = NULL
    };

    struct Person* person3 = &(struct Person) {
        .name = "Alice",
        .surname = "Johnson",
        .email = "alice@example.com",
        .number = "555-123-4567",
        .next = NULL
    };

    struct Person* person4 = &(struct Person) {
        .name = "Bob",
        .surname = "Williams",
        .email = "bob@example.com",
        .number = "111-222-3333",
        .next = NULL
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
        .next = NULL
    };

    // Act

    ret = insert_to_the_list(&list, person5, 5);

    // Assert

    TEST_ASSERT_EQUAL_PERSON(person1, temp);
    temp = temp->next;
    TEST_ASSERT_EQUAL_PERSON(person2, temp);
    temp = temp->next;
    TEST_ASSERT_EQUAL_PERSON(person3, temp);
    temp = temp->next;
    TEST_ASSERT_EQUAL_PERSON(person4, temp);
    temp = temp->next;
    TEST_ASSERT_EQUAL_PERSON(person5, temp);
    TEST_ASSERT_EQUAL_INT(expectedRet, ret);
    TEST_ASSERT_EQUAL_INT(expectedSize, size_of_the_book(list));
}

void test_unsuccessfullyInsertingPersonToNegativePosition(void)
{
    struct Person *list = NULL, *temp = NULL;
    int ret = 0;

    int expectedRet = 1, expectedSize = 2;
    
    // Arrange

    struct Person* person1 = &(struct Person) {
        .name = "John",
        .surname = "Doe",
        .email = "john@example.com",
        .number = "123-456-7890",
        .next = NULL
    };

    struct Person* person2 = &(struct Person) {
        .name = "Jane",
        .surname = "Smith",
        .email = "jane@example.com",
        .number = "987-654-3210",
        .next = NULL
    };

    add_to_the_end_of_the_list(&list, person1);
    add_to_the_end_of_the_list(&list, person2);  

    temp = list;

    struct Person* person3 = &(struct Person) {
        .name = "Eva",
        .surname = "Brown",
        .email = "eva@example.com",
        .number = "444-555-6666",
        .next = NULL
    };

    // Act

    ret = insert_to_the_list(&list, person3, -1);    

    // Assert

    TEST_ASSERT_EQUAL_PERSON(person1, temp);
    temp = temp->next;
    TEST_ASSERT_EQUAL_PERSON(person2, temp);
    TEST_ASSERT_EQUAL_INT(expectedRet, ret);
    TEST_ASSERT_EQUAL_INT(expectedSize, size_of_the_book(list));
}


void test_successfullyAddingPersonToTheEndOfEmptyList(void)
{
    struct Person *list = NULL;

    int expectedSize = 1;
    
    // Arrange

    struct Person* person = &(struct Person) {
        .name = "Eva",
        .surname = "Brown",
        .email = "eva@example.com",
        .number = "444-555-6666",
        .next = NULL
    };

    // Act

    add_to_the_end_of_the_list(&list, person);    

    // Assert

    TEST_ASSERT_EQUAL_PERSON(person, list);
    TEST_ASSERT_EQUAL_INT(expectedSize, size_of_the_book(list));
}

void test_successfullyAddingPersonToTheEndOfNotEmptyList(void)
{
    struct Person *list = NULL, *temp = NULL;

    int expectedSize = 3;
    
    // Arrange

    struct Person* person1 = &(struct Person) {
        .name = "John",
        .surname = "Doe",
        .email = "john@example.com",
        .number = "123-456-7890",
        .next = NULL
    };

    struct Person* person2 = &(struct Person) {
        .name = "Jane",
        .surname = "Smith",
        .email = "jane@example.com",
        .number = "987-654-3210",
        .next = NULL
    };

    add_to_the_end_of_the_list(&list, person1);
    add_to_the_end_of_the_list(&list, person2);

    temp = list;

    struct Person* person3 = &(struct Person) {
        .name = "Eva",
        .surname = "Brown",
        .email = "eva@example.com",
        .number = "444-555-6666",
        .next = NULL
    };

    // Act

    add_to_the_end_of_the_list(&list, person3);    

    // Assert

    TEST_ASSERT_EQUAL_PERSON(person1, temp);
    temp = temp->next;
    TEST_ASSERT_EQUAL_PERSON(person2, temp);
    temp = temp->next;
    TEST_ASSERT_EQUAL_PERSON(person3, temp);
    TEST_ASSERT_EQUAL_INT(expectedSize, size_of_the_book(list));
}


void test_successfullyCreatingNode(void)
{
    // Arrange

    struct Person* expectedPerson = &(struct Person) {
        .name = "Eva",
        .surname = "Brown",
        .email = "eva@example.com",
        .number = "444-555-6666",
        .next = NULL
    };

    // Act 

    struct Person *actualPerson = create_node(expectedPerson->name, expectedPerson->surname, 
                                              expectedPerson->email, expectedPerson->number);

    // Assert

    TEST_ASSERT_EQUAL_PERSON(expectedPerson, actualPerson);
    TEST_ASSERT_NOT_EQUAL_PTR(expectedPerson, actualPerson);
}

void test_successfullyCopyingNode(void)
{
    // Arrange

    struct Person* expectedPerson = &(struct Person) {
        .name = "Eva",
        .surname = "Brown",
        .email = "eva@example.com",
        .number = "444-555-6666",
        .next = NULL
    };

    // Act 

    struct Person *actualPerson = copy_node(expectedPerson);

    // Assert

    TEST_ASSERT_EQUAL_PERSON(expectedPerson, actualPerson);
    TEST_ASSERT_NOT_EQUAL_PTR(expectedPerson, actualPerson);
}

void test_successfullyDeletingAddressFromTheBeginningOfFullList(void)
{
    struct Person *list = NULL;
    int ret = 0;

    struct Person *expectedPerson = &(struct Person) {
        .name = "Jane",
        .surname = "Smith",
        .email = "jane@example.com",
        .number = "987-654-3210",
        .next = NULL
    };
    int expectedRet = 0;
    
    // Arrange

    struct Person *person1 = create_node("John", "Doe", "john@example.com", "123-456-7890");
    struct Person *person2 = create_node(expectedPerson->name, expectedPerson->surname,
                                         expectedPerson->email, expectedPerson->number);

    add_to_the_end_of_the_list(&list, person1);
    add_to_the_end_of_the_list(&list, person2);

    // Act

    ret = delete_addr_at_pos(&list, 1);

    // Assert

    TEST_ASSERT_EQUAL_PERSON(expectedPerson, list);
    TEST_ASSERT_EQUAL_INT(expectedRet, ret);
}

void test_successfullyDeletingTheOnlyElementOfList(void)
{
    struct Person *list = NULL;
    int ret = 0;

    int expectedRet = 0, expectedSize = 0;
    
    // Arrange

    struct Person *person = create_node("John", "Doe", "john@example.com", "123-456-7890");
    add_to_the_end_of_the_list(&list, person);

    // Act

    ret = delete_addr_at_pos(&list, 1);
    
    // Assert

    TEST_ASSERT_EQUAL_INT(expectedRet, ret);
    TEST_ASSERT_EQUAL_INT(expectedSize, size_of_the_book(list));
}

void test_successfullyDeletingAddressFromTheEndOfFullList(void)
{
    struct Person *list = NULL, *temp;
    int ret = 0;

    struct Person *expectedPerson1 = &(struct Person) {
        .name = "John",
        .surname = "Doe",
        .email = "john@example.com",
        .number = "123-456-7890",
        .next = NULL
    };
    struct Person *expectedPerson2 = &(struct Person) {
        .name = "Jane",
        .surname = "Smith",
        .email = "jane@example.com",
        .number = "987-654-3210",
        .next = NULL
    };
    struct Person *expectedPerson3 = &(struct Person) {
        .name = "Alice",
        .surname = "Johnson",
        .email = "alice@example.com",
        .number = "555-555-5555",
        .next = NULL
    };

    int expectedRet = 0, expectedSize = 3;
    
    // Arrange

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

    // Act

    ret = delete_addr_at_pos(&list, 4);

    // Assert

    TEST_ASSERT_EQUAL_PERSON(expectedPerson1, temp);
    temp = temp->next;
    TEST_ASSERT_EQUAL_PERSON(expectedPerson2, temp);
    temp = temp->next;
    TEST_ASSERT_EQUAL_PERSON(expectedPerson3, temp);
    TEST_ASSERT_EQUAL_INT(expectedRet, ret);
    TEST_ASSERT_EQUAL_INT(expectedSize, size_of_the_book(list));
}

void test_successfullyDeletingAddressFromTheMiddleOfList(void)
{
    struct Person *list = NULL, *temp;
    int ret = 0;

    struct Person *expectedPerson1 = &(struct Person) {
        .name = "John",
        .surname = "Doe",
        .email = "john@example.com",
        .number = "123-456-7890",
        .next = NULL
    };
    struct Person *expectedPerson2 = &(struct Person) {
        .name = "Jane",
        .surname = "Smith",
        .email = "jane@example.com",
        .number = "987-654-3210",
        .next = NULL
    };
    struct Person *expectedPerson3 = &(struct Person) {
        .name = "Alice",
        .surname = "Johnson",
        .email = "alice@example.com",
        .number = "555-555-5555",
        .next = NULL
    };
    int expectedRet = 0;
    int expectedSize = 3;
    
    // Arrange

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

    // Act

    ret = delete_addr_at_pos(&list, 3);

    // Assert

    TEST_ASSERT_EQUAL_PERSON(expectedPerson1, temp);
    temp = temp->next;
    TEST_ASSERT_EQUAL_PERSON(expectedPerson2, temp);
    temp = temp->next;
    TEST_ASSERT_EQUAL_PERSON(expectedPerson3, temp);
    TEST_ASSERT_EQUAL_INT(expectedRet, ret);
    TEST_ASSERT_EQUAL_INT(expectedSize, size_of_the_book(list));
}

void test_unsuccessfullyDeletingAddressFromEmptyList(void)
{
    struct Person *list = NULL;
    int ret = 0;

    int expectedRet = 1;
    
    // Act

    ret = delete_addr_at_pos(&list, 3);

    // Assert

    TEST_ASSERT_EQUAL_INT(expectedRet, ret);
}

void test_unsuccessfullyDeletingAddressFromNotExistingPos(void)
{
    struct Person *list = NULL, *temp;
    int ret = 0;

    struct Person *expectedPerson1 = &(struct Person) {
        .name = "John",
        .surname = "Doe",
        .email = "john@example.com",
        .number = "123-456-7890",
        .next = NULL
    };
    struct Person *expectedPerson2 = &(struct Person) {
        .name = "Jane",
        .surname = "Smith",
        .email = "jane@example.com",
        .number = "987-654-3210",
        .next = NULL
    };

    int expectedRet = 1;
    int expectedSize = 2;
    
    // Arrange

    struct Person *person1 = create_node(expectedPerson1->name, expectedPerson1->surname,
                                         expectedPerson1->email, expectedPerson1->number);

    struct Person *person2 = create_node(expectedPerson2->name, expectedPerson2->surname,
                                         expectedPerson2->email, expectedPerson2->number);
                                         

    add_to_the_end_of_the_list(&list, person1);
    add_to_the_end_of_the_list(&list, person2);

    temp = list;

    // Act

    ret = delete_addr_at_pos(&list, 3);

    // Assert

    TEST_ASSERT_EQUAL_PERSON(expectedPerson1, temp);
    temp = temp->next;
    TEST_ASSERT_EQUAL_PERSON(expectedPerson2, temp);

    TEST_ASSERT_EQUAL_INT(expectedRet, ret);
    TEST_ASSERT_EQUAL_INT(expectedSize, size_of_the_book(list));
}

void test_deletingEmptyList(void)
{
    struct Person *list = NULL;

    int expectedSize = 0;

    // Act

    delete_list(&list);

    // Assert

    TEST_ASSERT_EQUAL_INT(expectedSize, size_of_the_book(list));

}


void test_deletingListOf1Element(void)
{
    struct Person *list = NULL;

    int expectedSize = 0;

    // Arrange

    struct Person *person = create_node("Bob", "Brown", "bob@example.com", "888-888-8888");                                     
    add_to_the_end_of_the_list(&list, person);

    // Act

    delete_list(&list);

    // Assert

    TEST_ASSERT_EQUAL_INT(expectedSize, size_of_the_book(list));
}

void test_deletingFullList(void)
{
    struct Person *list = NULL;

    int expectedSize = 0;

    // Arrange

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

    // Act

    delete_list(&list);

    // Assert

    TEST_ASSERT_EQUAL_INT(expectedSize, size_of_the_book(list));
}

void test_successfullyFindingAddressByKeywordName(void)
{
    struct Person *list = NULL;

    struct Person *expectedPerson = &(struct Person) {
        .name = "Jane",
        .surname = "Smith",
        .email = "jane@example.com",
        .number = "987-654-3210",
        .next = NULL
    };

    // Arrange

    struct Person *person1 = create_node("Bob", "Brown", "bob@example.com", "888-888-8888");

    struct Person *person2 = create_node(expectedPerson->name, expectedPerson->surname, 
                                         expectedPerson->email, expectedPerson->number);

    struct Person *person3 = create_node("Charlie", "Smith", "charlie@example.com", "123-456-7890");

    add_to_the_end_of_the_list(&list, person1);
    add_to_the_end_of_the_list(&list, person2);
    add_to_the_end_of_the_list(&list, person3);

    // Act

    struct Person *actualPerson = find_address_by_keyword(list, "Smith");

    // Assert

    TEST_ASSERT_EQUAL_PERSON(expectedPerson, actualPerson);
}

void test_unsuccessfullyFindingAddressByKeyword(void)
{
    struct Person *list = NULL;

    // Arrange

    struct Person *person1 = create_node("Bob", "Brown", "bob@example.com", "888-888-8888");
    struct Person *person2 = create_node("David", "Williams", "david@example.com", "987-654-3210");
    struct Person *person3 = create_node("Charlie", "Smith", "charlie@example.com", "123-456-7890");

    add_to_the_end_of_the_list(&list, person1);
    add_to_the_end_of_the_list(&list, person2);
    add_to_the_end_of_the_list(&list, person3);

    // Act

    struct Person *actualPerson = find_address_by_keyword(list, "------");

    // Assert

    TEST_ASSERT_NULL(actualPerson);
}

void test_successfullyFindingAddressByIndexFromTheMiddle(void)
{
    struct Person *list = NULL;

    struct Person *expectedPerson = &(struct Person) {
        .name = "Jane",
        .surname = "Smith",
        .email = "jane@example.com",
        .number = "987-654-3210",
        .next = NULL
    };

    // Arrange

    struct Person *person1 = create_node("Bob", "Brown", "bob@example.com", "888-888-8888");

    struct Person *person2 = create_node(expectedPerson->name, expectedPerson->surname, 
                                         expectedPerson->email, expectedPerson->number);

    struct Person *person3 = create_node("Charlie", "Smith", "charlie@example.com", "123-456-7890");

    add_to_the_end_of_the_list(&list, person1);
    add_to_the_end_of_the_list(&list, person2);
    add_to_the_end_of_the_list(&list, person3);

    // Act

    struct Person *actualPerson = find_address(&list, 2);

    // Assert

    TEST_ASSERT_EQUAL_PERSON(expectedPerson, actualPerson);
}

void test_successfullyFindingAddressByIndexFromTheBeginning(void)
{
    struct Person *list = NULL;

    struct Person *expectedPerson = &(struct Person) {
        .name = "Jane",
        .surname = "Smith",
        .email = "jane@example.com",
        .number = "987-654-3210",
        .next = NULL
    };

    // Arrange

    struct Person *person1 = create_node(expectedPerson->name, expectedPerson->surname, 
                                         expectedPerson->email, expectedPerson->number);
    struct Person *person2 = create_node("Bob", "Brown", "bob@example.com", "888-888-8888");
    struct Person *person3 = create_node("Charlie", "Smith", "charlie@example.com", "123-456-7890");

    add_to_the_end_of_the_list(&list, person1);
    add_to_the_end_of_the_list(&list, person2);
    add_to_the_end_of_the_list(&list, person3);

    // Act

    struct Person *actualPerson = find_address(&list, 1);

    // Assert

    TEST_ASSERT_EQUAL_PERSON(expectedPerson, actualPerson);
}

void test_successfullyFindingAddressByIndexFromTheEnd(void)
{
    struct Person *list = NULL;

    struct Person *expectedPerson = &(struct Person) {
        .name = "Jane",
        .surname = "Smith",
        .email = "jane@example.com",
        .number = "987-654-3210",
        .next = NULL
    };

    // Arrange  
    
    struct Person *person1 = create_node("Bob", "Brown", "bob@example.com", "888-888-8888");
    struct Person *person2 = create_node("Charlie", "Smith", "charlie@example.com", "123-456-7890");
    struct Person *person3 = create_node(expectedPerson->name, expectedPerson->surname, 
                                         expectedPerson->email, expectedPerson->number);

    add_to_the_end_of_the_list(&list, person1);
    add_to_the_end_of_the_list(&list, person2);
    add_to_the_end_of_the_list(&list, person3);

    // Act

    struct Person *actualPerson = find_address(&list, 3);

    // Assert

    TEST_ASSERT_EQUAL_PERSON(expectedPerson, actualPerson);
}

void test_unsuccessfullyFindingAddressByNegativeIndex(void)
{
    struct Person *list = NULL;

    // Arrange

    struct Person *person1 = create_node("Bob", "Brown", "bob@example.com", "888-888-8888");
    struct Person *person2 = create_node("David", "Williams", "david@example.com", "987-654-3210");
    struct Person *person3 = create_node("Charlie", "Smith", "charlie@example.com", "123-456-7890");

    add_to_the_end_of_the_list(&list, person1);
    add_to_the_end_of_the_list(&list, person2);
    add_to_the_end_of_the_list(&list, person3);

    // Act

    struct Person *actualPerson = find_address(&list, -1);

    // Assert

    TEST_ASSERT_NULL(actualPerson);
}

void test_unsuccessfullyFindingAddressByPositiveIndex(void)
{
    struct Person *list = NULL;

    // Arrange

    struct Person *person1 = create_node("Bob", "Brown", "bob@example.com", "888-888-8888");
    struct Person *person2 = create_node("David", "Williams", "david@example.com", "987-654-3210");
    struct Person *person3 = create_node("Charlie", "Smith", "charlie@example.com", "123-456-7890");

    add_to_the_end_of_the_list(&list, person1);
    add_to_the_end_of_the_list(&list, person2);
    add_to_the_end_of_the_list(&list, person3);

    // Act

    struct Person *actualPerson = find_address(&list, 5);

    // Assert

    TEST_ASSERT_NULL(actualPerson);
}

void test_unsuccessfullyFindingAddressByZeroIndex(void)
{
    struct Person *list = NULL;

    // Arrange

    struct Person *person1 = create_node("Bob", "Brown", "bob@example.com", "888-888-8888");
    struct Person *person2 = create_node("David", "Williams", "david@example.com", "987-654-3210");
    struct Person *person3 = create_node("Charlie", "Smith", "charlie@example.com", "123-456-7890");

    add_to_the_end_of_the_list(&list, person1);
    add_to_the_end_of_the_list(&list, person2);
    add_to_the_end_of_the_list(&list, person3);

    // Act

    struct Person *actualPerson = find_address(&list, 0);

    // Assert

    TEST_ASSERT_NULL(actualPerson);
}

void test_sizeOfFullBook(void)
{
    struct Person *list = NULL;
    int actualSize;

    int expectedSize = 3;

    // Arrange

    struct Person *person1 = create_node("David", "Williams", "david@example.com", "987-654-3210");
    struct Person *person2 = create_node("Bob", "Brown", "bob@example.com", "888-888-8888");
    struct Person *person3 = create_node("Charlie", "Smith", "charlie@example.com", "123-456-7890");

    add_to_the_end_of_the_list(&list, person1);
    add_to_the_end_of_the_list(&list, person2);
    add_to_the_end_of_the_list(&list, person3);

    // Act

    actualSize = size_of_the_book(list);

    // Assert

    TEST_ASSERT_EQUAL_INT(expectedSize, actualSize);
}

void test_sizeOfBookOf1Element(void)
{
    struct Person *list = NULL;
    int actualSize;

    int expectedSize = 1;

    // Arrange

    list = create_node("David", "Williams", "david@example.com", "987-654-3210");

    // Act

    actualSize = size_of_the_book(list);

    // Assert

    TEST_ASSERT_EQUAL_INT(expectedSize, actualSize);
}


void test_sizeOfEmptyBook(void)
{
    struct Person *list = NULL;
    int actualSize;

    int expectedSize = 0;

    // Act

    actualSize = size_of_the_book(list);

    // Assert

    TEST_ASSERT_EQUAL_INT(expectedSize, actualSize);
}

#endif
