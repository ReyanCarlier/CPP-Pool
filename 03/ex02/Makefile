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

OBJECT		=		0

$(OBJS_DIR)%.o	: %.cpp
				@c++ $(FLAGS) -c $< -I$(HEADS_DIR) -o $@
				@echo "$(GREEN)Generating $(CYAN)$@ $(CLR_RMV) ✔️";

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

${NAME}:	makedir_p ${OBJS}
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			@${CC} $(FLAGS) -o $(NAME) $(OBJS)
			@echo "$(YELLOW)$(NAME) $(GREEN)binary created[0m ✔️"

makedir_p:
	@if [ ! -e "$(OBJS_DIR)" ]; then mkdir -p $(OBJS_DIR); echo "$(GREEN)Creation ${CLR_RMV}of ${CYAN}objects ${CLR_RMV}directory ✔️"; else echo "${YELLOW}objects ${CLR_RMV}directory already exists ✔️"; fi
	@echo "$(GREEN)Creation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}objects..."

clean:
	@if [ ! -e "$(OBJS_DIR)" ]; then echo "$(YELLOW)$(NAME) $(CLR_RMV)objects folder already $(RED)deleted $(CLR_RMV)! ✔️" ; else echo "$(RED)Deleted $(YELLOW)$(NAME) $(CLR_RMV)objects folder ✔️"; fi
			@${RM} $(OBJS_DIR)
			
fclean: 	clean
	@if [ ! -e "$(NAME)" ]; then echo "$(YELLOW)$(NAME) $(CLR_RMV)binary already $(RED)deleted $(CLR_RMV)! ✔️"; else echo "$(RED)Deleted $(YELLOW)$(NAME) $(CLR_RMV)binary ✔️"; fi
			@ ${RM} ${NAME}

re: 		fclean $(NAME)

.PHONY: clean fclean re all