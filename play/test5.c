/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namohamm <namohamm@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 14:09:29 by namohamm          #+#    #+#             */
/*   Updated: 2022/05/28 14:31:23 by namohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

/****----Program to pass parameters to a thread---****/ 
void *thread_function(void *arg);

int num[2] = {2, 5};
int main()
{
	pthread_t a_thread;
	void *result;
	pthread_create(&a_thread, NULL, thread_function, (void *)num); // thread is created
	pthread_join(a_thread, &result); // process waits fot thread to finish
	printf("Inside the Main Process\n");
	printf("Thread returned: %d\n", (int )result);
}

void *thread_function(void *arg)
{
	printf("Inside the Thread\n");
	long int n;
	int *x = arg;
	int sum = x[0] + x[1];
	n = sum;
	// printf("Sum is %d\n", sum);
	printf("Sum is comming...\n");
	pthread_exit((void *)n);
}