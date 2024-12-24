PLUGIN_NAME = calculator
SRC = calculator.c
# SRCの'.c'を'.o'に置換
OBJ = $(SRC:.c=.o) 

all: lib$(PLUGIN_NAME).so

lib$(PLUGIN_NAME).so: $(OBJ)
	gcc -shared -o lib$(PLUGIN_NAME).so $(OBJ)

%.o: %.c
	gcc -fPIC -c $< -o $@

clean:
	rm -f $(OBJ) lib$(PLUGIN_NAME).so
