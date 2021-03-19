#ifndef DEBUG_H
# define DEBUG_H

# include <stdio.h>
# include "defs.h"

# define DEBUGV(v_fmt, v) \
    dprintf(2, #v ": " v_fmt "\t(file \"%s\", line %d, in %s)\n", \
        v, __FILE__, __LINE__, __FUNCTION__);

# define DC(v) DEBUGV("%c", v);
# define DP(v) DEBUGV("%p", v);
# define DS(v) DEBUGV("%s", v);
# define DI(v) DEBUGV("%d", v);
# define DU(v) DEBUGV("%u", v);
# define DF(v) DEBUGV("%f", v);
# define DD(v) DEBUGV("%lf", v);
# define DX(v) DEBUGV("%x", v);
# define DL(v) DEBUGV("%ld", v);
# define DSZ(v) DEBUGV("%zu", v);
# define DSSZ(v) DEBUGV("%zd", v);

# define DEBUGF(fmt, ...) \
    dprintf(2, fmt "\t(file \"%s\", line %d, in %s)\n", \
        __VA_ARGS__, __FILE__, __LINE__, __FUNCTION__);

void	print_list_nums(t_num *num_list);
void	print_current_status(t_num *stack_a, t_num *stack_b);
void	print_current_status_wrapper(t_num **stack_a, t_num **stack_b);

#endif