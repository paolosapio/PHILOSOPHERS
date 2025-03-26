#ifndef PHILO_H
# define PHILO_H

# include "enum.h"
# include "structures.h"

# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <stdlib.h>
# include <string.h>

//FUNCIONES

//parser.c
int			traductor_char_to_token(char c);
int			get_state(t_state current_state, int token_char);
int			evaluate_string(char *str);
int			parser(int argc, char **argv);

//utils.c
long		ft_atol(const char *nptr);
void		*ft_calloc(size_t count, size_t size);
int			ft_isdigit(int c);
long		ft_atol(const char *nptr);

//init.c
t_data_pack init_data(char **argv);
int			init_array_forks(t_data_pack *data);
int			init_array_philo(t_data_pack *data);

//list_philo.c
void		ft_lstadd_back(t_philo **lst, t_philo *new);
t_philo		*ft_lstnew(int id);

//destroy_data.c
void		destroy_data(t_data_pack *data);

//init_philos.c
void		*print_philo_n(void	*arg);
void		init_philos(t_data_pack *d_pack);

#endif