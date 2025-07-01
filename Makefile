# Variáveis
CC = g++
CFLAGS = -Wall -g
EXEC = programa
SRC_DIR  = classes
SRCS = $(wildcard $(SRC_DIR)/*.cpp)

# Regras
all: $(EXEC)

$(EXEC): $(SRCS)
	$(CC) -o $@ $^

$(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(SRC_DIR)/*.o