#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_st
{
	int	*stack_a;
	int	*stack_b;
	int	size;
	int	sizeA;
	int	sizeB;
	int	position;
	int	bigPosition;
	int	value;
	int	chunks;

}		t_list;	

/*typedef struct	s_list
{
	int			*content;
	struct s_list	*next;
}				t_list;*/

int		ft_atoi(const char *str);
int		ft_strlen(char *str);
int		ft_longatoi(const char *str);
int		subSubOrganizeGhost(int *stackGhost, int size, int control,
			t_list *s_st);
int		subOrganizeGhost(int *stackGhost, int size, int control, t_list *s_st);
int		ft_isdigit(int c);
int		doubles(char *argv[]);
void	s(int *stack, int control);
void	ss(int *stack_a, int *stack_b);
void	r(int *stack, int size, int control);
void	rr(int *stack, int size, int control);
void	pb(int *stack_b, int *stack_a, t_list *s_st);
void	pa(int *stack_a, int *stack_b, t_list *s_st);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	push(int *stack_a, int *stack_b, int size);
void	initStruct(t_list *s_st, int argc);
int		zerochk(int *stack, int size);
void	initStacks(int *stack_a, int *stack_b, int size, char *argv[]);
int		organizeGhost(int *stack, int size, t_list *s_st);
void	Digits(int *stack, int sizeA);
void	sender(int *stack_a, int *stack_b, t_list *s_st);

#endif
