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

int		abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

void	check_distance(t_fg *e, char let, int y, int x)
{
	// for up
	int n;
	int k;
	int diffx = 0;
	int diffy = 0;
	static int change;
	/*
	***search coordinates of last sharp in my figure (not in piece)
	*/
	diffx = e->p[e->szp * 2 - 1] - e->f[e->szf * 2 - 1];
	diffy = e->p[e->szp * 2 - 2] - e->f[e->szf * 2 - 2];
	if (change == 2)
	{
		n = abs(e->wm - 1 - (x + e->wf - 1 - diffx)) + abs(0 - (y + e->hf - 1 - diffy));
		k = abs(e->wm - 1 - (e->rezx + e->wf - 1 - diffx)) + abs(0 - (e->rezy + e->hf - 1 - diffy));
	}
	/*
	***top - bottom
	*/
	if (change == 1)
	{
		n = abs(e->wm / 2 - (x + e->wf - 1 - diffx)) + abs(e->hm - (y + e->hf - 1 - diffy));
		k = abs(e->wm / 2 - (e->rezx + e->wf - 1 - diffx)) + abs(e->hm - (e->rezy + e->hf - 1 - diffy));
	}
	/*
	***top - center
	*/
	else
	{	
		n = abs(e->wm / 2 + 2- (x + e->wf - 1 - diffx)) + abs(0 - (y + e->hf - 1 - diffy));
		k = abs(e->wm / 2 + 2- (e->rezx + e->wf - 1 - diffx)) + abs(0 - (e->rezy + e->hf - 1 - diffy));
	}	
	if ((n < k && let) || (e->rezx == 0 && e->rezy == 0))
	{
		e->rezx = x;
		e->rezy = y;
	}
	if (e->map[0][e->wm / 2 + 2] == let)
		change = 1;
	if (e->map[e->hm - 1][e->wm - 1] == let)
		change = 2;
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
			if ((e->pc[i][j] == '*') && (e->map[y + i][x + j] != let) &&\
				(e->map[y + i][x + j] != '.'))
			{
				i = e->hf;
				break ;
			}
			if ((e->pc[i][j] == '*') && (e->map[y + i][x + j] == let))
				tch++;	
			j++;
		}
		i++;
	}
	if (tch == 1 && i == e->hf && j == e->wf)
		check_distance(e, let, y, x);
}

void	algoritmup(t_fg *e, char let)
{
	int i;
	int j;

	i = 0;
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

void	init_struct(t_fg *e)
{
	e->hf = 0;
	e->rezy = 0;
	e->rezx = 0;
	e->flag = 0;
}

void	set_flag(t_fg *e, char let)
{
	if ((let == 'O') && (e->o[0] <= e->x[0]))
		e->flag = 1;
	else if ((let == 'X') && (e->x[0] <= e->o[0]))
		e->flag = 1;
	else
		e->flag = 2;
}

void	read_piece(t_fg *e, char let, int i)
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
	if (e->flag == 1)
		algoritmup(e, let);
	if (e->flag == 2)
		algoritmdown(e, let);
	ft_putnbr_fd(e->rezy, 1);
	ft_putstr_fd(" ", 1);
	ft_putnbr_fd(e->rezx, 1);
	ft_putstr_fd("\n", 1);
	free_struct(e);
}


int		main (void)
{
	char	*line;
	t_fg	e;
	int 	i;
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
