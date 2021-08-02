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

void	push(int *stack_a, int *stack_b, int size)
{
	int index;

	index = 0;
	while (index < size - 1)
	{
		p(stack_a, stack_b, size, 2);
		//printf("%d\n", stack_b[index]);
		index++;
	}
}

void	initStruct(t_list *s_st, int argc, char *argv[])
{
	int	index;

	index = 0;
	s_st->stack_a = (int *)malloc(sizeof(int) * (argc - 1));
	s_st->stack_b = (int *)malloc(sizeof(int) * (argc - 1));
	while (index < argc - 1)
	{
		if (!ft_strncmp(argv[index + 1], "0", sizeof(argv[index + 1])))
			s_st->stack_b[index] = ft_atoi("-1");
		else
			s_st->stack_b[index] = ft_atoi(argv[index + 1]);
		s_st->stack_a[index] = 0;
		index++;
	}
	s_st->size = argc - 1;
	s_st->position = 0;
	s_st->value = 0;
}
