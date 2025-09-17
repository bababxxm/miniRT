/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errmsg.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 23:36:29 by sklaokli          #+#    #+#             */
/*   Updated: 2025/09/15 20:41:15 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRMSG_H
# define ERRMSG_H

# define ERR_FILE "Expected an existing .rt file."
# define ERR_ELEMENT_UNKNOWN "Unknown element encountered."
# define ERR_ELEMENT_DUPLICATE "Duplicate singleton element."
# define ERR_ELEMENT_MISSING "Missing required scene element."

# define ERR_AMBIENT_ARGS "Invalid ambient format."
# define ERR_AMBIENT_RATIO "Invalid ambient ratio. \
Must be between 0 and 1."
# define ERR_AMBIENT_COLOR "Invalid ambient color."

# define ERR_CAMERA_ARGS "Invalid camera format."
# define ERR_CAMERA_POSITION "Invalid camera position. \
Must be between -100 and 100."
# define ERR_CAMERA_DIRECTION "Invalid camera direction."
# define ERR_CAMERA_FOV "Invalid camera FOV. \
Must be between 0 and 180."

# define ERR_LIGHT_ARGS "Invalid light format."
# define ERR_LIGHT_POSITION "Invalid light position. \
Must be between -100 and 100."
# define ERR_LIGHT_BRIGHTNESS "Invalid light brightness. \
Must be between 0 and 1."
# define ERR_LIGHT_COLOR "Invalid light color."

# define ERR_SPHERE_ARGS "Invalid sphere format."
# define ERR_SPHERE_CENTER "Invalid sphere center."
# define ERR_SPHERE_RADIUS "Invalid sphere radius. \
Must be between 0 and 1000."
# define ERR_SPHERE_COLOR "Invalid sphere color."

# define ERR_PLANE_ARGS "Invalid plane format."
# define ERR_PLANE_POSITION "Invalid plane position. \
Must be between -100 and 100."
# define ERR_PLANE_NORMAL "Invalid plane normal. \
Must be between -1 and 1."
# define ERR_PLANE_COLOR "Invalid plane color."

# define ERR_CYLINDER_ARGS "Invalid cylinder format."
# define ERR_CYLINDER_CENTER "Invalid cylinder center."
# define ERR_CYLINDER_AXIS "Invalid cylinder axis."
# define ERR_CYLINDER_RADIUS "Invalid cylinder radius. \
Must be between -1000 and 1000."
# define ERR_CYLINDER_HEIGHT "Invalid cylinder height. \
Must be between -1000 and 1000."
# define ERR_CYLINDER_COLOR "Invalid cylinder color."

# define ERR_VECTOR_FORMAT "Vector must be in x,y,z format."
# define ERR_RGB_FORMAT "Expected RGB format between 0 and 255."

#endif