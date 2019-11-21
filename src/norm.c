/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   norm.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/11 19:11:07 by mjalenqu     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/13 08:29:07 by mjalenqu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*ft_filling_while(char *s, int *t, t_env *g_env)
{
	char	*tmp;
	char	*res;

	res = ft_strdup("");
	tmp = NULL;
	while (s[t[0]] && ((s[t[0]] >= 9 && s[t[0]] <= 13) || s[t[0]] == ' '))
		(t[0])++;
	if (s[t[0]] == '"' && (t[0] == 0 || s[t[0] - 1] != '\\'))
	{
		if ((tmp = fill_double(s, &t[0], g_env)) == NULL)
			return (NULL);
		res = ft_strfjoin(res, tmp);
		(t[0])++;
	}
	if ((res = filling_simple(s, t, tmp, res)) == NULL)
		return (NULL);
	if (s[t[0]] == '~' && (t[0] == 0 || s[t[0] - 1] != '\\'))
		res = home(s, res, t, g_env);
	if (s[t[0]] == '$' && (t[0] == 0 || s[t[0] - 1] != '\\'))
		res = variable(s, res, t, g_env);
	else
		res = nothing(s, res, t, g_env);
	if (tmp)
		ft_strdel(&tmp);
	return (res);
}

int		count_first(char *buf)
{
	int	cnt;
	int	i;

	i = 0;
	cnt = 1;
	while (buf[i++])
	{
		if (buf[i] == ';' && (i == 0 || buf[i - 1] != '\\'))
			cnt++;
		if (buf[i] == '"' && (i == 0 || buf[i - 1] != '\\'))
		{
			i++;
			while (buf[i] && ((buf[i] != '"' && (i == 0 ||
								buf[i - 1] != '\\'))))
				i++;
		}
		if (buf[i] && ((buf[i] == '\'' && (i == 0 || buf[i - 1] != '\\'))))
		{
			i++;
			while (buf[i] && ((buf[i] != '\'' && (i == 0 ||
								buf[i - 1] != '\\'))))
				i++;
		}
	}
	return (cnt);
}

int		next_first(char *buf, int i)
{
	int	cnt;

	cnt = 0;
	while (buf[i] && ((buf[i] != ';' && (i == 0 || buf[i - 1] != '\\'))))
	{
		i++;
		cnt++;
	}
	return (cnt);
}

char	**first_split(char *buf)
{
	int		j;
	int		k;
	char	**res;

	j = 0;
	k = 0;
	res = malloc(sizeof(char*) * (count_first(buf) + 1));
	if (nul_split(buf) == 1)
		return (NULL);
	second_first_split(buf, res, j, k);
	return (res);
}

int		make_clean(char *buf, t_env **g_env)
{
	char	**fres;
	int		ret;
	int		i;
	char	**res;

	i = 0;
	fres = first_split(buf);
	if (fres == NULL)
		return (0);
	while (fres[i])
	{
		if ((res = strsplit(fres[i], (*g_env))) == NULL)
			break ;
		ret = check_arg(res, g_env);
		if (ret == -1)
		{
			ft_free_tab(fres);
			ft_free_tab(res);
			return (-1);
		}
		ft_free_tab(res);
		i++;
	}
	ft_free_tab(fres);
	return (ret);
}
