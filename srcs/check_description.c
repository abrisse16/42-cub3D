/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_description.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 19:32:51 by abrisse           #+#    #+#             */
/*   Updated: 2023/06/12 09:37:13 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_extension(char *file, char *ext)
{
	char	*str;
	char	**split;
	int		i;

	split = ft_split(file, "/");
	i = -1;
	while (split[++i])
		;
	str = ft_strrchr(split[i - 1], '.');
	if (str == NULL || ft_strcmp(str, ext) || !ft_strcmp(split[i - 1], ext))
		return (1);
	return (0);
}

static int	check_rgb(int *colors)
{
	int	i;

	i = -1;
	while (++i < 3)
	{
		if (colors[i] > 255 || colors[i] < 0)
			return (1);
	}
	return (0);
}

int	check_description(t_data *data)
{
	if (!data->no || check_extension(data->no, ".xpm"))
		return (ft_error(
				"Path to the north texture is missing or invalid format file"));
	if (!data->so || check_extension(data->so, ".xpm"))
		return (ft_error(
				"Path to the south texture is missing or invalid format file"));
	if (!data->we || check_extension(data->we, ".xpm"))
		return (ft_error(
				"Path to the west texture is missing or invalid format file"));
	if (!data->ea || check_extension(data->ea, ".xpm"))
		return (ft_error(
				"Path to the east texture is missing or invalid format file"));
	if (check_rgb(data->celling))
		return (ft_error("Color of the celling is not in the RGB range"));
	if (check_rgb(data->floor))
		return (ft_error("Color of the floor is not in the RGB range"));
	return (0);
}
