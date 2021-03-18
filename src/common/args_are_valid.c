#include <push_swap.h>
#include <libft.h>

static bool	digits_num_is_over_int_max(const char *str)
{
	size_t	index;

	index = 0;
	if (str[index] == '+' || str[index] == '-')
		index++;
	while (str[index] == '0')
		index++;
	return (ft_strlen(&str[index]) > INT_MAX_DIGITS);
}

static bool	str_is_within_int_range(const char *str)
{
	bool				sign;
	unsigned long long	n;
	size_t				index;

	index = 0;
	if (digits_num_is_over_int_max(str))
		return (false);
	sign = false;
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			sign = true;
		index++;
	}
	n = ft_atoull(&str[index]);
	if (n == 0)
		return (true);
	if (sign)
		n--;
	return (n <= INT_MAX);
}

static bool	str_is_numeric(const char *str)
{
	const char	first_c = str[0];

	if (!str || !first_c)
		return (false);
	if (first_c == '+' || first_c == '-')
		return (ft_str_is_numeric(&str[1]));
	return (ft_str_is_numeric(str));
}

static bool	args_are_numeric(size_t argc, char *argv[])
{
	size_t	index;

	index = 1;
	while (index < argc)
	{
		if (!str_is_numeric(argv[index]))
			return (false);
		index++;
	}
	return (true);
}

static bool	args_are_integers(size_t argc, char *argv[])
{
	size_t	index;

	if (!args_are_numeric(argc, argv))
		return (false);
	index = 1;
	while (index < argc)
	{
		if (!str_is_within_int_range(argv[index]))
			return (false);
		index++;
	}
	return (true);
}

bool		args_are_valid(size_t argc, char *argv[])
{
	return (args_are_integers(argc, argv) && args_are_unique(argc, argv));
}
