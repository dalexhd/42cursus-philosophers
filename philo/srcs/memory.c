/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 16:01:28 by aborboll          #+#    #+#             */
/*   Updated: 2021/09/26 19:21:42 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/core.h"

void	clear_memory(t_core *core)
{
	size_t	i;

	i = 1;
	while (i <= core->n_ph)
	{
		free(core->philo[i].forks.right);
		i++;
	}
	free(core->log);
	free(core->philo);
	free(core);
}
