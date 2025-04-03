NAME = philo

CC = cc

CFLAGS	 =	-Wextra -Wall -Werror #-Wunreachable-code
CFLAGS	+= -I incl
CFLAGS	+= -O3

#DEBUG	 =	-g3 -fsanitize=thread -pthread
DEBUG	 =	-g3 -fsanitize=address

CPPFLAGS =	-MMD

HEADERS = -I ./inc

SRCS =							\
		srcs/main.c				\
		srcs/parser.c			\
		srcs/utils.c			\
		srcs/init.c				\
		srcs/destroy_data.c		\
		srcs/init_philos.c		\
		srcs/time.c				\



OBJS = $(patsubst srcs/%.c, objs/srcs/%.o, $(SRCS))
DEPS = $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(DEBUG) $(OBJS) $(HEADERS) -o $(NAME) && printf "Linking: $(NAME)\n"

objs/srcs/%.o: ./srcs/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CPPFLAGS) $(DEBUG) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"

clean:
	@rm -rf objs

fclean: clean
	@rm -rf $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
