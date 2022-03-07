/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 20:36:16 by radan             #+#    #+#             */
/*   Updated: 2022/03/07 20:37:41 by radan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stacks *valid_num)
{
	t_stack	*s;

	s = valid_num->a[1];
	valid_num->a[1] = valid_num->a[0];
	valid_num->a[0] = s;
	write(1, "sa\n", 3);
}

void	sb(t_stacks *valid_num)
{
	t_stack	*s;

	s = valid_num->b[1];
	valid_num->b[1] = valid_num->b[0];
	valid_num->b[0] = s;
	write(1, "sb\n", 3);
}

void	pa(t_stacks *valid_num)
{
	int		i;
	t_stack	*s;

	i = 0;
	if (valid_num->num_of_b == 0)
		return ;
	i = valid_num->num_of_a;
	s = valid_num->a[i];
	while (i > 0)
	{
		valid_num->a[i] = valid_num->a[i - 1];
		i--;
	}
	valid_num->a[0] = valid_num->b[0];
	i = 0;
	while (i + 1 < valid_num->num_of_b)
	{
		valid_num->b[i] = valid_num->b[i + 1];
		i++;
	}
	valid_num->b[i] = s;
	valid_num->num_of_b--;
	valid_num->num_of_a++;
	write(1, "pa\n", 3);
}

void	pb(t_stacks *valid_num)
{
	int		i;
	t_stack	*s;

	i = 0;
	if (valid_num->num_of_a == 0)
		return ;
	i = valid_num->num_of_b;
	s = valid_num->b[i];
	while (i > 0)
	{
		valid_num->b[i] = valid_num->b[i - 1];
		i--;
	}
	valid_num->b[0] = valid_num->a[0];
	i = 0;
	while (i + 1 < valid_num->num_of_a)
	{
		valid_num->a[i] = valid_num->a[i + 1];
		i++;
	}
	valid_num->a[i] = s;
	valid_num->num_of_a--;
	valid_num->num_of_b++;
	write(1, "pb\n", 3);
}

void	ra(t_stacks *valid_num)
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
	write(1, "ra\n", 3);
}
