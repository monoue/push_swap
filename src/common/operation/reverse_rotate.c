#include <push_swap.h>
#include <libft.h>
#include <debug.h>

static void	reverse_rotate(t_num **num_list)
{
	int		tmp;

	if (lstsize(*num_list) < 2)
		return ;
	tmp = lstlast(*num_list)->num;
	lstdel_back(num_list);
	lstadd_front(num_list, lstnew(tmp));
}

void		reverse_rotate_a(t_num **stack_a, t_num **stack_b)
{
	(void)stack_b;
	reverse_rotate(stack_a);
}

void		reverse_rotate_b(t_num **stack_a, t_num **stack_b)
{
	(void)stack_a;
	reverse_rotate(stack_b);
}

void		reverse_rotate_double(t_num **stack_a, t_num **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}
