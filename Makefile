NAME			=	pipex

LIBFT			=	libft.a libftprintf.a

DIR_SRCS		=	srcs/mandatory

DIR_BONUS		=	srcs/bonus

DIR_OBJS		=	objs

SRCS_NAMES		=	pipex.c process.c

SRCS_NAMES_B	=	pipex.c process.c here_doc.c

OBJS_NAMES		=	${SRCS_NAMES:.c=.o}

OBJS_NAMES_B	=	${SRCS_NAMES_B:.c=.o}

SRCS			=	$(addprefix $(DIR_SRCS)/,$(SRCS_NAMES))

SRCS_B			=	$(addprefix $(DIR_BONUS)/,$(SRCS_NAMES_B))

OBJS			=	$(addprefix $(DIR_OBJS)/,$(OBJS_NAMES))

OBJS_B			=	$(addprefix $(DIR_OBJS)/,$(OBJS_NAMES))

HEAD			=	-Ilibft/includes -Iincludes

CC				=	cc

CFLAGS			=	-g3 -Wall -Werror -Wextra

MAKEFLAGS		=	--no-print-directory

all				:	${NAME}

$(NAME): $(OBJS)
	make -C libft
	make -C libft/ft_printf
	mv libft/libft.a .
	mv libft/ft_printf/libftprintf.a .
	$(CC) $(CFLAGS) $(OBJS) ${LIBFT} ${HEAD} -o $(NAME)
	@echo "\033[34;5mpipex mandatory\033[0m"

$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.c | $(DIR_OBJS)
	$(CC) $(CFLAGS) -c $< -o $@ $(HEAD)

$(DIR_OBJS):
	mkdir -p $(DIR_OBJS)

bonus:
	make -C libft
	make -C libft/ft_printf
	mv libft/ft_printf/libftprintf.a .
	mv libft/libft.a .
	$(CC) $(CFLAGS) $(SRCS_B) ${LIBFT} ${HEAD} -o $(NAME)
	@echo "\033[39;5mpipex bonus\033[0m"

clean:
	make clean -C libft
	rm -rf ${DIR_OBJS}
	rm -rf ${OBJS}

fclean:	clean
	make fclean -C libft
	rm -rf ${LIBFT}
	rm -rf ${NAME}

re:	fclean all

stop:
	rm -f ${NAME}

.PHONY:	all clean fclean re bonus
# .SILENT:
