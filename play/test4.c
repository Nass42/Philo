/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namohamm <namohamm@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 13:28:34 by namohamm          #+#    #+#             */
/*   Updated: 2022/05/28 13:48:29 by namohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *thread_function(void *arg);

// int i, n, j;
int main()
{
	int j = 0;
	pthread_t a_thread; // thread declaration
	pthread_create(&a_thread, NULL, thread_function, NULL); // thread is created
	pthread_join(a_thread, NULL); // process waits for thread to finish
	printf("-------------Inside the main---------\n");
	j = 20;
	while (j < 25)
	{
		printf("%d\n", j);
		sleep(1);
		j++;
	}
	return (0);
}

void *thread_function(void *arg) // the work to be done by the thread
{
	printf("------------Inside the tread------------\n");
	int i = 0;
	while (i < 5)
	{
		printf("%d\n", i);
		sleep(1);
		i++;
	}
}