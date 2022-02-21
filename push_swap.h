#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

#define MAX_INT 2147483648

typedef struct Node {
    int value;
    struct Node *next;

} Node;

typedef struct t_stacks {
    int num_of_a;
    int num_of_b;
    int min;


    t_stack **a;
    t_stack **b;

} t_stacks;

typedef struct t_stack {
    int data;
    int step_sum;
    int step_a;
    int step_b;
    int opt_way;
    int sort_numb;

} t_stack;

int main(int argc, char **argv);
int sortet(t_stacks *valid_num, int num_of_elem);
void sort_two_elem(t_stacks *v_n);
void sort_three_elem(t_stacks *v_n);
void sa(t_stacks *valid_num);
void sb(t_stacks *valid_num);
void pa(t_stacks *valid_num);
void ra(t_stacks *valid_num);
void rb(t_stacks *valid_num);
void rr(t_stacks *valid_num);
void rra(t_stacks *valid_num);
void rrb(t_stacks *valid_num);
void rrr(t_stacks *valid_num);
int	num_space(char *s, char c);
char	*make_word(char *str, int first, int last);
char	**ft_split(char *s, char c);
long	ft_error(int i);
int free_stacks (t_stacks *valid_arg);
int ft_strrchr(char **str, int argc, int start, int step_argc);
int ft_strlen_2(char **str);
int cleaning(t_stacks *valid_num, int i);
int cleaning_b(t_stacks *valid_num, int i);
int create_stack_b(t_stacks *valid_num, int lenght);
int stack_record_num (char **str, t_stacks *valid_num, int start, int lenght);
int check_valid_arg (int argc, char **argv, t_stacks *valid_num);

#endif