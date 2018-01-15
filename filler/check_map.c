/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 14:51:49 by omakovsk          #+#    #+#             */
/*   Updated: 2018/01/15 14:51:51 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	check_dosk(t_fg *e, char *line)
{
	if (ft_strstr(line, "Plateau"))
	{
		e->hm = ft_atoi(line + 8);
		e->wm = ft_atoi(line + 11);
		e->map = (char**)malloc(sizeof(char*) * (e->hm + 1));
	}
	if (ft_isdigit(line[0]))
		e->map[ft_atoi(line)] = ft_strsub(line, 4, e->wm);
}

void	check_map(t_fg *e, char *line, char *let, int i)
{
	if (ft_strstr(line, "omakovsk.filler") && ft_strstr(line, "p1"))
		*let = 'O';
	if (ft_strstr(line, "omakovsk.filler") && ft_strstr(line, "p2"))
		*let = 'X';
	check_dosk(e, line);
	if (ft_strstr(line, "Piece"))
	{
		e->hf = ft_atoi(line + 6);
		e->wf = ft_atoi(line + 8);
		e->pc = (char**)malloc(sizeof(char*) * (e->hf + 1));
	}
	if (line[0] == '.' || line[0] == '*')
		e->pc[i++] = ft_strsub(line, 0, e->wf);
}
