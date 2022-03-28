SRCS		=   src/get_path.c \
				src/ft_split.c \
				src/pipex.c \
				src/utils.c

SRCS_BONUS	=	src/get_path_bonus.c \
				src/ft_split_bonus.c \
				src/pipex_bonus.c \
				src/utils_bonus.c \
				src/ft_pipex_bonus.c \
				src/get_next_line.c \
				src/get_next_line_utils.c

OBJS		= ${SRCS:.c=.o}

OBJS_BONUS	= ${SRCS_BONUS:.c=.o}

NAME		= pipex

NAME_BONUS	= pipex_bonus

CC			= gcc

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror -Iinclude

${NAME}:	${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS}

all:		${NAME}

$(NAME_BONUS): ${OBJS_BONUS}
			${CC} ${CFLAGS} -o ${NAME_BONUS} ${OBJS_BONUS}

bonus:		$(NAME_BONUS)

clean:
			${RM} ${OBJS} ${OBJS_BONUS}

fclean:		clean
			${RM} ${NAME} ${NAME_BONUS}

re:			fclean all

.PHONY:		all clean fclean re bonus
