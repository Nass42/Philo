/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namohamm <namohamm@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 10:56:59 by namohamm          #+#    #+#             */
/*   Updated: 2022/05/30 12:43:01 by namohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_arg	*arg;
	if (!ft_parse(ac, av, &arg))
	{
		printf("WRONG ARGS\n");
		return (0);
	}
	ft_mutex_init(&arg);
	ft_thread(&arg);
	ft_wait_thread(&arg);
	// printf("philos = %d, die = %d, eat = %d, sleep = %d, m_eat = %d\n", arg->philos, arg->die, arg->eat, arg->sleep, arg->m_eat);
	// free(arg);
}