SOURCES = $(wildcard $(C_REP)*.c)
OBJETS = $(SOURCES:.c=.o)
OBJETSC = $(patsubst $(C_REP)%.c, $(O_REP)%.o, $(SOURCES))

GREEN =\033[1;32m
BOLD =\033[1;38m
LBLUE =\033[1;34m
RED =\033[1;31m
NC =\033[0m #No color

O_REP = obj/
E_REP = bin/
C_REP = src/
H_REP = include/
D_REP = dist/
IFLAGS = -I include -W -Wall
VPATH = $(H_REP)
vpath %.o $(E_REP)
vpath %.c $(C_REP)
vpath %.h $(H_REP)
vpath main $(O_REP)


main : $(OBJETS)
	gcc -g -o $@ $(OBJETSC)
	mkdir -p $(E_REP)
	mv $@ $(E_REP)
	@echo  "\n\t\t$(BOLD)##============[$(GREEN)  Compilation SUCCESS  $(NC)$(BOLD)]=============##\n$(NC)\n"


%.o : %.c
	gcc -c $(IFLAGS) -o $@ $< 
	mkdir -p $(O_REP)
	mv $@ $(O_REP)


.PHONY : clean

	
clean:
	@echo  "\n\t\t$(BOLD)##============[$(GREEN)  Cleaning  $(LBLUE)$(O_REP), $(E_REP)  $(NC)$(BOLD)]=============##\n$(NC)\n"
	rm $(O_REP)* $(E_REP)*
	rmdir $(O_REP)
	rmdir $(E_REP)
	@echo  "\n\t\t$(BOLD)##============[$(GREEN)  Cleaning SUCCESS  $(NC)$(BOLD)]=============##\n$(NC)\n"

docs:
	doxygen Doxyfile


dist: 
	@mkdir -p dist
	tar -l -cvf dist/Etienne_KREBS.tar.xz src include makefile image Doxyfile
	@echo "\n ######## Archive créée ########\n$(NC)\n"
	

rmdist: 
		rm $(D_REP)*
		rmdir $(D_REP)
		@echo  "\n\t\t$(BOLD)##============[$(GREEN)  rmDist SUCCESS  $(NC)$(BOLD)]=============##\n$(NC)\n"

run:
	clear
	@echo  "\n\t\t$(BOLD)##============[$(GREEN)  Compiling $(LBLUE)$(E_REP)main  $(NC)$(BOLD)]=============##$(NC)\n"
	make
	@echo  "\n\t\t$(BOLD)##============[$(GREEN)  Running $(LBLUE)$(E_REP)main  $(NC)$(BOLD)]=============##$(NC)\n"
	./$(E_REP)main
	@echo  "\n\t\t$(BOLD)##============[$(GREEN)  Running $(LBLUE)$(E_REP)main $(GREEN)Done. $(NC)$(BOLD)]=============##\n$(NC)\n"