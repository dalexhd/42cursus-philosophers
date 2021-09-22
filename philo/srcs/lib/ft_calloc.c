/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:41:26 by aborboll          #+#    #+#             */
/*   Updated: 2021/09/22 19:00:28 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/core.h"

void	*ft_calloc(size_t count, size_t size)
{
	t_uchar	*tab;
	size_t	i;

	i = 0;
	tab = (t_uchar *)malloc(size * count);
	if (!tab)
		return (NULL);
	while (i < count * size)
		tab[i++] = '\0';
	return (tab);
}
