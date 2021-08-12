/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 20:45:27 by aborboll          #+#    #+#             */
/*   Updated: 2021/08/12 13:51:57 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/*
** Incluimos las librerias esenciales.
*/
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>
# include <math.h>

/*
** Incluimos nuestros types.
*/
# include "types.h"

/*
** Incluimos las constantes.
*/
# include "constants.h"

/*
** Incluimos la parte interna.
*/
# include "internal.h"

typedef struct s_philo
{
	size_t	n_ph;
	size_t	t_die;
	size_t	t_eat;
	size_t	t_sleep;
	size_t	n_times;
}				t_philo;

/*
** Definimos las funciones de internas
*/

t_philo	*init_philo(int argc, char **argv);
t_bool	validate_args(int argc, char **argv);

/*
** Definimos las funciones de la lib
*/

t_llong	ft_atoll(const char *str);
t_bool	ft_isdigit(int c);
t_bool	ft_isspace(int c);
void	ft_putchar(char c);
void	ft_putstr(char *s);
size_t	ft_strlen(const char *s);
t_bool	ft_strevery(char const *s, t_bool (*f)(int));
void	ft_bzero(void *s, size_t n);
int		ft_atoi(const char *str);

#endif
