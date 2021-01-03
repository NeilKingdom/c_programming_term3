/***************************************************************************
   Filename: test_llist.h
   Version:  1.0
   Author:   Surbhi Bahri
   S/N:      040967309
   Lab:      010
   Assign#:  5
   Assign:   Single Linked List
   Due:      2020/11/23
   Date:     2020/11/23
   Prof:     Surbhi Bahri
   Purpose:  Contains all tests for check test runner
***************************************************************************/

START_TEST ( test_contains ) {
   
   	node_t * head = NULL;
   	
   	llist_push( &head, 10 );
   	ck_assert( llist_contains( head, 10 ) == 1 );
  	llist_free( &head );
  	
}
END_TEST

 START_TEST ( test_count ) {
   
   	node_t * head = NULL;
 
   	ck_assert(  llist_count( head, 10 ) == 0 );  	
   	llist_push( &head, 10 );
   	llist_push( &head, 10 );
   	llist_push( &head, 10 );
   	llist_push( &head, 10 );
   	ck_assert( llist_count( head, 10 ) == 4 );
   	
   	llist_free( &head );
  
}
END_TEST

START_TEST ( test_find ) {
   
   	node_t * head = NULL;
   
   	ck_assert( llist_find( head,  5 ) == -1 );	
   	llist_push( &head, 10 );
   	llist_push( &head, 5 );
   	ck_assert( llist_find( head,  5 ) ==  0 );
   	ck_assert( llist_find( head, 10 ) ==  1);
   	ck_assert( llist_find( head,  7 ) == -1 );
   
  	llist_free( &head );
  
}
END_TEST

START_TEST ( test_equal ) {
   
   	node_t * h1 = NULL;
   	node_t * h2 = NULL;

	ck_assert( llist_is_equal( h1, h1 ) );
   	llist_push( &h1, 10 );
   	llist_push( &h1, 5  );
	llist_push( &h2, 10 );
   	llist_push( &h2, 5  );
	ck_assert( llist_is_equal( h1, h2 ) );
	llist_push( &h2, 15 );
	ck_assert( !llist_is_equal( h1, h2 ) );   	
	 
  	llist_free( &h1 );
  	llist_free( &h2 );
}
END_TEST

START_TEST ( test_addlast ) {
   
   	node_t * h1 = NULL;

   	llist_addlast( &h1, 76 );
 	ck_assert( llist_find( h1, 76 ) == 0 );   	
   	llist_push( &h1, 10 );
   	llist_push( &h1,  5 );
   	llist_push( &h1,  8 ); 
   	llist_addlast( &h1, 20 );

	ck_assert( llist_size( h1 ) == 5 );
	ck_assert( llist_find( h1, 20 ) == 4 );   	
	 
  	llist_free( &h1 );
}
END_TEST

START_TEST ( test_insert ) {
   
   	node_t * h1 = NULL;

   	llist_insert( &h1, 76, 0 );
 	ck_assert( llist_find( h1, 76 ) == 0 );   	
    	ck_assert( llist_insert( &h1, 6, 10 ) == 1 );
 	ck_assert(!llist_contains( h1, 6 ) );  
   	llist_push( &h1, 10 );
   	llist_push( &h1,  5 );
   	llist_push( &h1,  8 ); 
   	llist_insert( &h1, 20, 2 );
	ck_assert( llist_size( h1 ) == 5 );
	ck_assert( llist_find( h1, 20 ) == 2 );   
	 
  	llist_free( &h1 );
}
END_TEST

START_TEST ( test_remove ) {
   
   	node_t * h1 = NULL;

   	llist_remove( &h1, 10 );
  	
 	llist_push( &h1, 10 );	
    	llist_remove( &h1,  10 ); 
 	ck_assert( llist_count( h1, 10 ) == 0 ); 
  
	llist_push( &h1, 20 );
	llist_push( &h1, 10 );
   	llist_push( &h1,  5 );
   	llist_push( &h1,  8 ); 
 	llist_push( &h1, 10 );
    	llist_remove( &h1,  10 );    	
 	ck_assert( llist_count( h1, 10 ) == 1 ); 
 	 
   	llist_remove( &h1,  8 ); 
 	ck_assert(!llist_contains( h1, 8 ) );
 	 
    	llist_remove( &h1,  10 ); 
   	ck_assert( llist_count( h1, 10 ) == 0 );   

  	llist_free( &h1 );
}
END_TEST
