/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fill_double.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mdelarbr <mdelarbr@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/05 16:51:08 by mdelarbr     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/05 18:59:23 by mdelarbr    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/minishell.h"

void		if_forest(int *tab, char *s)
{
	if (s[tab[0]] == '\\' && s[tab[0] + 1] == '\\')
		(tab[0])++;
	if (s[tab[0]] == '\\' && s[tab[0] + 1] == '$')
		(tab[0])++;
	if (s[tab[0]] == '\\' && s[tab[0] + 1] == '"')
		(tab[0])++;
}

void		while_double(char *var, int ivar, char *res, int *tab)
{
	while (var[ivar])
	{
		res[tab[1]] = var[ivar];
		(tab[1])++;
		ivar++;
	}
}

char		*fill_double_solve(char *s, int *tab, t_env *g_env, char *res)
{
	char	*var;
	int		ivar;

	ivar = 0;
	if_forest(tab, s);
	if (s[tab[0]] == '$' && (tab[0] == 0 || s[tab[0] - 1] != '\\'))
	{
		var = fill_var(s, &tab[0], g_env);
		if (ft_strcmp(var, "") == 0)
		{
			res[tab[1]] = '\0';
			return (res);
		}
		while_double(var, ivar, res, tab);
	}
	else
	{
		res[tab[1]] = s[tab[0]];
		(tab[0])++;
		(tab[1])++;
	}
	return (res);
}

char		*fill_double(char *s, int *i, t_env *g_env)
{
	char	*res;
	int		tab[2];
	char	*tmp;

	tab[0] = ++(*i);
	tab[1] = 0;
	while (s[*i] != '"' && s[*i])
		(*i)++;
	if (!s[*i])
	{
		ft_putcolor(BRED, "\terror :end the \", its not 21sh bro.", RESET);
		return (NULL);
	}
	res = malloc(sizeof(char) * (*i - tab[0]) + 1);
	while (tab[0] < *i)
	{
		tmp = fill_double_solve(s, tab, g_env, res);
		if (tmp)
			res = ft_strjoin(res, tmp);
	}
	res[tab[1]] = '\0';
	*i = tab[0];
	return (res);
}
