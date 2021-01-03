/***************************************************************************
   Filename: test_llist.c
   Version:  1.0
   Author:   Surbhi Bahri
   S/N:      040967309
   Lab:      010
   Assign#:  5
   Assign:   Single Linked List
   Due:      2020/11/23
   Date:     2020/11/23
   Prof:     Surbhi Bahri
   Purpose:  Primary test file for testing functions
***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <check.h>

#include "llist.h"
/*#include "test_llist.h"*/


#define TEST_SUCCESS "SUCCESS: All current tests passed!"
#define TEST_FAILURE "FAILURE: At least one test failed or crashed"
#define FILLER "*****************************************************************************"
#define NUM_RANDOM( min, max ) ( min + (int)( (double)max * rand() / ( RAND_MAX + 1.0 ) ) )

/*******************************************************************/
/* Function Prototypes
 *******************************************************************/
Suite * test_suite(void);
int run_testsuite(void);

/*******************************************************************/
/* Tests
 *******************************************************************/
START_TEST(test_count) {

	node_t *head = NULL;
 
   ck_assert(llist_count(head, 10) == 0);    
   llist_push(&head, 10);
   llist_push(&head, 10);
   llist_push(&head, 10);
   llist_push(&head, 10);

   ck_assert(llist_count(head, 10) == 4);
   llist_free(&head);
}
END_TEST

START_TEST(test_equal) {

	node_t *h1 = NULL;
   node_t *h2 = NULL;

   ck_assert(llist_is_equal(h1, h2) == -1);
	/*Push on h1 list*/
   llist_push(&h1, 10);
   llist_push(&h1, 5);
	/*Push on h2 list*/
   llist_push(&h2, 10);
   llist_push(&h2, 5);

   ck_assert(llist_is_equal(h1, h2) == 0);
   llist_push(&h2, 15);
   ck_assert(llist_is_equal(h1, h2) == -1);

   llist_free(&h1);
   llist_free(&h2);
}
END_TEST

START_TEST(test_addlast) {

 	node_t *h1 = NULL;

   llist_addlast(&h1, 76);
   ck_assert(llist_count(h1, 76) == 1);

   llist_push(&h1, 10);
   llist_push(&h1, 5);
   llist_push(&h1, 8);
   llist_addlast(&h1, 20);

   ck_assert(llist_size(h1) == 5);
   ck_assert(llist_count(h1, 20) == 1);

   llist_free(&h1);
}
END_TEST

START_TEST(test_insert) {

	node_t *h1 = NULL;

   llist_insert(&h1, 76, 0);
   ck_assert(llist_count(h1, 76) == 1);
   ck_assert(llist_insert(&h1, 6, 10) == -1);
   ck_assert(llist_count(h1, 6) == 0);

   llist_push(&h1, 10);
   llist_push(&h1, 5);
   llist_push(&h1, 8);
   llist_insert(&h1, 20, 2);

   ck_assert(llist_size(h1) == 5);
   ck_assert(llist_count(h1, 20) == 1);

	llist_free(&h1);
}
END_TEST
	
START_TEST(test_free) {
	
	node_t *h1 = NULL;
	llist_push(&h1, 1);
	llist_push(&h1, 2);
	llist_push(&h1, 3);
	ck_assert(h1 != NULL);

	llist_free(&h1);
	ck_assert(h1 == NULL);
}
END_TEST

/*******************************************************************/
/* main( ) 
 *******************************************************************/
int main(int argc, char* argv[]){
	srand(time(NULL));
   return run_testsuite();
}


/*******************************************************************/
/* test_suit( ) 
 *******************************************************************/
Suite * test_suite(void) {
	Suite *s;
	TCase *tc_llist;
	
	s = suite_create("ALL CASES Link List");
	tc_llist = tcase_create("Link List");

	/***************  TEST A **********************
	 * 10 Cases
	 **********************************************/
  	tcase_add_test(tc_llist, test_count);
   tcase_add_test(tc_llist, test_equal);
   tcase_add_test(tc_llist, test_addlast);
   tcase_add_test(tc_llist, test_insert);
   tcase_add_test(tc_llist, test_free);
	
	suite_add_tcase( s, tc_llist );
	
	return s;
}

/*******************************************************************/
/* run_testsuite( ) 
 *******************************************************************/
int run_testsuite(){

	int fail_nr;
	Suite *s;
	SRunner *sr;

	printf("%s\n", FILLER );
	
	s = test_suite();
	sr = srunner_create(s);
	
	srunner_run_all(sr, CK_VERBOSE);

	fail_nr = srunner_ntests_failed(sr);
	srunner_free(sr);
	printf("%s\n", FILLER );
	printf("%s\n", fail_nr ? TEST_FAILURE : TEST_SUCCESS );
	printf("%s\n", FILLER );

	return ( !fail_nr ) ? EXIT_SUCCESS : EXIT_FAILURE;
}
