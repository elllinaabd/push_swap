/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 20:48:39 by radan             #+#    #+#             */
/*   Updated: 2022/03/07 20:49:32 by radan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_work(t_stacks *v, int i)
{
	int	sum_rr;
	int	sum_rrr;
	int	sum_mix;

	while (++i < v->num_of_a)
	{
		v->a[i]->step_b = ev_b_rr(v, v->a[i]->sort_numb);
		sum_rr = sum_step(i, v->a[i]->step_b, 0);
		v->a[i]->step_b = ev_b_rrr(v, v->a[i]->sort_numb);
		sum_rrr = sum_step(v->num_of_a - i, v->a[i]->step_b, v->num_of_a);
		if (i <= v->num_of_a / 2)
			sum_mix = i + v->a[i]->step_b;
		else
			sum_mix = v->num_of_a - i + ev_b_rr(v, v->a[i]->sort_numb);
		v->a[i]->step_sum = compration(sum_rr, sum_rrr, sum_mix);
		if (v->a[i]->step_sum == sum_rr)
			i_v(v->a[i], i, ev_b_rr(v, v->a[i]->sort_numb), 1);
		else if (v->a[i]->step_sum == sum_rrr)
			i_v(v->a[i], v->num_of_a - i, ev_b_rrr(v, v->a[i]->sort_numb), 2);
		else if (i <= v->num_of_a / 2)
			i_v(v->a[i], i, ev_b_rrr(v, v->a[i]->sort_numb), 3);
		else
			i_v(v->a[i], v->num_of_a - i, ev_b_rr(v, v->a[i]->sort_numb), 4);
	}
}

void	f_sort(t_stacks *v_n)
{
	int	i;
	int	min;
	int	remeber;

	i = -1;
	min = v_n->a[0]->step_sum;
	if (v_n->num_of_b == 0)
		pb(v_n);
	stack_work(v_n, -1);
	remeber = 0;
	while (++i < v_n->num_of_a)
	{
		if (v_n->a[i]->step_sum <= min)
		{
			min = v_n->a[i]->step_sum;
			remeber = i;
		}
	}
	push_to_b(v_n, remeber);
	if (v_n->num_of_a != 0)
		f_sort(v_n);
}

int	part(int *sort_mas, int l, int r)
{
	int	less;
	int	t;

	less = l;
	while (l < r)
	{
		if (sort_mas[l] < sort_mas[r])
		{
			t = sort_mas[l];
			sort_mas[l] = sort_mas[less];
			sort_mas[less++] = t;
		}
		l++;
	}
	t = sort_mas[less];
	sort_mas[less] = sort_mas[r];
	sort_mas[r] = t;
	return (less);
}

void	sortirovka(int *sort_mas, int l, int r)
{
	int	q;

	if (l < r)
	{
		q = part(sort_mas, l, r);
		sortirovka(sort_mas, l, q - 1);
		sortirovka(sort_mas, q + 1, r);
	}
}

void	sort_elem(t_stacks *v_n, int num_of_elem, int i)
{
	int	*sort_mas;
	int	counter;

	sort_mas = malloc(sizeof(char) * num_of_elem + 1);
	if (!sort_mas)
		return ;
	while (++i < num_of_elem)
		sort_mas[i] = v_n->a[i]->data;
	sortirovka(sort_mas, 0, i - 1);
	i = 0;
	while (i < num_of_elem)
	{
		counter = -1;
		while (++counter < num_of_elem)
		{
			if (sort_mas[i] == v_n->a[counter]->data)
			{
				v_n->a[counter]->sort_numb = ++i;
				break ;
			}
		}
	}
	free(sort_mas);
	f_sort(v_n);
	push_to_a(v_n, -1);
}
