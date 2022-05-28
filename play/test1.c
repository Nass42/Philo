/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namohamm <namohamm@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 19:42:48 by namohamm          #+#    #+#             */
/*   Updated: 2022/05/28 10:11:25 by namohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>

sem_t chop[5];
char status[6] = {'-','-','-','-','-'};

void printstatus()
{
	int i;
	
	i = 0;
	printf("\n");
	while (i < 5)
	{
		printf("    %c", status[i]);
		i++;
	}
}

void *philosopher(void *arg)
{
	long int nbr = (long int) arg;
	// philo in a hungry state
	status[nbr] = 'H';
	printstatus();
	// Aquire the left and right chopstick
	sem_wait(&chop[nbr]);
	sem_wait(&chop[(nbr + 1) % 5]);
	// Philo is eating
	status[nbr] = 'E';
	printstatus();
	// Need a time to eat
	sleep(1);
	// Release the chopstick
	sem_post(&chop[(nbr + 1) % 5]);
	sem_post(&chop[nbr]);
	// Philo is thinking
	status[nbr] = 'T';
	printstatus();
	pthread_exit(NULL);
}

int main()
{
	pthread_t phil[5];
	long int i, j;
	/***-------------------------INIT A SEMAPHORE---------------------***/
	i = 0;
	while (i < 5)
	{
		sem_init(&chop[i], 0, 1);
		i++;
	}
	/***------------------------------END-----------------------------***/
	/***----------------------------PRINTING--------------------------***/
	j = 0;
	printf("\n");
	while (j < 5)
	{
		printf(" P[%ld]", j);
		j++;
	}
	/***------------------------------END-----------------------------***/
	/***-------------------CREATE THREADS OF PHILO--------------------***/
	i = 0;
	while (i < 5)
	{
		pthread_create(&phil[i], NULL, philosopher, (void *)i);
		i++;
	}
	/***-----------------------------END------------------------------***/
	/***-------------------CREATE THREADS OF PHILO--------------------***/
	i = 0;
	while (i < 5)
	{
		pthread_join(phil[i], NULL);
		i++;
	}
	/***-----------------------------END------------------------------***/
	return (0);
}

// cc test1.c -Wno-deprecated -lpthread 