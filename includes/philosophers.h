/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:47:41 by flopez-r          #+#    #+#             */
/*   Updated: 2024/02/13 15:11:09 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H

# include <stdlib.h>
# include <sys/time.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_philo
{
    struct timeval	time_init;
    struct timeval	time_now;
}               t_philo;




#endif