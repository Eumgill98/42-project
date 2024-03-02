#include "libft.h"

void    ft_lstiter(t_list *lst, void (*f)(void *))
{
    t_list  *cur;

    if (!lst || !f)
        return ;
    cur = lst;
    while (cur)
    {
        f(cur->content);
        cur = cur->next;
    }
}