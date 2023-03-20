##
## EPITECH PROJECT, 2022
## Project Plazza
## File description:
## Makefile
##

CXX			=	g++

SRC_POJECT	=	src/Lib.cpp				\
				src/Plazza.cpp			\
				src/ParseParams.cpp		\
				src/Kitchen/Kitchen.cpp	\
				src/Kitchen/TreatCommand.cpp	\
				src/Cook.cpp			\
				src/IPC.cpp				\
				src/Display.cpp			\
				src/Pizza/Americana.cpp	\
				src/Pizza/Fantasia.cpp	\
				src/Pizza/Margarita.cpp	\
				src/Pizza/Regina.cpp	\
				src/Reception/Reception.cpp		\
				src/Reception/Communication.cpp		\
				src/Parser/CommandParsing.cpp		\
				src/SelectI.cpp			\
				src/Prompt.cpp

SRC			=	main.cpp				\
				$(SRC_POJECT)			\

SRC_TEST	=	tests/unit_test_lib.cpp	\
				tests/unit_test_parse_params.cpp\
				tests/unit_test_plazza.cpp\
				tests/unit_test_reception.cpp\
				tests/unit_test_kitchen.cpp\
				$(SRC_POJECT)			\

OBJ			=	$(SRC:.cpp=.o)

NAME		=	plazza

NAME_TEST	=	unit_test

CXXFLAGS	=	-o $(NAME)			\
				-iquote ./include	\
				-lpthread\

LDFLAGS		+=	--coverage -lcriterion

all:			$(NAME)

debug:			CXXFLAGS +=	-g
debug:			$(NAME)

$(NAME):		$(OBJ)
				$(CXX) $(CXXFLAGS) $(OBJ)

clean:
				$(RM) $(OBJ)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

tclean:
	$(RM) $(NAME_TEST)
	$(RM) *.gcno
	$(RM) *.gcda

tests_run:		$(SRC_TEST)
				$(CXX) $(CXXFLAGS) -o $(NAME_TEST) $(SRC_TEST) $(LDFLAGS)
				./$(NAME_TEST)
				gcovr
				$(RM) *.gcno
				$(RM) *.gcda

.PHONY:			all clean fclean re debug tests_run tclean