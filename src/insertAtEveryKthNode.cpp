/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};
int linked_list_length(struct node *);
struct node * insertAtEveryKthNode(struct node *head, int K) {
	//inserts value K at every Kth node and returns head,returns  NULL in fail cases

	//checking for invalid condition
	if (head == NULL || K <= 0){
		return NULL;
	}

	int len = 0, i, count = 0;

	//getting length of linked list
	len = linked_list_length(head);
	if (K > len){
		return head;
	}

	struct node *curr;
	curr = head;

	for (i = 1; i <= len;i++){
		if (count == K - 1){
			struct node *temp = (struct node *)malloc(sizeof(struct node));
			temp->num = K;
			temp->next = NULL;

			//inserting node at Kth position
			temp->next = curr->next;
			curr->next = temp;

			curr = temp->next;
			count = 0;
		}
		else{
			curr = curr->next;
			count++;
		}
	}//for

	return head;
}


int linked_list_length(struct node * h){
	int i = 0;

	while (h != NULL){
		++i;
		h = h->next;
	}
	return i;
}
