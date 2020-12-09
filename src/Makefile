# Definition des constantes
CC = gcc
CFLAGS = -Wall
EXEC = Puzzle
LDFLAGS = -lMLV
OBJ = Main.o IGraph.o Plateau.o Melange.o Score.o Solve.o Menu.o


# Definition des commandes a effectuer
$(EXEC) : $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

Main.o : Main.c IGraph.h Plateau.h Melange.h Score.h Solve.h Menu.h

IGraph.o : IGraph.c IGraph.h Plateau.h Menu.h

Plateau.o : Plateau.c Plateau.h

Melange.o : Melange.c Melange.h Plateau.h

Score.o : Score.c Score.h Solve.h

Solve.o : Solve.c Solve.h Melange.h

Menu.o : Menu.c Menu.h

%.o : %.c
	$(CC) -c $< $(CFLAGS) $(LDFLAGS)


# Définition des commandes de nettoyage
clean :
	rm -f *.o

mrproper : clean
	rm -f $(EXEC)


# Définition des commandes à appeler
install : $(EXEC)
	mkdir ../bin
	mv $(EXEC) ../bin/$(EXEC)
	make mrproper

uninstall : mrproper
	rm -f ../bin/$(EXEC)
	rm -rf ../bin
