/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_work.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 20:49:45 by radan             #+#    #+#             */
/*   Updated: 2022/03/07 20:49:47 by radan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ev_b_rr(t_stacks *v_n, int s_n)
{
	int	i;

	i = find_place_b(v_n, s_n, 2147483647, -2147483647);
	if (i == 0)
	{
		if (s_n < v_n->b[0]->sort_numb)
			return (1);
		else
			return (0);
	}
	if (i > 0)
		return (i + 1);
	else
		return (i * (-1));
}

int	ev_b_rrr(t_stacks *v_n, int s_n)
{
	int	i;

	i = find_place_b(v_n, s_n, 2147483647, -2147483647);
	if (i == 0)
	{
		if (s_n < v_n->b[0]->sort_numb)
			return (v_n->num_of_b - 1);
		else
			return (0);
	}
	if (i > 0)
		return (v_n->num_of_b - (i + 1));
	else
		return (v_n->num_of_b - (-1) * i);
}

int	compration(int sum_rr, int sum_rrr, int sum_mix)
{
	if (sum_rr >= sum_rrr)
	{
		if (sum_rrr <= sum_mix)
			return (sum_rrr);
		else
			return (sum_mix);
	}
	else if (sum_rr <= sum_mix)
		return (sum_rr);
	else
		return (sum_mix);
}

void	i_v(t_stack *valid_num, int i, int b, int way)
{
	valid_num->step_a = i;
	valid_num->opt_way = way;
	valid_num->step_b = b;
}

void	push_to_a(t_stacks *v_n, int i)
{
	int	max;
	int	remeber;

	max = 0;
	while (++i < v_n->num_of_b)
	{
		if (v_n->b[i]->sort_numb >= max)
		{
			max = v_n->b[i]->sort_numb;
			remeber = i;
		}
	}
	i = -1;
	if (remeber <= v_n->num_of_b / 2)
	{
		while (++i < remeber)
			rb(v_n);
	}
	else
	{
		while (++i < v_n->num_of_b - remeber)
			rrb(v_n);
	}
	while (v_n->num_of_b > 0)
		pa(v_n);
}
