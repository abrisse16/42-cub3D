/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nb_line_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:42:19 by ambouren          #+#    #+#             */
/*   Updated: 2023/03/16 14:42:19 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_nb_line_array(char **tab)
{
	int	len;

	len = -1;
	while (tab[++len])
		;
	return (len);
}
