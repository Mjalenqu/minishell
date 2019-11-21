/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   place_v2.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/12 08:50:44 by mjalenqu     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/13 11:20:09 by mjalenqu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/minishell.h"

int		exec_v2(char **path, char **tab, t_env *g_env, int i)
{
	char	*tmp;

	tmp = ft_join_path(path[i], tab[0]);
	if (access(tmp, F_OK) == 0)
	{
		execute(tab, tmp, g_env);
		ft_strdel(&tmp);
		return (1);
	}
	else
	{
		ft_strdel(&tmp);
		return (0);
	}
}

char	*filling_simple(char *s, int *tab, char *tmp, char *res)
{
	if (s[tab[0]	] == '\'' && (tab[0] == 0 || s[tab[0] - 1] != '\\'))
	{
		tmp = fill_simple(s, &tab[0]);
		if (!tmp)
			return (NULL);
		res = ft_strfjoin(res, tmp);
		tab[0]++;
	}
	return (res);
}

int		ft_filling(char **split, char *s, t_env *g_env)
{
	int		tab[2];
	char	*res;

	tab[0] = 0;
	tab[1] = 0;
	while (s[tab[0]])
	{
		if ((res = ft_filling_while(s, tab, g_env)) == NULL)
			return (-1);
		if (ft_strcmp(res, "") != 0)
		{
			split[tab[1]] = ft_strdup(res);
			tab[1]++;
		}
		free(res);
	}
	return (1);
}

char	**strsplit(char *s, t_env *g_env)
{
	char	**split;
	int		words;
	int		i;

	i = 0;
	while (s[i] && ((s[i] >= 9 && s[i] <= 13) || s[i] == ' '))
		i++;
	if (!s[i])
		return (NULL);
	words = count_word(s);
	if (!(split = (char**)malloc(sizeof(char*) * (words + 1))))
		return (0);
	split[words] = NULL;
	if (ft_filling(split, s, g_env) == -1)
		return (NULL);
	return (split);
}

int		nul_split(char *buf)
{
	int	i;

	i = 0;
	while (buf[i] && ((buf[i] >= 9 && buf[i] <= 13) || buf[i] == ' ' ||
				buf[i] == ';'))
		i++;
	if (!buf[i])
		return (1);
	return (0);
}
