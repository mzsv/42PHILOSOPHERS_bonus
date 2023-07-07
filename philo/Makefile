# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/02 19:30:59 by amenses-          #+#    #+#              #
#    Updated: 2023/05/24 16:28:43 by amenses-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				=	cc
RM				=	rm -f
CFLAGS			=	-Wall -Wextra -Werror -fsanitize=address

SRCS			=	philo_main.c philo_readinput.c philo_time.c \
					philo_initializer.c philo_mutexes.c philo_routine.c \
					philo_bigbrother.c philo_waiter.c philo_free.c \
					philo_utils.c \
					
OBJS			=	$(SRCS:.c=.o)

NAME			=	philo

all:				$(NAME)

$(NAME):			$(OBJS)
					$(CC) $(CFLAGS) $(OBJS) -pthread -o $(NAME)

clean:
					$(RM) $(OBJS)

fclean:				clean
					$(RM) $(NAME)

re:					fclean all
