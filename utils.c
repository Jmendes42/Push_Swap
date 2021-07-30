#include "push_swap.h"

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
