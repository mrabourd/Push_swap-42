/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabourd <mrabourd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 15:49:05 by mrabourd          #+#    #+#             */
/*   Updated: 2023/02/03 17:10:56 by mrabourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				content;
	int				value;
	int				tmp_value;
	struct s_list	*next;
}	t_list;

typedef struct s_data
{
	t_list	*start_a;
	t_list	*start_b;
	int		divide;
	int		num_str;
	char	**tab;
	char	*num_char;
	int		*num_i;
}	t_data;

/*MAIN AND PARSE*/
int		ft_len(char *str);
int		ft_notdigit(char *str);
void	ft_bzero(void *s, size_t n);
int		ft_parse(char **str, int ac, t_data *data);

/*JOIN AND ATOI*/
char	*malloc_z(t_data *data);
char	*ft_strjoin(t_data *data, char *s2);
int		ft_empty(char *str);
int		ft_minus(char *str);
int		ft_atoi(char *num, t_data *data);

/*SPLIT*/
int		ft_numchar(char *str, int y);
int		ft_numstr(char *str);
void	ft_strdup(char *str, char *tab, int *y);
void	ft_split(t_data *data);

/*FREE AND EXIT*/
void	ft_freeall(char **tab);
void	ft_exit(t_data *data, int i);

/*CREATE LISTE*/
void	ft_lstclear(t_list **lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(int content);
void	create_list(t_data *data, int *tab);

/*CHECK LISTE*/
void	check_dup(t_data *data);
int		ft_already_sorted(t_data *data);
void	assign_value(t_list **start);
void	tmp_value(t_list **start);
int		count_items(t_list **start);

/*SORT A TO B*/
void	send_median(t_data *list, int max, int devide);
void	send_big(t_data *data, int max, int divide);
void	ft_sort(t_data *data);
int		check_under_median(t_list *list, int median);

/*SORT 2 AND 3*/
void	ft_three(t_list **lst);
void	first_is_sup(t_list **lst);
void	first_is_inf(t_list **lst);
void	ft_two(t_list **lst);

/*SORT BACK B TO A*/
void	send_up_btoa(t_data *data, t_list *send);
void	send_down_btoa(t_data *data, t_list *send);
void	b_to_a_up(t_data *data, t_list *big, t_list *small);
void	b_to_a_down(t_data *data, t_list *big, t_list *small);
void	b_to_a(t_list **list, t_data *data);

/*GET NUMBER*/
t_list	*get_up(t_list *list, int median);
t_list	*get_down(t_list *list, int median);
t_list	*get_big(t_list *list, int sup_value);
t_list	*get_small(t_list *list);

/*COUNT AND SEND*/
int		count_up(t_list **start, t_list *cmp);
int		count_down(t_list *start);
void	send_up(t_data *data, int median, int divide, int c);
void	send_down(t_data *data, int median, int divide, int c);
void	ft_end(t_list **list);

/*MOVES*/
void	ft_sa(t_list **list);
void	ft_sb(t_list **list);
void	ft_ss(t_list **list_i, t_list **list_y);
void	ft_pb(t_list **list_i, t_list **list_y);
void	ft_pa(t_list **list_y, t_list **list_i);
void	ft_ra(t_list **list);
void	ft_rb(t_list **list);
void	ft_rr(t_list **list_i, t_list **list_y);
void	ft_rra(t_list **list);
void	ft_rrb(t_list **list);
void	ft_rrr(t_list **list_i, t_list **list_y);

#endif