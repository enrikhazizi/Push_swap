/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fqose <fqose@student.42.fr>                #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-18 20:51:31 by fqose             #+#    #+#             */
/*   Updated: 2025-10-18 20:51:31 by fqose            ###   ########.al       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	clear_helper(t_list *ptr, void (*del)(void *))
{
	if (ptr == NULL)
		return ;
	clear_helper(ptr->next, del);
	del(ptr->content);
	free(ptr);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	clear_helper(*lst, del);
	*lst = NULL;
}
