/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 06:28:27 by marvin            #+#    #+#             */
/*   Updated: 2017/01/24 16:20:37 by gmonein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int					ft_get_arg(int ac, char **av, char **arg)
{
	int		i;
	int		j;

	i = 1;
	j = 1;
	*arg = ft_strnew(1);
	*arg[0] = '\0';
	while (i <= (ac - 1) && av[i][0] == '-')
	{
		while (av[i][j] && av[i][0] == '-')
		{
			if (ft_strchr(VALID_ARG, av[i][j]) == NULL)
				return (ft_error(1, av[i][j]));
			*arg = ft_stradd(*arg, av[i][j], 1);
			j++;
		}
		j = 1;
		i++;
	}
	return (1);
}

struct l_file		*ft_get_dir(int ac, char **av, t_arg *sarg)
{
	int				i;
	int				r;
	struct l_file	*lst;
	struct l_file	*tmp;

	i = 1;
	lst = ft_init_lst();
	tmp = lst;
	r = ac - 1;
	while (av[i] && av[i][0] == '-')
		i++;
	sarg->single_arg = (ac - i > 1 ? 0 : 1);
	if (ac - i == 0 || ac == 1)
	{
		lst->next = ft_init_lst();
		lst = lst->next;
		lst->name = ft_strdup(".");
	}
	else
		while ((sarg->r == -1 && av[i]) || (sarg->r == 1 && av[r] && r != i))
		{
			lst->next = ft_init_lst();
			lst = lst->next;
			lst->name = ft_strdup(av[(sarg->r == 1 ? r : i)]);
			(sarg->r == 1 ? r-- : i++);
		}
	lst->next = NULL;
	return (tmp);
}
