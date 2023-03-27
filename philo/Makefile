NAME = philo

FILES = philo.c ft_atoi.c ft_isdigit.c ft_strcmp.c time.c check_args.c \
		creation.c action.c

FILES := $(addprefix src/, $(FILES))

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(FILES)
	cc $(FLAGS) $(FILES) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all