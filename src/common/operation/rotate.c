#include <push_swap.h>
#include <libft.h>
#include <debug.h>

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
}

void		rotate_b(t_num **stack_a, t_num **stack_b)
{
	(void)stack_a;
	rotate(stack_b);
}

void		rotate_double(t_num **stack_a, t_num **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}
