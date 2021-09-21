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

typedef struct s_forks
{
	int			right;
	int			left;
}				t_forks;

typedef struct s_philo
{
	pthread_t		thread;
	t_forks			forks;
	size_t			n;
	char			*status;
	pthread_mutex_t	mutex;
}				t_philo;

typedef struct s_core
{
	size_t			n_ph;
	size_t			t_die;
	size_t			t_eat;
	size_t			t_sleep;
	t_llong			n_times;
	t_philo			*philo;
	pthread_mutex_t	mutex;
}				t_core;

/*
** Definimos las funciones de internas
*/

t_core	*initialize(int argc, char **argv);
t_bool	initialize_threads(t_core *core);
t_bool	validate_args(int argc, char **argv);
void	report_status(t_philo *philo);
void	clear_memory(t_core *core);

/*
** Definimos las funciones de la lib
*/

t_llong	ft_atoll(const char *str);
t_bool	ft_isdigit(int c);
t_bool	ft_isspace(int c);
void	ft_putchar(char c);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr(char *s);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *s);
t_bool	ft_strevery(char const *s, t_bool (*f)(int));
void	ft_bzero(void *s, size_t n);
int		ft_atoi(const char *str);
char	*ft_strcat(char *s1, const char *s2);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_error(char *s);

#endif
