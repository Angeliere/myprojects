/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschweit <aschweit@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 16:01:11 by aschweit          #+#    #+#             */
/*   Updated: 2025/05/19 16:38:09 by aschweit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <signal.h>
# include <unistd.h>
# include <sys/types.h>
# include <stdlib.h>
# include "libft.h"

struct s_notification
{
	pid_t		client_pid;
	int			sig;
};

typedef struct s_client
{
	pid_t				pid;
	unsigned char		cur_char;
	int					bit_count;
	char				msg;
}	t_clients;

void	reset_client(t_clients *client);
void	bit_processing(t_clients *g_client,
			int bit,
			struct s_notification *noti);

#endif
