#include <push_swap.h>
#include <libft.h>
#include <debug.h>

t_num	*lstlast(t_num *stack)
{
	if (stack == NULL)
		return (stack);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	lstadd_back(t_num **stack, t_num *new)
{
	if (!stack || !new)
		return ;
	new->prev = lstlast(*stack);
	lstlast(*stack)->next = new;
}

void	lstadd_front(t_num **stack, t_num *new)
{
	if (!stack || !new)
		return ;
	new->next = *stack;
	(*stack)->prev = new;
	*stack = new;
}

void	lstdel_one(t_num *lst)
{
	lst->prev = NULL;
	lst->next = NULL;
	SAFE_FREE(lst);
}

void	lstdel_front(t_num **stack)
{
	t_num	*tmp;

	if (!stack)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	lstdel_one(tmp);
	if (*stack)
		(*stack)->prev = NULL;
}

void	lstdel_back(t_num **stack)
{
	t_num	*head;
	t_num	*tmp;

	if (!stack)
		return ;
	head = *stack;
	tmp = lstlast(*stack);
	*stack = tmp->prev;
	lstdel_one(tmp);
	if (*stack)
		(*stack)->next = NULL;
	*stack = head;
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

size_t	lstsize(t_num *stack)
{
	t_num	*tmp;
	size_t	count;

	if (!stack)
		return (0);
	tmp = stack;
	count = 0;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}
