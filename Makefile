SRCS		=   get_path.c \
				ft_split.c \
				pipex.c \
				utils.c

SRCS		:= $(addprefix src/,$(SRCS)) 

SRCS_BONUS	=	get_path_bonus.c \
				ft_split_bonus.c \
				pipex_bonus.c \
				utils_bonus.c \
				ft_pipex_bonus.c \
				get_next_line.c \
				get_next_line_utils.c

SRCS_BONUS	:= $(addprefix src/,$(SRCS_BONUS)) 

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
