#OBJS specifies which files to compile as part of the project
OBJS = loop.c game.c

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = out

#This is the target that compiles our executable
all : $(OBJS)
	gcc $(OBJS) -I./SDL2 -w -g -lm -lSDL2main -lSDL2 -o $(OBJ_NAME)
	@ls -l | grep $(OBJ_NAME)
