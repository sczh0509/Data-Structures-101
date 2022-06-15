#include <stdio.h>

int	size = 0;

// fn to swap values
void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

// fn to heapify
void	heapify(int array[], int size, int i)
{
	int	largest;
	int	left;
	int	right;

	if (size == 1)
	{
		printf("Single element in the heap.\n");
	}
	else
	{
		largest = i;
		left = 2 * i + 1;
		right = 2 * i + 2;
		if (left < size && array[left] > array[largest])
		{
			largest = left;
		}
		if (right < size && array[right] > array[largest])
		{
			largest = right;
		}
		if (largest != i)
		{
			ft_swap(&array[i], &array[largest]);
			heapify(array, size, largest);
		}
	}
}

// fn to insert
void	insert(int array[], int new)
{
	if (size == 0)
	{
		array[0] = new;
		size += 1;
	}
	else
	{
		array[size] = new;
		size += 1;
		for (int i = size / 2 - 1; i >= 0; i--)
		{
			heapify(array, size, i);
		}
	}
}

// fn to delete root
void	deleteRoot(int array[], int num)
{
	int	i;
	int	j;

	for (i = 0; i < size; i++)
	{
		if (num == array[i])
		{
			break;
		}
	}
	ft_swap(&array[i], &array[size - 1]);
	size -= 1;
	for (j = size / 2 - 1; j >= 0; j--)
	{
		heapify(array, size, j);
	}
}

// display heap
void	printHeap(int array[], int size)
{
	int i;

	if (size == 0)
	{
		printf("Nothing to display. Heap is empty.\n");
	}
	else
	{
		printf("heap contains -> ");
		for (i = 0; i <= size - 1; i++)
		{
			printf("%d ", array[i]);
		}
		printf("\n");
	}
}

// driver code
int	main(void)
{
	int	array[10];
	int	i;

	for (i = 1; i <= 10; i++)
	{
		insert(array, i);
	}
	printf("Max-Heap array \n");
	printHeap(array, size);
	deleteRoot(array, 5);
	printf("After deletion of element value 5 ");
	printHeap(array, size);
}
