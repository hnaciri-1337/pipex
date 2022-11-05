/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaciri- <hnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 12:53:48 by hnaciri-          #+#    #+#             */
/*   Updated: 2022/11/05 13:47:59 by hnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	*cmd_path(char **path, char **cmd)
{
	char	*line;
	int		i;

	if (!access(cmd[0], X_OK))
		return (ft_strdup (cmd[0]));
	i = -1;
	while (path[++i])
	{
		line = ft_strjoin (path[i], cmd[0]);
		if (!access(line, X_OK))
			return (line);
		free (line);
	}
	ft_exit_cmd (path, cmd);
	return (0);
}

char	**ft_get_path_index(char **env)
{
	int		i;
	char	*line;
	char	**path;

	i = -1;
	while (env[++i])
	{
		line = ft_substr (env[i], 0, 4);
		if (!ft_strncmp(line, "PATH", 4))
			break ;
		free (line);
	}
	free (line);
	if (env[i] == 0)
		exit (0);
	path = ft_split (env[i] + 5, ':');
	i = -1;
	while (path[++i])
	{
		line = path[i];
		path[i] = ft_strjoin (path[i], "/");
		free (line);
	}
	return (path);
}

void	ft_do_all(char **av, char **path, int *fd, char **env)
{
	t_list	cmds[2];
	char	**args;
	int		pip[2];

	args = ft_split(av[2], ' ');
	cmds[0].path = cmd_path(path, args);
	cmds[0].args = args;
	args = ft_split(av[3], ' ');
	cmds[1].path = cmd_path(path, args);
	cmds[1].args = args;
	pipe(pip);
	cmds[0].pid = fork();
	if (!cmds[0].pid)
	{
		dup2(fd[0], 0);
		dup2(pip[1], 1);
		close(pip[0]);
		execve(cmds[0].path, cmds[0].args, env);
		write(2, "bash :", 7);
		perror(cmds[0].path);
		exit (0);
	}
	cmds[1].pid = fork();
	if (!cmds[1].pid)
	{
		dup2(pip[0], 0);
		dup2(fd[1], 1);
		close(pip[1]);
		execve(cmds[1].path, cmds[1].args, env);
		write(2, "bash :", 7);
		perror(cmds[1].path);
		exit (0);
	}
	close(pip[0]);
	close(pip[1]);
	free(cmds[0].path);
	free(cmds[1].path);
	ft_free(cmds[0].args);
	ft_free(cmds[1].args);
	waitpid(cmds[0].pid, 0, 0);
	waitpid(cmds[1].pid, 0, 0);
}
