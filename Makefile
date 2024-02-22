NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRCS =  so_long.c
HEADD = ./
HEADS = so_long.h

BONUS = 
BONUSD = 
BONUSC = 

BONUSS = $(addprefix $(BONUSD), $(BONUSC))

LIBFT = libft/libft.a
LIBFTHD = libft/

all: $(NAME)

$(NAME): $(SRCS) Makefile $(LIBFT)
	$(CC) $(CFLAGS) -I $(HEADD) -I $(LIBFTHD) -o $(NAME) $(SRCS) $(LIBFT)

$(BONUS): $(BONUSS) Makefile
	$(CC) $(CFLAGS) -I $(HEADBD) -o $(BONUS) $(BONUSS) 

$(LIBFT):
	@make --no-print-directory -C $(LIBFTHD)

bonus: $(BONUS)

clean:
	@make --no-print-directory -C $(LIBFTHD) clean

fclean: clean
	$(RM) $(NAME) $(BONUS)
	@make --no-print-directory -C $(LIBFTHD) fclean

re: fclean all

ga:
	git add Makefile $(SRCS) $(HEADS) $(BONUSS) $(HEADB)
	@make --no-print-directory -C $(LIBFTHD) ga

gp:
	git push
	git push github

norm:
	norminette $(SRCS) $(HEADS) $(BONUSS) $(HEADB)
	make --no-print-directory -C ft_printf norm


.PHONNY : norm bonus re fclean clean all ga gp
