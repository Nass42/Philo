/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namohamm <namohamm@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:08:12 by namohamm          #+#    #+#             */
/*   Updated: 2022/06/05 18:40:45 by namohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*****---------------------------ATOI------------------*****/
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
/*****----------------------------END-------------------*****/

/****---------------------GET THE TIME-------------------****/
size_t	ft_current_time(void)
{
	size_t			time;
	struct timeval	currrent;

	gettimeofday(&currrent, NULL);
	time = (currrent.tv_sec * 1000) + (currrent.tv_usec / 1000);
	return (time);
}
/****------------------------END--------------------------****/

/****---------------------ELAPSED TIME--------------------****/
size_t	ft_elapsed_time(size_t prev, size_t current)
{
	size_t	time;

	time = 0;
	time = current - prev;
	return (time);
}
/****------------------------END--------------------------****/

/****---------------------ELAPSED TIME--------------------****/
void	ft_write_status(t_arg *arg, int id, char *string)
{
	pthread_mutex_lock(&(arg->mut_write));
	if (!(arg->dead))
	{
		printf(purple"⏳ %zu ", ft_current_time() - arg->start_time);
		printf(yellow"%d ", id + 1);
		printf(blue"%s\n", string);
	}
	pthread_mutex_unlock(&(arg->mut_write));
	return ;
}
/****------------------------END--------------------------****/
// void		ft_usleep(size_t time, t_arg *arg)
// {
// 	size_t i;

// 	i = ft_current_time();
// 	while (!(arg->dead))
// 	{
// 		if (ft_elapsed_time(i, ft_current_time()) >= time)
// 			break ;
// 		usleep(50);
// 	}
// }
/****------------------------END--------------------------****/

void		ft_usleep(size_t time, t_arg *arg)
{
	size_t i;

	i = ft_current_time();
	while (!(arg->dead))
	{
		if (ft_elapsed_time(i, ft_current_time()) >= time)
			break ;
		usleep(100);
	}
	
}