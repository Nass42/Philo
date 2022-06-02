	// while (1)
    // {
    // 	if (!pthread_mutex_lock(&(ph->mutex[inc])) &&
    // 		 !pthread_mutex_lock(&(ph->mutex[(inc + 1) % ph->philos])))
	// 	{
	// 		pthread_mutex_lock(&(ph->write_mutex));
	// 		ft_write_status(ph, "has taken a fork 🥢", time);
	// 		ft_write_status(ph, "has taken a fork 🥢", time);
	// 		pthread_mutex_unlock(&(ph->write_mutex));
			
	// 	}
		
	// 	pthread_mutex_lock(&(ph->write_mutex));
	// 	ft_write_status(ph, "is  eating  ...  🍔", time);
	// 	pthread_mutex_unlock(&(ph->write_mutex));
		
	// 	pthread_mutex_lock(&(ph->mut_eat));
	// 	usleep(ph->eat * 1000);
	// 	pthread_mutex_unlock(&(ph->mut_eat));
	
	// 	pthread_mutex_lock(&(ph->write_mutex));
	// 	ft_write_status(ph, "is sleeping ...  😴", time);
	// 	pthread_mutex_unlock(&(ph->write_mutex));
		
	// 	pthread_mutex_lock(&(ph->mut_sleep));
	// 	usleep(ph->sleep * 1000);
	// 	pthread_mutex_unlock(&(ph->mut_sleep));
		
    // 	pthread_mutex_unlock(&(ph->mutex[(inc + 1) % ph->philos]));
    // 	pthread_mutex_unlock(&(ph->mutex[inc]));
		
	// 	pthread_mutex_lock(&(ph->write_mutex));
	// 	ft_write_status(ph, "is thinking ...  🤓", time);
	// 	pthread_mutex_unlock(&(ph->write_mutex));
	// }