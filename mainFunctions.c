#include "push_swap.h"

int	organizeGhost(int *stack, int size, t_list *s_st)
{
	int	value;
	int	index;
	int	*stackGhost;
	int	control;

	index = 0;
	stackGhost = calloc(s_st->size, sizeof(int *));
	while (index < s_st->size)
	{
		stackGhost[index] = stack[index];
		index++;
	}
	if (s_st->size > 100)
		control = 1;
	else
		control = 0;
	value = subOrganizeGhost(stackGhost, size, control, s_st);
	index = 0;
	free (stackGhost);
	return (value);
}

int	stackRun(int *stack, int size, int value, t_list *s_st)
{
	int	index;

	index = 0;
	while (index < size)
	{
		if (stack[index] < value)
		{
			s_st->bigPosition = index;
			return (1);
		}
		index++;
	}
	return (0);
}

void	biggerNumber(int *stack, int size, t_list *s_st)
{
	int	index;

	s_st->value = INT_MIN;
	index = 0;
	while (index < size)
	{
		if (stack[index] > s_st->value)
		{
			s_st->value = stack[index];
			s_st->position = index;
		}
		index++;
	}
}

void	subSender(int *stack_a, int *stack_b, t_list *s_st)
{
	while (s_st->sizeB > 0)
	{
		biggerNumber(stack_b, s_st->sizeB, s_st);
		while (stack_b[0] != s_st->value)
		{
			if (s_st->position > (s_st->sizeB / 2))
				rr(stack_b, s_st->sizeB, 2);
			else
				r(stack_b, s_st->sizeB, 2);
		}
		pa(stack_a, stack_b, s_st);
	}
}

void	sender(int *stack_a, int *stack_b, t_list *s_st)
{
	while (s_st->sizeA > 3)
	{
		s_st->value = organizeGhost(stack_a, s_st->sizeA, s_st);
		while (stackRun(stack_a, s_st->sizeA, s_st->value, s_st) != 0)
		{	
			while (stack_a[0] < s_st->value)
			{
				pb(stack_b, stack_a, s_st);
			}
			if (s_st->bigPosition > (s_st->sizeA / 2))
				rr(stack_a, s_st->sizeA, 1);
			else
				r(stack_a, s_st->sizeA, 1);
			while (stack_a[0] < s_st->value)
			{
				pb(stack_b, stack_a, s_st);
			}
		}
	}
	Digits(stack_a, s_st->sizeA);
	subSender(stack_a, stack_b, s_st);
}
