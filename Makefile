NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRCS =  so_long.c sl_load_map.c \
		sl_error.c
HEADD = ./
HEADS = so_long.h

BONUS = 
BONUSD = 
BONUSC = 

BONUSS = $(addprefix $(BONUSD), $(BONUSC))

LIBFTHD = libft/
LIBFT = $(LIBFTHD)libft.a
LIBFTCC = -I $(LIBFTHD) $(LIBFT)

MLXD = mlx/
MLXL = $(MLXD)libmlx.a
MLXCC = -I $(MLXD) -L $(MLXD) -lmlx -framework OpenGL -framework AppKit

OPENGL = -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(SRCS) Makefile $(LIBFT) $(MLXL)
	$(CC) $(CFLAGS) -I $(HEADD) -o $(NAME) $(SRCS) $(LIBFTCC) $(MLXCC)

$(BONUS): $(BONUSS) Makefile
	$(CC) $(CFLAGS) -I $(HEADBD) -o $(BONUS) $(BONUSS) 

$(LIBFT):
	@make --no-print-directory -C $(LIBFTHD)

$(MLXL):
	@make --no-print-directory -C $(MLXD)

bonus: $(BONUS)

clean:
	@make --no-print-directory -C $(LIBFTHD) clean
	@make --no-print-directory -C $(MLXD) clean

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

testmlx: testmlx.c
	$(CC) $(CFLAGS) -o $@ $< $(LIBFTCC) $(MLXCC)

.PHONNY : norm bonus re fclean clean all ga gp
