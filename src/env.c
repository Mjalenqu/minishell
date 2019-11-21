/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   env.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/26 10:42:09 by mjalenqu     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/12 18:05:53 by mjalenqu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/minishell.h"

void	print_env(t_env *g_env)
{
	t_env	*save;

	save = g_env;
	if (g_env == NULL)
		return ;
	while (g_env)
	{
		ft_putcolor2(g_env->name, "=", g_env->data, "\n");
		g_env = g_env->next;
	}
	g_env = save;
}

void	new_env(t_env **g_env, char **tab, t_env *save)
{
	(*g_env)->next = malloc(sizeof(t_env));
	(*g_env) = (*g_env)->next;
	(*g_env)->name = ft_strdup(tab[1]);
	(*g_env)->data = ft_strdup(tab[2]);
	(*g_env)->type = 0;
	(*g_env)->next = NULL;
	(*g_env) = save;
}

int		set_env(char **tab, t_env **g_env)
{
	t_env	*save;

	save = (*g_env);
	if (error_tab(tab[1]) == -1)
		return (-1);
	if (ft_strcmp((*g_env)->name, tab[1]) == 0)
	{
		change_env(g_env, tab);
		return (0);
	}
	while ((*g_env)->next)
	{
		if (ft_strcmp((*g_env)->name, tab[1]) == 0)
		{
			change_env(g_env, tab);
			(*g_env) = save;
			return (0);
		}
		(*g_env) = (*g_env)->next;
	}
	new_env(g_env, tab, save);
	(*g_env) = save;
	return (0);
}

int		set_var(char *str, char *s, t_env *g_env)
{
	t_env	*save;

	save = g_env;
	while (g_env->next != NULL)
		g_env = g_env->next;
	g_env->next = malloc(sizeof(t_env));
	g_env = g_env->next;
	g_env->name = ft_strdup(str);
	g_env->data = ft_strdup(s);
	g_env->type = 1;
	g_env = save;
	return (0);
}

int		exec_unsetenv(char **res, t_env **g_env)
{
	t_env	*start;
	t_env	*ndel;

	ndel = NULL;
	if (error_tab(res[1]) == -1)
		return (-1);
	if (ft_strcmp((*g_env)->name, res[1]) == 0)
	{
		start = (*g_env)->next;
		ft_free_one(*g_env);
		(*g_env) = start;
		return (1);
	}
	start = *g_env;
	while (start->next)
	{
		if (unsetenv_v2(start, res, ndel) == 1)
			break ;
		start = start->next;
	}
	return (1);
}
