/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmendes <jmendes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 04:50:03 by jmendes           #+#    #+#             */
/*   Updated: 2022/09/29 01:46:03 by jmendes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_strlen(char *str)
{
	int	index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

int	ft_longatoi(const char *str)
{
	long long		res;
	int				sign;
	unsigned int	index;

	res = 0;
	sign = 1;
	index = 0;
	while (str[index] && ((str[index] >= 9 && str[index] <= 13)
			|| (str[index] == 32)))
		index++;
	if (str[index] == '-')
	{
		if (str[index + 1] == '-' || str[index + 1] == '+')
			return (0);
		sign = -1;
		index++;
	}
	if (str[index] == '+')
		index++;
	while (str[index] >= '0' && str[index] <= '9')
	{
		res = res * 10 + str[index] - '0';
		index++;
	}
	return ((res * sign));
}

int	ft_atoi(const char *str)
{
	long long		res;
	int				sign;
	unsigned int	index;

	res = 0;
	sign = 1;
	index = 0;
	while (str[index] && ((str[index] >= 9 && str[index] <= 13)
			|| (str[index] == 32)))
		index++;
	if (str[index] == '-')
	{
		if (str[index + 1] == '-' || str[index + 1] == '+')
			return (0);
		sign = -1;
		index++;
	}
	if (str[index] == '+')
		index++;
	while (str[index] >= '0' && str[index] <= '9')
	{
		res = res * 10 + str[index] - '0';
		index++;
	}
	return ((int)(res * sign));
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	index;

	index = 0;
	if (n == 0)
		return (0);
	while (s1[index] == s2[index] && index < n - 1 && s1[index] != '\0')
		index++;
	return ((unsigned char)s1[index] - (unsigned char)s2[index]);
}
