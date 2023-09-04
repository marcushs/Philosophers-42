# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/24 17:22:01 by hleung            #+#    #+#              #
#    Updated: 2023/09/04 20:13:20 by hleung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	philo
CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror -pthread -fsanitize=thread
RM				=	rm -rf
HEADER			=	includes
DIR_SRCS		=	./srcs/
LIST_SRCS		=	philo.c ft_putstr.c parse.c init.c free.c time.c threads.c actions.c print.c
SRCS			=	${addprefix ${DIR_SRCS}, ${LIST_SRCS}}
DIR_OBJS		=	.objs/
LIST_OBJS		=	${LIST_SRCS:.c=.o}
OBJS			=	${addprefix ${DIR_OBJS}, ${LIST_OBJS}}

${DIR_OBJS}%.o:	${DIR_SRCS}%.c ./includes/philo.h
				${CC} ${CFLAGS} -c $< -o $@ -I ${HEADER}

all:			${NAME}

${NAME}:		${DIR_OBJS} ${OBJS} ./includes/philo.h
				${CC} ${CFLAGS} ${OBJS} -o ${NAME}

${DIR_OBJS}:
				mkdir ${DIR_OBJS}

clean:
				${RM} ${DIR_OBJS}

fclean:			clean
				${RM} ${NAME}

re:				fclean
				${MAKE} all

.PHONY:			all clean fclean .c.o re






