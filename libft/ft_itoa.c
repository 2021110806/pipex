/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <minjeon2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:37:06 by minjeon2          #+#    #+#             */
/*   Updated: 2023/03/27 20:21:25 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	count_digits(long nb)
{
	int	return_value;

	return_value = 0;
	while (nb)
	{
		nb /= 10;
		return_value++;
	}
	return (return_value);
}

void	set_number(char *arr, long nb, int idx, int is_minus)
{
	arr[idx] = '\0';
	idx--;
	if (is_minus)
		arr[0] = '-';
	while (nb)
	{
		arr[idx] = nb % 10 + 48;
		nb /= 10;
		idx--;
	}
}

char	*ft_itoa(int n)
{
	int			digits;
	int			is_minus;
	long long	long_n;
	char		*return_value;

	long_n = (long long) n;
	is_minus = 0;
	digits = 0;
	if (n == 0)
		return (ft_strdup("0"));
	if (n < 0)
	{
		is_minus = 1;
		long_n *= -1;
		digits++;
	}
	digits += count_digits(long_n);
	return_value = (char *) malloc (sizeof (char) * (digits + 1));
	if (!return_value)
		return ((void *)0);
	set_number(return_value, long_n, digits, is_minus);
	return (return_value);
}
