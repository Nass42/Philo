/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namohamm <namohamm@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:08:12 by namohamm          #+#    #+#             */
/*   Updated: 2022/06/06 16:25:41 by namohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*****---------------------------ATOI------------------*****/
/*****---------------------------ATOI------------------*****/

size_t	ft_strlen(const char *str);
// {
// 	int	n;

// 	n = 0;
// 	while (str[n] != '\0')
// 		n++;
// 	return (n);
// }

void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}


void	ft_putstr_fd(char *s, int fd)
{
	if (!s || !fd)
		return ;
	write (fd, s, ft_strlen(s));
}

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb == -2147483648)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putchar('8', fd);
	}
	else if (nb < 0)
	{
		ft_putchar('-', fd);
		ft_putnbr_fd(-nb, fd);
	}
	else
	{
		if (nb > 9)
		{
			ft_putnbr_fd(nb / 10, fd);
		}
		ft_putchar(48 + nb % 10, fd);
	}
}


/*****---------------------------ATOI------------------*****/
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
// void	ft_write_status(t_arg *arg, int id, char *string)
// {
// 	pthread_mutex_lock(&(arg->mut_write));
// 	if (!(arg->dead))
// 	{
// 		printf(purple"⏳ %zu ", ft_current_time() - arg->start_time);
// 		printf(yellow"%d ", id + 1);
// 		printf(blue"%s\n", string);
// 	}
// 	pthread_mutex_unlock(&(arg->mut_write));
// 	return ;
// }
void	ft_write_status(t_arg *arg, int id, char *string)
{
	size_t n;
	pthread_mutex_lock(&(arg->mut_write));
	if (!(arg->dead))
	{
		n = ft_current_time() - arg->start_time;
		ft_putnbr_fd(n, 1);
		write(1, " ", 1);
		ft_putnbr_fd(id + 1, 1);
		write(1, " ", 1);
		ft_putstr_fd(string, 1);
		write(1, "\n", 1);
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