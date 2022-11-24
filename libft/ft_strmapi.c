/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicole- <inicole-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 21:14:22 by inicole-          #+#    #+#             */
/*   Updated: 2022/10/17 21:14:34 by inicole-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	ctr;
	char			*pt;

	if (!s || (!s && !f))
		return (ft_strdup (""));
	else if (!f)
		return (ft_strdup (s));
	pt = ft_strdup (s);
	if (!pt)
		return (NULL);
	ctr = 0;
	while (s[ctr])
	{
		pt[ctr] = f(ctr, pt[ctr]);
		ctr++;
	}
	return (pt);
}
