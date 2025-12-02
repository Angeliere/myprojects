/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschweit <aschweit@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 12:31:13 by aschweit       #+#    #+#             */
/*   Updated: 2025/10/08 12:32:07 by aschweit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <pthread.h>

typedef struct s_philosophers
{
    int         id;
    long long   last_meal;
    int         left_fork;
    int         right_fork;
    int         time_eaten;
    pthread_t   *thread;
}   t_philosophers;

typedef struct s_arguments
{
    int             num_phi;
    int             time_die;
    int             time_eat;
    int             time_sleep;
    int             time_think;
    int             number_eat;
    pthread_mutex_t *fork;
    long long       start_time;
    t_philosophers   *philosophers;

}   t_arguments;
