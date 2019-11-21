/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   minishell.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/24 13:26:08 by mjalenqu     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/12 19:03:24 by mjalenqu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <time.h>

# define RESET "\033[00m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"
# define BRED "\033[1;31m"
# define BGREEN "\033[1;32m"
# define BYELLOW "\033[1;33m"
# define BBLUE "\033[1;34m"
# define BPURPLE "\033[1;35m"
# define BCYAN "\033[1;36m"

# define ERR00 "Try to reflechir pour see?\n"
# define ERR01 "tu m'as pris pour Sifouche?\n"
# define ERR02 "atgriezties logos\n"
# define ERR03 "Nan, je disais que t'etais sympa\n"
# define ERR04 "Робот и Елиът са едно и също лице.\n"
# define ERR05 "You should ctr+d yourself\n"
# define ERR06 "Why your parents didn't rm-rf you earlier?\n"
# define ERR07 "Warning :l'erreur se trouve entre le clavier et la chaise.\n"
# define ERR08 "Pars en pause connard\n"
# define ERR09 "c'est toi l'erreur\n"
# define ERR10 "utilise tes mains pour ecrire pas tes pied!\n"
# define ERR11 "Bon, personne n'est parfait mais toi c'est quand meme chaud!\n"

typedef struct	s_env
{
	char			*name;
	char			*data;
	int				type;
	struct s_env	*next;
}				t_env;

/*
*******************************************************************************
**								main.c										***
*******************************************************************************
*/
int				main(int ac, char **av, char **env);
void			free_env(t_env *g_env);
void			restart(int i);
void			restart_prog(int i);

/*
*******************************************************************************
**								check_arg.c									***
*******************************************************************************
*/
int				check_arg(char **tab, t_env **g_env);
t_env			*init_var(char **env, t_env *g_env);
void			ft_free_tab(char **tab);

/*
*******************************************************************************
**								env.c										***
*******************************************************************************
*/
void			print_env(t_env	*g_env);
int				set_env(char **tab, t_env **g_env);
int				set_var(char *str, char *s, t_env *g_env);
int				exec_unsetenv(char **res, t_env **g_env);
void			ft_free_one(t_env *g_env);

/*
*******************************************************************************
**								exec.c										***
*******************************************************************************
*/
int				execute(char **tab, char *path, t_env *g_env);
int				check_path(char **tab, t_env *g_env);
char			*ft_join_path(char *s1, char *s2);
void			ft_cd(char **tab, t_env *g_env);
void			change_pwd(t_env *g_env);
int				exec_toukour(char **tab, t_env *save);
int				exec_path(char **tab, t_env *g_env);

/*
*******************************************************************************
**								ft_comp.c									***
*******************************************************************************
*/
void			ft_echo(char **tab);
void			ft_env(char **tab, t_env *g_env);

/*
*******************************************************************************
**								split_argv.c								***
*******************************************************************************
*/
char			**ft_strsplit_space(char *s, char c);
void			ft_filling_space(char **split, char *s, char c, int words);
int				ft_countwords_space(char *str, char splitter);

/*
*******************************************************************************
**								split_argv.c								***
*******************************************************************************
*/
void			choose_error(void);
void			error_bis(int i);

/*
*******************************************************************************
**								exec.c										***
*******************************************************************************
*/
char			*fill_double(char *s, int *i, t_env *g_env);
char			*fill_simple(char *s, int *i);
char			*fill_nothing(char *s, int *i, t_env *g_env);
char			*fill_var(char *s, int *i, t_env *g_env);
int				ft_filling(char **split, char *s, t_env *g_env);
int				count_word(char *s);
char			**strsplit(char *s, t_env *g_env);

char			*check_home(char *s, t_env *g_env);
char			*check_var(char *str, t_env *g_env);

/*
*******************************************************************************
**								clean.c										***
*******************************************************************************
*/
char			*filling_simple(char *s, int *tab, char *tmp, char *res);
char			*ft_filling_while(char *s, int *tab, t_env *g_env);
int				ft_filling(char **split, char *s, t_env *g_env);
char			**strsplit(char *s, t_env *g_env);
char			**first_split(char *buf);
int				make_clean(char *buf, t_env **g_env);

/*
*******************************************************************************
**								fill_double.c								***
*******************************************************************************
*/
void			if_forest(int *tab, char *s);
void			while_double(char *var, int ivar, char *res, int *tab);
char			*fill_double_solve(char *s, int *tab, t_env *g_env, char *res);
char			*fill_double(char *s, int *i, t_env *g_env);

/*
*******************************************************************************
**								count_word.c								***
*******************************************************************************
*/
void			count_word_while(char *s, int *i);
int				count_word(char *s);
char			*fill_home(int *i, t_env *g_env);
char			*fill_simple(char *s, int *i);

/*
*******************************************************************************
**								fill_nothing.c						***
*******************************************************************************
*/
void			second_if_forest(int *start, char *s);
char			*fill_nothing_solve(char *s, int *tab, t_env *g_env, char *res);
char			*fill_nothing(char *s, int *i, t_env *g_env);
char			*filg_env(char *s, int *i, t_env *g_env);

void			change_env(t_env **g_env, char **tab);
int				error_tab(char *s);
int				unsetenv_v2(t_env *start, char **res, t_env *ndel);
int				exec_v2(char **path, char **tab, t_env *g_env, int i);
int				nul_split(char *buf);
char			*home(char *s, char *res, int *tab, t_env *g_env);
char			*variable(char *s, char *res, int *tab, t_env *g_env);
char			*nothing(char *s, char *res, int *tab, t_env *g_env);
char			**split_env(t_env *g_env);
void			second_first_split(char *buf, char **res, int j, int k);
int				next_first(char *buf, int i);
#endif
