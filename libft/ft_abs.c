int		ft_abs(int x)
{
	int	neg;

	neg = x >> ((sizeof(int) * 8) - 1);
	return ((neg ^ x) - neg);
}