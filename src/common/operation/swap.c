#include <push_swap.h>
#include <libft.h>
#include <debug.h>

static void	swap(t_num **stack)
{
	int	a;
	int	b;

	if (lstsize(*stack) < 2)
		return ;
	a = (*stack)->num;
	b = (*stack)->next->num;
	lstdel_front(stack);
	lstdel_front(stack);
	if (!(*stack))
		*stack = lstnew(a);
	else
		lstadd_front(stack, lstnew(a));
	lstadd_front(stack, lstnew(b));
}

void		swap_a(t_num **stack_a, t_num **stack_b)
{
	(void)stack_b;
	swap(stack_a);
}

void		swap_b(t_num **stack_a, t_num **stack_b)
{
	(void)stack_a;
	swap(stack_b);
}

void		swap_double(t_num **stack_a, t_num **stack_b)
{
	swap(stack_a);
	swap(stack_b);
}
