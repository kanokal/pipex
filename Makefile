# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/11 14:51:11 by jpyo              #+#    #+#              #
#    Updated: 2021/11/27 01:27:29 by jpyo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	pipex
CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror

HEADER_DIR		=	./includes/

FILES			=	pipex \
					pipex_fork pipex_child \
					error_handling pipex_utils pipex_utils2 pipex_utils3
SRCS_DIR		=	./srcs/
SRCS			=	$(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))
SRCS_OBJS		=	$(addprefix $(SRCS_DIR), $(addsuffix .o, $(FILES)))

BONUS_FILES		=	pipex_bonus \
					pipex_fork pipex_child \
					error_handling pipex_utils pipex_utils2 pipex_utils3 \
					pipex_here_doc
BONUS			=	$(addprefix $(SRCS_DIR), $(addsuffix .c, $(BONUS_FILES)))
BONUS_OBJS		=	$(addprefix $(SRCS_DIR), $(addsuffix .o, $(BONUS_FILES)))

FT_LIB_DIR		=	./libft/
FT_LIB			=	libft.a

all : $(NAME)

$(NAME) : $(FT_LIB_DIR)$(FT_LIB) $(SRCS_OBJS)
	$(CC) -o $(NAME) $(CFLAGS) $(FT_LIB_DIR)$(FT_LIB) $(SRCS_OBJS)

$(FT_LIB_DIR)$(FT_LIB) :
	$(MAKE) -C $(FT_LIB_DIR)

%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $(<:.c=.o)

bonus : $(FT_LIB_DIR)$(FT_LIB) $(BONUS_OBJS)
	$(CC) -o $(NAME) $(CFLAGS) $(FT_LIB_DIR)$(FT_LIB) $(BONUS_OBJS)

clean :
	rm -rf $(SRCS_OBJS) $(BONUS_OBJS)
	$(MAKE) -C $(FT_LIB_DIR) clean

fclean : clean
	rm -rf $(NAME) $(FT_LIB_DIR)$(FT_LIB)

re : fclean all
