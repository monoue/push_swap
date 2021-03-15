#include <push_swap.h>
#include <libft.h>
#include <debug.h>

static void	swap(t_num **num_list)
{
	int	a;
	int	b;

	if (lstsize(*num_list) < 2)
		return ;
	a = (*num_list)->num;
	b = (*num_list)->next->num;
	lstdel_front(num_list);
	lstdel_front(num_list);
	if (!(*num_list))
		*num_list = lstnew(a);
	else
		lstadd_front(num_list, lstnew(a));
	lstadd_front(num_list, lstnew(b));
}

void		swap_a(t_num **list_a, t_num **list_b)
{
	(void)list_b;
	swap(list_a);
}

void		swap_b(t_num **list_a, t_num **list_b)
{
	(void)list_a;
	swap(list_b);
}

void		swap_double(t_num **list_a, t_num **list_b)
{
	swap(list_a);
	swap(list_b);
}
