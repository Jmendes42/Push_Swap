/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmendes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 12:43:43 by jmendes           #+#    #+#             */
/*   Updated: 2021/08/01 17:46:58 by jmendes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	biggerNumber(int *stack, int size, t_list *s_st)
{
	int index;

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

/*void	smallerNumber(int *stack, int size)
{
	int index;

	index = 0;
	while (index < size)
	{
		if (stack[index] < s_st->value)
		{
			s_st->value = stack[index];
			s_st->position = index;
		}
		index++;
	}
}*/

void	biggerRotate(int *stack, t_list *s_st, int control, int up)
{
	int index;

	if (up == 0)
		index = s_st->position + 1;
	else
		index = s_st->position;
	if (s_st->position <= ((s_st->size - 1) / 2))
	{
		while (index > 0)
		{
			r(stack, s_st->size, control);
			index--;
		}
	}
	else
	{
		while (index < s_st->size)
		{
			rr(stack, s_st->size, control);
			index++;
		}
	}
}

void	push(int *stack_a, int *stack_b, int size)
{
	int index;

	index = 0;
	while (index < size - 1)
	{
		p(stack_a, stack_b, size, 2);
		index++;
	}
}

static void	initStruct(t_list *s_st, int argc, char *argv[])
{
	int	index;

	index = 0;
	s_st->stack_a = (int *)malloc(sizeof(int) * (argc - 1));
	s_st->stack_b = (int *)malloc(sizeof(int) * (argc - 1));
	while (index < argc - 1)
	{
		s_st->stack_a[index] = ft_atoi(argv[index + 1]);
		s_st->stack_b[index] = 0;
		index++;
	}
	s_st->size = argc - 1;
	s_st->position = 0;
	s_st->value = 0;
}

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

int	main(int argc, char *argv[])
{
	t_list	s_st;
	
	initStruct(&s_st, argc, argv);
	biggerNumber(s_st.stack_a, s_st.size, &s_st);
	biggerRotate(s_st.stack_a, &s_st, 1, 0);
	push(s_st.stack_a, s_st.stack_b, s_st.size);
	while (zerochk(s_st.stack_b, s_st.size) != 0)
	{
		biggerNumber(s_st.stack_b, s_st.size, &s_st);
		biggerRotate(s_st.stack_b, &s_st, 2, 1);
		p(s_st.stack_b, s_st.stack_a, s_st.size, 1);
	}








	printf("%d\n", s_st.stack_a[0]);
	printf("%d\n", s_st.stack_a[1]);
	printf("%d\n", s_st.stack_a[2]);
	printf("%d\n", s_st.stack_a[3]);
	printf("*******************\n");
	printf("%d\n", s_st.stack_b[0]);
	printf("%d\n", s_st.stack_b[1]);
	printf("%d\n", s_st.stack_b[2]);
	printf("%d\n", s_st.stack_b[3]);
	/*p(stack_a, stack_b, s_st.size, 2);
	rr(stack_a, s_st.size, 1);
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
	}*/
	free (s_st.stack_a);
	free (s_st.stack_b);
}
