/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschweit <aschweit@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 15:59:45 by aschweit       #+#    #+#             */
/*   Updated: 2025/09/18 18:38:19 by aschweit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_d = 0;

void	handler(int sig)
{
	(void) sig;
	g_d = 1;
}

void	send_bit(pid_t server_pid, int bit)
{
	int	s;

	if (bit)
		s = SIGUSR2;
	else
	{
		s = SIGUSR1;
	}
	usleep(100);
	g_d = 0;
	if (kill (server_pid, s) == -1)
	{
		write(2, "Error\n", sizeof("Error\n") - 1);
		exit (1);
	}
	while (!g_d)
		pause();
}

void	send_char(pid_t server_pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		send_bit(server_pid, (c >> i) & 1);
		i--;
	}
}

int	main(int argc, char **argv)
{
	pid_t				server_pid;
	char				*msg;
	struct sigaction	si;

	if (argc != 3)
	{
		ft_printf("Invalid number of arguments given , give 3");
		return (1);
	}
	si.sa_handler = handler;
	si.sa_flags = 0;
	sigemptyset(&si.sa_mask);
	sigaction(SIGUSR1, &si, NULL);
	server_pid = (pid_t)ft_atoi(argv[1]);
	msg = argv[2];
	while (*msg)
	{
		send_char(server_pid, *msg);
		if (*msg == '\0')
			break ;
		msg++;
	}
	send_char(server_pid, '\0');
	return (0);
}
