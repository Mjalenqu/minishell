/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   place_v2_bis.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/12 13:06:18 by mjalenqu     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/13 08:20:55 by mjalenqu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*home(char *s, char *res, int *tab, t_env *g_env)
{
	char *tmp;

	s++;
	tmp = fill_home(&tab[0], g_env);
	res = ft_strfjoin(res, tmp);
	ft_strdel(&tmp);
	return (res);
}

char	*variable(char *s, char *res, int *tab, t_env *g_env)
{
	char *tmp;

	tmp = fill_var(s, &tab[0], g_env);
	res = ft_strfjoin(res, tmp);
	ft_strdel(&tmp);
	return (res);
}

char	*nothing(char *s, char *res, int *tab, t_env *g_env)
{
	char *tmp;

	tmp = fill_nothing(s, &tab[0], g_env);
	res = ft_strfjoin(res, tmp);
	ft_strdel(&tmp);
	return (res);
}

void	second_first_split(char *buf, char **res, int j, int k)
{
	int i;

	i = 0;
	while (buf[i])
	{
		res[j] = malloc(sizeof(char) * (next_first(buf, i) + 1));
		while (buf[i] && (buf[i] != ';' && (i == 0 || buf[i - 1] != '\\')))
		{
			res[j][k] = buf[i++];
			k++;
		}
		if (buf[i] && (buf[i] == ';' && (i == 0 || buf[i - 1] != '\\')))
		{
			res[j][k] = '\0';
			k = 0;
			j++;
			i++;
		}
		else if (!buf[i])
		{
			res[j][k] = '\0';
			j++;
		}
	}
	res[j] = NULL;
}
