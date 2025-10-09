/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschweit <aschweit@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 15:52:48 by aschweit       #+#    #+#             */
/*   Updated: 2025/09/18 18:37:29 by aschweit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_pipefd[2];

static void	handler(int sig, siginfo_t *info, void *ucontext)
{
	struct s_notification	noti;

	noti.client_pid = info->si_pid;
	noti.sig = sig;
	(void)write(g_pipefd[1], &noti, sizeof(noti));
	(void)ucontext;
}

void	setup_signal(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf ("PID: %d\n", getpid());
}

void	complete_character(t_clients *g_client)
{
	if (g_client->cur_char != 0)
		ft_printf("%c", g_client->cur_char);
	reset_client(g_client);
	g_client->cur_char = 0;
	g_client->bit_count = 0;
}

int	read_notification(struct s_notification *noti)
{
	ssize_t	n;

	n = read(g_pipefd[0], noti, sizeof(noti));
	if (n != sizeof(noti))
		return (0);
	return (1);
}

int	main(void)
{
	struct s_notification	noti;
	t_clients				g_client;
	int						bit;

	ft_memset(&g_client, 0, sizeof(g_client));
	bit = 0;
	if (pipe(g_pipefd) == -1)
	{
		write(1, "pipe", 5);
		return (1);
	}
	setup_signal();
	while (1)
	{
		if (!read_notification(&noti))
			continue ;
		if (g_client.pid == 0)
			g_client.pid = noti.client_pid;
		else if (g_client.pid != noti.client_pid)
			continue ;
		bit_processing(&g_client, bit, &noti);
		if (g_client.bit_count == 8)
			complete_character(&g_client);
	}
	return (0);
}
