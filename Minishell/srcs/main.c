/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 13:29:41 by fremoor           #+#    #+#             */
/*   Updated: 2019/07/30 09:03:55 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int				main(int ac, char **av, char **env)
{
	int			i;
	char		*line;
	char		*home;
	char		**commands;

	(void)ac;
	(void)av;
	i = 1;
	system("clear");
	while (i)
	{
		home = get_dir_path(env);
		ft_printf("\033[32;1m~%s$>\033[0m ", home);
		get_next_line(0, &line);
		commands = ft_strsplit(line, ';');
		i = exec_args(commands, env);
		free(line);
		free(home);
		free(commands);
	}
}
