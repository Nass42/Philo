/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namohamm <namohamm@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 10:58:12 by namohamm          #+#    #+#             */
/*   Updated: 2022/05/29 14:18:55 by namohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct	s_arg
{
	int	philos;
	int	die;
	int	eat;
	int	sleep;
	int	m_eat;
}		t_arg;

typedef struct s_philo
{
	t_arg	ph;
};


int	ft_parse(int ac, char **av, t_arg **arg);

#endif