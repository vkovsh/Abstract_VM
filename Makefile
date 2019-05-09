NAME				=	avm

CC 					=	g++
CC_FLAGS			=	-std=gnu++11 -g

SRC_PATH			=	./srcs/
INC_PATH			=	./includes/
OBJ_PATH			=	./obj/

OBJ					=	$(addprefix $(OBJ_PATH),$(OBJ_NAME))

INC					=	$(addprefix -I, $(INC_PATH))

OBJ_NAME			=	$(SRC_NAME:.cpp=.o)

SRC_NAME			=	main.cpp			\
						Operand.cpp			\
						OperandFactory.cpp	\
						Double.cpp			\
						Float.cpp			\
						Int16.cpp			\
						Int32.cpp			\
						Int8.cpp

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(OBJ)
	@echo "Compiling" [ $(NAME) ]

$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CC_FLAGS) -o $@ -c $< $(INC)
	@echo "Linking" [ $< ]

clean:
	@rm -rf $(OBJ_PATH)
	@echo "Cleaning obj [ $(NAME) ]..."

fclean: clean
	@rm -f $(NAME)
	@echo "Remove [ $(NAME) ]..."

re: fclean all