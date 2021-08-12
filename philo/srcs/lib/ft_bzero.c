/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 13:11:41 by aborboll          #+#    #+#             */
/*   Updated: 2021/08/12 13:11:47 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	ft_bzero(void *s, size_t n)
{
	char	*p;
	int		i;

	i = 0;
	p = s;
	while (n-- > 0)
		p[i++] = '\0';
}
