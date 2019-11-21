/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   exec.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/31 10:53:45 by mjalenqu     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/12 19:25:15 by mjalenqu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*ft_join_path(char *s1, char *s2)
{
	char	*dest;
	size_t	i;
	size_t	j;

	if (!(s1 && s2))
		return (0);
	i = -1;
	j = 0;
	if (!(dest = (char*)malloc(sizeof(char) *
					(ft_strlen((char*)s1) + ft_strlen((char*)s2) + 2))))
		return (0);
	while (s1[++i])
		dest[i] = s1[i];
	dest[i] = '/';
	i++;
	while (s2[j])
	{
		dest[i] = s2[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

int		exec_path(char **tab, t_env *g_env)
{
	int		ret;

	ret = 0;
	if ((access(tab[0], F_OK) == 0))
	{
		ret = 1;
		if (access(tab[0], X_OK) != 0)
			ft_putcolor2(BRED, tab[0], ": Permission denied\n", RESET);
		else
			execute(tab, tab[0], g_env);
	}
	return (ret);
}

int		exec_toukour(char **tab, t_env *save)
{
	t_env	*g_env;
	int		i;
	int		ret;
	char	**path;

	ret = 0;
	i = 0;
	g_env = save;
	while (ft_strcmp(save->name, "PATH") != 0 && save->next)
	{
		save = save->next;
		ret = 1;
	}
	if (ret == 0)
		return (0);
	ret = 0;
	path = ft_strsplit(save->data, ':');
	while (path[i])
	{
		if (exec_v2(path, tab, g_env, i) == 1)
			ret = 1;
		i++;
	}
	ft_free_tab(path);
	return (ret);
}

char	*ft_join_env(char *s1, char const *s2)
{
	char	*dest;
	size_t	i;
	size_t	j;

	if (!(s1 && s2))
		return (0);
	i = -1;
	j = 0;
	if (!(dest = (char*)malloc(sizeof(char) *
					(ft_strlen((char*)s1) + ft_strlen((char*)s2) + 2))))
		return (0);
	while (s1[++i])
		dest[i] = s1[i];
	dest[i] = '=';
	i++;
	while (s2[j])
	{
		dest[i] = s2[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**split_env(t_env *g_env)
{
	char	**tab;
	t_env	*save;
	int		i;
	int		j;

	i = 0;
	j = 0;
	save = g_env;
	while (save)
	{
		save = save->next;
		i++;
	}
	save = g_env;
	tab = malloc(sizeof(char*) * (i + 1));
	tab[i] = 0;
	while (i)
	{
		tab[j] = ft_join_env(save->name, save->data);
		i--;
		j++;
		save = save->next;
	}
	return (tab);
}
