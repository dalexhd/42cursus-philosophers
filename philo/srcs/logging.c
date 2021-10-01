/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logging.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 13:07:51 by aborboll          #+#    #+#             */
/*   Updated: 2021/10/01 17:50:25 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/core.h"

void	report_status(t_philo *philo)
{
	t_llong	time;

	pthread_mutex_lock(philo->shared_mutex);
	if (philo->any_died[0] == 1)
	{
		pthread_mutex_unlock(philo->shared_mutex);
		return ;
	}
	time = get_time() - philo->start_time;
	if (!ft_strcmp(philo->status, "forking"))
		printf("%lld %zu %s\n%lld %zu %s\n", time, philo->n,
			D_R_FORKING, time, philo->n, D_R_FORKING);
	else if (!ft_strcmp(philo->status, "eating"))
		printf("%lld %li %s\n", time, philo->n, D_R_EATING);
	else if (!ft_strcmp(philo->status, "sleeping"))
		printf("%lld %zu %s\n", time, philo->n, D_R_SLEEPING);
	else if (!ft_strcmp(philo->status, "thinking"))
		printf("%lld %zu %s\n", time, philo->n, D_R_THINKING);
	else if (!ft_strcmp(philo->status, "died"))
		printf("%lld %zu %s\n", time, philo->n, D_R_DIED);
	else if (!ft_strcmp(philo->status, "test"))
		printf("Pointer: %lld n: %zu left: %p right: %p\n", time,
			philo->n, philo->forks.left, philo->forks.right);
	pthread_mutex_unlock(philo->shared_mutex);
}
