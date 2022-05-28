/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test6.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namohamm <namohamm@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 14:51:40 by namohamm          #+#    #+#             */
/*   Updated: 2022/05/28 15:07:57 by namohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

/*****--------------SIMULATION OF DATA RACE---------------*****/ 
void *func1();
void *func2();

int shared = 1;
int main()
{
	pthread_t thread1, thread2;
	pthread_create(&thread1, NULL, func1, NULL);
	pthread_create(&thread2, NULL, func1, NULL);
	
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	printf("Final shared value = %d\n", shared);
}

void *func1()
{
	int x;

	x = shared;
	printf("thread1 reads the value of shared as %d\n", x);
	x++;
	printf("local opdation by thread1 : %d\n", x);
	sleep(1);
	shared = x;
	printf("value of shared var update by thread1 %d\n", shared);
	pthread_exit(0);
}
void *func2()
{
	int x;

	x = shared;
	printf("thread2 reads the value of shared as %d\n", x);
	x--;
	printf("local opdation by thread2 : %d\n", x);
	sleep(1);
	shared = x;
	printf("value of shared var update by thread2 %d\n", shared);
	pthread_exit(0);
}
