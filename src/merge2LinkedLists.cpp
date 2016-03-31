/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include<stdlib.h>
struct node {
	int num;
	struct node *next;
};
void add_node_at_end(struct node **h, int k);
struct node * merge2LinkedLists(struct node *head1, struct node *head2) {

	if (head1 == NULL&&head2 == NULL)//checking for valid inputs
		return NULL;
	if (head1 == NULL)
		return head2;
	if (head2 == NULL)
		return head1;

	//m is resultant list after merging two sorted linked lists i.e, head1,head2
	struct node * result = NULL;

	//applying merge algorithm
	for (; head1 != NULL&&head2 != NULL;){
		if (head1->num <= head2->num){
			add_node_at_end(&result, head1->num);
			head1 = head1->next;
		}
		else{
			add_node_at_end(&result, head2->num);
			head2 = head2->next;
		}
	}
	while (head1 != NULL){
		add_node_at_end(&result, head1->num);
		head1 = head1->next;
	}

	while (head2 != NULL){
		add_node_at_end(&result, head2->num);
		head2 = head2->next;
	}

	return result;
}
void add_node_at_end(struct node **h, int k){
	//inserting node at end
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	struct node *curr;
	temp->num = k;
	temp->next = NULL;

	if (*h == NULL){
		*h = temp;
		curr = temp;
	}
	else 
	{
		//moving upto end of linked list
		curr = *h;
		while (curr->next != NULL){
			curr = curr->next;
		}
		curr->next = temp;

	}

}
