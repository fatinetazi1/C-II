/*
JTSK-320112
a6_p2.c
Fatine Tazi
f.tazi@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

static void copy_to_node(Item item, Node *pn);
//static void copy_to_item(Node *pn, Item *pi);

void initialize_queue(Queue *pq)
{
	pq->front = pq->rear = NULL;
	pq->items = 0;
}

int queue_is_full(const Queue *pq)
{
	return pq->items == MAXQUEUE;
}

int queue_is_empty(const Queue *pq)
{
	return pq->items == 0;
}

int queue_item_count(const Queue *pq)
{
	return pq->items;
}

int enqueue(Item item, Queue *pq)
{
	Node *new = (Node*)(malloc((1)*sizeof(Node)));
	copy_to_node(item, new);
	if (queue_is_full(pq)){
		printf("Queue Overflow");
		exit(1);
	}
	if(pq->front == NULL && pq->rear == NULL){
		pq->front = pq->rear = new;
		pq->items = 1;
	} else {
		pq->rear->next = new;
		new->next = NULL;
		pq->rear = new;
		pq->items++;
	}
    return 0;
}

int dequeue(Item *pitem, Queue *pq)
{
	if (queue_is_empty(pq)){
		printf("Queue Underflow");
		exit(1);
	}
	Node *temp = (Node*)(malloc((1)*sizeof(Node)));
	temp = pq->front;
	pq->front = pq->front->next;
	*pitem = temp->item;
	free(temp);
	pq->items--;
    return 0;
}

void empty_queue(Queue *pq)
{
	Item dummy;
	while (!queue_is_empty(pq)) {
		dequeue(&dummy, pq);
	}
}

static void copy_to_node(Item item, Node *pn)
{
	pn->item = item;
}

/*static void copy_to_item(Node *pn, Item *pi)
{
	*pi = pn->item;
}*/
