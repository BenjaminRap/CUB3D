/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entities_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 10:07:32 by brappo            #+#    #+#             */
/*   Updated: 2024/10/02 04:30:03 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITIES_BONUS_H
# define ENTITIES_BONUS_H

# include <stdbool.h>

# include "map_bonus.h"

# define ENTITY_UPDATE_PER_FRAME		1

# define ROCKET_DAMAGE					2

# define DEMON_SPEED					5
# define DEMON_SQUARED_RADIUS			0.5
# define DEMON_SENSIBILITY_RADIUS		0.05
# define DEMON_HEALTH_POINT				6
# define DEMON_ATTACK_RANGE				1.5
# define DEMON_PAUSE					2
# define DEMON_DAMAGE					4
# define DEMON_HEIGHT_RATIO				0.7
# define DEMON_RELOAD_PROBABILITY		0.6f
# define DEMON_RELOAD_RATIO				0.5f

# define IMP_SPEED						2
# define IMP_SQUARED_RADIUS				0.5
# define IMP_SENSIBILITY_RADIUS			0.05
# define IMP_HEALTH_POINT				2
# define IMP_CLOSE_ATTACK_RANGE			1.5
# define IMP_CLOSE_PAUSE				2
# define IMP_RANGE_PAUSE				1
# define IMP_CLOSE_DAMAGE				2
# define IMP_RANGE_DAMAGE				1
# define IMP_HEIGHT_RATIO				0.4
# define IMP_RELOAD_PROBABILITY			0.4f
# define IMP_RELOAD_RATIO				0.25f

# define CACO_SPEED						2
# define CACO_SQUARED_RADIUS			0.25
# define CACO_SENSIBILITY_RADIUS		0.025
# define CACO_HEALTH_POINT				5
# define CACO_CLOSE_ATTACK_RANGE		1.5
# define CACO_CLOSE_PAUSE				2
# define CACO_RANGE_PAUSE				2
# define CACO_CLOSE_DAMAGE				10
# define CACO_RANGE_DAMAGE				3
# define CACO_HEIGHT_RATIO				0.5
# define CACO_RELOAD_PROBABILITY		0.65f
# define CACO_RELOAD_RATIO				0.4f

# define BOH_SPEED						2
# define BOH_SQUARED_RADIUS				0.5
# define BOH_SENSIBILITY_RADIUS			0.05
# define BOH_HEALTH_POINT				30
# define BOH_CLOSE_ATTACK_RANGE			1.5
# define BOH_CLOSE_PAUSE				5
# define BOH_RANGE_PAUSE				2
# define BOH_CLOSE_DAMAGE				5
# define BOH_RANGE_DAMAGE				4
# define BOH_HEIGHT_RATIO				0.8
# define BOH_RELOAD_PROBABILITY			0.8f
# define BOH_RELOAD_RATIO				0.8f

# define LOST_SOUL_SPEED				2
# define LOST_SOUL_SQUARED_RADIUS		0.1
# define LOST_SOUL_SENSIBILITY_RADIUS	0.01
# define LOST_SOUL_RANGE				1
# define LOST_SOUL_HEIGHT_RATIO			0.5
# define LOST_SOUL_RELOAD_PROBABILITY	0
# define LOST_SOUL_RELOAD_RATIO			0
# define LOST_SOUL_SUICIDE_DAMAGE		4

# define PAIN_ELEM_SPEED				1
# define PAIN_ELEM_SQUARED_RADIUS		0.75
# define PAIN_ELEM_SENSIBILITY_RADIUS	0.075
# define PAIN_ELEM_DAMAGE				3
# define PAIN_ELEM_ATTACK_RANGE			1.5
# define PAIN_ELEM_PAUSE				1
# define PAIN_ELEM_SPAWN_PAUSE			3
# define PAIN_ELEM_HEALTH_POINT			20
# define PAIN_ELEM_HEIGHT_RATIO			0.8
# define PAIN_ELEM_RELOAD_PROBABILITY	0.7f
# define PAIN_ELEM_RELOAD_RATIO			0.6f

# define CYBER_SPEED					0.5
# define CYBER_SQUARED_RADIUS			0.7
# define CYBER_SENSIBILITY_RADIUS		0.075
# define CYBER_HEALTH_POINT				80
# define CYBER_RANGE_PAUSE				15
# define CYBER_RANGE_DAMAGE				10
# define CYBER_HEIGHT_RATIO				1
# define CYBER_RELOAD_PROBABILITY		1.0f
# define CYBER_RELOAD_RATIO				0.8f

# define REV_SPEED						2
# define REV_SQUARED_RADIUS				0.5
# define REV_SENSIBILITY_RADIUS			0.03
# define REV_HEALTH_POINT				12
# define REV_CLOSE_ATTACK_RANGE			1.5
# define REV_CLOSE_PAUSE				2
# define REV_RANGE_PAUSE				1
# define REV_CLOSE_DAMAGE				1
# define REV_RANGE_DAMAGE				1
# define REV_HEIGHT_RATIO				0.7
# define REV_RELOAD_PROBABILITY			0.7f
# define REV_RELOAD_RATIO				0.7f

# define MANC_SPEED						2
# define MANC_SQUARED_RADIUS			0.5
# define MANC_SENSIBILITY_RADIUS		0.05
# define MANC_HEALTH_POINT				15
# define MANC_CLOSE_ATTACK_RANGE		1.5
# define MANC_CLOSE_PAUSE				2
# define MANC_RANGE_PAUSE				2
# define MANC_CLOSE_DAMAGE				6
# define MANC_RANGE_DAMAGE				5
# define MANC_HEIGHT_RATIO				0.9
# define MANC_RELOAD_PROBABILITY		0.8f
# define MANC_RELOAD_RATIO				0.6f

# define COMMANDO_PAUSE					2
# define COMMANDO_SPEED					1
# define COMMANDO_SQUARED_RADIUS		0.25
# define COMMANDO_SENSIBILITY_RADIUS	0.025
# define COMMANDO_HEALTH_POINT			5
# define COMMANDO_HEIGHT_RATIO			0.65f
# define COMMANDO_RELOAD_PROBABILITY	0.6f
# define COMMANDO_RELOAD_RATIO			0.5f

# define SERGEANT_PAUSE					1
# define SERGEANT_SPEED					1
# define SERGEANT_SQUARED_RADIUS		0.25
# define SERGEANT_SENSIBILITY_RADIUS	0.025
# define SERGEANT_HEALTH_POINT			5
# define SERGEANT_HEIGHT_RATIO			0.625
# define SERGEANT_RELOAD_PROBABILITY	0.6f
# define SERGEANT_RELOAD_RATIO			0.5f

typedef struct s_entity		t_entity;
typedef struct s_list		t_list;
typedef struct s_demon		t_demon;
typedef struct s_bullet		t_bullet;

struct s_entity
{
	float		speed;
	bool		is_path_circular;
	t_list		*path;
	t_sprite	*sprite;
	float		squared_radius;
	float		bullet_sensibility_radius;
	size_t		health_point;
	bool		(*update)(t_game *, t_entity *, float );
	void		(*get_damage)(t_game *, t_entity *, size_t);
	void		(*get_killed)(t_game *, t_entity *);
	void		(*get_chainsawed)(t_game *, t_entity *, size_t);
	void		*type;
	float		cooldown;
	float		cooldown_from_player;
	float		reload_probability;
	float		reload_ratio;
	bool		see_player;
	t_animation	*walk;
	t_animation	*pain;
	t_animation	*death;
	t_animation	*close_attack;
	t_animation	*range_attack;
	size_t		close_damage;
	void		(*bullet_init)(t_animation [MAP_NB_IDS], t_bullet *);
};

void	t_entity_destroy(void *data);
bool	init_entities(t_game *game);
void	update_entities_path(t_game *game);
bool	move_entity(t_list *entities, t_vector *position, t_vector *move,
			t_map *map);
bool	update_entities(t_game *game, float delta_time);
void	damage_entity(t_game *game, t_entity *entity, size_t damage);
void	update_entity_position(t_entity *entity, float delta_time,
			t_list *entities, t_map *map);
int		equal(void *a, void *b);
bool	entity_shoot_bullet(t_game *game, t_sprite *entity_sprite);
void	*add_entity(t_game *game, float x, float y, char id);
bool	collide_entity(t_list *entities, t_vector *position);
void	get_entity_direction(t_vector *result, t_vector *player_pos,
			t_vector *entity_pos);
bool	get_spawn_position(t_vector *result, t_entity *entity,
			t_vector *direction, t_game *game);
void	entity_get_killed(t_game *game, t_entity *entity);
void	entity_get_damage(t_game *game, t_entity *entity, size_t damage);
void	entity_get_chainsawed(t_game *game, t_entity *entity, size_t damage);
void	stop_walk_animation(t_entity *entity);
void	range_attack(t_entity *entity, t_game *game, size_t cooldown);
void	close_attack(t_entity *entity, t_game *game, size_t cooldown);
int		is_sprite_of_entity(void *entity_void, void *sprite_void);
bool	entity_damage_player(t_game *game, t_sprite *entity_sprite);

// Init entities species
void	demon_init(t_entity *entity, t_animation anim[MAP_NB_IDS]);
bool	demon_update(t_game *game, t_entity *entity, float delta_time);
void	imp_init(t_entity *entity, t_animation anim[MAP_NB_IDS]);
bool	imp_update(t_game *game, t_entity *entity, float delta_time);
void	caco_init(t_entity *entity, t_animation anim[MAP_NB_IDS]);
bool	caco_update(t_game *game, t_entity *entity, float delta_time);
void	boh_init(t_entity *entity, t_animation anim[MAP_NB_IDS]);
bool	boh_update(t_game *game, t_entity *entity, float delta_time);
void	lost_soul_init(t_entity *entity, t_animation anim[MAP_NB_IDS]);
bool	lost_soul_update(t_game *game, t_entity *entity, float delta_time);
void	pain_elem_init(t_entity *entity, t_animation anim[MAP_NB_IDS]);
bool	pain_elem_update(t_game *game, t_entity *entity, float delta_time);
void	cyber_init(t_entity *entity, t_animation anim[MAP_NB_IDS]);
bool	cyber_update(t_game *game, t_entity *entity, float delta_time);
void	revenant_init(t_entity *entity, t_animation anim[MAP_NB_IDS]);
bool	revenant_update(t_game *game, t_entity *entity, float delta_time);
void	mancubus_init(t_entity *entity, t_animation anim[MAP_NB_IDS]);
bool	mancubus_update(t_game *game, t_entity *entity, float delta_time);
void	arch_vile_init(t_entity *entity, t_animation anim[MAP_NB_IDS]);
bool	arch_vile_update(t_game *game, t_entity *entity, float delta_time);
void	sergeant_init(t_entity *entity, t_animation anim[MAP_NB_IDS]);
bool	sergeant_update(t_game *game, t_entity *entity, float delta_time);
void	commando_init(t_entity *entity, t_animation anim[MAP_NB_IDS]);
bool	commando_update(t_game *game, t_entity *entity, float delta_time);
void	init_entity_type(t_entity *entity, char id, \
			t_animation anim[MAP_NB_IDS]);

#endif
