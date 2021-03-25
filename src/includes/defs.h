/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <monoue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 06:33:26 by monoue            #+#    #+#             */
/*   Updated: 2021/03/25 09:18:46 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFS_H
# define DEFS_H

# define OPERATORS_NUM 11
# define INT_MAX_DIGITS	10

# define ERROR_MESSAGE "Error"
# define SUCCESS_MESSAGE "OK"
# define FAILURE_MESSAGE "KO"
# define ARG_NUM_ERROR_MESSAGE "Arg list too long"

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

typedef struct	e_stacks
{
	t_num	*stack_a;
	t_num	*stack_b;
}				t_stacks;

typedef struct	s_op_func_set
{
	char	*str;
	void	(*func)(t_num **, t_num **);
}				t_op_func_set;

typedef void	(*t_op_func)(t_num **, t_num **, int);

typedef struct	s_op_func_set2
{
	char		*str;
	t_op_func	func;
	int			stack_type;
}				t_op_func_set2;

#endif
