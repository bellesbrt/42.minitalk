/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicole- <inicole-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:07:27 by inicole-          #+#    #+#             */
/*   Updated: 2022/11/21 19:29:30 by inicole-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	clear_bit(int c, int position)
{
	int	mask;

	mask = 1 << position;
	return (c & ~mask);
}

int	set_bit(int c, int position)
{
	int	mask;

	mask = 1 << position;
	return (c | mask);
}

char	*add_char_to_str(char *msg, char c)
{
	char	*ret;
	size_t	size;
	int		i;

	if (!msg)
	{
		ret = malloc(2);
		ret[0] = c;
		ret[1] = '\0';
		return (ret);
	}
	size = ft_strlen(msg) + 2;
	ret = malloc(size);
	i = 0;
	while (msg[i])
	{
		ret[i] = msg[i];
		i++;
	}
	ret[i] = c;
	ret[i + 1] = '\0';
	free(msg);
	return (ret);
}
