/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicole- <inicole-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 21:15:34 by inicole-          #+#    #+#             */
/*   Updated: 2022/10/17 21:15:44 by inicole-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	counter;
	size_t	dst_len;

	counter = 0;
	dst_len = ft_strlen (dst);
	if (size == 0)
		return (ft_strlen (src));
	if (size <= dst_len)
		return (size + ft_strlen (src));
	else
	{
		while (src[counter] && (dst_len + counter + 1) < size)
		{
			dst[dst_len + counter] = src[counter];
			counter++;
		}
		dst[dst_len + counter] = '\0';
		return (dst_len + ft_strlen (src));
	}
}
