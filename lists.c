#include "push_swap.h"

t_list	*ft_lstnew(void *content)
{
	t_list *new;

	new = malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_front(t_list **lst, t_list *new1)
{
	if (!*lst)
	{
		*lst = new1;
		return ;
	}
	if (!new1)
		return ;
	new1->next = *lst;
	*lst = new1;
}

int	ft_lstsize(t_list *lst)
{
	int index;

	index = 0;
	while (lst)
	{
		lst = lst->next;
		index++;
	}
	return (index);
}

t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new1)
{
	t_list *temp;

	if (!*lst)
	{
		*lst = new1;
		return ;
	}
	else if (*lst && new1)
	{
		temp = ft_lstlast(*lst);
		temp->next = new1;
	}
}

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst)
	{
		del(lst->content);
		free(lst);
	}
}
