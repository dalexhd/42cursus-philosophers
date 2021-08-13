/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 13:07:51 by aborboll          #+#    #+#             */
/*   Updated: 2021/08/13 13:04:36 by aborboll         ###   ########.fr       */
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
