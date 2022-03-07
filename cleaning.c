/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 20:33:40 by radan             #+#    #+#             */
/*   Updated: 2022/03/07 20:34:52 by radan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	free_stacks(t_stacks *valid_arg)
{
	free(valid_arg);
	return (0);
}

int	cleaning(t_stacks *valid_num, int i)
{
	while (--i >= 0)
		free(valid_num->a[i]);
	free(valid_num->a);
	free(valid_num);
	return (0);
}

int	cleaning_b(t_stacks *valid_num, int i)
{
	int	n;

	n = 0;
	while (n < i)
	{
		free(valid_num->b[n]);
		n++;
	}
	free(valid_num->b);
	return (cleaning(valid_num, i));
}
