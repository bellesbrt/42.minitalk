/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicole- <inicole-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:07:20 by inicole-          #+#    #+#             */
/*   Updated: 2022/11/22 15:17:00 by inicole-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	end_client(int s_pid)
{
	static int	i = 0;

	if (i++ != 8)
	{
		if (kill(s_pid, SIGUSR1) == -1)
		{
			ft_putstr_fd("error\n", 1);
			exit(1);
		}
		return (0);
	}
	return (1);
}

void	binary_conversion(char *send, int s_pid)
{
	if (*send % 2 == 0)
	{
		*send = *send / 2;
		if (kill(s_pid, SIGUSR1) == -1)
		{
			ft_putstr_fd("error\n", 1);
			exit(1);
		}
	}
	else
	{
		*send = *send / 2;
		if (kill(s_pid, SIGUSR2) == -1)
		{
			ft_putstr_fd("error\n", 1);
			exit(1);
		}
	}
}

int	string_to_binary(char *msg, int pid)
{
	static char	*send = NULL;
	static int	s_pid = 0;
	static int	i = 0;
	static int	bits = 0;

	if (send == NULL)
		send = msg;
	if (pid)
		s_pid = pid;
	if (bits == 8)
	{
		bits = 0;
		i++;
	}
	if (send[i] == '\0' && bits == 0)
	{
		if (!end_client(s_pid))
			return (0);
		send = NULL;
		return (1);
	}
	if (bits++ < 8)
		binary_conversion(&send[i], s_pid);
	return (0);
}

void	handle_signal(int sign)
{
	int	finish;

	finish = 0;
	if (sign == SIGUSR1)
		finish = string_to_binary(0, 0);
	if (finish)
		exit(0);
}

int	main(int argc, char *argv[])
{
	struct sigaction	sa;
	sigset_t			mask;

	if (argc != 3)
	{
		ft_putstr_fd("Try again: ./client [PID] [your string]\n", 1);
		return (0);
	}
	sigemptyset(&mask);
	sa.sa_handler = handle_signal;
	sa.sa_flags = 0;
	sa.sa_mask = mask;
	sigaction(SIGUSR1, &sa, NULL);
	string_to_binary(argv[2], ft_atoi(argv[1]));
	while (1)
		pause();
	return (0);
}
