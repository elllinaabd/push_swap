/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radan <radan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 20:47:38 by radan             #+#    #+#             */
/*   Updated: 2022/03/07 22:40:14 by radan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>

# define MAX_INT 2147483648

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_stack {
	int	data;
	int	step_sum;
	int	step_a;
	int	step_b;
	int	opt_way;
	int	sort_numb;

}	t_stack;

typedef struct s_stacks {
	int		num_of_a;
	int		num_of_b;
	int		min;

	t_stack	**a;
	t_stack	**b;

}	t_stacks;

int		main(int argc, char **argv);
int		sortet(t_stacks *valid_num, int num_of_elem);
void	sort_two_elem(t_stacks *v_n);
void	sort_three_elem(t_stacks *v_n);
void	sa(t_stacks *valid_num);
void	sb(t_stacks *valid_num);
void	pa(t_stacks *valid_num);
void	pb(t_stacks *valid_num);
void	ra(t_stacks *valid_num);
void	rb(t_stacks *valid_num);
void	rr(t_stacks *valid_num);
void	rra(t_stacks *valid_num);
void	rrb(t_stacks *valid_num);
void	rrr(t_stacks *valid_num);
int		num_space(char *s, char c);
char	*make_word(char *str, int first, int last);
char	**ft_split(char *s, char c);
long	ft_error(int i);
int		free_stacks(t_stacks *valid_arg);
int		ft_strrchr(char **str, int argc, int start, int step_argc);
int		ft_strlen_2(char **str);
int		cleaning(t_stacks *valid_num, int i);
int		cleaning_b(t_stacks *valid_num, int i);
int		create_stack_b(t_stacks *valid_num, int lenght);
int		stck_rec_num(char **str, t_stacks *valid_num, int start, int lenght);
int		check_valid_arg(int argc, char **argv, t_stacks *valid_num);
long	ft_atoi(char *str);
int		ft_strlen(char *str);
int		find_min(t_stacks *v_n);
int		find_max(t_stacks *v_n);
void	sort_4or5_elem(t_stacks *v_n);
void	sort_elem(t_stacks *v_n, int num_of_elem, int i);
void	sortirovka(int *sort_mas, int l, int r);
int		part(int *sort_mas, int l, int r);
void	f_sort(t_stacks *v_n);
void	stack_work(t_stacks *v, int i);
int		ev_b_rr(t_stacks *v_n, int s_n);
int		ev_b_rrr(t_stacks *v_n, int s_n);
int		compration(int sum_rr, int sum_rrr, int sum_mix);
void	i_v(t_stack *valid_num, int i, int b, int way);
void	push_to_a(t_stacks *v_n, int i);
void	push_to_b(t_stacks *v_n, int r);
int		sortet(t_stacks *valid_num, int num_of_elem);
int		find_place_b(t_stacks *v_n, int s, int m, int x);
int		sum_step(int a, int b, int i);
void	push_w_4(t_stacks *v_n, int r);
void	push_w_3(t_stacks *v_n, int r);
void	push_w_2(t_stacks *v_n, int r);
void	push_w_1(t_stacks *v_n, int r);

#endif
