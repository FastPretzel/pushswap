/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_h.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 16:11:28 by cgoth             #+#    #+#             */
/*   Updated: 2022/02/17 16:13:19 by cgoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_H_H
# define PS_H_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# define DEF =
# define BUFFER_SIZE 4

typedef struct s_list
{
	void			*content;
	int				index;
	struct s_list	*next;
}	t_list;

typedef struct s_malloc
{
	char	**av;
	int		*nums;
	int		buf_size;
	t_list	*a_st;
	t_list	*b_st;
}	t_malloc;

char	*get_next_line(int fd);
char	*free_all(char **s1, char **s2);
int		find_n(char *s);
size_t	ft_strlen(const char *s);
void	free_cache(char **s1);
char	*ft_strjoin(char const *s1, char const *s2);
void	cache_gen(char **buf, char **cache, int r);
t_list	*ft_lstnew(void *content);
t_list	*ft_lstadd_back(t_list *lst, t_list *new_lst);
t_list	*ft_lstadd_front(t_list *lst, t_list *new_lst);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst);
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
int		ft_atoi(const char *nptr, t_malloc *tmc);
char	**ft_split(char const *s, char c);
char	**separ(char **argv, t_malloc *tmc);
int		masslen(char **str);
void	ft_err(t_malloc *tmc);
void	clean(t_malloc *tmc);
int		*stoi(char **av, int size, t_malloc *tmc);
void	create_stack(t_malloc *tmc, int size);
void	sa(t_list **lst, int val);
void	sb(t_list **lst, int val);
void	ss(t_list **alst, t_list **blst, int val);
void	ra(t_list **lst, int val);
void	rb(t_list **lst, int val);
void	rr(t_list **alst, t_list **blst, int val);
void	rra(t_list **lst, int val);
void	rrb(t_list **lst, int val);
void	rrr(t_list **alst, t_list **blst, int val);
void	pa(t_list **alst, t_list **blst, int val);
void	pb(t_list **blst, t_list **alst, int val);
int		is_sorted(t_malloc *tmc, t_list **lst);
void	sort_for_3(t_malloc *tmc, int size);
void	sort_for_5(t_malloc *tmc, int size);
void	sort_for_100500(t_malloc *tmc, int size);
void	fill_nums(t_malloc *tmc, int *nums, char *str, int i);
void	**ptrs_init(void);

#endif
