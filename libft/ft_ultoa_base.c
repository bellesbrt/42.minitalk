/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicole- <inicole-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 21:08:57 by inicole-          #+#    #+#             */
/*   Updated: 2022/10/17 21:09:06 by inicole-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ultoa_base(unsigned long n, char *base)
{
	size_t	len;
	char	*pt;

	len = ft_digits_base(n, base);
	pt = malloc(sizeof(char) * (len + 1));
	if (!pt)
		return (NULL);
	pt[len] = '\0';
	while (--len)
	{
		pt[len] = *(base + (n % ft_strlen(base)));
		n /= ft_strlen(base);
	}
	pt[0] = *(base + (n % ft_strlen(base)));
	return (pt);
}
