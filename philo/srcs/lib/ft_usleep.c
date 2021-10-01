/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 19:52:48 by aborboll          #+#    #+#             */
/*   Updated: 2021/10/01 20:43:50 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/core.h"

void	ft_usleep(size_t time)
{
	t_llong	count;

	count = get_time() + time;
	while (count > get_time())
	{
		usleep(500);
	}
}
