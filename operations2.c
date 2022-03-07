/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 20:37:47 by radan             #+#    #+#             */
/*   Updated: 2022/03/07 20:38:37 by radan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_stacks *valid_num)
{
	t_stack	*s;
	int		i;

	i = 0;
	s = valid_num->b[i];
	while (i + 1 < valid_num->num_of_b)
	{
		valid_num->b[i] = valid_num->b[i + 1];
		i++;
	}
	valid_num->b[i] = s;
	write(1, "rb\n", 3);
}

void	rr(t_stacks *valid_num)
{
	t_stack	*s;
	int		i;

	i = 0;
	s = valid_num->a[i];
	while (i + 1 < valid_num->num_of_a)
	{
		valid_num->a[i] = valid_num->a[i + 1];
		i++;
	}
	valid_num->a[i] = s;
	i = 0;
	s = valid_num->b[i];
	while (i + 1 < valid_num->num_of_b)
	{
		valid_num->b[i] = valid_num->b[i + 1];
		i++;
	}
	valid_num->b[i] = s;
	write (1, "rr\n", 3);
}

void	rra(t_stacks *valid_num)
{
	t_stack	*s;
	int		i;

	i = valid_num->num_of_a - 1;
	s = valid_num->a[valid_num->num_of_a - 1];
	while (i > 0)
	{
		valid_num->a[i] = valid_num->a[i - 1];
		i--;
	}
	valid_num->a[i] = s;
	write(1, "rra\n", 4);
}

void	rrb(t_stacks *valid_num)
{
	t_stack	*s;
	int		i;

	i = valid_num->num_of_b - 1;
	s = valid_num->b[valid_num->num_of_b - 1];
	while (i > 0)
	{
		valid_num->b[i] = valid_num->b[i - 1];
		i--;
	}
	valid_num->b[i] = s;
	write(1, "rra\n", 4);
}

void	rrr(t_stacks *valid_num)
{
	t_stack	*s;
	int		i;

	i = valid_num->num_of_a - 1;
	s = valid_num->a[valid_num->num_of_a - 1];
	while (i > 0)
	{
		valid_num->a[i] = valid_num->a[i - 1];
		i--;
	}
	valid_num->a[i] = s;
	i = valid_num->num_of_b - 1;
	s = valid_num->b[valid_num->num_of_b - 1];
	while (i > 0)
	{
		valid_num->b[i] = valid_num->b[i - 1];
		i--;
	}
	valid_num->b[i] = s;
	write(1, "rrr\n", 4);
}
