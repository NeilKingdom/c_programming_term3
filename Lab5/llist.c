/*************************************************************************** 
	AUTHOR:   Neil Kingdom 
	S/N:		 040967309
	ASSIGN:	 5 - Single linked list
	COURSE:	 CST8234_010 - C Language
	PROF:		 Surhbi Bahri
   DUE:      20/11/23
	DATE:		 20/11/23
	FILES:	 llist.c, llist.h, test_llist.c, test_llist.h
***************************************************************************/

/**************************************************************************/
/* Declare include files
 **************************************************************************/
#include "llist.h"

/**************************************************************************/
/* Provided functions
 **************************************************************************/
 
/**************************************************************************/
/* llist_push:  Add an element to the head of the list
 **************************************************************************/
int llist_push( node_t **headRef, int data ) {

	node_t *new;

	if ( ( new = ( node_t *) malloc( sizeof( node_t ) ) ) == NULL )
		return EXIT_FAILURE;
	
	new->data = data;
	new->next = *headRef;
	*headRef  = new; 

	return 0;

}
/**************************************************************************/
/* llist_pop:   Removes first element of the list
 **************************************************************************/
void llist_pop   ( node_t **headRef ) {

	node_t *h = *headRef;
	
	if(h == NULL) {
		printf("Cannot pop because list is empty\n");
		return;
	}
	
	*headRef = h->next;
	free(h);

	return;
}
/**************************************************************************/
/* llist_size:  Returns number of elements in the list
 **************************************************************************/ 
int  llist_size  ( node_t * head ) {
	int cnt = 0;
	
	struct node * tmp = head;

	while( tmp != NULL ) {
		cnt++;
		tmp = tmp->next;
	}
	return cnt;

}
/**************************************************************************/
/* llist_print:   Prints a list
 **************************************************************************/
void llist_print ( node_t * head ){

	int nodes = 0;
	struct node *current = head;


	fprintf( stdout, "{ " );
	while( current != NULL ) {
		fprintf( stdout, "%4d -->", current->data );
		nodes++;
		current = current->next;
	}
	fprintf( stdout, " NULL }\n" );
		
	fprintf(stdout, "Number of elements in the list: %d\n", nodes );

	return;
}

/**************************************************************************/
/* User created functions 
 **************************************************************************/

/***************************************************************************
	Function: llist_count
	Author: Neil Kingdom
	Version: 1.0
	Params: h - Head node of the linked list, value - The key being searched
	Return: Function returns the # of occurences that key appeared in llist
	Purpose: This function counts the number of occurences that the user
		inputted value appears in the linked list	
***************************************************************************/
int llist_count(node_t *h, int value) {
	
	int count = 0;
	struct node *current = h;

	while(current != NULL) {
		if(current->data == value) 
			count++;
		current = current->next;
	}
	free(current);	
	return count;
}

/***************************************************************************
	Function: llist_is_equal
	Author: Neil Kingdom
	Version: 1.0
	Params: h1 - head of first linked list, h2 - head of second linked list
	Return: Returns 0 if lists are equal, or -1 if an error occured
	Purpose: This function will check if two linked lists are equivellant
***************************************************************************/
int llist_is_equal(node_t *h1, node_t *h2) {

	struct node *c1 = h1;
	struct node *c2 = h2;

	if(c1 == NULL && c2 == NULL) {
		printf("Both lists are empty\n");
		return -1;
	}

	while(c1 != NULL && c2 != NULL) {
		if((c1->next == NULL && c2->next != NULL) || (c1->next != NULL && c2->next == NULL)) {
			printf("Lists are of differing length\n");
			return -1;
		}
		else if(c1->data != c2->data)
			return -1;
		c1 = c1->next;
		c2 = c2->next;
	}
	
	free(c1);
	free(c2);	
	return 0;
}

/***************************************************************************
	Function: llist_addlast
	Author: Neil Kingdom
	Version: 1.0
	Params: href - A pointer to head node, value - Data for new node 
	Return: Returns 0 if the addition was successful, or -1 if the function
		failed.
	Purpose: This function adds a new node containing the user specified
		data to the end of the linked list
***************************************************************************/
int llist_addlast(node_t **href, int value) {

	struct node *current = *href;
	struct node *add = malloc(sizeof(struct node));
	if(add == NULL) {
		printf("Error allocating space for node\n");
		return -1;
	}

	add->data = value;
	add->next = NULL;

	if(*href == NULL) {
		*href = add;
		return 0;
	}

	while(current->next != NULL) {
		current = current->next;
	}

	current->next = add;	
	return 0;
}

/***************************************************************************
	Function: llist_insert
	Author: Neil Kingdom
	Version: 1.0
	Params: href - A pointer to head node, value - Data for new node, index -
		Index of where the new node should be placed 
	Return: Returns 0 if addition was successful, or -1 if an error occurred
	Purpose: This function inserts a new node at a user given position. If
		the index is out of bounds, the function returns -1
***************************************************************************/
int llist_insert(node_t **href, int value, int index) {

	int i;
	struct node *current = *href;
	struct node *add = malloc(sizeof(struct node));

	if(add == NULL) {
		printf("Error allocating space for node\n");
		return -1;
	}

	add->data = value;

	if(index == 0) {
		if(*href != NULL) 
			add->next = *href;
		*href = add;
		return 0;
	}

	else if(index == 1) {
		add->next = current->next;
		current->next = add;
		return 0;
	}

	for(i = 0; i < index-1; i++) {
		if(current->next == NULL) {
			printf("Index out of bounds\n");
			return -1;
		}
		current = current->next;
	}

	add->next = current->next;
	current->next = add;	
	return 0;
}

/***************************************************************************
	Function: llist_free
	Author: Neil Kingdom
	Version: 1.0
	Params: href - A pointer to head node
	Return: void
	Purpose: This function frees all allocated nodes within a given
		 linked list
***************************************************************************/
void llist_free(node_t **href) {
	
	struct node *current = *href;
	struct node *prev = NULL;
	while(current->next != NULL) {
		prev = current;
		current = current->next;
		free(prev);
	}
	/*Since prev is one behind current:*/
	prev = prev->next;
	free(prev);
	/*Only way to track that nodes have been freed is to set them = NULL*/
	*href = NULL;
}
