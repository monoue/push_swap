/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 06:33:26 by monoue            #+#    #+#             */
/*   Updated: 2021/03/23 13:33:35 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFS_H
# define DEFS_H

# define OPERATORS_NUM 11
# define INT_MAX_DIGITS	10

# define ERROR_MESSAGE "Error"
# define SUCCESS_MESSAGE "OK"
# define FAILURE_MESSAGE "KO"

typedef struct	s_num
{
	int				num;
	struct s_num	*prev;
	struct s_num	*next;
}				t_num;

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
