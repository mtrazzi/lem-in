/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrazzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 16:16:31 by mtrazzi           #+#    #+#             */
/*   Updated: 2017/08/11 09:52:06 by mtrazzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *dst;
	char *tmp;

	if (s == NULL)
		return (NULL);
	if (start + len > ft_strlen(s))
		return (NULL);
	if ((dst = ft_strnew(len)) == NULL)
	{
		return (NULL);
	}
	tmp = ft_strncpy(dst, s + start, len); 
	free(dst);
	return (tmp);
}
