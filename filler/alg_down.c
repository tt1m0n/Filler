/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_down.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:21:10 by omakovsk          #+#    #+#             */
/*   Updated: 2018/01/15 15:21:12 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		init_rez(t_fg *e, int x, int y)
{
	e->rezx = x;
	e->rezy = y;
}

static int		myabs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

void			set_change_down(t_fg *e, char let, int *change)
{
	int i;

	i = e->wm / 2 - 2;
	while (i < e->wm - 1)
	{
		if (e->map[0][i] == let)
			*change = 1;
		i++;
	}
	if (e->map[e->hm - 1][e->wm / 2] == let ||
		e->map[e->hm - 1][e->wm / 2 - 1] == let ||
		e->map[e->hm - 1][e->wm / 2 + 1] == let ||
		e->map[e->hm - 1][e->wm / 2 + 2] == let)
		*change = 2;
}

void			check_distance_down(t_fg *e, char let, int y, int x)
{
	int			n;
	int			k;
	static int	change;

	if (change == 0)
		n = myabs(e->wm / 2 - (x + e->wf - 1 - e->diffx)) +
			myabs(0 - (y + e->hf - 1 - e->diffy));
	if (change == 0)
		k = myabs(e->wm / 2 - (e->rezx + e->wf - 1 - e->diffx)) +
			myabs(0 - (e->rezy + e->hf - 1 - e->diffy));
	if (change == 1)
		n = myabs(e->wm / 2 - (x + e->wf - 1 - e->diffx)) +
			myabs(e->hm - (y + e->hf - 1 - e->diffy));
	if (change == 1)
		k = myabs(e->wm / 2 - (e->rezx + e->wf - 1 - e->diffx)) +
			myabs(e->hm - (e->rezy + e->hf - 1 - e->diffy));
	if (change == 2)
		n = myabs(0 - (x + e->wf - 1 - e->diffx)) +
			myabs(e->hm - 1 - (y + e->hf - 1 - e->diffy));
	if (change == 2)
		k = myabs(0 - (e->rezx + e->wf - 1 - e->diffx)) +
			myabs(e->hm - 1 - (e->rezy + e->hf - 1 - e->diffy));
	if ((n < k && let) || (e->rezx == 0 && e->rezy == 0))
		init_rez(e, x, y);
	set_change_down(e, let, &change);
}
