/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 20:45:27 by aborboll          #+#    #+#             */
/*   Updated: 2021/08/13 12:49:30 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_H
# define CORE_H

/*
** Incluimos las librerias esenciales.
*/
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>
# include <pthread.h>
# include <string.h>
# include <stdio.h>
# include <sys/time.h>

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

/*
** Incluimos la parte de colores.
*/
# include "color.h"

typedef struct s_forks
{
	pthread_mutex_t	*right;
	pthread_mutex_t	*left;
}				t_forks;

typedef struct s_philo
{
	pthread_t		thread;
	t_forks			forks;
	size_t			n;
	size_t			n_ph;
	size_t			t_die;
	size_t			t_eat;
	size_t			t_sleep;
	t_llong			n_times;
	t_llong			start_time;
	pthread_mutex_t	*shared_mutex;
	int				*any_died;
	char			*status;
}				t_philo;

typedef struct s_core
{
	size_t			n_ph;
	size_t			t_die;
	size_t			t_eat;
	size_t			t_sleep;
	t_llong			start_time;
	t_llong			n_times;
	size_t			ph_n;
	t_philo			*philo;
	int				any_died;
	pthread_mutex_t	*shared_mutex;
}				t_core;

/*
** Definimos las funciones de internas
*/

t_core	*initialize(int argc, char **argv);
t_bool	initialize_threads(t_core *core);
t_bool	validate_args(int argc, char **argv);
void	report_status(t_philo *philo);
void	clear_memory(t_core *core);
t_bool	forking(t_philo *philo);
t_bool	eating(t_philo *philo);
t_bool	sleeping(t_philo *philo);
t_bool	thinking(t_philo *philo);
t_bool	died(t_philo *philo);
t_llong	get_time(void);

/*
** Definimos las funciones de la lib
*/

t_llong	ft_atoll(const char *str);
t_bool	ft_isdigit(int c);
t_bool	ft_isspace(int c);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *s);
t_bool	ft_strevery(char const *s, t_bool (*f)(int));
void	ft_bzero(void *s, size_t n);
int		ft_atoi(const char *str);
int		ft_strcmp(const char *s1, const char *s2);
void	*ft_calloc(size_t count, size_t size);
void	ft_error(char *s);

#endif
