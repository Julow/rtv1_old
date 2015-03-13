/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 16:46:25 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/13 18:29:02 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSG_H
# define MSG_H

# include "ft_colors.h"

# define ENDL				"\n"

# define FATAL				C_RED "[Fatal Error]" C_RESET " "
# define ERROR				C_LRED "[Error]" C_RESET "   "
# define WARNING			C_YELLOW "[Warning]" C_RESET " "
# define INFO				C_CYAN "[Info]" C_RESET "    "

/*
** ========================================================================== **
** parser errors
*/

# define ERROR_OPEN_MSG		ERROR "%s: '%r'\n"

# define W_BAD_OPTION_MSG	WARNING "Bad option '%c'" ENDL

# define ERROR_INCLUDE_MSG	ERROR "Cannot include '%r' at %s:%d" ENDL
# define ERROR_INCLOOP_MSG	ERROR "Include loop detected at %s:%d" ENDL

# define ERROR_BEFORE_MSG	ERROR "%s before '%s' at %s:%d" ENDL
# define ERROR_UNDEF_MSG	ERROR "Undefined %s '%s' at %s:%d" ENDL
# define ERROR_REDEF_MSG	ERROR "Redefined %s '%s' at %s:%d" ENDL

# define WARNING_REDEF_MSG	WARNING "Redefining %s '%s' at %s:%d" ENDL

/*
** ========================================================================== **
** other
*/

# define SCENE_LOAD_MSG		INFO "%d scene(s) loaded." ENDL
# define SHAPE_LOAD_MSG		INFO "%d shape(s) loaded." ENDL
# define NO_SCENE_MSG		FATAL "0 scene loaded." ENDL
# define NO_SHAPE_MSG		WARNING "0 shape loaded." ENDL

#endif
