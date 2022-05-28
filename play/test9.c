/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test9.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namohamm <namohamm@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 17:16:19 by namohamm          #+#    #+#             */
/*   Updated: 2022/05/28 17:34:53 by namohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <unistd.h>
// #include <pthread.h>

// /******--------Synchronisation-using-mutex-lock-------*******/
// void *func1();
// void *func2();

// int shared = 1;

// pthread_t *l; // mutex-lock

// int main()
// {
// 	pthread_mutex_init(l, NULL); // init mutex var, 
// 	pthread_t thread1, thread2;
// 	pthread_create(&thread1, NULL, func1, NULL);
// 	pthread_create(&thread2, NULL, func2, NULL);
// 	pthread_join(thread1, NULL);
// 	pthread_join(thread2, NULL);
// 	printf("final value shared = %d\n", shared);
// }

// void *func1()
// {
// 	int x;
// 	printf("thread_1 trying to acquire lock\n");
// 	pthread_mutex_lock(&l); // tread_1 lock the var, thread_2 can't have access
// 	x = shared;
// 	printf("thread_1 reads the value of shared as %d\n", x);
// 	x++;
// 	printf("local opdation by thread_1 : %d\n", x);
// 	sleep(1);
// 	shared = x;
// 	printf("value of shared var update by thread_1 %d\n", shared);
// 	pthread_mutex_unlock(&l);
// 	printf("thread_1 release the lock\n");
// 	// pthread_exit(0);
// }
// void *func2()
// {
// 	int x;
// 	printf("thread_2 trying to acquire lock\n");
// 	pthread_mutex_lock(&l); // tread_1 lock the var, thread_2 can't have access
// 	x = shared;
// 	printf("thread_2 reads the value of shared as %d\n", x);
// 	x--;
// 	printf("local opdation by thread_2 : %d\n", x);
// 	sleep(1);
// 	shared = x;
// 	printf("value of shared var update by thread_2 %d\n", shared);
// 	pthread_mutex_unlock(&l);
// 	printf("thread_2 release the lock\n");
// 	// pthread_exit(0);
// }


#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
void *fun1();
void *fun2();
 int shared=1; //shared variable
 pthread_mutex_t l; //mutex lock
 int main()
 {
 pthread_mutex_init(&l, NULL); //initializing mutex locks
 pthread_t thread1, thread2;
 pthread_create(&thread1, NULL, fun1, NULL);
 pthread_create(&thread2, NULL, fun2, NULL);
 pthread_join(thread1, NULL);
 pthread_join(thread2,NULL);
 printf("Final value of shared is %d\n",shared); //prints the last updated value of shared variable
 }
 
 void *fun1()
 {
     int x;
     printf("Thread1 trying to acquire lock\n");
     pthread_mutex_lock(&l); //thread one acquires the lock. Now thread 2 will not be able to acquire the lock //until it is unlocked by thread 1
    printf("Thread1 acquired lock\n");
     x=shared;//thread one reads value of shared variable
     printf("Thread1 reads the value of shared variable as %d\n",x);
     x++;  //thread one increments its value
     printf("Local updation by Thread1: %d\n",x);
     sleep(1);  //thread one is preempted by thread 2
     shared=x; //thread one updates the value of shared variable
     printf("Value of shared variable updated by Thread1 is: %d\n",shared);
     pthread_mutex_unlock(&l);
     printf("Thread1 released the lock\n");
 }
 
 void *fun2()
 {
     int y;
     printf("Thread2 trying to acquire lock\n");
     pthread_mutex_lock(&l);
     printf("Thread2 acquired lock\n");
     y=shared;//thread two reads value of shared variable
     printf("Thread2 reads the value as %d\n",y);
     y--;  //thread two increments its value
     printf("Local updation by Thread2: %d\n",y);
     sleep(1); //thread two is preempted by thread 1
     shared=y; //thread one updates the value of shared variable
     printf("Value of shared variable updated by Thread2 is: %d\n",shared);
     pthread_mutex_unlock(&l);
     printf("Thread2 released the lock\n");
 }