/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 16:46:25 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/12 18:43:45 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSG_H
# define MSG_H

# include "ft_colors.h"

# define FATAL				C_RED "[Fatal Error]" C_RESET " "
# define ERROR				C_LRED "[Error]" C_RESET " "
# define WARNING			C_YELLOW "[Warning]" C_RESET " "
# define INFO				C_CYAN "[Info]" C_RESET " "

# define ERROR_OPEN_MSG		ERROR "%s: '%s'\n"

# define ERROR_BEFORE_MSG	ERROR "%s before '%s' at %s:%d\n"
# define ERROR_UNDEF_MSG	ERROR "Undefined %s '%s' at %s:%d\n"
# define ERROR_REDEF_MSG	ERROR "Redefined %s '%s' at %s:%d\n"

# define WARNING_REDEF_MSG	WARNING "Redefining %s '%s' at %s:%d\n"

# define SCENE_LOAD_MSG		INFO "%d scene(s) loaded.\n"
# define SHAPE_LOAD_MSG		INFO "%d shape(s) loaded.\n"
# define NO_SCENE_MSG		FATAL "0 scene loaded.\n"
# define NO_SHAPE_MSG		WARNING "0 shape loaded.\n"

#endif
