/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test7.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namohamm <namohamm@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 15:08:15 by namohamm          #+#    #+#             */
/*   Updated: 2022/05/28 18:20:28 by namohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <fcntl.h>

/******--------Synchronisation-usigng-semaphores-------*******/
void *func1();
void *func2();

int shared = 1;

sem_t s;

int main()
{
	sem_init(&s, 0, 1); // init semaphore var,
	// s = sem_open("sem", O_CREAT);
	pthread_t thread1, thread2;
	pthread_create(&thread1, NULL, func1, NULL);
	pthread_create(&thread2, NULL, func2, NULL);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	// printf("final value shared = %d\n", shared);
}

void *func1()
{
	int x;
	sem_wait(&s); // execute wait operation on s
	x = shared;
	printf("thread1 reads the value of shared as %d\n", x);
	x++;
	printf("local opdation by thread1 : %d\n", x);
	sleep(1);
	shared = x;
	printf("value of shared var update by thread1 %d\n", shared);
	sem_post(&s);
	// pthread_exit(0);
}
void *func2()
{
	int x;
	sem_wait(&s); // execute wait operation on s
	x = shared;
	printf("thread2 reads the value of shared as %d\n", x);
	x--;
	printf("local opdation by thread2 : %d\n", x);
	sleep(1);
	shared = x;
	printf("value of shared var update by thread2 %d\n", shared);
	sem_post(&s);
	// pthread_exit(0);
}