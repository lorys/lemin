#include "lem_in.h"
#include "parser.h"

void	warn_parsing(char *str, int nline)
{
	if (str && DEBUG)
	{
		ft_putstr_fd("\e[95;1mwarning\e[0m: line ", 2);
		ft_putstr_fd(ft_itoa(nline), 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(str, 2);
		ft_putchar_fd('\n', 2);
	}
}

void	error_parsing(char *str, int nline)
{
	if (str && DEBUG)
	{
		ft_putstr_fd("\e[91;1merror\e[0m: line ", 2);
		ft_putstr_fd(ft_itoa(nline), 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(str, 2);
		ft_putchar_fd('\n', 2);
	}
}