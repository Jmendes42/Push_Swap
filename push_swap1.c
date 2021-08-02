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
	


	//meti a stack b a iniciar e isto empanca, verificar!
	//inicializar ambas as stacks a 0, e so depois usar a atoi
	//incrementar e decremnetar o tamanho das stacks? como?
	

	initStruct(&s_st, argc, argv);
//	zeroTransform(s_st.stack_a, s_st.size);
//	biggerNumber(s_st.stack_a, s_st.size, &s_st);
//	biggerRotate(s_st.stack_a, &s_st, 1, 0);
//	push(s_st.stack_a, s_st.stack_b, s_st.size);
	while (zerochk(s_st.stack_b, s_st.size) != 0)
	{
		biggerNumber(s_st.stack_b, s_st.size, &s_st);
		//printf("%d\n", s_st.position);
		biggerRotate(s_st.stack_b, &s_st, 2, 1);
		p(s_st.stack_b, s_st.stack_a, s_st.size, 1);
	}
	int index = 0;
	while (index < s_st.size)
	{
		printf("%d\n", s_st.stack_a[index]);
		index++;
	}
	free (s_st.stack_a);
	free (s_st.stack_b);
}
