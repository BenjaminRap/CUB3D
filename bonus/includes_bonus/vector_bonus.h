/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 01:02:00 by codekiwi          #+#    #+#             */
/*   Updated: 2024/07/19 11:48:22 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_BONUS_H
# define VECTOR_BONUS_H

typedef struct s_vector	t_vector;

struct s_vector
{
	float	x;
	float	y;
};

// t_vector functions
void		t_vector_init(t_vector *vector, float x, float y);
void		t_vector_get_slope(t_vector *slope, float angle_rad);
float		get_distance(t_vector *a, t_vector *b);
float		get_vector_length(t_vector *vector);
void		add_vector(t_vector *src, t_vector *other);
void		mutlitply_vector(t_vector *vector, float factor);
float		get_squared_distance(t_vector *a, t_vector *b);
void		normalize_vector(t_vector *a);

#endif
