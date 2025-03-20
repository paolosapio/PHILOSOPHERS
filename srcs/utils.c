#include "philo.h"

long	ft_atol(const char *nptr)
{
	int		i;
	long	sign;
	long	conversion;

	i = 0;
	sign = 1;
	conversion = 0;
	while ((nptr[i] == ' ') || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+')
		i++;
	else if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	while ((nptr[i] != '\0') && ((nptr[i] >= '0') && (nptr[i] <= '9')))
	{
		conversion = conversion * 10;
		conversion = conversion + nptr[i] - '0';
		i++;
	}
	conversion = conversion * sign;
	return (conversion);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total_size;
	size_t	i;
	char	*pointer;

	i = 0;
	total_size = count * size;
	pointer = malloc(total_size);
	if (pointer == NULL)
		return (NULL);
	while (total_size > 0)
	{
		pointer[i] = 0;
		total_size--;
		i++;
	}
	return (pointer);
}

int	philo_isdigit(int c)
{
	if ((c > '0') && (c <= '9'))
		return (1);
	else
		return (0);
}
