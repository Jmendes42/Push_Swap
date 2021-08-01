#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_st
{
	int *stack_a;
	int *stack_b;
	int size;
	int position;
	int value;

}		t_list;	

/*typedef struct	s_list
{
	int			*content;
	struct s_list	*next;
}				t_list;*/

int	ft_atoi(const char *str);

void	s(int *stack, int control);
void	ss(int *stack_a, int *stack_b);
void	r(int *stack, int size, int control);
void	p(int *stack_p, int *stack_r, int size, int control);
void	rr(int *stack, int size, int control);
void	p(int *stack_p, int *stack_r, int size, int control);

//LISTS
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new1);
int	ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new1);
void	ft_lstdelone(t_list *lst, void (*del)(void*));










#endif
