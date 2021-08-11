/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmendes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 04:50:03 by jmendes           #+#    #+#             */
/*   Updated: 2021/08/11 04:52:53 by jmendes          ###   ########.fr       */
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

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	doubles(char *argv[])
{
	int	index;
	int	i;

	index = 1;
	i = 0;
	while (argv[index] != NULL)
	{
		i = index + 1;
		while (argv[i] != NULL)
		{
			if (ft_strncmp(argv[index], argv[i], 11) == 0)
				return (1);
			i++;
		}
		index++;
	}
	return (0);
}
