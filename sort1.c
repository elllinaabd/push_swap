/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 20:47:55 by radan             #+#    #+#             */
/*   Updated: 2022/03/07 20:48:33 by radan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two_elem(t_stacks *v_n)
{
	if (v_n->a[0]->data > v_n->a[1]->data)
		sa(v_n);
}

void	sort_three_elem(t_stacks *v_n)
{
	int	max;
	int	i;

	i = 0;
	max = v_n->a[0]->data;
	while (i < v_n->num_of_a)
	{
		if (v_n->a[i]->data > max)
			max = v_n->a[i]->data;
		i++;
	}
	if (v_n->a[0]->data == max)
		ra(v_n);
	if (v_n->a[1]->data == max)
		rra(v_n);
	if (v_n->a[0]->data > v_n->a[1]->data)
		sa(v_n);
}

int	find_min(t_stacks *v_n)
{
	int	i;
	int	min;

	i = 0;
	min = v_n->a[0]->data;
	while (i < v_n->num_of_a)
	{
		if (v_n->a[i]->data < min)
			min = v_n->a[i]->data;
		i++;
	}
	return (min);
}

int	find_max(t_stacks *v_n)
{
	int	i;
	int	max;

	i = 0;
	max = v_n->a[0]->data;
	while (i < v_n->num_of_a)
	{
		if (v_n->a[i]->data > max)
			max = v_n->a[i]->data;
		i++;
	}
	return (max);
}

void	sort_4or5_elem(t_stacks *v_n)
{
	int	min;
	int	max;

	min = find_min(v_n);
	max = find_max(v_n);
	while (v_n->num_of_a > 3)
	{
		if (v_n->a[0]->data == max || v_n->a[0]->data == min)
			pb(v_n);
		else
			ra(v_n);
	}
	sort_three_elem(v_n);
	pa(v_n);
	pa(v_n);
	if (v_n->a[0]->data == max)
		ra(v_n);
	else if (v_n->a[1]->data < v_n->a[2]->data)
		return ;
	else
	{
		sa(v_n);
		ra(v_n);
	}
}
