#include "push_swap.h"

int	zerochk(int *stack, int size)
{
	int index;

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
	int index;

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

int	organizeGhost(int *stack, int size)
{
	int	tmp;
	int	index;
	int	stackGhost[size];

	index = 0;
	while (index < size)
	{
		stackGhost[index] = stack[index];
		index++;
	}
	index = 0;
	while (index < size)
	{
		while (stackGhost[index] > stackGhost[index + 1])
		{
			if (stackGhost[index + 1] == 0)
				break ;
			tmp = stackGhost[index];
			stackGhost[index] = stackGhost[index + 1];
			stackGhost[index + 1] = tmp;
			 index--;
		}
		index++;
	}
	index = 0;
	while (index < size)
	{
		index++;
	}
	return (stackGhost[size / 2]);
}

int	stackRun(int *stack, int size, int value)
{
	int index;

	index = 0;
	while (index < size)
	{
		if (stack[index] <= value)
			return (1);
		index++;
	}
	return (0);
}

void	sender(int *stack_a, int *stack_b, t_list *s_st)
{
	int index;

	index = 0;
	while (s_st->sizeA > 3)
	{
		s_st->value = organizeGhost(stack_a, s_st->size);
		while (index < s_st->size)
		{
			if (stack_a[index] <= s_st->value && stack_a[index] != 0)
			{
				printf("%d$$$$$\n", stack_a[index]);
				p(stack_b, stack_a, 2, s_st);
			}
			else
				r(stack_a, s_st->size, 1);
			if (stackRun(stack_a, s_st->sizeA, s_st->value) == 0)
				break ;
			if (s_st->sizeA == 3)
				break ;
			index++;
		}
	}
	index = 0;
	Digits(stack_a, s_st->sizeA);
	index = 0;
	while (index < s_st->size)
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
	}
}

