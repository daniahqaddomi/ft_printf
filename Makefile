NAME	= libftprintf.a

FILES	= ft_printf	\

# LIBFT_DIR = libft
CFILES = $(FILES:%=%.c)
OFILES	= $(FILES:%=%.o)

CC	= cc

RM	= rm -f

CFLAGS	= -Wall -Wextra -Werror

all: $(NAME)

# buildft: $(LIBFT_DIR)
# 	make -C $(LIBFT_DIR)

$(NAME):	$(OFILES)
			ar rcs $(NAME) $(OFILES) libft/libft.a
			
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
			$(RM) $(OFILES)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all
 
# .PHONY:		all clean fclean re buildft

