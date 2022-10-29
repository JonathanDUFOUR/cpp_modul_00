# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/11 19:31:37 by jodufour          #+#    #+#              #
#    Updated: 2022/10/29 08:00:28 by jodufour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

######################################
#              COMMANDS              #
######################################
CXX			=	clang++
LINK		=	clang++
MKDIR		=	mkdir -p
RM			=	rm -rf

######################################
#             EXECUTABLE             #
######################################
NAME		=	phone_book.out

#######################################
#             DIRECTORIES             #
#######################################
SRC_DIR		=	srcs
OBJ_DIR		=	objs
PRV_DIR		=	private

######################################
#            SOURCE FILES            #
######################################
SRC			=	\
				${addprefix class/,	\
					Contact.cpp		\
					PhoneBook.cpp	\
				}					\
				main.cpp

######################################
#            OBJECT FILES            #
######################################
OBJ			=	${SRC:.cpp=.o}
OBJ			:=	${addprefix ${OBJ_DIR}/, ${OBJ}}

DEP			=	${OBJ:.o=.d}

#######################################
#                FLAGS                #
#######################################
CXXFLAGS	=	-c
CXXFLAGS	+=	-Wall -Wextra -Werror
CXXFLAGS	+=	-Wshadow
CXXFLAGS	+=	-MMD -MP
CXXFLAGS	+=	-std=c++98
CXXFLAGS	+=	-I${PRV_DIR}

LDFLAGS		=	

ifeq (${DEBUG}, 1)
	CXXFLAGS	+=	-g
	CXXFLAGS	+=	-DDEBUG=1
endif

#######################################
#                RULES                #
#######################################
.PHONY:	all clean fclean re fre

${NAME}: ${OBJ}
	${LINK} $^ ${LDFLAGS} ${OUTPUT_OPTION}

all: ${NAME}

-include ${DEP}

${OBJ_DIR}/%.o: ${SRC_DIR}/%.cpp
	@${MKDIR} ${@D}
	${CXX} ${CXXFLAGS} $< ${OUTPUT_OPTION}

clean:
	${RM} ${OBJ_DIR} ${NAME} vgcore.*

fclean:
	${RM} ${OBJ_DIR} ${NAME} vgcore.*

re: clean all

fre: fclean all

-include ${HOME}/Templates/mk_files/coffee.mk
