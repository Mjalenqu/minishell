/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_comp.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/28 07:42:28 by mjalenqu     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/13 11:17:06 by mjalenqu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_putecho(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '"')
			i++;
		ft_putchar(s[i]);
		i++;
	}
}

void	ft_echo(char **tab)
{
	int i;

	i = 1;
	if (!tab[1])
	{
		ft_putchar('\n');
		return ;
	}
	if (ft_strcmp(tab[1], "-n") == 0)
		i++;
	while (tab[i])
	{
		ft_putecho(tab[i]);
		ft_putchar(' ');
		i++;
	}
	if (ft_strcmp(tab[1], "-n") != 0)
		ft_putchar('\n');
}

void	ft_env(char **tab, t_env *g_env)
{
	int		i;
	t_env	*tmp;

	i = 2;
	tmp = NULL;
	if (!(tab[1]))
		print_env(g_env);
	else
		ft_putcolor(BRED, "\tToo much arguments\n", RESET);
}
