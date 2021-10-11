/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logging.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 13:07:51 by aborboll          #+#    #+#             */
/*   Updated: 2021/10/11 17:36:48 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/core.h"

void	report_status(t_philo *ph)
{
	t_llong	time;

	pthread_mutex_lock(ph->shared_mutex);
	if (ph->any_died[0] == 1)
		return ((void)(pthread_mutex_unlock(ph->shared_mutex)));
	time = get_time() - ph->tm_time;
	if (!ft_strcmp(ph->status, "forking"))
		printf("%lld %zu %s\n%lld %zu %s\n", time, ph->n,
			D_R_FORKING, time, ph->n, D_R_FORKING);
	else if (!ft_strcmp(ph->status, "forking1"))
		printf("%lld %zu %s\n", time, ph->n, D_R_FORKING);
	else if (!ft_strcmp(ph->status, "eating"))
		printf("%lld %li %s\n", time, ph->n, D_R_EATING);
	else if (!ft_strcmp(ph->status, "sleeping"))
		printf("%lld %zu %s\n", time, ph->n, D_R_SLEEPING);
	else if (!ft_strcmp(ph->status, "thinking"))
		printf("%lld %zu %s\n", time, ph->n, D_R_THINKING);
	else if (!ft_strcmp(ph->status, "died"))
	{
		printf("%lld %zu %s\n", time, ph->n, D_R_DIED);
	}
	else if (!ft_strcmp(ph->status, "test"))
		printf("Pointer: %lld n: %zu left: %p right: %p\n", time,
			ph->n, ph->forks.left, ph->forks.right);
	pthread_mutex_unlock(ph->shared_mutex);
}
