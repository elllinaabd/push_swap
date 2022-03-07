/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radan <radan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 20:32:00 by radan             #+#    #+#             */
/*   Updated: 2022/03/07 22:40:00 by radan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_error(int i)
{
	if (i == 1)
	{
		write (i, "Error\n", 6);
		return (MAX_INT);
	}
	else
	{
		write (1, "Error\n", 6);
		return (0);
	}
}

int	create_stack_b(t_stacks *valid_num, int lenght)
{
	int	i;

	i = 0;
	valid_num->b = malloc(sizeof(char **) * lenght + 1);
	if (!valid_num->b)
	{
		free(valid_num);
		return (0);
	}
	while (lenght > i)
	{
		valid_num->b[i] = malloc(sizeof(t_stack));
		if (!valid_num->b[i])
		{
			cleaning_b(valid_num, lenght);
			return (0);
		}
		valid_num->b[i]->sort_numb = 0;
		i++;
	}
	return (1);
}

int	stck_rec_num(char **str, t_stacks *valid_num, int start, int lenght)
{
	int	i;

	i = 0;
	lenght += 1;
	valid_num->a = malloc(sizeof(char **) * lenght + 1);
	if (!valid_num->a)
		return (cleaning(valid_num, i));
	while (lenght - start > i)
	{
		valid_num->a[i] = malloc(sizeof(t_stack));
		if (!valid_num->a[i])
			return (cleaning(valid_num, i));
		valid_num->a[i]->data = ft_atoi(str[i + start]);
		valid_num->a[i]->sort_numb = 0;
		i++;
	}
	if (!create_stack_b(valid_num, lenght))
		return (cleaning(valid_num, i));
	return (i);
}

int	check_valid_arg(int argc, char **argv, t_stacks *valid_num)
{
	char	**str;
	int		step_argc;

	step_argc = 0;
	str = NULL;
	if (argc < 2)
	{
		write (1, "No args\n", 8);
		return (free_stacks(valid_num));
	}
	else if (argc == 2)
	{
		str = ft_split(argv[1], ' ');
		if (!str)
			return (free_stacks(valid_num));
		if (!ft_strrchr(str, ft_strlen_2(str), 0, step_argc))
			return (free_stacks(valid_num));
		return (stck_rec_num(str, valid_num, 0, ft_strlen_2(str)));
	}
	else
	{
		if (!ft_strrchr(argv, --argc, 1, step_argc))
			return (free_stacks(valid_num));
		return (stck_rec_num(argv, valid_num, 1, argc));
	}
}
