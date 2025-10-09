/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschweit <aschweit@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 14:07:23 by aschweit          #+#    #+#             */
/*   Updated: 2025/09/19 18:31:48 by aschweit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	bit_processing(t_clients *g_client,
						int bit,
						struct s_notification *noti)
{
	if (noti->sig == SIGUSR2)
		bit = 1;
	else
		bit = 0;
	kill (noti->client_pid, SIGUSR1);
	g_client->cur_char = (g_client->cur_char << 1) | bit;
	g_client->bit_count++;
}

void	reset_client(t_clients *client)
{
	client->msg = 0;
	client->pid = 0;
	client->cur_char = 0;
	client->bit_count = 0;
}
