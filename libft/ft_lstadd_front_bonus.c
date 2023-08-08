/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilverb <hsilverb@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:39:05 by hsilverb          #+#    #+#             */
/*   Updated: 2023/01/05 17:18:12 by hsilverb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*
-> lst = adresse du pointeur vers le 1er element de la liste
-> new = adresse du pointeur vers l'element a rajouter a la liste
*/
#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst)
		return ;
	if (*lst)
		new->next = *lst;
	*lst = new;
}
