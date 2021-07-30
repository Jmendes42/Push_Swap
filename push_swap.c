#include "push_swap.h"

/*static void	initStruct(t_strc *strc)
{
	strc->size = 0;
}*/

static t_list	**createList(int argc, char **argv)
{
	t_list	**list;
	//t_list	*new;
	int	index;

	list = NULL;
	index = 0;
	while (index < argc - 1)
	{
		*list = ft_lstnew(argv[index + 1]);
		ft_lstadd_front(list, list[index]);
		printf("%ls\n", list[index]->content);
	}
	return (list);
}

int	main(int argc, char **argv)
{
	printf("*****");
	//t_strc	strc;
	
	createList(argc, argv);
	/*while (index < argc -1)
	{
		printf("%ls\n", stack_a[index]->content);
		index++;
	}*/
	//free (stack_a);
}
