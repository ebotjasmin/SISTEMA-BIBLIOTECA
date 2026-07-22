# ============================================
# SISTEMA DE BIBLIOTECA
# ============================================

# Compilador
CC = gcc

# Opções de compilação
CFLAGS = -Wall -Wextra -std=c11

# Nome do programa
TARGET = biblioteca

# Arquivos-fonte
SOURCES = main.c biblioteca.c

# Arquivos objeto
OBJECTS = main.o biblioteca.o


# ============================================
# REGRA PRINCIPAL
# ============================================

all: $(TARGET)


# ============================================
# LINKAGEM
# ============================================

$(TARGET): $(OBJECTS)

	$(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET)


# ============================================
# COMPILAÇÃO DE main.c
# ============================================

main.o: main.c biblioteca.h

	$(CC) $(CFLAGS) -c main.c


# ============================================
# COMPILAÇÃO DE biblioteca.c
# ============================================

biblioteca.o: biblioteca.c biblioteca.h

	$(CC) $(CFLAGS) -c biblioteca.c


# ============================================
# LIMPEZA
# ============================================

clean:

	rm -f $(OBJECTS) $(TARGET)