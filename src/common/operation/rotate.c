#include <push_swap.h>
#include <libft.h>
#include <debug.h>
#include "swapper.h"

static void	rotate(t_num **num_list)
{
	int	tmp;

	if (lstsize(*num_list) < 2)
		return ;
	tmp = (*num_list)->num;
	lstdel_front(num_list);
	lstadd_back(num_list, lstnew(tmp));
}

void		rotate_a(t_num **stack_a, t_num **stack_b)
{
	(void)stack_b;
	rotate(stack_a);
	ft_putendl("ra");
}

void		rotate_b(t_num **stack_a, t_num **stack_b)
{
	(void)stack_a;
	rotate(stack_b);
	ft_putendl("rb");
}

void		rotate_double(t_num **stack_a, t_num **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putendl("rr");
}

void		rotate_designated(t_num **stack_a, t_num **stack_b, int stack_type)
{
	if (stack_type == STACK_A)
		rotate_a(stack_a, stack_b);
	else if (stack_type == STACK_B)
		rotate_b(stack_a, stack_b);
	else if (stack_type == DOUBLE)
		rotate_double(stack_a, stack_b);
}
