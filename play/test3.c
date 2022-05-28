/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namohamm <namohamm@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 10:28:35 by namohamm          #+#    #+#             */
/*   Updated: 2022/05/28 13:17:59 by namohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
	pid_t	p;
	p = fork();
	if (p == 0)
	{
		sleep(3);
		printf("I'm child having id => %d\n", getpid());
		printf("My parent's id is   => %d\n", getppid());
	}
	else
	{
		// wait(NULL);
		printf("My child's id is    => %d\n", p);
		printf("I'm a parent having => %d\n", getpid());
	}
	printf("/-------------------------------------/\n");
	// return (0);
}

// #include<stdio.h>
// #include<unistd.h>
// #include<sys/types.h>
// #include<sys/wait.h>
// int main()
// {
// 	pid_t p;
// 	printf("before fork\n");
// 	p=fork();
// 	if(p == 0)
// 	{
// 		printf("I am child having id %d\n",getpid());
// 		printf("My parent's id is %d\n",getppid());
// 	}
// 	else
// 	{
// 		printf("My child's id is %d\n",p);
// 		printf("I am parent having id %d\n",getpid());
// 	}
// 	printf("/-------------------------------------/\n");
// 	wait(NULL);
// }

// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// #include <unistd.h>

// int main(int ac, char **av)
// {
// 	int id = fork();
// 	if (id == 0)
// 		printf("hello from child %d\n", getpid());
// 	else
// 		printf("hello from parent %d\n", getpid());
		
// 	return (0);
// }