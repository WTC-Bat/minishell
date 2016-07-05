NAME = minishell
SRC = "./src/"
HEAD = "./includes/"
HEADLFT = "./libft/"
FLAGS = -Wall -Werror -Wextra
LIB_FT = -L ./libft/ -lft

SRCS = $(SRC)minishell.c $(SRC)msh_bltn_echo.c $(SRC)msh_bltn_env.c \
	   $(SRC)msh_bltn_setenv.c $(SRC)msh_bltn_unsetenv.c $(SRC)msh_funcs.c

#OBJS = ./msh_bltn_echo.o ./msh_bltn_env.o ./msh_bltn_setenv.o \
#	   ./msh_bltn_unsetenv.o ./msh_funcs.o

all: $(NAME)

$(NAME):
	make -C ./libft/
	gcc $(FLAGS) -I$(HEAD) -I$(HEADLFT) $(SRCS) $(LIB_FT) -o minishell

dbg:
	make -C ./libft/
	gcc -g $(FLAGS) -I$(HEAD) -I$(HEADLFT) $(SRCS) $(LIB_FT) -o minishell

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
