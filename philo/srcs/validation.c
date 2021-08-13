/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 12:45:17 by aborboll          #+#    #+#             */
/*   Updated: 2021/08/13 12:51:47 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/core.h"

static	t_bool	check_arg(size_t i, char *arg)
{
	t_bool	ret;

	ret = true;
	if (i == 1 && ft_atoi(arg) < 2)
	{
		ft_error(ERR_BAD_N_PH);
		ret = false;
	}
	else if ((i == 2 || i == 3 || i == 4) && ft_atoi(arg) < 1)
	{
		if (i == 2)
			ft_error(ERR_BAD_T_DIE);
		else if (i == 3)
			ft_error(ERR_BAD_T_EAT);
		else if (i == 4)
			ft_error(ERR_BAD_T_SLEEP);
		ret = false;
	}
	else if (i == 5 && ft_atoi(arg) < 1)
	{
		ft_error(ERR_BAD_N_TIMES_1""ERR_BAD_N_TIMES_2);
		ret = false;
	}
	return (ret);
}

static	t_bool	check_args(int argc, char **argv)
{
	int		i;
	t_bool	ret;

	i = 0;
	ret = true;
	while (++i < argc)
	{
		if (!ft_strevery(argv[i], ft_isdigit)
			&& (argv[i][0] == '-' && !ft_strevery(&argv[i][1], ft_isdigit)))
		{
			ft_error(ERR_NOT_NUMBER);
			ret = false;
			break ;
		}
		if (ft_atoll(argv[i]) >= INT_MAX || ft_atoll(argv[i]) <= INT_MIN)
		{
			ft_error(ERR_NOT_INT_NUMBER);
			ret = false;
			break ;
		}
		ret = check_arg(i, argv[i]);
		if (!ret)
			break ;
	}
	return (ret);
}

t_bool	validate_args(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
	{
		ft_error(ERR_BAD_ARGS);
		return (false);
	}
	return (check_args(argc, argv));
}
