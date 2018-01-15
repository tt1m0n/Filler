/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrt_coord.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:03:46 by omakovsk          #+#    #+#             */
/*   Updated: 2018/01/15 15:03:48 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	wrt_cor_o(t_fg *e)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	while (e->map[i])
	{
		j = 0;
		while (e->map[i][j] != '\0')
		{
			if (e->map[i][j] == 'o' || e->map[i][j] == 'O')
			{
				e->o[k] = i;
				e->o[k + 1] = j;
				k++;
			}
			j++;
		}
		i++;
	}
}

void	wrt_cor_x(t_fg *e)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	while (e->map[i])
	{
		j = 0;
		while (e->map[i][j] != '\0')
		{
			if (e->map[i][j] == 'x' || e->map[i][j] == 'X')
			{
				e->x[k] = i;
				e->x[k + 1] = j;
				k++;
			}
			j++;
		}
		i++;
	}
}

void	wrt_cor_f(t_fg *e)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	while (e->pc[i])
	{
		j = 0;
		while (e->pc[i][j] != '\0')
		{
			if (e->pc[i][j] == '*')
			{
				e->f[k] = i;
				e->f[k + 1] = j;
				k = k + 2;
			}
			j++;
		}
		i++;
	}
}

void	wrt_cor_p(t_fg *e)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	while (e->pc[i])
	{
		j = 0;
		while (e->pc[i][j] != '\0')
		{
			e->p[k] = i;
			e->p[k + 1] = j;
			k = k + 2;
			j++;
		}
		i++;
	}
}

void	wrt_coord(t_fg *e)
{
	count_sz_fg(e);
	count_sz_pc(e);
	mem_for_fg(e);
	wrt_cor_o(e);
	wrt_cor_x(e);
	wrt_cor_p(e);
	wrt_cor_f(e);
}
