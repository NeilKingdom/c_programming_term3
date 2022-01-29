/* PROGRAM:  SET
   AUTHOR:   
   DATE:     
   TOPIC:     
   PURPOSE:  Type and Function declarations 
   NOTES:    
             
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
START_TEST ( init_NULL ) {
    
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
/*
 * capacity null
 * capacity reached
 */

/**********************  ADD TEST **********************************/
/*
 * add multiple
 * add duplicated
 * add negative
 * add over capacitiy --> capacity_reached
 */


/**********************  REMOVE TEST **********************************/
/*
 */


/**********************  POP TEST **********************************/
/*
 */


/** GENERIC TEST SUITE CODE **/

Suite * test_suite(void) {
	Suite *s;
	TCase *tc_core;
	s = suite_create("Default");
	tc_core = tcase_create("Core");

   	tcase_add_test(tc_core, init_NULL);
 

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

