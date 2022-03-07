/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 20:46:30 by radan             #+#    #+#             */
/*   Updated: 2022/03/07 20:47:04 by radan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sum_step(int a, int b, int i)
{
	if (i == 1)
		a = 0;
	if (a >= b)
		return (a);
	else
		return (b);
}

int	find_place_b(t_stacks *v_n, int s, int m, int x)
{
	int	i;
	int	remeber;
	int	remeber_m;

	i = -1;
	while (++i < v_n->num_of_b)
	{
		if (v_n->b[i]->sort_numb - s == 1)
			return (i);
		else if (v_n->b[i]->sort_numb - s > 0 && v_n->b[i]->sort_numb - s < m)
		{
			remeber = i;
			m = v_n->b[i]->sort_numb - s;
		}
		else if (v_n->b[i]->sort_numb - s == -1)
			return (-i);
		else if (v_n->b[i]->sort_numb - s < 0 && v_n->b[i]->sort_numb - s > x)
		{
			remeber_m = i;
			x = v_n->b[i]->sort_numb - s;
		}
	}
	if (m > x * (-1))
		remeber = remeber_m * (-1);
	return (remeber);
}

int	sortet(t_stacks *valid_num, int num_of_elem)
{
	int	i;

	i = 1;
	while (i < num_of_elem)
	{
		if (valid_num->a[i - 1]->data < valid_num->a[i]->data)
			i++;
		else
			return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stacks	*valid_num;
	int			num_of_elem;

	valid_num = malloc(sizeof(t_stacks));
	if (!valid_num)
		return (0);
	valid_num->num_of_b = 0;
	num_of_elem = check_valid_arg(argc, argv, valid_num);
	if (!num_of_elem)
		return (0);
	valid_num->num_of_a = num_of_elem;
	if (sortet(valid_num, num_of_elem) || num_of_elem == 1)
		return (cleaning_b(valid_num, num_of_elem));
	else if (num_of_elem == 2)
		sort_two_elem(valid_num);
	else if (num_of_elem == 3)
		sort_three_elem(valid_num);
	else if (num_of_elem == 4 || num_of_elem == 5)
		sort_4or5_elem(valid_num);
	else
		sort_elem(valid_num, num_of_elem, -1);
	return (cleaning_b(valid_num, num_of_elem));
}
