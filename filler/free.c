/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:14:19 by omakovsk          #+#    #+#             */
/*   Updated: 2018/01/15 15:14:22 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	free_map(t_fg *e)
{
	int i;

	i = 0;
	while (e->map[i])
	{
		ft_bzero(e->map[i], e->wm);
		free(e->map[i]);
		e->map[i++] = NULL;
	}
	free(e->map);
	e->map = NULL;
}

void	free_pc(t_fg *e)
{
	int i;

	i = 0;
	while (e->pc[i])
	{
		ft_bzero(e->pc[i], e->wf);
		free(e->pc[i]);
		e->pc[i++] = NULL;
	}
	free(e->pc);
	e->pc = NULL;
}

void	free_struct(t_fg *e)
{
	free_map(e);
	free_pc(e);
	free(e->o);
	free(e->x);
	free(e->p);
	free(e->f);
	e->hf = 0;
	e->rezy = 0;
	e->rezx = 0;
}
