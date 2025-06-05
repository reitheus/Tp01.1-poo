# Variáveis
CC = g++
CFLAGS = -Wall -g 
EXEC = programa
SRC_DIR =  classes



SRCS = $(wildcard $(SRC_DIR)/*.c)


#regra padrão
all: $(EXEC)
	
# Regra de compilação
$(EXEC): $(SRCS)
	$(CC) -o $@ $^

# Regra de compilação dos objetos
$(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:	
	rm -f $(SRC_DIR)/*.o 
