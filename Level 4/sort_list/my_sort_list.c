#include "list.h"
#include <stdlib.h>

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	int *swap;
	t_list *tmp;

	tmp = lst;

	while (lst->next != NULL)
	{
		if ((*cmp)(*lst->data, *lst->next->data) == 0)
		{
			swap = lst->data;
			lst->data = lst->next->data;
			lst->next->data = swap;
			lst = tmp;
		}
		else
		{
			lst = lst->next;
		}
	}
	lst = tmp;
	return (lst);
}

#include <assert.h>
#include <stdlib.h>

void test_sort_list() {
    // Create a list
    t_list *node1 = malloc(sizeof(t_list));
    t_list *node2 = malloc(sizeof(t_list));
    t_list *node3 = malloc(sizeof(t_list));
    int val1 = 3, val2 = 1, val3 = 2;
    node1->data = &val1;
    node2->data = &val2;
    node3->data = &val3;
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;

    // Sort the list
    t_list *sorted_list = sort_list(node1, cmp);

    // Check the order of the elements
    assert(*(int*)(sorted_list->data) == 1);
    assert(*(int*)(sorted_list->next->data) == 2);
    assert(*(int*)(sorted_list->next->next->data) == 3);

    // Free the memory
    free(node1);
    free(node2);
    free(node3);
}

int main() {
    test_sort_list();
    return 0;
}