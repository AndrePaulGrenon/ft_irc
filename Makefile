###THIS PROJECT: FT_CONTAINER 

NAME = IRC #(Nom de L'exécutable)

###----------------####1.  VARIABLES####----------------------------------###

COM			= commands
CC			=	c++
FLAGS		=	-Wall -Wextra -Werror -std=c++98

SRCS		=	main.cpp Servers.cpp utility.cpp Users.cpp Channels.cpp Parser.cpp $(COM)/Pass.cpp $(COM)/User.cpp $(COM)/Nick.cpp \
				$(COM)/Topic.cpp 


HEADER_CON	=	
HEADER_TEM	=	
HEADER_ITE	=

PATH_CON	=	
PATH_TEM	=	
PATH_ITE	=	
				
OBJS		=	$(SRCS:.cpp=.o)

all		: 	$(NAME)

$(NAME)	:	$(OBJS)
			@$(CC) -o $(NAME) $(FLAGS) $(OBJS)
			@echo "\n\n\033[32;1m----- Ft_irc succesfully built -----\033[0;0m\n"

$(OBJS)	:	$(addprefix $(PATH_CON), $(HEADER_CON)) $(addprefix $(PATH_TEM), $(HEADER_TEM)) \
			$(addprefix $(PATH_ITE), $(HEADER_ITE))

clean	:	
				@rm -rf $(OBJS)
				@printf "\033[31;1mObjects removed\n\033[0;0m"

fclean	:	clean
				@rm -rf $(NAME)
				@printf "\033[31;1mExecutable removed\n\033[0;0m"

re		:	fclean all

.PHONY	:	all clean fclean re

%.o		:	%.cpp
			@$(CC) $(FLAGS) -o $@ -c $<
			@printf "\033[32;1mCompilation of $(NAME):\033[0;0m $(notdir $<)                             \r"
