/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmendes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 12:43:43 by jmendes           #+#    #+#             */
/*   Updated: 2021/08/11 07:36:36 by jmendes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	subError(char *argv[], int max)
{
	int	index;

	index = 1;
	if (doubles(argv) == 1)
		return (1);
	while (argv[index] != NULL)
	{
		if (ft_strlen(argv[index]) > 10)
			return (1);
		max = ft_longatoi(argv[index]);
		if (max > INT_MAX || max < INT_MIN)
			return (1);
		index++;
	}
	return (0);
}

int	subSubError(char *argv[], int index, int i)
{
	i = 0;
	while (argv[index][i] != '\0')
	{
		if (ft_isdigit(argv[index][i]) == 0)
		{
			if (argv[index][i] == '-' && i == 0)
				i++;
			else
				return (1);
		}
		i++;
	}
	return (0);
}

int	error(int argc, char *argv[])
{
	int				index;
	int				i;
	long long int	max;

	i = 0;
	max = 0;
	index = argc - 1;
	while (index > 0)
	{
		if (subSubError(argv, index, i) == 1)
			return (1);
		index--;
	}
	return (subError(argv, max));
}

int	order(int *stack, int size)
{
	int	i;

	i = 0;
	while (i + 1 < size)
	{
		if (stack[i] < stack[i + 1])
			i++;
		else
			return (1);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_list	s_st;

	if (error(argc, argv) == 1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	s_st.stack_a = (int *)malloc(sizeof(int) * (argc - 1));
	s_st.stack_b = (int *)malloc(sizeof(int) * (argc - 1));
	initStruct(&s_st, argc);
	if (initStacks(s_st.stack_a, s_st.stack_b, s_st.size, argv) == 1)
		return (0);
	if (order(s_st.stack_a, s_st.sizeA) == 0)
		return (0);
	if (argc == 4)
	{
		Digits(s_st.stack_a, s_st.sizeA);
		return (0);
	}
	sender(s_st.stack_a, s_st.stack_b, &s_st);
	free (s_st.stack_a);
	free (s_st.stack_b);
}
