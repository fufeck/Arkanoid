# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbazenne <vbazenne@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/20 14:31:41 by vbazenne          #+#    #+#              #
##   Updated: 2013/11/27 22:29:52 by kashim           ###   ########.fr       ##
#                                                                              #
# **************************************************************************** #

CC		=	gcc
NAME	=	Arkanoid
SRCS	=	srcs/arkanoid.c \
			srcs/create_map.c \
			srcs/draw.c \
			srcs/main.c
			
INC		=	-I../include/ -I./libft/ -I./includes/
OBJS	= 	$(SRCS:.c=.o)
CCFLAGS	=	-Wall -Wextra -Werror
LDFLAGS	=	-lglfw3 -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo -L../lib/ -L./libft/ -lft

all:	$(NAME)

$(NAME):	$(OBJS)
	@make -C libft
	$(CC) $(CCFLAGS) $(LDFLAGS) $(INC) $(OBJS) -o $(NAME)
	
.c.o:
	$(CC) -c $(CCFLAGS) $(INC) $< -o $@
	
clean:
	@make clean -C libft
	rm -f $(OBJS)
	
fclean:	clean
	@make fclean -C libft
	rm -f $(NAME)
	
re: fclean all