/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 16:46:25 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/13 19:04:28 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSG_H
# define MSG_H

# include "ft_colors.h"

# define ENDL				"\n"

# define PRE_FATAL				C_RED "[Fatal Error]" C_RESET " "
# define PRE_ERROR				C_LRED "[Error]" C_RESET "   "
# define PRE_WARN				C_YELLOW "[Warning]" C_RESET " "
# define PRE_DEBUG				C_CYAN "[DEBUG]" C_RESET "   "
# define PRE_INFO				C_CYAN "[Info]" C_RESET "    "

/*
** ========================================================================== **
** parser errors
*/

# define PARSE_AT_MSG		" at %s:%d"

# define ERROR_OPEN_MSG		PRE_ERROR "%s: '%r'" ENDL

# define W_BAD_OPTION_MSG	PRE_WARN "Bad option '%c'" ENDL

# define ERROR_INCLUDE_MSG	PRE_ERROR "Cannot include '%r'" PARSE_AT_MSG ENDL
# define ERROR_INCLOOP_MSG	PRE_ERROR "Include loop detected" PARSE_AT_MSG ENDL

# define ERROR_BEFORE_MSG	PRE_ERROR "%s before '%s'" PARSE_AT_MSG ENDL
# define ERROR_UNDEF_MSG	PRE_ERROR "Undefined %s '%s'" PARSE_AT_MSG ENDL
# define ERROR_REDEF_MSG	PRE_ERROR "Redefined %s '%s'" PARSE_AT_MSG ENDL

# define WARNING_REDEF_MSG	PRE_WARN "Redefining %s '%s'" PARSE_AT_MSG ENDL

/*
** ========================================================================== **
** debug msg
*/

# define DEBUG_SCENE_MSG	PRE_DEBUG "Loading scene '%s'" PARSE_AT_MSG ENDL
# define DEBUG_SHAPE_MSG	PRE_DEBUG "Loading shape '%s'" PARSE_AT_MSG ENDL

# define DEBUG_FILE_MSG		PRE_DEBUG "Loading '%s'" ENDL
# define DEBUG_INCLUDE_MSG	PRE_DEBUG "Including '%s'" PARSE_AT_MSG ENDL

/*
** ========================================================================== **
** other
*/

# define SCENE_LOAD_MSG		PRE_INFO "%d scene(s) loaded." ENDL
# define SHAPE_LOAD_MSG		PRE_INFO "%d shape(s) loaded." ENDL
# define NO_SCENE_MSG		PRE_FATAL "0 scene loaded." ENDL
# define NO_SHAPE_MSG		PRE_WARN "0 shape loaded." ENDL

#endif
