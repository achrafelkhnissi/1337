/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 00:34:19 by ael-khni          #+#    #+#             */
/*   Updated: 2022/01/20 14:53:54 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	rotate_reverse(char *str, t_stack *a, t_stack *b)
{
	if (ft_strcmp(str, "ra") == 0)
		ra_rotate_a(a, true);
	else if (ft_strcmp(str, "rb") == 0)
		rb_rotate_b(b, true);
	else if (ft_strcmp(str, "rra") == 0)
		rra_reverse_rotate_a(a, true);
	else if (ft_strcmp (str, "rrb") == 0)
		rrb_reverse_rotate_b(b, true);
	else if (ft_strcmp (str, "rr") == 0)
		rr_ra_rb(a, b);
	else if (ft_strcmp (str, "rrr") == 0)
		rrr_rra_rrb(a, b);
	else
	{
		write(2, "Error\n", 6);
		free_stack(a);
		free_stack(b);
		exit(EXIT_FAILURE);
	}
}

void	do_operation(char *str, t_stack *a, t_stack *b)
{
	if (ft_strcmp(str, "pa") == 0)
		pa_push_a(a, b);
	else if (ft_strcmp(str, "pb") == 0)
		pb_push_b(a, b);
	else if (ft_strcmp(str, "sa") == 0)
		sa_swap_a(a, true);
	else if (ft_strcmp (str, "sb") == 0)
		sb_swap_b(b, true);
	else if (ft_strcmp (str, "ss") == 0)
		ss_sa_sb(a, b);
	else
		rotate_reverse(str, a, b);
}

void	read_from_stdin(t_stack *a, t_stack *b)
{
	char	*input;
	char	c;

	input = NULL;
	while (read(0, &c, 1))
	{
		if (c == '\n')
		{
			do_operation(input, a, b);
			free(input);
			input = ft_strdup("");
		}
		else
			input = ft_strjoin(input, c);
	}
	free(input);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac == 1)
		exit (EXIT_FAILURE);
	a = stack_init();
	b = stack_init();
	get_input(a, av + 1, ac - 1);
	read_from_stdin(a, b);
	if (is_sorted(*a))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	free_stack(a);
	free_stack(b);
	exit (EXIT_SUCCESS);
}
