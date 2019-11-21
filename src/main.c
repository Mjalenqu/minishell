/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/23 13:55:45 by mjalenqu     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/12 19:05:06 by mjalenqu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*fill_prompt(char *tmp, char *save, int i)
{
	int j;

	j = 0;
	i += 2;
	while (save[i])
	{
		tmp[j] = save[i];
		j++;
		i++;
	}
	tmp[j] = '\0';
	return (tmp);
}

int		get_prompt(void)
{
	int		i;
	int		j;
	char	*save;
	char	*tmp;
	char	*buf;

	buf = NULL;
	i = 0;
	j = 0;
	save = getcwd(buf, 0);
	free(buf);
	while (save[i])
		i++;
	while (save[i--] != '/' && i >= 0)
		j++;
	if (!(tmp = malloc(sizeof(char) * j + 1)))
		return (-1);
	j = 0;
	tmp = fill_prompt(tmp, save, i);
	ft_putcolor2(BCYAN, tmp, "->", RESET);
	free(tmp);
	free(save);
	return (0);
}

void	restart_prog(int i)
{
	if (i == SIGINT)
		ft_putchar('\n');
}

void	restart(int i)
{
	if (i == SIGINT)
	{
		ft_putchar('\n');
		get_prompt();
	}
}

int		main(int ac, char **av, char **env)
{
	int		i;
	char	buf[100000];
	t_env	*g_env;

	ac = 1;
	av++;
	g_env = NULL;
	g_env = init_var(env, g_env);
	while (1)
	{
		get_prompt();
		signal(SIGINT, restart);
		while ((i = read(0, buf, 99999)) > 0)
		{
			buf[i - 1] = '\0';
			if (i < 2)
				break ;
			if (make_clean(buf, &g_env) == -1)
			{
				free_env(g_env);
				return (0);
			}
			get_prompt();
		}
	}
}
