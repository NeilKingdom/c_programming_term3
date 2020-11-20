/* PROGRAM: SET	
	AUTHOR:  NEIL
   DATE:    2020-11-10 
   TOPIC:   Lab 4  
   PURPOSE: To create generic test cases for 
		checking if set functions are working properly
*/
#include <stdio.h>
#include <stdlib.h>
#include <check.h>
#include "set.h"

#define TEST_SUCCESS "SUCCESS: All current tests passed!"
#define TEST_FAILURE "FAILURE: At least one test failed or crashed"

/**********************  INIT TEST **********************************/
/*
 * init NULL
 */
START_TEST( init_NULL ) {
    
    	/*
	 *  Declare a set and initialize with basic values
	 */
    
    	set_t set  = { NULL, 0, 0 };
    	
    	/*
	 *  if the set has been initialized with capacity 10,
	 *  then size should be 0 and capacity 10
	 */
    
    	set_init(&set, 10);
    	set_clear(&set);
    	ck_assert(set_capacity(set) == 10);
    	ck_assert(set_size(set) == 0);
    	set_free(&set);
}
END_TEST


/**********************  CAPACITY TEST **********************************/
START_TEST( test_cap ) {
	set_t set = { NULL, 0, 0 };
 	/*capacity null*/
	set_init(&set, NULL);
	ck_assert(set_capacity(set) == NULL);
   ck_assert(set_size(set) == 0);
 	/*capacity reached*/
	ck_assert_int_eq(set_add(&set, 1), 1);
   ck_assert(set_size(set) == 0);
	set_free(&set);
}
END_TEST

/**********************  ADD TEST **********************************/
/*
 */
START_TEST( test_add ) {
	set_t set = { NULL, 0, 0 };
	set_init(&set, 5);
 	/*add multiple*/
	set_add(&set, 1);
	set_add(&set, 2);
	set_add(&set, 3);
	ck_assert(set_capacity(set) == 5);
	ck_assert_int_eq(set_size(set), 3);
	ck_assert(set.array != NULL);
 	/*add duplicated*/
	set_add(&set, 3);
	ck_assert_int_eq(set_size(set), 4);
 	/*add negative*/
	set_add(&set, -1);
	ck_assert_int_eq(set_size(set), 5);
 	/*add over capacitiy --> capacity_reached*/
	ck_assert_int_eq(set_add(&set, 1), 1);
	set_free(&set);
}
END_TEST

/**********************  REMOVE TEST **********************************/
START_TEST( test_remove ) {
	set_t set = { NULL, 0, 0 };
	set_init(&set, 5);
	set_add(&set, 1);
	set_add(&set, 2);
	set_add(&set, 3);
	set_add(&set, 3);
	set_add(&set, 4);
	set_remove(&set, 3);
	/*remove duplicates*/
	ck_assert_int_eq(set_contains(&set, 3), 1);
	ck_assert_int_eq(set_size(set), 3);
	/*remove from empty*/
	set_clear(&set);
	ck_assert_int_eq(set_remove(&set, 4), 1);
	set_free(&set);
}
END_TEST


/**********************  POP TEST **********************************/
START_TEST( test_pop ) {
	set_t set = { NULL, 0, 0 };
	set_init(&set, 5);
	set_add(&set, 1);
	set_add(&set, 2);
	set_add(&set, 3);
	set_pop(&set);
	ck_assert_int_eq(set.array[0], 2);
	ck_assert_int_eq(set_contains(&set, 1), 1);	
	set_free(&set);
}
END_TEST

/** GENERIC TEST SUITE CODE **/

Suite *test_suite(void) {
	Suite *s;
	TCase *tc_core;
	s = suite_create("Default");
	tc_core = tcase_create("Core");
   tcase_add_test(tc_core, init_NULL);
   tcase_add_test(tc_core, test_cap);
   tcase_add_test(tc_core, test_add);
   tcase_add_test(tc_core, test_remove);
   tcase_add_test(tc_core, test_pop);
	suite_add_tcase(s, tc_core);
	return s;
}

int run_testsuite(){

	int fail_nr;
	Suite *s;
	SRunner *sr;

	s = test_suite();
	sr = srunner_create(s);

	srunner_run_all(sr, CK_NORMAL);
	fail_nr = srunner_ntests_failed(sr);
	srunner_free(sr);

	printf("%s\n", fail_nr ? TEST_FAILURE : TEST_SUCCESS );

	return ( !fail_nr ) ? EXIT_SUCCESS : EXIT_FAILURE;
}

int main(int argc, char* argv[]){
    return run_testsuite();
}
