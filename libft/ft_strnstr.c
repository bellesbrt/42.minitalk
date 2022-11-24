/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicole- <inicole-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 21:12:48 by inicole-          #+#    #+#             */
/*   Updated: 2022/10/17 21:13:02 by inicole-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	littlelen;

	littlelen = ft_strlen(little);
	if (!littlelen)
		return ((char *)big);
	while (*big && littlelen <= n--)
	{
		if (ft_strncmp(big, little, littlelen) == 0)
			return ((char *)big);
		big++;
	}
	return (NULL);
}
