/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_animation_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 11:52:44 by brappo            #+#    #+#             */
/*   Updated: 2024/10/02 04:43:54 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "error_bonus.h"
#include "mlx_api_bonus.h"
#include "animation_bonus.h"

static void	copy_image(
	t_image *dest,
	t_image *src,
	t_mlx_coords *src_coords,
	t_mlx_coords *size
)
{
	char			*color;
	t_mlx_coords	dest_coords;

	dest_coords.y = 0;
	while (dest_coords.y < size->y)
	{
		dest_coords.x = 0;
		while (dest_coords.x < size->x)
		{
			color = t_mlx_get_pixel(src, src_coords->x + dest_coords.x,
					src_coords->y + dest_coords.y);
			t_mlx_draw_pixel(dest, &dest_coords, *(unsigned int *)color);
			dest_coords.x++;
		}
		dest_coords.y++;
	}
}

static bool	add_anim_sprite(
	t_list **anim,
	t_image *texture,
	t_dimension *dim,
	void *mlx_ptr
)
{
	t_image	*image;
	t_list	*new_node;

	image = t_image_init(mlx_ptr, dim->size.x, dim->size.y);
	if (image == NULL)
		return (false);
	copy_image(image, texture, &dim->coords, &dim->size);
	new_node = ft_lstnew(image);
	if (new_node == NULL)
	{
		t_image_destroy(mlx_ptr, image, true);
		return (false);
	}
	ft_lstadd_back(anim, new_node);
	return (true);
}

t_list	*create_animation_textures(
	t_image *texture,
	t_mlx_coords *size,
	void *mlx_ptr,
	char *texture_name
)
{
	t_list			*anim;
	t_dimension		dim;

	if (texture->width % size->x != 0 || texture->height % size->y != 0)
		return (error_print_string(ERR_TEXTURE_SIZE, texture_name), NULL);
	dim.size = *size;
	dim.coords.y = 0;
	anim = NULL;
	while (dim.coords.y < texture->height)
	{
		dim.coords.x = 0;
		while (dim.coords.x < texture->width)
		{
			if (!add_anim_sprite(&anim, texture, &dim, mlx_ptr))
				return (destroy_animation_textures(anim, mlx_ptr), NULL);
			dim.coords.x += size->x;
		}
		dim.coords.y += size->y;
	}
	return (anim);
}
