/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_for_fg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:10:00 by omakovsk          #+#    #+#             */
/*   Updated: 2018/01/15 15:10:03 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	count_sz_fg(t_fg *e)
{
	int i;
	int j;

	i = 0;
	e->szo = 0;
	e->szx = 0;
	while (e->map[i])
	{
		j = 0;
		while (e->map[i][j] != '\0')
		{
			if (e->map[i][j] == 'o' || e->map[i][j] == 'O')
				e->szo++;
			if (e->map[i][j] == 'x' || e->map[i][j] == 'X')
				e->szx++;
			j++;
		}
		i++;
	}
}

void	count_sz_pc(t_fg *e)
{
	int i;
	int j;

	i = 0;
	e->szp = 0;
	e->szf = 0;
	while (e->pc[i])
	{
		j = 0;
		while (e->pc[i][j] != '\0')
		{
			if (e->pc[i][j] == '.' || e->pc[i][j] == '*')
				e->szp++;
			if (e->pc[i][j] == '*')
				e->szf++;
			j++;
		}
		i++;
	}
}

void	mem_for_fg(t_fg *e)
{
	e->o = (int*)malloc(sizeof(int) * (e->szo * 2));
	if (e->o == NULL)
		return ;
	e->x = (int*)malloc(sizeof(int) * (e->szx * 2));
	if (e->x == NULL)
		return ;
	e->p = (int*)malloc(sizeof(int) * (e->szp * 2));
	if (e->p == NULL)
		return ;
	e->f = (int*)malloc(sizeof(int) * (e->szf * 2));
	if (e->f == NULL)
		return ;
}
