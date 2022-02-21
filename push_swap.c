#include "push_swap.h"
int sortet(t_stacks *valid_num, int num_of_elem)
{
    int i;

    i = 1;
    while (i < num_of_elem)
    {
        if (valid_num->a[i - 1]->data < valid_num->a[i]->data)
            i++;
        else 
            return(0);
    }
    return (1);
}


int main(int argc, char **argv)
{
    t_stacks *valid_num;
    int num_of_elem;

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
    if (num_of_elem == 2)
        sort_two_elem(valid_num);
    if (num_of_elem == 3)
        sort_three_elem(valid_num);
    return (cleaning_b(valid_num, num_of_elem));
}