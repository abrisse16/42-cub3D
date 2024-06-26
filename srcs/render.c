/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 13:23:02 by abrisse           #+#    #+#             */
/*   Updated: 2023/06/11 02:41:27 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_background(t_data *data)
{
	data->to_draw.x = 0;
	data->to_draw.width = data->graph.win_width;
	data->to_draw.height = data->graph.win_height / 2;
	data->to_draw.y = 0;
	data->to_draw.color = data->celling[0] << 16 | data->celling[1] << 8
		| data->celling[2];
	draw_color_rect(&data->graph.game, &data->to_draw);
	data->to_draw.y = data->graph.win_height / 2;
	data->to_draw.color = data->floor[0] << 16 | data->floor[1] << 8
		| data->floor[2];
	draw_color_rect(&data->graph.game, &data->to_draw);
}

void	render_player(t_data *data)
{
	int	x;

	x = -1;
	while (++x < data->num_rays)
		if (x % (TILE_SIZE / 2) == 0)
			draw_ray(&data->graph.game, &data->player.coord, &data->rays[x],
				data);
	draw_circle(&data->graph.game, &data->player.coord, 0xFF0000, data);
}
