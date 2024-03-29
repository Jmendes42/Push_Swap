/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmendes <jmendes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 11:51:45 by jmendes           #+#    #+#             */
/*   Updated: 2022/09/29 01:45:12 by jmendes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	s(int *stack, int control)
{
	int	tmp;

	if (stack[1] < 1)
		return ;
	tmp = stack[0];
	stack[0] = stack[1];
	stack[1] = tmp;
	if (control == 1)
		write(1, "sa\n", 3);
	else if (control == 2)
		write(1, "sb\n", 3);
}

void	ss(int *stack_a, int *stack_b)
{
	s(stack_a, 0);
	s(stack_b, 0);
}

void	r(int *stack, int size, int control)
{
	int	tmp;
	int	index;

	index = 0;
	tmp = stack[0];
	while (index < size - 1)
	{
		stack[index] = stack[index + 1];
		index++;
	}
	stack[size - 1] = tmp;
	if (control == 1)
		write(1, "ra\n", 3);
	else if (control == 2)
		write(1, "rb\n", 3);
}

void	r_r(int *stack_a, int *stack_b, int size)
{
	r(stack_a, size, 0);
	r(stack_b, size, 0);
}

void	rr(int *stack, int size, int control)
{
	int	tmp;

	tmp = stack[size - 1];
	while (size > 1)
	{
		stack[size - 1] = stack[size - 2];
		size--;
	}
	stack[0] = tmp;
	if (control == 1)
		write(1, "rra\n", 4);
	else if (control == 2)
		write(1, "rrb\n", 4);
}
