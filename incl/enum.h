#ifndef ENUM_H
# define ENUM_H

typedef enum e_char_token {
	CT__ERROR,
	CT___PLUS,
	CT_NUMBER
} t_char_token;

typedef enum e_philo_info {
	INFO_PH_N_FILOS = 1,
	INFO_PH_TIME_LIFE,
	INFO_PH_TIME_EAT,
	INFO_PH_TIME_SLEEP,
	INFO_PH_N_PLATES
} t_philo_info;

typedef enum	e_state {
	ST_INICIAL,
	ST___ERROR,
	ST____PLUS,
	ST__NUMBER,
	ST_NUMBER_OF_STATES
} t_state;

#endif