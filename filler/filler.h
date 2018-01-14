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

#include <stdio.h>

#include "../libft/libft.h"
#include <fcntl.h>

typedef struct s_fg
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
}				t_fg;

void	wrt_coord(t_fg *e);
