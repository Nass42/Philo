/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namohamm <namohamm@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 10:57:33 by namohamm          #+#    #+#             */
/*   Updated: 2022/05/30 09:23:58 by namohamm         ###   ########.fr       */
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

/*****--------------------------PARSING-------------------------*****/
int	ft_parse(int ac, char **av, t_arg **arg)
{
	if ((ac == 5 || ac == 6) && is_num(av))
	{
		(*arg) = (t_arg *)malloc(sizeof(t_arg));
		(*arg)->philos = ft_atoi(av[1]);
		(*arg)->die = ft_atoi(av[2]);
		(*arg)->eat = ft_atoi(av[3]);
		(*arg)->sleep = ft_atoi(av[4]);
		(*arg)->m_eat = 0;
		if (ac == 6)
			(*arg)->m_eat = ft_atoi(av[5]);
		if ((*arg)->philos <= 0 || (*arg)->die <= 0 || (*arg)->eat <= 0
			|| (*arg)->sleep <= 0)
		{
			free((*arg));
			return (0);
		}
		return (1);
	}
	return (0);
}
/*****---------------------------END---------------------------*****/