/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmendes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 12:43:43 by jmendes           #+#    #+#             */
/*   Updated: 2021/08/03 06:15:02 by jmendes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void	zeroTransform(int *stack, int size)
{
	int index;

	index = 0;
	while (index < size - 1)
	{
		printf("%d\n", stack[index]);
		if (stack[index] == 0)
		{
			printf("%d\n", stack[index]);
			stack[index] = -1;
		}
		index++;
	}
}*/

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


void	Digits(int *stack, int sizeA)
{
	if (stack[0] > stack[1] && stack[2] > stack[0])
		s(stack, 1);
	if (stack[0] > stack[1] && stack[1] > stack[2])
	{
		s(stack, 1);
		rr(stack, sizeA, 1);
	}
	if (stack[0] > stack[1] && stack[2] > stack[1])
		r(stack, sizeA, 1);
	if (stack[0] < stack[2] && stack[0] < stack[1])
	{
		s(stack, 1);
		r(stack, sizeA, 1);
	}
	if (stack[0] < stack[1] && stack[0] > stack[2])
		rr(stack, sizeA, 1);
}

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

void	biggerNumber(int *stack, int size, t_list *s_st)
{
	int index;

	s_st->value = 0;
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
int	main(int argc, char *argv[])
{
	t_list	s_st;
	
	s_st.stack_a = (int *)malloc(sizeof(int) * (argc - 1));
	s_st.stack_b = (int *)malloc(sizeof(int) * (argc - 1));
	initStruct(&s_st, argc);
	initStacks(s_st.stack_a, s_st.stack_b, s_st.size, argv);
	s_st.value = organizeGhost(s_st.stack_a, s_st.size);
	sender(s_st.stack_a, s_st.stack_b, &s_st);
	if (argc == 4)
	{
		Digits(s_st.stack_a, s_st.sizeA);
		return (0);
	}
//	zeroTransform(s_st.stack_a, s_st.size);
//	biggerNumber(s_st.stack_a, s_st.size, &s_st);
//	biggerRotate(s_st.stack_a, &s_st, 1, 0);
//	push(s_st.stack_a, s_st.stack_b, s_st.size);
	while (zerochk(s_st.stack_b, s_st.size) != 0)
	{
		biggerNumber(s_st.stack_b, s_st.size, &s_st);
		biggerRotate(s_st.stack_b, &s_st, 2, 1);
		p(s_st.stack_b, s_st.stack_a, s_st.size, 1);
	}
	int index = 0;
	while (index < s_st.size)
	{
		printf("%d\n", s_st.stack_a[index]);
		index++;
	}
	index = 0;
	free (s_st.stack_a);
	free (s_st.stack_b);
}
