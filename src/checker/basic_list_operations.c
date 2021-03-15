#include <push_swap.h>
#include <libft.h>
#include <debug.h>

t_num	*lstlast(t_num *lst)
{
	if (lst == NULL)
		return (lst);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	lstadd_back(t_num **lst, t_num *new)
{
	if (!lst || !new)
		return ;
	new->prev = lstlast(*lst);
	lstlast(*lst)->next = new;
}

void	lstadd_front(t_num **lst, t_num *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	(*lst)->prev = new;
	*lst = new;
}

void	lstdel_one(t_num *lst)
{
	lst->prev = NULL;
	lst->next = NULL;
	SAFE_FREE(lst);
}

void	lstdel_front(t_num **lst)
{
	t_num	*tmp;

	if (!lst)
		return ;
	tmp = *lst;
	*lst = (*lst)->next;
	lstdel_one(tmp);
	if (*lst)
		(*lst)->prev = NULL;
}

void	lstdel_back(t_num **lst)
{
	t_num	*head;
	t_num	*tmp;

	if (!lst)
		return ;
	head = *lst;
	tmp = lstlast(*lst);
	*lst = tmp->prev;
	lstdel_one(tmp);
	if (*lst)
		(*lst)->next = NULL;
	*lst = head;
}

t_num	*lstnew(int num)
{
	t_num	*tmp;

	if (!(tmp = malloc(sizeof(t_num))))
		return (NULL);
	tmp->num = num;
	tmp->prev = NULL;
	tmp->next = NULL;
	return (tmp);
}

size_t	lstsize(t_num *num_list)
{
	t_num	*tmp;
	size_t	count;

	if (!num_list)
		return (0);
	tmp = num_list;
	count = 0;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}
