/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   error.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/04 15:10:29 by mjalenqu     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/04 15:40:17 by mjalenqu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/minishell.h"

void	error_bis(int i)
{
	if (i == 9)
		ft_putcolor2(BRED, "\t", ERR09, RESET);
	else if (i == 10)
		ft_putcolor2(BRED, "\t", ERR10, RESET);
	else if (i == 11)
		ft_putcolor2(BRED, "\t", ERR11, RESET);
}

void	choose_error(void)
{
	int i;

	srand(time(NULL));
	i = rand();
	i = i % 12;
	if (i == 0)
		ft_putcolor2(BRED, "\t", ERR00, RESET);
	else if (i == 1)
		ft_putcolor2(BRED, "\t", ERR01, RESET);
	else if (i == 2)
		ft_putcolor2(BRED, "\t", ERR02, RESET);
	else if (i == 3)
		ft_putcolor2(BRED, "\t", ERR03, RESET);
	else if (i == 4)
		ft_putcolor2(BRED, "\t", ERR04, RESET);
	else if (i == 5)
		ft_putcolor2(BRED, "\t", ERR05, RESET);
	else if (i == 6)
		ft_putcolor2(BRED, "\t", ERR06, RESET);
	else if (i == 7)
		ft_putcolor2(BRED, "\t", ERR07, RESET);
	else if (i == 8)
		ft_putcolor2(BRED, "\t", ERR08, RESET);
	else
		error_bis(i);
}
