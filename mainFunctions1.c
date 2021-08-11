/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainFunctions1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmendes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 04:25:37 by jmendes           #+#    #+#             */
/*   Updated: 2021/08/11 07:37:52 by jmendes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	initStruct(t_list *s_st, int argc)
{
	s_st->size = argc - 1;
	s_st->sizeA = argc - 1;
	s_st->sizeB = 0;
	s_st->position = 0;
	s_st->bigPosition = 0;
	s_st->value = 0;
	s_st->chunks = 0;
}

int	initStacks(int *stack_a, int *stack_b, int size, char *argv[])
{
	int	index;

	index = 0;
	while (index < size)
	{
		stack_a[index] = ft_atoi(argv[index + 1]);
		stack_b[index] = 0;
		index++;
	}
	if (size == 2)
	{
		if (stack_a[0] > stack_a[1])
		{
			s(stack_a, 1);
			return (1);
		}
	}
	return (0);
}

int	subSubOrganizeGhost(int *stackGhost, int size, int control, t_list *s_st)
{
	if (control == 1)
	{
		s_st->chunks = s_st->chunks + (s_st->size / 10);
		return (stackGhost[s_st->chunks]);
	}
	else
		return (stackGhost[size / 2]);
}

int	subOrganizeGhost(int *stackGhost, int size, int control, t_list *s_st)
{
	int	index;
	int	tmp;
	int	temp;

	temp = s_st->size;
	index = 0;
	if (control == 1)
		size = temp;
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
	return (subSubOrganizeGhost(stackGhost, size, control, s_st));
}
