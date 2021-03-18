#include <push_swap.h>
#include <libft.h>
#include <debug.h>

static void	push(t_num **src, t_num **dst)
{
	int		tmp;
	t_num	*new;

	if (!lstsize(*src))
		return ;
	tmp = (*src)->num;
	lstdel_front(src);
	new = lstnew(tmp);
	if (!(*dst))
		*dst = new;
	else
		lstadd_front(dst, new);
}

void		push_a(t_num **stack_a, t_num **stack_b)
{
	push(stack_b, stack_a);
}

void		push_b(t_num **stack_a, t_num **stack_b)
{
	push(stack_a, stack_b);
}
