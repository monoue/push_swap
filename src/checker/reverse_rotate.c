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

void		reverse_rotate_a(t_num **list_a, t_num **list_b)
{
	(void)list_b;
	reverse_rotate(list_a);
}

void		reverse_rotate_b(t_num **list_a, t_num **list_b)
{
	(void)list_a;
	reverse_rotate(list_b);
}

void		reverse_rotate_double(t_num **list_a, t_num **list_b)
{
	reverse_rotate(list_a);
	reverse_rotate(list_b);
}
