/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicole- <inicole-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 21:47:11 by inicole-          #+#    #+#             */
/*   Updated: 2022/10/17 21:47:43 by inicole-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	ct;
	int	nbr;
	int	signal;

	ct = 0;
	nbr = 0;
	signal = 1;
	while (nptr[ct] && (nptr[ct] == 32 || (nptr[ct] <= 14 && nptr[ct] >= 9)))
		ct++;
	if (nptr[ct] && nptr[ct] == '-')
	{
		signal = -1;
		ct++;
	}
	else if (nptr[ct] == '+')
		ct++;
	while (nptr[ct] && ft_isdigit(nptr[ct]))
		nbr = (nbr * 10) + (nptr[ct++] - '0');
	return (nbr * signal);
}
