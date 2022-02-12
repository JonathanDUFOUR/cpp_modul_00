# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/11 18:39:33 by jodufour          #+#    #+#              #
#    Updated: 2022/02/12 19:12:09 by jodufour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

######################################
#              COMMANDS              #
######################################
CXX			=	c++ -c
LINK		=	c++
MKDIR		=	mkdir -p
RM			=	rm -rf

######################################
#             EXECUTABLE             #
######################################
NAME		=	megaphone

#######################################
#             DIRECTORIES             #
#######################################
SRC_DIR		=	srcs/
OBJ_DIR		=	objs/

#######################################
#              LIBRARIES              #
#######################################

######################################
#            SOURCE FILES            #
######################################
SRC			=	\
				megaphone.cpp

######################################
#            OBJECT FILES            #
######################################
OBJ			=	${SRC:.cpp=.o}
OBJ			:=	${addprefix ${OBJ_DIR}, ${OBJ}}

DEP			=	${OBJ:.o=.d}

#######################################
#                FLAGS                #
#######################################
CPPFLAGS	=	-Wall -Wextra -Werror
CPPFLAGS	+=	-MMD -MP
CPPFLAGS	+=	-std=c++98

LDFLAGS		=	

ifeq (${DEBUG}, 1)
	CPPFLAGS	+=	-g
endif

#######################################
#                RULES                #
#######################################
${NAME}: ${OBJ}
	${LINK} ${OBJ} ${LDFLAGS} ${OUTPUT_OPTION}

all: ${NAME}

-include ${DEP}

${OBJ_DIR}%.o: ${SRC_DIR}%.cpp
	@${MKDIR} ${@D}
	${CXX} ${CPPFLAGS} $< ${OUTPUT_OPTION}

clean:
	${RM} ${OBJ_DIR} ${NAME} vgcore.*

fclean:
	${RM} ${OBJ_DIR} ${NAME} vgcore.*

re: clean all

fre: fclean all

-include /home/jodufour/Templates/mk_files/coffee.mk

.PHONY:	all clean fclean re fre
