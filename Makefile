NAME = minishell
SRC = "./src/"
HEAD = "./includes/"
HEADLFT = "./libft/"
FLAGS = -Wall -Werror -Wextra
LIB_FT = -L ./libft/ -lft

SRCS = $(SRC)minishell.c $(SRC)msh_bltn_echo.c $(SRC)msh_bltn_env.c \
	   $(SRC)msh_bltn_setenv.c $(SRC)msh_bltn_unsetenv.c $(SRC)msh_funcs.c \
	   $(SRC)msh_exec.c $(SRC)msh_bltn_cd.c $(SRC)msh_cd_navigate.c

all: $(NAME)

$(NAME):
	make re -C ./libft/ && make clean -C ./libft/
	gcc $(FLAGS) -I$(HEAD) -I$(HEADLFT) $(SRCS) $(LIB_FT) -o minishell

dbg:
	make re -C ./libft/ && make clean -C ./libft/
	gcc -g $(FLAGS) -I$(HEAD) -I$(HEADLFT) $(SRCS) $(LIB_FT) -o minishell

clean:
	rm -f ./libft/libft.a

fclean: clean
	rm -f $(NAME)

re: fclean all
