# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    testing.sh                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/14 13:08:31 by ael-khni          #+#    #+#              #
#    Updated: 2022/01/14 14:44:42 by ael-khni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

echo "Numbers : $(python testing/random_ints.py $@ > test && cat test) - \n\n\n $(./push_swap $(cat test) \
	| wc -l) Lines, and Checker is : $(./push_swap $(cat test) | ./testing/checker_Mac $(cat test))"; rm test

