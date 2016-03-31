/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>
#include<malloc.h>
struct node {
	int num;
	struct node *next;
};
int linkedListLength(struct node * );
int linkedListMedian(struct node *head) {
	if (head == NULL){
		return -1;

	}
	
	struct node * temp=(struct node *)malloc(sizeof( struct node));
	int median = -1, len = 0,i;

	temp = head;
	
	len = linkedListLength(head);

	//finding median
	temp = head;
	i = 1;

    //if length of linked list is odd then median is the middle number
	//else median is average of middle pair of numbers
	if ((len % 2) != 0){
		while (i<=(len/2)){
			temp = temp->next;
			i++;
		}
		return temp->num;
	}
	else{
		i = 1;
		while (i < (len / 2)){
			temp = temp->next;
			i++;
		}
		median = ((temp->num) + (temp->next->num))/2;
	}
	return median;
}
int linkedListLength(struct node * h){
	int i = 0;

	while (h != NULL){
		++i;
		h = h->next;
	}
	return i;
}
