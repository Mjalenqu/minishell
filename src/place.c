/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   place.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/11 19:47:24 by mjalenqu     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/12 18:08:45 by mjalenqu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_free_one(t_env *g_env)
{
	if (g_env)
	{
		free(g_env->name);
		free(g_env->data);
		free(g_env);
	}
}

int		error_tab(char *s)
{
	if (!(s))
	{
		choose_error();
		return (-1);
	}
	return (0);
}

void	change_env(t_env **g_env, char **tab)
{
	free((*g_env)->data);
	(*g_env)->data = ft_strdup(tab[2]);
}

int		unsetenv_v2(t_env *start, char **res, t_env *ndel)
{
	if ((ft_strcmp(res[1], start->next->name) == 0))
	{
		if (!(start->next->next))
			ndel = NULL;
		else
			ndel = start->next->next;
		free(start->next->data);
		free(start->next->name);
		free(start->next);
		start->next = ndel;
		return (1);
	}
	return (0);
}

void	free_env(t_env *g_env)
{
	t_env *tmp;

	while (g_env->next)
	{
		tmp = g_env;
		free(g_env->name);
		free(g_env->data);
		g_env = g_env->next;
		free(tmp);
	}
	free(g_env->name);
	free(g_env->data);
	free(g_env);
}
