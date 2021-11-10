# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/04 11:25:09 by ael-khni          #+#    #+#              #
#    Updated: 2021/11/10 18:28:30 by ael-khni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=GCC
FLAGS= -Wall -Werror -Wextra -I libft.h
AR=ar crs
RM=rm -rf
FILES= ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_strlen \
	   ft_toupper ft_tolower ft_strchr ft_strrchr ft_strncmp \
	   ft_strnstr ft_strlcpy ft_strlcat ft_atoi ft_strdup \
	   ft_substr ft_strjoin ft_split ft_itoa ft_strmapi \
	   ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_isprint \
	   ft_putnbr_fd ft_strtrim ft_memcpy ft_memmove ft_memset \
	   ft_memcmp ft_memchr ft_bzero ft_calloc ft_striteri
BFILES  = ft_lstnew ft_lstadd_front \
	   ft_striteri ft_lstsize ft_lstlast ft_lstadd_back ft_lstdelone \
	   ft_lstclear ft_lstiter ft_lstmap
OBJ=$(FILES:=.o)
BOBJ=$(BFILES:=.o)
NAME=libft.a

RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
RESET = \033[0m

.PHONY: all bonus clean fclean re

all: $(NAME)
	@echo "$(RED)------safi done------$(RESET)"


bonus: all $(BOBJ)
	echo "hani kan commpili $(GREEN)" $< "$(RESET)akhay sat"
	@$(AR) $(NAME) $(BOBJ)

$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)

%.o: %.c libft.h
	@echo "hani kan commpili$(GREEN)" $< "$(RESET)akhay sat"
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@echo "$(YELLOW)Cleaned$(RESET)"
	@$(RM) $(OBJ) $(BOBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
