#include "push_swap.h"

int	zerochk(int *stack, int size)
{
	int	index;

	index = 0;
	while (index < size)
	{
		if (stack[index] != 0)
			return (-1);
		index++;
	}
	return (0);
}

/*void	push(int *stack_a, int *stack_b, int size)
{
	int index;

	index = 0;
	while (index < size - 1)
	{
		p(stack_a, stack_b, 2, s_st);
		//printf("%d\n", stack_b[index]);
		index++;
	}
}*/

void	initStruct(t_list *s_st, int argc)
{
	s_st->size = argc - 1;
	s_st->sizeA = argc - 1;
	s_st->sizeB = 0;
	s_st->position = 0;
	s_st->value = 0;
}

void	initStacks(int *stack_a, int *stack_b, int size, char *argv[])
{
	int	index;

	index = 0;
	while (index < size)
	{
		if (!ft_strncmp(argv[index + 1], "0", sizeof(argv[index + 1])))
			stack_b[index] = ft_atoi("-1");
		else
		{
			stack_a[index] = ft_atoi(argv[index + 1]);
			stack_b[index] = 0;
		}
		index++;
	}
}

int	subOrganizeGhost(int *stackGhost, int size)
{
	int index;
	int tmp;

	index = 0;
	while (index < size)
	{
		if (stackGhost[index] > stackGhost[index + 1])
		{
			tmp = stackGhost[index];
			stackGhost[index] = stackGhost[index + 1];
			stackGhost[index + 1] = tmp;
			 index = -1;
		}
		index++;
	}
	return (stackGhost[size / 2]);
}

int	organizeGhost(int *stack, int size)
{
	int	value;
	int	index;
	int	*stackGhost;

	index = 0;
	stackGhost = calloc(size, sizeof(int *));
	//stackGhost = (int *)malloc(sizeof(int) * size);
	while (index < size)
	{
		stackGhost[index] = stack[index];
		index++;
	}
	value = subOrganizeGhost(stackGhost, size);
	index = 0;
	free (stackGhost);
	return (value);
}

int	stackRun(int *stack, int size, int value)
{
	int index;

	index = 0;
	while (index < size)
	{
		if (stack[index] < value)
			return (1);
		index++;
	}
	return (0);
}

void	biggerNumber(int *stack, int size, t_list *s_st)
{
	int index;

	s_st->value = INT_MIN;
	index = 0;
	while (index < size)
	{
		if (stack[index] > s_st->value)
		{
			s_st->value = stack[index];
			s_st->position = index;
			//printf("%d\n", s_st->value);
			//printf("%d\n", s_st->position);
		}
		index++;
	}
}

void	sender(int *stack_a, int *stack_b, t_list *s_st)
{

	while (s_st->sizeA > 3)
	{
		s_st->value = organizeGhost(stack_a, s_st->sizeA);
		//printf("%d$$$$$\n", s_st->value);
		while (stackRun(stack_a, s_st->sizeA, s_st->value) != 0)
		{	
			if (stack_a[0] < s_st->value)
			{
				pb(stack_b, stack_a, s_st);
			}
			else 
				r(stack_a, s_st->sizeA, 1);
		}
	}
	Digits(stack_a, s_st->sizeA);
	while (s_st->sizeB > 0)
	{
		biggerNumber(stack_b, s_st->sizeB, s_st);
		while (stack_b[0] != s_st->value)
			r(stack_b, s_st->sizeB, 2);
		pa(stack_a, stack_b, s_st);
	}

	/*index = 0;
	while (index < s_st->sizeA)
	{
		printf("%d\n", s_st->stack_a[index]);
		index++;
	}
		printf("*****%d\n", s_st->sizeB);
		index = 0;
	while (index < s_st->sizeB)
	{
		printf("%d\n", s_st->stack_b[index]);
		index++;
	}*/
}
