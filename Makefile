NAME	:= solong

CFLAGS	:= -Wextra -Wall -Werror -g3

HEADERS	:= -Iinclude -IMLX42/include

LIBS	:= MLX42/build/libmlx42.a -ldl -lglfw -lm -g3

SRCS	:= 	src/main.c \
			src/get_next_line.c \
			src/get_next_line_utils.c \
			src/map.c \
			src/check.c \
			src/utils.c \
			src/path_finding.c \
			src/init.c \
			src/window.c \
			src/move.c \
			src/pick_up.c \

OBJS	:= ${SRCS:.c=.o}

all: $(NAME)

r: re
	./$(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) 

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re