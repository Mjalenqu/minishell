/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   builtins.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/12 18:24:31 by mjalenqu     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/13 08:56:06 by mjalenqu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/minishell.h"

int		execute(char **tab, char *path, t_env *g_env)
{
	char	**var;
	int		w;
	pid_t	p;

	var = split_env(g_env);
	p = fork();
	signal(SIGINT, restart_prog);
	if (p == 0)
		execve(path, tab, var);
	else
		wait(&w);
	ft_free_tab(var);
	return (0);
}

int		check_path(char **tab, t_env *g_env)
{
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	if (ft_strchr(tab[0], '/') != 0)
		i = exec_path(tab, g_env);
	else if (g_env != NULL)
		i = exec_toukour(tab, g_env);
	if (i == 0)
		choose_error();
	return (0);
}

void	change_pwd(t_env *g_env)
{
	char	*buf;
	t_env	*save;

	save = g_env;
	buf = NULL;
	while (g_env)
	{
		if (ft_strcmp(g_env->name, "PWD") == 0)
		{
			free(g_env->data);
			g_env->data = getcwd(buf, 0);
			free(buf);
			break ;
		}
		g_env = g_env->next;
	}
	g_env = save;
}

int		cd_bis(t_env *g_env, char **tab)
{
	char	*buf;

	buf = NULL;
	if (ft_strcmp(g_env->name, "OLDPWD") == 0)
	{
		if (ft_strcmp(tab[1], "-") == 0)
		{
			chdir(g_env->data);
			ft_putendl(g_env->data);
		}
		free(g_env->data);
		g_env->data = getcwd(buf, 0);
		free(buf);
		return (1);
	}
	if (!(g_env) || g_env->next == NULL)
	{
		g_env->next = malloc(sizeof(t_env));
		g_env->next->name = ft_strdup("OLDPWD");
		g_env->next->data = ft_strdup(getcwd(buf, 0));
		free(buf);
		return (1);
	}
	return (0);
}

void	ft_cd(char **tab, t_env *g_env)
{
	t_env	*save;

	save = g_env;
	if (!(tab[1]))
	{
		while (g_env && (ft_strcmp(g_env->name, "HOME") != 0))
			g_env = g_env->next;
		if (!(g_env) || g_env->next == NULL)
			return ;
		chdir(g_env->data);
		change_pwd(g_env);
		g_env = save;
		return ;
	}
	while (g_env)
	{
		if (cd_bis(g_env, tab) == 1)
			break ;
		g_env = g_env->next;
	}
	if ((chdir(tab[1]) == -1) && (ft_strcmp(tab[1], "-") != 0))
		ft_putcolor(BRED, "\tcd: no such directory\n", RESET);
	g_env = save;
	change_pwd(g_env);
}
