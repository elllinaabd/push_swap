#include "push_swap.h"

void sort_two_elem(t_stacks *v_n)
{
    if (v_n->a[0]->data > v_n->a[1]->data)
        sa(v_n);
}

void sort_three_elem(t_stacks *v_n) // 427
{
    int max;
    int i;

    i = 0;
    max = v_n->a[0]->data;
    while (i < v_n->num_of_a)
    {
        if (v_n->a[i]->data > max)
            max = v_n->a[i]->data;
        i++;
    }
    if (max == v_n->a[2]->data)
        sa(v_n);
    if (max == v_n->a[1]->data)
    {
        if (v_n->a[0]->data > v_n->a[2]->data)
            rra(v_n);
        else
        {
            sa(v_n);
            rra(v_n);
        }
    }
    if (max == v_n->a[0]->data)
    {
        if (v_n->a[1]->data < v_n->a[2]->data)
            ra(v_n);
        else
        {
            sa(v_n);
            rra(v_n);
        }      
    }

    

}
