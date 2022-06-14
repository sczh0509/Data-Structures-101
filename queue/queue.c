#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

// Create queue struct
typedef struct queue
{
	int	items[SIZE];
	int	front;
	int	rear;
}	qu;

// Create empty queue
void	createEmptyQueue(qu *q)
{
	q->front = -1;
	q->rear = -1;
}

// Add items in queue
void	enQueue(qu *q, int new)
{
	if (q->rear == SIZE - 1)
	{
		printf("queue is full.\n");
	}
	else
	{
		if (q->front == -1)
		{
			q->front = 0;
		}
		q->rear++;
		q->items[q->rear] = new;
		printf("item added into queue is: %d\n", q->items[q->rear]);
	}
}

// Remove items from queue
void	deQueue(qu *q)
{
	if (q->front == -1)
	{
		printf("queue is empty.\n");
	}
	else
	{
		printf("item removed is: %d\n", q->items[q->front]);
		q->front++;
		if (q->front > q->rear)
		{
			q->front = -1;
			q->rear = -1;
		}
	}
}

// Display elements of a queue
void	display(qu *q)
{
	if (q->front == -1)
	{
		printf("queue is empty.\n");
	}
	else
	{
		for (int i = q->front; i <= q->rear; i++)
		{
			printf("%d\n", q->items[i]);
		}
	}
}

// Driver code
int	main(void)
{
	qu *q;

	q = malloc(sizeof(qu));
	createEmptyQueue(q);

	// won't be able to dequeue an empty queue
	deQueue(q);

	for (int i = 1; i < 6; i++)
	{
		enQueue(q, i);
	}

	// can't enqueue cause queue is already full
	enQueue(q, 6);
	display(q);
	// remove first element of queue 
	deQueue(q);
	display(q);

	// free memory allocated for queue
	free (q);
	return (0);
}
