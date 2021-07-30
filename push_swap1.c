#include "push_swap.h"

static void	initStruct(t_strc *strc)
{
	strc->size = 0;
}

int	main(int argc, char *argv[])
{
	t_strc	strc;
	int	index;
	int	*stack_a;
	int	*stack_b;
	
	initStruct(&strc);
	strc.size = argc - 1;
	index = 0;
	stack_a = (int *)malloc(sizeof(int) * argc - 1);
	stack_b = (int *)malloc(sizeof(int) * argc - 1);
	while (index < argc - 1)
	{
		stack_a[index] = ft_atoi(argv[index + 1]);
		stack_b[index] = 0;
		index++;
	}
	p(stack_a, stack_b, strc.size, 2);
	rr(stack_a, strc.size, 1);
	index = 0;
	while (index < argc -1)
	{
		printf("%d\n", stack_a[index]);
		index++;
	}
	index = 0;
	while (index < argc -1)
	{
		printf("%d\n", stack_b[index]);
		index++;
	}
	free (stack_a);
}
