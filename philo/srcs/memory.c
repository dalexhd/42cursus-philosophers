/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 16:01:28 by aborboll          #+#    #+#             */
/*   Updated: 2021/10/08 07:27:39 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/core.h"

void	clear_memory(t_core *core)
{
	size_t	i;

	i = 0;
	while (i <= core->n_ph)
	{
		free(core->philo[i].forks.right);
		i++;
	}
	free(core->shared_mutex);
	free(core->philo);
	free(core);
}
