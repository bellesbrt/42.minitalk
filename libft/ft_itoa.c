/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicole- <inicole-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 21:40:13 by inicole-          #+#    #+#             */
/*   Updated: 2022/10/17 21:40:32 by inicole-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_is_negative(int n)
{
	if (n < 0)
		return (1);
	else
		return (0);
}

static size_t	ft_columns(int n, size_t signal)
{
	size_t	len;

	if (n == -2147483648)
		return (11);
	len = 0;
	if (signal)
	{
		len = 1;
		n = -n;
	}
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static char	*ft_alocation(char *pt, int n, size_t signal, size_t len)
{
	if (n == -2147483648)
		return (pt = ft_strdup ("-2147483648"));
	else if (n == 0)
		return (pt = ft_strdup ("0"));
	else
		pt = malloc (sizeof(char) * (len + 1));
	if (!pt)
		return (0);
	if (signal)
		n = -n;
	pt[len] = '\0';
	while (--len)
	{
		pt[len] = (n % 10) + '0';
		n /= 10;
	}
	if (signal)
		pt[0] = '-';
	else
		pt[0] = (n % 10) + '0';
	return (pt);
}

char	*ft_itoa(int n)
{
	char	*pt;
	size_t	signal;
	size_t	len;

	signal = ft_is_negative (n);
	len = ft_columns(n, signal);
	pt = 0;
	pt = ft_alocation(pt, n, signal, len);
	if (!pt)
		return (0);
	return (pt);
}
