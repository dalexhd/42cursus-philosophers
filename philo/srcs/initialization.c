/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 13:07:51 by aborboll          #+#    #+#             */
/*   Updated: 2021/09/01 16:23:07 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/core.h"

t_core	*initialize(int argc, char **argv)
{
	t_core	*core;

	core = malloc(sizeof(t_core));
	ft_bzero(core, sizeof(t_core));
	core->n_ph = ft_atoi(argv[1]);
	core->t_die = ft_atoi(argv[2]);
	core->t_eat = ft_atoi(argv[3]);
	core->t_sleep = ft_atoi(argv[4]);
	core->philo = (t_philo *)malloc(sizeof(t_philo) * core->n_ph);
	if (argc == 6)
		core->n_times = ft_atoi(argv[5]);
	else
		core->n_times = -1;
	return (core);
}

void	*exec_thread(void *vargp)
{
	(void)vargp;
	ft_putstr("Init thread!\n");
	return (NULL);
}

t_bool	initialize_threads(t_core *core)
{
	pthread_t	thread;
	size_t		i;
	int			err;

	i = -1;
	while (++i < core->n_ph)
	{
		err = pthread_create(&thread, NULL, exec_thread, NULL);
		if (err)
		{
			ft_error(strerror(err));
			return (false);
		}
		core->philo[i].thread = thread;
		core->philo[i].forks.right = 0;
		core->philo[i].forks.left = 0;
	}
	i = 0;
	while (i < core->n_ph)
		pthread_join(core->philo[i++].thread, NULL);
	return (true);
}
