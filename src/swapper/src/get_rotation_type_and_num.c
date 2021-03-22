#include "push_swap.h"
#include "debug.h"
#include "swapper.h"
#include "defs.h"
#include "libft.h"
#include "operation.h"

t_rotation_info	*get_rotation_type_and_num(size_t nums_num, size_t target_i)
{
	t_rotation_info	*rotation_info;
	const size_t	middle_i = nums_num / 2;

	if (target_i == 0)
		return (get_zero_rotation());
	rotation_info = malloc(sizeof(t_rotation_info));
	if (!rotation_info)
		exit(EXIT_FAILURE);
	if (nums_num % 2 == 0 && target_i == middle_i)
	{
		// DS("1");
		rotation_info->rotation_type = BOTH;
		rotation_info->num = target_i;
	}
	else if (target_i <= middle_i)
	{
		// DS("2");
		rotation_info->rotation_type = NORMAL;
		rotation_info->num = target_i;
	}
	else
	{
		// DS("3");
		rotation_info->rotation_type = REVERSE;
		rotation_info->num = nums_num - target_i;
	}
	// DSZ(target_i);
	// DSZ(middle_i);
	// DI(rotation_info->rotation_type);
	// DSZ(rotation_info->num);
	return (rotation_info);
}
