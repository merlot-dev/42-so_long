NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -f

BONUSC = so_long_bonus.c sl_load_map_bonus.c check_path_bonus.c \
		 init_map_bonus.c \
		 draw_map_bonus.c draw_wall_bonus.c draw_coll_bonus.c \
		 draw_sidescr_bonus.c \
		 key_moves_bonus.c \
		 img_tools_bonus.c x_tools_bonus.c \
		 load_elements_bonus.c \
		 sl_error_bonus.c 
BONUSD = bonus/
BONUSS = $(addprefix $(BONUSD),$(BONUSC))
HEADBD = bonus/
HEADB = so_long_bonus.h
HEADBS = $(addprefix $(HEADBD),$(HEADB))

ifndef BONUS
SRCS =  so_long.c sl_load_map.c check_path.c init_map.c \
		draw_map.c draw_wall.c draw_coll.c draw_sidescr.c \
		key_moves.c \
		img_tools.c x_tools.c \
		load_elements.c \
		sl_error.c
HEADD = ./
HEADS = so_long.h
else
SRCS = $(BONUSS)
HEADD = $(HEADBD)
HEADS = $(HEADBS)
endif

LIBFTHD = libft/
LIBFT = $(LIBFTHD)libft.a
LIBFTCC = -I $(LIBFTHD) $(LIBFT)

MLXD = mlx/
MLXL = $(MLXD)libmlx.a
MLXCC = -I $(MLXD) -L $(MLXD) -lmlx -framework OpenGL -framework AppKit

OPENGL = -framework OpenGL -framework AppKit

all: 
ifneq ("$(wildcard .do_bonus)","")
	@$(RM) $(NAME) .do_bonus
endif
	@make --no-print-directory mandatory

mandatory: $(NAME)
	@echo "Mandatory so_long available"

$(NAME): $(SRCS) Makefile $(LIBFT) $(MLXL) $(HEADS)
	$(CC) $(CFLAGS) -I $(HEADD) -o $(NAME) $(SRCS) $(LIBFTCC) $(MLXCC)

$(LIBFT):
	@make --no-print-directory -C $(LIBFTHD)

$(MLXL):
	@make --no-print-directory -C $(MLXD)

clean:
	@make --no-print-directory -C $(LIBFTHD) clean
	@make --no-print-directory -C $(MLXD) clean

fclean: clean
	$(RM) $(NAME)
	@make --no-print-directory -C $(LIBFTHD) fclean

re: fclean all

bonus:
ifeq ("$(wildcard .do_bonus)","")
	@$(RM) $(NAME)
endif
	make --no-print-directory BONUS=1 do_bonus

do_bonus: $(NAME)
	@echo "Bonus so_long available"
	@touch .do_bonus

ga:
	git add Makefile $(SRCS) $(HEADS) $(BONUSS) $(HEADBS) sprites/*.xpm *.ber
	@make --no-print-directory -C $(LIBFTHD) ga

gp:
	git push
	git push github

norm:
	norminette $(SRCS) $(HEADS) $(BONUSS) $(HEADBS)
	@make --no-print-directory -C $(LIBFTHD)  norm

testmlx: testmlx.c
	$(CC) $(CFLAGS) -o $@ $< $(LIBFTCC) $(MLXCC)

.PHONY : norm mandatory bonus do_bonus re fclean clean all ga gp
