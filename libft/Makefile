# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/07 23:52:33 by jpyo              #+#    #+#              #
#    Updated: 2021/07/04 14:49:00 by jpyo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror

NAME			=	libft.a

HEADER_DIR		=	./includes

SRCS_DIR		=	./srcs/
SRCS_FILES		=	ft_memset ft_bzero ft_memcpy ft_memccpy ft_memmove \
					ft_memchr ft_memcmp ft_strlen ft_strlcpy ft_strlcat \
					ft_strchr ft_strrchr ft_strnstr ft_strncmp ft_atoi \
					ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint \
					ft_toupper ft_tolower ft_calloc ft_strdup ft_substr \
					ft_strjoin ft_strtrim ft_split ft_itoa ft_strmapi \
					ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd
SRCS			=	$(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRCS_FILES)))
SRCS_OBJS		=	$(addprefix $(SRCS_DIR), $(addsuffix .o, $(SRCS_FILES)))

BONUS_DIR		=	./srcs_bonus/
BONUS_FILES		=	ft_lstnew ft_lstadd_front ft_lstsize ft_lstlast ft_lstadd_back \
					ft_lstdelone ft_lstclear ft_lstiter ft_lstmap
BONUS			=	$(addprefix $(BONUS_DIR), $(addsuffix .c, $(BONUS_FILES)))
BONUS_OBJS		=	$(addprefix $(BONUS_DIR), $(addsuffix .o, $(BONUS_FILES)))

USER_DIR		=	./srcs_user/
USER_FILES		=	ft_uint_to_str		ft_ulong_to_str		ft_ullong_to_str	ft_ushort_to_str	ft_uchar_to_str \
					ft_uint_length		ft_ulong_length		ft_ullong_length	ft_ushort_length	ft_uchar_length \
					ft_get_top_double	ft_putwchar_fd		ft_putwchar_str_fd 	ft_strcpy			ft_cpy_arr_uint \
					ft_raise_base_str	ft_rounds_dbl		ft_double_power		ft_rev_str			ft_wint_byte \
					ft_wchar_strlen		ft_free_int			ft_free_ptr			ft_str_in_chr		ft_power \
					ft_putbits			ft_dtoa				ft_clamp			ft_atol				ft_bankers_rounding_str	\
					ft_atoi2			ft_strmvptr			ft_atol2			ft_atod2			ft_quick_sort \
					ft_swap				ft_bzero_int		ft_free_split		ft_error_handling	ft_rand_xor
USER_SRCS		=	$(addprefix $(USER_DIR), $(addsuffix .c, $(USER_FILES)))
USER_OBJS		=	$(addprefix $(USER_DIR), $(addsuffix .o, $(USER_FILES)))

BIGINT_DIR		=	./srcs_bigint/
BIGINT_FILES	=	ft_bigint_utils		ft_bigint_utils2	ft_bigint_add		ft_bigint_add_val	ft_bigint_mult_val \
					ft_binary_to_bigint	ft_bigint_power		ft_bigint_to_a		ft_bigint_putstr
BIGINT_SRCS		=	$(addprefix $(BIGINT_DIR), $(addsuffix .c, $(BIGINT_FILES)))
BIGINT_OBJS		=	$(addprefix $(BIGINT_DIR), $(addsuffix .o, $(BIGINT_FILES)))

DTOB_DIR		=	./srcs_dbl/
DTOB_FILES		=	ft_dtob ft_dtob_utils
DTOB_SRCS		=	$(addprefix $(DTOB_DIR), $(addsuffix .c, $(DTOB_FILES)))
DTOB_OBJS		=	$(addprefix $(DTOB_DIR), $(addsuffix .o, $(DTOB_FILES)))

GNL_DIR			=	./srcs_gnl/
GNL_FILES		=	get_next_line
GNL_SRCS		=	$(addprefix $(GNL_DIR), $(addsuffix .c, $(GNL_FILES)))
GNL_OBJS		=	$(addprefix $(GNL_DIR), $(addsuffix .o, $(GNL_FILES)))

VEC3_DIR		=	./srcs_vec3/
VEC3_FILES		=	vec3_math1 vec3_math2 vec3_math3 vec3_utils
VEC3_SRCS		=	$(addprefix $(VEC3_DIR), $(addsuffix .c, $(VEC3_FILES)))
VEC3_OBJS		=	$(addprefix $(VEC3_DIR), $(addsuffix .o, $(VEC3_FILES)))

all : $(NAME)

$(NAME) : $(SRCS_OBJS) $(BONUS_OBJS) $(USER_OBJS) $(BIGINT_OBJS) $(DTOB_OBJS) $(VEC3_OBJS) $(GNL_OBJS)
	ar rcs $(NAME) $(SRCS_OBJS) $(BONUS_OBJS) $(USER_OBJS) $(BIGINT_OBJS) $(DTOB_OBJS) $(VEC3_OBJS) $(GNL_OBJS)

obj	: $(SRCS_OBJS) $(BONUS_OBJS) $(USER_OBJS) $(BIGINT_OBJS) $(DTOB_OBJS) $(VEC3_OBJS) $(GNL_OBJS)

bonus : $(NAME)

%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $(<:.c=.o)

clean :
	rm -f $(SRCS_OBJS) $(BONUS_OBJS) $(USER_OBJS) $(BIGINT_OBJS) $(DTOB_OBJS) $(VEC3_OBJS) $(GNL_OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all bonus clean fclean re obj