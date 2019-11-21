/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   var.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/30 18:54:30 by mjalenqu     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/11 21:01:49 by mjalenqu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*get_var(char *str, t_env *g_env)
{
	int		i;
	char	*tmp;
	t_env	*save;

	i = 0;
	save = g_env;
	if (save)
	{
		while (save)
		{
			if (ft_strcmp(save->name, str) == 0)
			{
				tmp = ft_strdup(save->data);
				return (tmp);
			}
			save = save->next;
		}
	}
	tmp = ft_strdup("");
	return (tmp);
}

char	*new_var(char *str, t_env *g_env)
{
	char	*tmp;
	char	*s;
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
		{
			tmp = ft_strsub(str, 1, i - 1);
			s = ft_strsub(str, i + 1, ft_strlen(str));
		}
		i++;
	}
	set_var(tmp, s, g_env);
	return (s);
}

int		is_it_new_var(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (1);
		else
			i++;
	}
	return (0);
}
