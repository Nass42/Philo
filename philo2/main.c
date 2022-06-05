/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namohamm <namohamm@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 11:28:33 by namohamm          #+#    #+#             */
/*   Updated: 2022/06/04 23:59:29 by namohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_arg	arg;
	int		ret;

	if (ac != 5 && ac != 6)
	{
		printf("ERROR: WRONG NUMBERS OF ARGS!\n");
		return (0);
	}
	if (!ft_parse_init(ac, av, &arg))
	{
		printf("ERROR: WRONG ARGS!\n");
		return (0);
	}
	if (arg.philos > 200)
	{
		printf("ERROR: PHILOSOPHERS > 200\n");
		return (0);
	}
	if (ft_threads(&arg))
	{
		printf("ERROR: CAN'T CREATE PHILOS!");
		return (0);
	}
	return (0);
}
