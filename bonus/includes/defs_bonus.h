/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defs_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <monoue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 06:33:26 by monoue            #+#    #+#             */
/*   Updated: 2021/03/29 07:38:31 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFS_BONUS_H
# define DEFS_BONUS_H

# define OPERATORS_NUM 11
# define INT_MAX_DIGITS	10

# define ERROR_MESSAGE "Error"
# define SUCCESS_MESSAGE "OK"
# define FAILURE_MESSAGE "KO"
# define ARG_NUM_ERROR_MESSAGE "Arg list too long"

# define ARGS_LIMIT	520

typedef enum	e_stack_type
{
	STACK_A,
	STACK_B,
	DOUBLE,

	STACKS_NUM
}				t_stack_type;

typedef struct	s_num
{
	int				num;
	struct s_num	*prev;
	struct s_num	*next;
}				t_num;

typedef struct	s_flags
{
	bool	total_count_flag;
	bool	frame_flag;
	bool	nums_in_stacks_flag;
	bool	num_of_operations_flag;
	bool	color_flag;
}				t_flags;

typedef struct	s_counts
{
	size_t	sa_count;
	size_t	sb_count;
	size_t	ss_count;
	size_t	pa_count;
	size_t	pb_count;
	size_t	ra_count;
	size_t	rb_count;
	size_t	rr_count;
	size_t	rra_count;
	size_t	rrb_count;
	size_t	rrr_count;
	size_t	total_count;
}				t_counts;

typedef enum	e_operation_type
{
	OP_SA,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR,

	OP_TYPE_NUM
}				t_operation_type;

typedef struct	s_stacks
{
	t_num		*stack_a;
	t_num		*stack_b;
	t_flags		*flags;
	t_counts	*counts;
	int			last_op;
}				t_stacks;

typedef struct	s_op_func_set
{
	char	*str;
	void	(*func)(t_num **, t_num **);
}				t_op_func_set;

typedef void	(*t_op_func)(t_stacks*, int);

typedef struct	s_op_func_set2
{
	char		*str;
	t_op_func	func;
	int			stack_type;
}				t_op_func_set2;

#endif
