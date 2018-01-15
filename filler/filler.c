/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 12:02:44 by omakovsk          #+#    #+#             */
/*   Updated: 2018/01/12 12:02:49 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	init_struct(t_fg *e)
{
	e->hf = 0;
	e->rezy = 0;
	e->rezx = 0;
	e->flag = 0;
	e->diffx = 0;
	e->diffy = 0;
}

static void	set_flag(t_fg *e, char let)
{
	if ((let == 'O') && (e->o[0] <= e->x[0]))
		e->flag = 1;
	else if ((let == 'X') && (e->x[0] <= e->o[0]))
		e->flag = 1;
	else
		e->flag = 2;
}

static void	read_piece(t_fg *e, char let, int i)
{
	char *line;

	while (i < e->hf)
	{
		ft_get_next_line(0, &line);
		check_map(e, line, &let, i);
		free(line);
		line = NULL;
		i++;
	}
	e->map[e->hm] = NULL;
	e->pc[e->hf] = NULL;
	wrt_coord(e);
	if (e->flag == 0)
		set_flag(e, let);
	algoritm(e, let);
	ft_putnbr_fd(e->rezy, 1);
	ft_putstr_fd(" ", 1);
	ft_putnbr_fd(e->rezx, 1);
	ft_putstr_fd("\n", 1);
	free_struct(e);
}

int			main(void)
{
	char		*line;
	t_fg		e;
	int			i;
	static char	let;

	init_struct(&e);
	while (ft_get_next_line(0, &line) > 0)
	{
		i = 0;
		check_map(&e, line, &let, i);
		free(line);
		line = NULL;
		if (e.hf)
			read_piece(&e, let, i);
	}
	return (0);
}
