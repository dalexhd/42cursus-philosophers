/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 13:07:51 by aborboll          #+#    #+#             */
/*   Updated: 2021/08/13 14:55:12 by aborboll         ###   ########.fr       */
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
	if (argc == 6)
		core->n_times = ft_atoi(argv[5]);
	else
		core->n_times = -1;
	return (core);
}

void	*exec_thread(void *vargp)
{
	(void)vargp;
	sleep(1);
	ft_putstr("Init thread!\n");
	return (NULL);
}

t_bool	initialize_thread(t_core *core)
{
	size_t		i;
	pthread_t	thread;

	i = 0;
	while (i < core->n_ph)
	{
		pthread_create(&thread, NULL, exec_thread, NULL);
		pthread_join(thread, NULL);
		i++;
	}
	ft_putstr("Finish thread!\n");
	return (true);
}
