/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicole- <inicole-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 21:33:48 by inicole-          #+#    #+#             */
/*   Updated: 2022/10/17 21:34:06 by inicole-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int c, size_t n)
{
	unsigned char	*str;
	size_t			count;

	str = (unsigned char *)ptr;
	count = 0;
	while (count < n)
	{
		str[count] = (unsigned char)c;
		count++;
	}
	return (ptr);
}
