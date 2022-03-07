/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 20:34:07 by radan             #+#    #+#             */
/*   Updated: 2022/03/07 20:35:47 by radan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(char *str)
{
	int		sign;
	int		num;
	int		i;

	sign = 1;
	num = 0;
	i = 0;
	if (!str[i])
		return (MAX_INT);
	if ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		return (ft_error(1));
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i++] - '0') * sign;
		if ((sign > 0 && num < 0) || (sign < 0 && num > 0))
			return (ft_error(1));
	}
	if (str[i])
		return (ft_error(1));
	return (num);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strlen_2(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (--i);
}

int	ft_strrchr(char **str, int argc, int start, int step_argc)
{
	long	c1;
	long	c2;

	if (argc <= 0)
	{
		if (ft_atoi(str[argc]) == MAX_INT)
			return (0);
		return (1);
	}
	while (argc > 0)
	{
		c2 = ft_atoi(str[argc]);
		if (c2 == MAX_INT)
			return (0);
		step_argc = argc--;
		while (--step_argc >= start)
		{
			c1 = ft_atoi(str[step_argc]);
			if (c1 == MAX_INT)
				return (0);
			if (c2 - c1 == 0)
				return (ft_error(0));
		}
	}
	return (1);
}
