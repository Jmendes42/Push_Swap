/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmendes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 12:43:43 by jmendes           #+#    #+#             */
/*   Updated: 2021/08/06 16:57:33 by jmendes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	Digits(int *stack, int sizeA)
{
	if (stack[0] < stack[1] && stack[1] < stack[2])
		return ;
	else if (stack[0] > stack[1] && stack[2] > stack[0])
		s(stack, 1);
	else if (stack[0] > stack[1] && stack[1] > stack[2])
	{
		s(stack, 1);
		rr(stack, sizeA, 1);
	}
	else if (stack[0] > stack[1] && stack[2] > stack[1])
		r(stack, sizeA, 1);
	else if (stack[0] < stack[2] && stack[0] < stack[1])
	{
		s(stack, 1);
		r(stack, sizeA, 1);
	}
	else if (stack[0] < stack[1] && stack[0] > stack[2])
		rr(stack, sizeA, 1);
	else if (stack[0] > stack[2] && stack[1] > stack[2])
		rr(stack, sizeA, 1);
	else if (stack[0] > stack[1] && stack[0] > stack[2])
		r(stack, sizeA, 1);
}

void	biggerRotate(int *stack, t_list *s_st, int control, int up)
{
	int	index;

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

int	main(int argc, char *argv[])
{
	t_list	s_st;
	int		index;

	index = 0;
	s_st.stack_a = (int *)malloc(sizeof(int) * (argc - 1));
	s_st.stack_b = (int *)malloc(sizeof(int) * (argc - 1));
	initStruct(&s_st, argc);
	initStacks(s_st.stack_a, s_st.stack_b, s_st.size, argv);
	if (argc == 4)
	{
		Digits(s_st.stack_a, s_st.sizeA);
		return (0);
	}
	/*r(s_st.stack_a, s_st.sizeA, 1);
	while (index < s_st.size)
	{
		printf("%d\n", s_st.stack_a[index]);
		index++;
	}
		index = 0;
	while (index < s_st.sizeB)
	{
		printf("%d\n", s_st.stack_b[index]);
		index++;
	}
	return (9);*/
	sender(s_st.stack_a, s_st.stack_b, &s_st);
	free (s_st.stack_a);
	free (s_st.stack_b);
}
