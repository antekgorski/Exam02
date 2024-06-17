#include <stdlib.h>
#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp) ())
{
	t_list *head;
	t_list *past;
	t_list *t_remove;

	head = *begin_list;
	past = NULL;
	t_remove = NULL;
	while (head != NULL)
	{
		if ((*cmp)(head->data, data_ref) == 0)
		{
			if (head == *begin_list)
				*begin_list = head->next;
			else
				past->next = head->next;
			t_remove = head;
			head = head->next;
			free(t_remove);
		}
		else
		{
			past = head;
			head = head->next;
		}
	}
}

// // Passed Moulinette 2019.09.01

// #include <stdlib.h>
// #include "ft_list.h"

// void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
// {
// 	if (begin_list == NULL || *begin_list == NULL)
// 		return;

// 	t_list *cur = *begin_list;

// 	if (cmp(cur->data, data_ref) == 0)
// 	{
// 		*begin_list = cur->next;
// 		free(cur);
// 		ft_list_remove_if(begin_list, data_ref, cmp);
// 	}
// 	else // if there is a no else, you cant pass the Moulinette, tryed 2023.09.08
// 	{
// 		cur = *begin_list;
// 		ft_list_remove_if(&cur->next, data_ref, cmp);
// 	}
// }
