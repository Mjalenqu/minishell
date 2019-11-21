/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_arg.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/24 13:30:12 by mjalenqu     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/13 11:19:05 by mjalenqu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*get_name(char *env)
{
	int		i;
	char	*name;

	i = 0;
	while (env[i] != '=')
		i++;
	name = malloc(sizeof(char) * i + 1);
	i = 0;
	while (env[i] != '=')
	{
		name[i] = env[i];
		i++;
	}
	name[i] = '\0';
	return (name);
}

char	*get_data(char *env)
{
	int		i;
	int		j;
	char	*data;

	i = 0;
	j = 0;
	while (env[i] != '=')
		i++;
	while (env[i++])
		j++;
	data = malloc(sizeof(char) * j + 1);
	i = 0;
	j = 0;
	while (env[i] != '=')
		i++;
	i++;
	while (env[i])
	{
		data[j] = env[i];
		i++;
		j++;
	}
	data[j] = '\0';
	return (data);
}

t_env	*init_var(char **env, t_env *g_env)
{
	int		i;
	t_env	*save;

	i = 0;
	if (!(env))
	{
		g_env = NULL;
		return (g_env);
	}
	g_env = malloc(sizeof(t_env));
	save = g_env;
	while (env[i])
	{
		g_env->name = get_name(env[i]);
		g_env->data = get_data(env[i]);
		i++;
		if (env[i])
		{
			g_env->next = malloc(sizeof(t_env));
			g_env = g_env->next;
		}
		else
			g_env->next = NULL;
	}
	return (save);
}

void	ft_free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		ft_strdel(&tab[i]);
		i++;
	}
	ft_strdel(&tab[i]);
	free(tab);
}

int		check_arg(char **tab, t_env **g_env)
{
	int i;

	i = 1;
	if (ft_strcmp(tab[0], "exit") == 0)
		return (-1);
	else if (ft_strcmp(tab[0], "env") == 0)
		ft_env(tab, (*g_env));
	else if (ft_strcmp(tab[0], "cd") == 0)
		ft_cd(tab, (*g_env));
	else if (ft_strcmp(tab[0], "echo") == 0)
		ft_echo(tab);
	else if (ft_strcmp(tab[0], "unsetenv") == 0)
		exec_unsetenv(tab, g_env);
	else if (ft_strcmp(tab[0], "setenv") == 0)
		set_env(tab, g_env);
	else
		check_path(tab, *g_env);
	return (0);
}
