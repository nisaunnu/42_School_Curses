/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nunnu <nunnu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 05:42:36 by nunnu             #+#    #+#             */
/*   Updated: 2023/07/27 03:44:37 by nunnu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

// #include <stdio.h>

// int main()
// {
// 	t_list *neptune;
// 	t_list *uranus;
// 	t_list *last;

// 	neptune = ft_lstnew("neptune");
// 	uranus = ft_lstnew("uranus");
// 	last = ft_lstnew("last");

// 	ft_lstadd_back(&neptune, uranus);
// 	ft_lstadd_back(&neptune, last);
// 	printf("%s", (ft_lstlast(neptune))->content);
// }
