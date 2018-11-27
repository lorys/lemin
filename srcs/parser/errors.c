#include "lem_in.h"

void	warn_parsing(char *str, int nline)
{
	if (str && DEBUG)
		ft_printf("\e[95;1mwarning\e[0m: line %d: %s", nline, str);
}

void	error_parsing(char *str, int nline)
{
	if (str && DEBUG)
		ft_printf("\e[91;1merror\e[0m: line %d: %s", nline, str);
	else
		ft_putstr("ERROR\n");
	exit(EXIT_FAILURE);
}