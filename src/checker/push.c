#include <push_swap.h>
#include <libft.h>
#include <debug.h>

static void	push(t_num **src, t_num **dst)
{
	int		tmp;
	t_num	*new;

	tmp = (*src)->num;
	lstdel_front(src);
	new = lstnew(tmp);
	if (!(*dst))
		*dst = new;
	else
		lstadd_front(dst, new);
}

void		push_a(t_num **list_a, t_num **list_b)
{
	push(list_b, list_a);
}

void		push_b(t_num **list_a, t_num **list_b)
{
	push(list_a, list_b);
}
