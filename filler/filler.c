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

void	check_dosk (t_fg *e, char *line)
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

void	check_map(t_fg *e, char *line, char *let)
{
	static int i;

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
				k++;
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
			k++;
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

void	free_map(t_fg *e)
{
	int i;

	i = 0;
	while (e->map[i])
	{	
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
}

void	check_touch(t_fg *e, char let, int y, int x)
{
	int i;
	int j;
	int tch;

	i = 0;
	tch = 0;
	while (i < e->hf)
	{
		j = 0;
		while (j < e->wf)
		{	
			if ((e->pc[i][j] == '*') && (e->map[y + i][x + j] == let))
				tch++;
			j++;
		}	
		i++;
	}
	if (tch == 1)
	{	
		e->rezy = y;
		e->rezx = x;
	}
}

void	algoritm(t_fg *e, char let)
{
	int i;
	int j;

	i = 0;
	while (i <= (e->hm - e->hf))
	{
		j = 0;
		while (j <= (e->wm - e->wf))
		{
			// if y-coord in token bigger zen y-coord in my figure - break, becouse then it's
			// not my figure
			if (e->f[0] > e->o[(e->szo)*2 - 2] && let == 'O')
				break ;
			if (e->f[0] > e->x[(e->szx)*2 - 2] && let == 'X')
				break ;
			check_touch(e, let, i, j);
			j++;
		}
		i++;
	}	
}

int		main (void)
{
	char	*line;
	t_fg	e;
	static char	let = 'O';
	int i = 999;
	e.hf = 0;
	e.rezy = 0;
	e.rezx = 0;
	while (i)
	{	
		ft_get_next_line(0, &line);
		check_map(&e, line, &let);
		if (e.hf && i == 999)
			i = e.hf + 1;
		if (e.hf)
			i--;
		free(line);
		line = NULL;
	}
	e.map[e.hm] = NULL;
	e.pc[e.hf] = NULL;
	wrt_coord(&e);
	algoritm(&e, let);
	printf ("%d %d\n", e.rezy, e.rezx);
	free_struct(&e);
	//free(&e);
//	}
//	printf ("wm == %d\n", e.wm);
//	printf ("hm == %d\n", e.hm);
//	printf ("wf == %d\n", e.wf);
//	printf ("hf == %d\n", e.hf);
//	printf ("sizeo == %d\n", e.szo);
//	printf ("rezx == %d\n", e.rezx);
//	printf ("rezy == %d\n", e.rezy);
//	system ("leaks omakovsk.filler");
	return (0);
}
