/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namohamm <namohamm@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 11:28:33 by namohamm          #+#    #+#             */
/*   Updated: 2022/06/02 14:44:18 by namohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		main(int ac, char **av)
{
	t_arg	arg;
	int		ret;

	if (ac != 5 && ac != 6)
	{
		printf("ERROR: WRONG NUMBERS OF ARGS\n");
		return (0);
	}
	if (!ft_parse_init(ac, av, &arg))
	{
		printf("ERROR: WRONG ARGS\n");
		return (0);
	}
	printf("philos = %d\n", arg.philos);
	printf("philos = %d\n", arg.die);
	printf("philos = %d\n", arg.eat);
	printf("philos = %d\n", arg.sleep);
	printf("philos = %d\n", arg.must_eat);
	
	// if ((ret = init_all(&arg, av)))
	// 	return (error_manager(ret));
	// if (launcher(&arg))
	// 	return (write_error("There was an error creating the threads"));
	return (0);
}