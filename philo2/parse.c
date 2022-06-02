/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namohamm <namohamm@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 11:29:52 by namohamm          #+#    #+#             */
/*   Updated: 2022/06/02 15:01:51 by namohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*****----------------------------ATOI----------------------------*****/
size_t	ft_strlen(const char *str)
{
	int	n;

	n = 0;
	while (str[n] != '\0')
		n++;
	return (n);
}
/*****----------------------------END-----------------------------*****/

/*****---------------------------ATOI-----------------------------*****/
int	ft_atoi(const char *str)
{
	unsigned long	result;
	int				sign;
	int				i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign *= -1;
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + str[i++] - '0';
	if (result > 2147483647 && sign == 1)
		return (-1);
	if (result > 2147483648 && sign == -1)
		return (0);
	return (result * sign);
}
/*****----------------------------END---------------------------*****/

/*****---------------------EVERYTHING IS NUM ?------------------*****/
int is_num(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9'
				|| ft_strlen(av[i]) > 10)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
/*****---------------------------END----------------------------*****/

/*****----------------------INIT MUTEXES------------------------*****/
void	ft_init_mutex(t_arg *arg)
{
	int	i;

	i = 0;
	while (i < arg->philos)
	{
		pthread_mutex_init(&(arg->chopstick[i]), NULL);
		i++;
	}
	pthread_mutex_init(&(arg->mut_write), NULL);
	pthread_mutex_init(&(arg->checking), NULL);
}
/*****---------------------------END----------------------------*****/

/*****--------------------PARSING-AND-INIT----------------------*****/
void	ft_init_philos(t_arg *arg)
{
	int i;

	i = 0;
	while (i < arg->philos)
	{
		arg->philo[i].id = i;
		arg->philo[i].ate = 0;
		arg->philo[i].left_chopstick = i;
		arg->philo[i].right_chopstick = (i + 1) % arg->philos;
		arg->philo[i].last_eat = 0;
		arg->philo[i].arg = arg;
		i++;
	}
}
/*****---------------------------END----------------------------*****/

/*****--------------------PARSING-AND-INIT----------------------*****/
int	ft_parse_init(int ac, char **av, t_arg *arg)
{
	if ((ac == 5 || ac == 6) && is_num(av))
	{
		arg->philos = ft_atoi(av[1]);
		arg->die = ft_atoi(av[2]);
		arg->eat = ft_atoi(av[3]);
		arg->sleep = ft_atoi(av[4]);
		arg->well_fed = 0;
		arg->dead = 0;
		if (arg->philos <= 1 || arg->die < 0 || arg->eat < 0
		|| arg->sleep < 0 || arg->philos > 512)
		return (1);
		if (av[5])
		{
			arg->must_eat = ft_atoi(av[5]);
			if (arg->must_eat <= 0)
				return (1);
		}
		else
			arg->must_eat = -1;
		ft_init_mutex(arg);
		ft_init_philos(arg);
		return (1);
	}
	
	return (0);
}
/*****---------------------------END---------------------------*****/
