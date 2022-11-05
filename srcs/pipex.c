/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaciri- <hnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 19:42:30 by hnaciri-          #+#    #+#             */
/*   Updated: 2022/11/05 13:49:48 by hnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_free(char **a)
{
	int	i;

	i = -1;
	while (a[++i])
		free (a[i]);
	free (a);
}

void	ft_exit_cmd(char **path, char **line)
{
	ft_putstr_fd ("bash: command not found: ", 2);
	ft_putendl_fd (line[0], 2);
	exit (0);
}

int	ft_open(char *av, int i)
{
	int		fd;
	char	*line;

	if (i == 1)
		fd = open (av, O_RDONLY, 0777);
	else if (i == 2)
		fd = open (av, O_WRONLY | O_CREAT, 0777);
	if (fd < 0)
	{
		ft_putstr_fd ("bash: ", 2);
		perror(av);
		exit (0);
	}
	return (fd);
}

void	ft_exit_args(void)
{
	ft_putstr_fd ("\033[0;31m", 2);
	ft_putendl_fd ("Args number is invalid !", 2);
	exit (0);
}

int	main(int ac, char **av, char **env)
{
	t_list	*head;
	char	**path;
	char	**args;
	int		fd[2];
	int		i;

	i = 1;
	if (ac != 5)
		ft_exit_args ();
	fd[0] = ft_open (av[1], 1);
	fd[1] = ft_open (av[4], 2);
	path = ft_get_path_index (env);
	ft_do_all (av, path, fd, env);
	close(fd[0]);
	close(fd[1]);
}
