/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmendes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 15:56:02 by jmendes           #+#    #+#             */
/*   Updated: 2021/08/06 15:57:35 by jmendes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(int *stack_b, int *stack_a, t_list *s_st)
{
	int	tmp;

	tmp = stack_a[0];
	stack_a[0] = 0;
	r(stack_a, s_st->size, 0);
	rr(stack_b, s_st->size, 0);
	stack_b[0] = tmp;
	s_st->sizeA -= 1;
	s_st->sizeB += 1;
	write(1, "pb\n", 3);
}

void	pa(int *stack_a, int *stack_b, t_list *s_st)
{
	int	tmp;

	tmp = stack_b[0];
	stack_b[0] = 0;
	r(stack_b, s_st->size, 0);
	rr(stack_a, s_st->size, 0);
	stack_a[0] = tmp;
	s_st->sizeB -= 1;
	s_st->sizeA += 1;
	write(1, "pa\n", 3);
}

void	rr_r(int *stack_a, int *stack_b, int size)
{
	rr(stack_a, size, 0);
	rr(stack_b, size, 0);
}
