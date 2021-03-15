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

void	print_current_status(t_num *list_a, t_num *list_b)
{
	ft_putstr("a: ");
	ft_putnbr((int)lstsize(list_a));
	ft_putstr("\tb: ");
	ft_putnbr((int)lstsize(list_b));
	ft_putendl("\n");
	while (list_a || list_b)
	{
		if (list_a)
		{
			ft_putnbr(list_a->num);
			list_a = list_a->next;
		}
		ft_putchar('\t');
		if (list_b)
		{
			ft_putnbr(list_b->num);
			list_b = list_b->next;
		}
		ft_putchar('\n');
	}
	ft_putendl("----------------------------------------");
}
