#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

// define a circular queue struct
typedef struct	circular_queue
{
	int	items[SIZE];
	int	front;
	int	rear;
}	cq;

// creating an empty circ_queue
void	createEmptyQueue(cq *c)
{
	c->front = -1;
	c->rear = -1;
}

// check if queue is full
int	isfull(cq *c)
{
	if ((c->front == 0 && c->rear == SIZE - 1) || c->front == c->rear + 1)
	{
		return (1);
	}
	return (0);
}

// check if queue is empty
int	isempty(cq *c)
{
	if (c->front == -1)
	{
		return (1);
	}
	return (0);
}

// adding elements
void	enQueue(cq *c, int new)
{
	if (isfull(c))
	{
		printf("Queue is full.\n");
	}
	else
	{
		if (c->front == -1)
		{
			c->front = 0;
		}
		c->rear = (c->rear + 1) % SIZE; 
		c->items[c->rear] = new;
		printf("Inserted -> %d\n", c->items[c->rear]);
	}
}

// removing elements
int	deQueue(cq *c)
{
	int	popped;

	if (isempty(c))
	{
		printf("Queue is empty.\n");
		return (0);
	}
	else
	{
		popped = c->items[c->front];
		if (c->front == c->rear)
		{
			c->front = -1;
			c->rear = -1;
		}
		else
		{
			c->front = (c->front + 1) % SIZE;
		}
		printf("Removed element -> %d\n", popped);
		return (popped);
	}
}

// display queue elements
void	display(cq *c)
{
	int	i;

	if (isempty(c))
	{
		printf("Queue is empty.\n");
	}
	else
	{
		printf("\n Front -> %d ", c->front);
		printf("\n Items -> ");
		for (i = c->front; i != c->rear; i = (i + 1) % SIZE)
		{
			printf("%d ", c->items[i]);
		}
		printf("%d ", c->items[i]);
		printf("\n Rear -> %d \n", c->rear);
	}
}

int	main()
{
	cq 	*c;
	int	i;

	c = malloc(sizeof(cq));

	// create empty queue
	createEmptyQueue(c);

	// will fail because queue is empty
	deQueue(c);
	
	for (i = 1; i <= 5; i++)
	{
		enQueue(c, i);
	}
	
	// will fail to enqueue because queue is full
	enQueue(c, 6);

	display(c);
	deQueue(c);
	display(c);
	enQueue(c, 7);
	display(c);

	return (0);
}

