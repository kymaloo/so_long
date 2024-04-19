NAME	:= solong

NAME_B  := solong_bonus

CFLAGS	:= -Wextra -Wall -Werror -g3

HEADERS	:= -Iinclude -IMLX42/include

LIBS	:= MLX42/build/libmlx42.a -ldl -lglfw -lm -g3

SRCS	:= 	src/main.c \
			src/get_next_line.c \
			src/get_next_line_utils.c \
			src/map.c \
			src/check.c \
			src/check2.c \
			src/utils.c \
			src/path_finding.c \
			src/init.c \
			src/init2.c \
			src/window.c \
			src/window2.c \
			src/move.c \
			src/pick_up.c \
			src/t_coin.c \
			src/t_coin2.c \
			src/utils2.c \
			src/utils3.c \
			src/printf2.c \
			src/printf.c

SRCS_B	:= 	bonus/main.c \
			bonus/get_next_line.c \
			bonus/get_next_line_utils.c \
			bonus/map.c \
			bonus/check.c \
			bonus/check2.c \
			bonus/utils.c \
			bonus/path_finding.c \
			bonus/init.c \
			bonus/init2.c \
			bonus/window.c \
			bonus/windows2.c \
			bonus/move.c \
			bonus/pick_up.c \
			bonus/t_coin.c \
			bonus/t_coin2.c \
			bonus/utils2.c \
			bonus/utils3.c \
			bonus/printf2.c \
			bonus/printf.c \
			bonus/tp.c

OBJS	:= ${SRCS:.c=.o}

OBJS_B	:= ${SRCS_B:.c=.o}

all: $(NAME)

r: re
	./$(NAME) "maps/map.ber"

v: re
	valgrind -s --leak-check=full --track-origins=yes  ./$(NAME) "maps/map.ber"

vb: bonus
	valgrind -s --leak-check=full --track-origins=yes  ./$(NAME_B) "maps/map_bonus.ber"

n:
	norminette src/ include/ bonus/

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

re :
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

bonus: $(NAME_B)
$(NAME_B): $(OBJS_B)
	@$(CC) $(CFLAGS) $(OBJS_B) $(LIBS) $(HEADERS) -o $(NAME_B)

clean:
	@rm -rf $(OBJS) $(OBJS_B)

fclean: clean
	@rm -rf $(NAME) $(NAME_B)

re: clean all

.PHONY: all, clean, fclean, re, bonus