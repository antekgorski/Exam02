#include "list.h"
#include <stdlib.h>

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
    int temp;
    t_list *tmp;

    tmp = lst;
    while (lst->next != NULL)
    {
        if (((*cmp)(*lst->data, *lst->next->data)) == 0 )
        {
           temp = lst->data;
           lst->data = lst->next->data;
           lst->next->data = temp;
           lst = tmp; 
        }
        else
        lst = lst->next;
    }
    lst = tmp;
    return(lst);
}