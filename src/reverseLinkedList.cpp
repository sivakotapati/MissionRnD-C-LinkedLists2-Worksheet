/*
OVERVIEW: Given a single linked list, reverse the linked list.
E.g.: 1->2->3->4->5, output is 5->4->3->2->1.

INPUTS: A linked list.

OUTPUT: Reverse the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include<stdlib.h>
struct node {
	int num;
	struct node *next;
};
void add_node_at_front(struct node **, int);
struct node * reverseLinkedList(struct node *head) {
	if (head == NULL)//checking for valid head 
		return NULL;

	struct node *rev = NULL;
	while (head != NULL){
		add_node_at_front(&rev, head->num);
		head = head->next;
	}
	return rev;
}

void add_node_at_front(struct node **h, int k){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->num = k;
	temp->next = NULL;
	
	if (*h != NULL)
		temp->next = *h; 
	*h = temp;
}