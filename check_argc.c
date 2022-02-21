#include "push_swap.h"

long	ft_error(int i)
{
	if (i == 1)
	{
		write (i, "Error\n", 6);
		return (2147483648);
	}
	else
	{
		write (1, "Error\n", 6);
		return (0);
	}
} 

int free_stacks (t_stacks *valid_arg)
{
    free (valid_arg);
    return (0);
}

int ft_strrchr(char **str, int argc, int start, int step_argc)
{
    long c1;
    long c2;

    if (argc <= 0)
    {
        if (ft_atoi(str[argc]) == MAX_INT)
            return(0);
        return (1);
    }
    while (argc > 0)
    {
        c2 = ft_atoi(str[argc]); 
        if (c2 == MAX_INT)
            return (0);
        step_argc = argc--; // 1
        while (--step_argc >= start)
        {
            c1 = ft_atoi(str[step_argc]);
            if (c1 == MAX_INT)
                return (0);
            if (c2 - c1 == 0)
                return (ft_error(0));
        }
    }
    return (1);

}

int ft_strlen_2(char **str)
{
    int i;

    i = 0;
    while (str[i]) 
        i++;
    return(--i);
}

int cleaning(t_stacks *valid_num, int i)
{
    while (--i >= 0)
        free(valid_num->a[i]);
    free(valid_num->a);
    free(valid_num);
    return(0);
}

int cleaning_b(t_stacks *valid_num, int i)
{
    int n;

    n = 0;
    while (n < i)
    {
        free(valid_num->b[n]);
        n++;
    }
    free(valid_num->b);
    return(cleaning(valid_num, i));

}

int create_stack_b(t_stacks *valid_num, int lenght)
{
    int i;

    i = 0;
    valid_num->b = malloc(sizeof(char **) * lenght + 1);
    if (!valid_num->b)
    {
        free(valid_num->b);
        return (0);
    }
    while (lenght > i)
    {
        valid_num->b[i] = malloc(sizeof(t_stack));
        if (!valid_num->b[i])
        {
            cleaning_b(valid_num, lenght);
            return (0);
        }
        valid_num->b[i]->sort_numb = 0;
        i++;  
    }
    return (1);
}

int stack_record_num (char **str, t_stacks *valid_num, int start, int lenght)
{
    int i;

    i = 0;
    valid_num->a = malloc(sizeof(char **) * lenght + 1);
    if (!valid_num->a)
        return(cleaning(valid_num, i));
    while (lenght - start >= i)
    {
        valid_num->a[i] = malloc(sizeof(t_stack));
        if (!valid_num->a[i])
            return (cleaning(valid_num, i));
        valid_num->a[i]->data = ft_atoi(str[i + start]);
        valid_num->a[i]->sort_numb = 0;
        i++;
    }
    if (!create_stack_b(valid_num, lenght))
        return(cleaning(valid_num, i));
    return (i);
    
}
int check_valid_arg (int argc, char **argv, t_stacks *valid_num)
{
    char **str;
    int step_argc;

    step_argc = 0;
    str = NULL;
    if (argc < 2)
        return(free_stacks(valid_num));
    else if (argc == 2)
    {
        str = ft_split(argv[1], ' ');
        if (!str)
            return(free_stacks(valid_num));
        if (!ft_strrchr(str, ft_strlen_2(str), 0, step_argc)) // если не true - false, если не false - true 
            return(free_stacks(valid_num)); // если 0 возвр ф-ция - выполняется
        return(stack_record_num(str, valid_num, 0, ft_strlen_2(str)));
    }
    else 
    {
        if (!ft_strrchr(argv, --argc, 1, step_argc))
            return(free_stacks(valid_num));
        return(stack_record_num(argv, valid_num, 1, argc));
    }
}
