#include "push_swap.h"
#include "libft.h"
#include "debug.h"

void	print_list_nums(t_num *num_list)
{
	t_num	*base;
	t_num	*next_holder;

	if (!lstsize(num_list))
	{
		ft_putendl("-----");
		ft_putendl("EMPTY");
		ft_putendl("-----");
	}
	base = num_list;
	while (base)
	{
		next_holder = base->next;
		ft_putnbr(base->num);
		ft_putchar('\n');
		base = next_holder;
	}
}

void	put_tab(int n)
{
	const int	intlen = ft_intlen(n);
	const int	tabsize = 8;
	const int	to_fill_len = tabsize - intlen;
	int			index;

	index = 0;
	while (index < to_fill_len)
	{
		ft_putchar(' ');
		index++;
	}
}

void	print_current_status(t_num *stack_a, t_num *stack_b)
{
	ft_putstr("       a: ");
	ft_putnbr((int)lstsize(stack_a));
	ft_putstr("    b: ");
	ft_putnbr((int)lstsize(stack_b));
	ft_putendl("\n");
	while (stack_a || stack_b)
	{
		if (stack_a)
		{
			put_tab(stack_a->num);
			ft_putnbr(stack_a->num);
			stack_a = stack_a->next;
		}
		else
			ft_putstr("        ");
		if (stack_b)
		{
			put_tab(stack_b->num);
			ft_putnbr(stack_b->num);
			stack_b = stack_b->next;
		}
		ft_putchar('\n');
	}
	ft_putendl("----------------------------------------");
}

void	print_current_status_wrapper(t_num **stack_a, t_num **stack_b)
{
	if (!stack_a)
		print_current_status(NULL, *stack_b);
	else if (!stack_b)
		print_current_status(*stack_a, NULL);
	else
		print_current_status(*stack_a, *stack_b);
}
