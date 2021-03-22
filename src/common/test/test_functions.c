#include "push_swap.h"
#include "libft.h"
#include "debug.h"

void	print_list_nums(t_num *num_list)
{
	t_num	*base;
	t_num	*next_holder;

	if (!lstsize(num_list))
	{
		ft_putendl_err("-----");
		ft_putendl_err("EMPTY");
		ft_putendl_err("-----");
	}
	base = num_list;
	while (base)
	{
		next_holder = base->next;
		ft_putnbr_err(base->num);
		ft_putchar_err('\n');
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
		ft_putchar_err(' ');
		index++;
	}
}

void	print_current_status(t_num *stack_a, t_num *stack_b)
{
	ft_putstr_err("       a: ");
	ft_putnbr_err((int)lstsize(stack_a));
	ft_putstr_err("    b: ");
	ft_putnbr_err((int)lstsize(stack_b));
	ft_putendl_err("\n");
	while (stack_a || stack_b)
	{
		if (stack_a)
		{
			put_tab(stack_a->num);
			ft_putnbr_err(stack_a->num);
			stack_a = stack_a->next;
		}
		else
			ft_putstr_err("        ");
		if (stack_b)
		{
			put_tab(stack_b->num);
			ft_putnbr_err(stack_b->num);
			stack_b = stack_b->next;
		}
		ft_putchar_err('\n');
	}
	ft_putendl_err("----------------------------------------");
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
