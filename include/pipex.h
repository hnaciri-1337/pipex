/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaciri- <hnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 13:23:26 by hnaciri-          #+#    #+#             */
/*   Updated: 2022/11/05 13:36:16 by hnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <errno.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include "../libft/libft.h"

void	ft_free(char **a);
int		ft_open(char *av, int i);
void	ft_exit_args(void);
void	ft_exit_file(char *name);
void	ft_exit_cmd(char **path, char **line);
void	ft_open_pipe(t_list **head, int *fd);
void	ft_open_pipe(t_list **head, int *fd);
void	ft_free_all(t_list **list);
void	ft_do_all(char **av, char **path, int *fd, char **env);
void	close_pipe(t_list **list);
void	wait_execute(t_list **list);
char	*cmd_path(char **path, char **cmd);
char	**ft_get_path_index(char **env);
int		ft_heredoc(char **av, char **env);
#endif
