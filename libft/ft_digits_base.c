/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digits_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicole- <inicole-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 21:43:17 by inicole-          #+#    #+#             */
/*   Updated: 2022/10/17 21:45:54 by inicole-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_digits_base(unsigned long n, char *base)
{
	size_t	len;

	if (n < ft_strlen(base))
		return (1);
	len = 0;
	while (n > 0)
	{
		n /= ft_strlen(base);
		len++;
	}
	return (len);
}
