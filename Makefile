NAME	:= solong

CFLAGS	:= -Wextra -Wall -Werror

HEADERS	:= -Iinclude -IMLX42/include

LIBS	:= MLX42/build/libmlx42.a -ldl -lglfw -lm -g3

SRCS	:= 	src/main.c \
			src/get_next_line.c \
			src/get_next_line_utils.c \

OBJS	:= ${SRCS:.c=.o}

all: libmlx $(NAME)

r: re
	valgrind ./$(NAME)

libmlx:
	@cmake MLX42 -B MLX42/build && make -C MLX42/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@rm -rf MLX42/build

fclean: clean
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx