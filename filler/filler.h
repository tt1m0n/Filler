/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 13:43:15 by omakovsk          #+#    #+#             */
/*   Updated: 2018/01/12 13:43:18 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/libft.h"

typedef struct	s_fg
{
	char		**map;
	char		**pc;
	int			flag;
	int			wm;
	int			hm;
	int			wf;
	int			hf;
	int			szo;
	int			szx;
	int			szp;
	int			szf;
	int			*o;
	int			*x;
	int			*p;
	int			*f;
	int			rezy;
	int			rezx;
	int			diffx;
	int			diffy;
}				t_fg;

void			check_map(t_fg *e, char *line, char *let, int i);
void			check_dosk (t_fg *e, char *line);
void			wrt_coord(t_fg *e);
void			count_sz_pc(t_fg *e);
void			count_sz_fg(t_fg *e);
void			mem_for_fg(t_fg *e);
void			wrt_cor_o(t_fg *e);
void			wrt_cor_x(t_fg *e);
void			wrt_cor_f(t_fg *e);
void			wrt_cor_p(t_fg *e);
void			free_struct(t_fg *e);
void			free_pc(t_fg *e);
void			free_map(t_fg *e);
void			algoritm(t_fg *e, char let);
void			check_touch(t_fg *e, char let, int y, int x);
void			count_diff(t_fg *e);
void			check_distance_up(t_fg *e, char let, int y, int x);
void			set_change_up(t_fg *e, char let, int *change);
void			check_distance_down(t_fg *e, char let, int y, int x);
void			set_change_down(t_fg *e, char let, int *change);

#endif
