/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 12:45:17 by aborboll          #+#    #+#             */
/*   Updated: 2021/08/12 14:15:20 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static	t_bool	check_args(int argc, char **argv)
{
	int		i;
	t_bool	ret;
	t_llong	index;

	i = 0;
	ret = TRUE;
	while (++i < argc)
	{
		if (!ft_strevery(argv[i], ft_isdigit))
		{
			ft_putstr(ERR_NOT_NUMBER);
			ret = FALSE;
			break ;
		}
		index = ft_atoll(argv[i]);
		if (index >= INT_MAX || index <= INT_MIN)
		{
			ft_putstr(ERR_NOT_INT_NUMBER);
			ret = FALSE;
			break ;
		}
	}
	return (ret);
}

t_bool	validate_args(int argc, char **argv)
{
	int		i;
	t_bool	ret;

	i = 0;
	ret = TRUE;
	if (argc < 5 || argc > 6)
	{
		ft_putstr(ERR_BAD_ARGS);
		return (FALSE);
	}
	ret = check_args(argc, argv);
	return (ret);
}
