################################################################################
#                                    CONFIG                                    #
################################################################################

CC = c++

NAME = FragTrap

FLAGS = -Wall -Werror -Wextra -std=c++98 -Wshadow -Wno-shadow

################################################################################
#                                   SOURCES                                    #
################################################################################

SRCS_FILES	:=		main \
					ClapTrap \
					ScavTrap \
					FragTrap

SRCS_FILES	:= 		$(addsuffix .cpp, $(SRCS_FILES))

SRCS_DIR	= 		sources/

VPATH		= 		$(SRCS_DIR)

################################################################################
#                                  HEADERS                                     #
################################################################################

HEADS_DIR 	= 		headers/

################################################################################
#                                  OBJECTS                                     #
################################################################################

OBJS		=		$(patsubst %.cpp,$(OBJS_DIR)%.o,${SRCS_FILES})

OBJS_DIR	= 		objects/

NEW_OBJS	=		0

$(OBJS_DIR)%.o	: %.cpp
	@if [ ! -e "$(OBJS_DIR)" ]; then mkdir -p $(OBJS_DIR); echo "$(GREEN)Creation ${CLR_RMV}of ${CYAN}objects ${CLR_RMV}directory ✔️"; fi
	@if [ ! $(NEW_OBJS) != 0 ]; then echo "$(BLUE)Generating $(YELLOW)$(NAME) $(BLUE)objects :"; fi
	$(eval NEW_OBJS=$(shell echo $$(($(NEW_OBJS)+1))))
				@c++ $(FLAGS) -c $< -I$(HEADS_DIR) -o $@
				@echo "$(CLR_RMV)- $(CYAN)$@";

################################################################################
#                                   RULES                                      #
################################################################################

CLR_RMV		:=		\033[0m
RED		    :=		\033[1;31m
GREEN		:=		\033[1;32m
YELLOW		:=		\033[1;33m
BLUE		:=		\033[1;34m
CYAN 		:=		\033[1;36m
RM		    :=		rm -rf

all = $(NAME)

${NAME}:	${OBJS}
			@echo "$(BLUE)Generated $(NEW_OBJS) objects successfully ! ✔️"
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}binary ..."
			@${CC} $(FLAGS) -o $(NAME) $(OBJS)
			@echo "$(YELLOW)$(NAME) $(GREEN)binary created[0m ✔️"

clean:
	@if [ ! -e "$(OBJS_DIR)" ]; then echo "$(YELLOW)$(NAME) $(CLR_RMV)objects folder already $(RED)deleted $(CLR_RMV)! ✔️" ; else echo "$(RED)Deleted $(YELLOW)$(NAME) $(CLR_RMV)objects folder ✔️"; fi
			@${RM} $(OBJS_DIR)
			
fclean: 	clean
	@if [ ! -e "$(NAME)" ]; then echo "$(YELLOW)$(NAME) $(CLR_RMV)binary already $(RED)deleted $(CLR_RMV)! ✔️"; else echo "$(RED)Deleted $(YELLOW)$(NAME) $(CLR_RMV)binary ✔️"; fi
			@ ${RM} ${NAME}

re: 		fclean $(NAME)

.PHONY: clean fclean re all