/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alghoritm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:17:08 by omakovsk          #+#    #+#             */
/*   Updated: 2018/01/15 15:17:10 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	count_diff(t_fg *e)
{
	e->diffx = e->p[e->szp * 2 - 1] - e->f[e->szf * 2 - 1];
	e->diffy = e->p[e->szp * 2 - 2] - e->f[e->szf * 2 - 2];
}

void	check_touch(t_fg *e, char let, int y, int x)
{
	int i;
	int j;
	int tch;

	i = -1;
	tch = 0;
	while (++i < e->hf)
	{
		j = -1;
		while (++j < e->wf)
		{
			if ((e->pc[i][j] == '*') && (e->map[y + i][x + j] != let) &&\
				(e->map[y + i][x + j] != '.'))
			{
				i = e->hf;
				break ;
			}
			if ((e->pc[i][j] == '*') && (e->map[y + i][x + j] == let))
				tch++;
		}
	}
	if (tch == 1 && i == e->hf && j == e->wf && e->flag == 1)
		check_distance_up(e, let, y, x);
	if (tch == 1 && i == e->hf && j == e->wf && e->flag == 2)
		check_distance_down(e, let, y, x);
}

void	algoritm(t_fg *e, char let)
{
	int i;
	int j;

	i = 0;
	count_diff(e);
	while (i <= (e->hm - e->hf))
	{
		j = 0;
		while (j <= (e->wm - e->wf))
		{
			check_touch(e, let, i, j);
			j++;
		}
		i++;
	}
}
