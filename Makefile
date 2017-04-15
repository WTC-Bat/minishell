NAME = minishell
SRC = "./src/"
HEAD = "./includes/"
HEADLFT = "./libft/"
FLAGS = -Wall -Werror -Wextra
SRCS = $(SRC)minishell.c $(SRC)msh_bltn_echo.c $(SRC)msh_bltn_env.c \
	   $(SRC)msh_bltn_setenv.c $(SRC)msh_bltn_unsetenv.c $(SRC)msh_funcs.c \
	   $(SRC)msh_exec.c $(SRC)msh_bltn_cd.c $(SRC)msh_cd_navigate.c \
	   $(SRC)msh_cmd_split.c $(SRC)msh_handle_input.c $(SRC)msh_sort_quote.c \
	   $(SRC)msh_cmd_split_funcs.c $(SRC)msh_semicolon_funcs.c \
	   $(SRC)msh_sort_quote_funcs.c

all: $(NAME)

$(NAME):
	cd libft && $(MAKE)
	gcc $(FLAGS) -I$(HEAD) -I$(HEADLFT) $(SRCS) libft/libft.a -o minishell

dbg:
	cd libft && $(MAKE)
	gcc -g -o0 $(FLAGS) -I$(HEAD) -I$(HEADLFT) $(SRCS) libft/libft.a -o minishell

clean:
	rm -f libft/libft.a
	cd libft && $(MAKE) clean

fclean: clean
	rm -f $(NAME)

re: fclean all
