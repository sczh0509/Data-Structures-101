#include <stdio.h>
#include <stdlib.h>

#define MAX 10

// Creating a stack struct
typedef struct	stack
{
	int	items[MAX];
	int	top;
}	st;

// Initialize top to -1 to indicate empty stack
void	createEmptyStack(st *s)
{
	s->top = -1;
}

// Check if stack is full
int	isfull(st *s)
{
	if (s->top == MAX - 1)
	{
		return (1);
	}
	return (0);
}

// Check if stack is empty
int	isempty(st *s)
{
	if (s->top == -1)
	{
		return (1);
	}
	return (0);
}

// Add elements into stack
void	push(st *s, int new)
{
	if (isfull(s))
	{
		printf("stack is full.\n");
	}
	else
	{
		s->top++;
		s->items[s->top] = new;
	}	
}

// Remove elements from stack
void	pop(st *s)
{
	if (isempty(s))
	{
		printf("stack is empty.\n");
	}
	else
	{
		printf("item popped is %d.\n", s->items[s->top]);
		s->top--;
	}
}

// Print elements in stack
void	printStack(st *s)
{
	int i;
	
	if (isempty(s))
	{
		printf("Stack is empty.\n");
	}
	else
	{
		i = 0;
		printf("Stack is made up of: \n");
		while (i <= s->top)
		{
			printf("%d\n", s->items[i]);
			i++;
		}
	}
}

// Driver code
int	main(void)
{
	st *s;
	s = malloc(sizeof(sizeof(st)));
	createEmptyStack(s);
	printStack(s);
	push(s, 2);
	push(s, 4);
	push(s, 8);

	printStack(s);

	pop(s);

	printf("After popping.\n");
	printStack(s);
	free(s);

	return (0);
}
