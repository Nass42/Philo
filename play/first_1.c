/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namohamm <namohamm@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 17:41:54 by namohamm          #+#    #+#             */
/*   Updated: 2022/05/28 18:43:38 by namohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t chopstick[5];
void	*philos(void*);
void	eat(int);

int main()
{
	int n[5];
	pthread_t t[5];
	
	int i = 0;
	while (i < 5)
	{
		sem_init(&chopstick[i], 0, 1);
		i++;
	}
	
	i = 0;
	while (i < 5)
	{
		n[i] = i;
		pthread_create(&t[i], NULL, philos, (void *)&n[i]);
		i++;
	}
	
	i = 0;
	while (i < 5)
	{
		pthread_join(t[i], NULL);
		i++;
	}
}

void *philos(void *n)
{
	int ph = *(int *)n;
	printf("philo %d wanna eat 😩\n", ph);
	printf("philo %d tries to pick left chopstick 🥢\n", ph);
	sem_wait(&chopstick[ph]);
	printf("philo %d pick the left chopstick 🥢\n", ph);
	printf("philo %d tries to pick right chopstick 🥢\n", ph);
	sem_wait(&chopstick[(ph + 1) % 5]);
	printf("philo %d pick the right chopstick 🥢\n", ph);
	eat(ph);
	sleep(2);
	printf("philo %d has finished to eat 🤡\n", ph);
	sem_post(&chopstick[(ph + 1)%5]);
	printf("philo %d leave the right chopstick 🥢\n", ph);
	sem_post(&chopstick[ph]);
	printf("philo %d leave the left chopstick 🥢\n", ph);
}

void eat(int ph)
{
	printf("Philo %d is eating 🤩\n", ph);
}