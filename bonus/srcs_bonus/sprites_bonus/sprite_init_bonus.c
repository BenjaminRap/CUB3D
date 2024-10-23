/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_init_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 11:09:07 by brappo            #+#    #+#             */
/*   Updated: 2024/10/02 22:41:50 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sprite_bonus.h"
#include "cub3d_bonus.h"
#include "libft.h"

void	*add_sprite(t_game *game, float x, float y, char id)
{
	t_list		*new_node;
	t_sprite	*new_sprite;

	(void)id;
	new_sprite = ft_calloc(1, sizeof(t_sprite));
	if (new_sprite == NULL)
		return (NULL);
	new_sprite->position.x = x;
	new_sprite->position.y = y;
	new_node = ft_lstnew(new_sprite);
	if (new_node == NULL)
	{
		free(new_sprite);
		return (NULL);
	}
	ft_lstadd_front(&game->sprites, new_node);
	return (new_sprite);
}

void	t_sprite_init(t_sprite *sprite, t_animation *animation, size_t height)
{
	if (sprite == NULL)
		return ;
	sprite->animation = animation;
	sprite->texture = animation->textures;
	sprite->next_animation = animation;
	sprite->distance = 0;
	sprite->height = height;
	sprite->animate = true;
	sprite->locked = false;
	sprite->on_ground = true;
}

bool	init_sprites(t_game *game)
{
	t_list		*current;
	t_sprite	*sprite;

	if (!get_elem_into_list(game, &game->sprites, IDS_MAP_SPRITE, \
			add_sprite))
		return (false);
	current = game->sprites;
	while (current)
	{
		sprite = current->content;
		t_sprite_init(sprite, &game->anim[IDX_TXTR_LIGHT], WIN_HEIGHT);
		current = current->next;
	}
	return (true);
}
