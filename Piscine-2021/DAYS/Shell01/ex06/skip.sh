# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    skip.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/28 09:33:42 by ael-khni          #+#    #+#              #
#    Updated: 2021/11/28 09:33:43 by ael-khni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/sh

ls -l | awk 'NR % 2 == 1'
