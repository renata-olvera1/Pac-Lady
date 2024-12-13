# Directorios de origen y destino
SRC_DIR := src
BIN_DIR := bin
INCLUDE_DIR := include

# Compilador y opciones
CXX := g++
CXXFLAGS := -std=c++17 -Wall -I$(INCLUDE_DIR)
LDFLAGS := -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lbox2d

# Archivos fuente y objetos
CPP_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(CPP_FILES:.cpp=.o)
EXE_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(BIN_DIR)/%.exe,$(CPP_FILES))

# Regla por defecto para compilar todos los archivos .cpp y generar los archivos .exe
all: $(EXE_FILES)

# Regla para compilar cada archivo .cpp y generar el archivo .exe correspondiente
$(BIN_DIR)/%.exe: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) $< -o $@ $(LDFLAGS)

# Regla para compilar archivos .cpp a .o
$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regla para ejecutar cada archivo .exe
run%: $(BIN_DIR)/%.exe
	./$<

# Regla para limpiar los archivos generados
clean:
	rm -f $(OBJ_FILES) $(EXE_FILES)

.PHONY: all clean
.PHONY: run-%
