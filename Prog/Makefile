NAME = fillit

CC = gcc

FLAG = -c -Wall -Werror -Wextra

SRC = checktetri.c complete_strsub.c main.c resolvetetris.c useful.c \
	  usefulmove.c usefultetri.c

OBJ = checktetri.o complete_strsub.o main.o resolvetetris.o useful.o \
	  usefulmove.o usefultetri.o

OBJ2 = header.h.gch ref_mino.h.gch

HDR = header.h ref_mino.h

RM = rm -f

all: $(NAME)

$(NAME):
	@$(CC) $(FLAG) $(SRC) $(HDR)
	@$(CC) $(OBJ) -o $(NAME)

clean:
	@$(RM) $(OBJ) $(OBJ2)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
