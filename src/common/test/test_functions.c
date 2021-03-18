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

void	print_current_status(t_num *stack_a, t_num *stack_b)
{
	ft_putstr("a: ");
	ft_putnbr((int)lstsize(stack_a));
	ft_putstr("\tb: ");
	ft_putnbr((int)lstsize(stack_b));
	ft_putendl("\n");
	while (stack_a || stack_b)
	{
		if (stack_a)
		{
			ft_putnbr(stack_a->num);
			stack_a = stack_a->next;
		}
		ft_putchar('\t');
		if (stack_b)
		{
			ft_putnbr(stack_b->num);
			stack_b = stack_b->next;
		}
		ft_putchar('\n');
	}
	ft_putendl("----------------------------------------");
}
