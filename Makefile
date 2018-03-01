# Cose del compilatore
CXX = g++
CFLAGS = -std=c++11 -g
# Oggetti
OBJ = obj/main.o obj/application.o obj/sdlApp.o
# Cartelle sorgenti e oggetti
OBJDIR = obj
SRCDIR = src
# File eseguibile
OUT = eseguibile.out

# Compile
$(OUT): $(OBJDIR) $(OBJ) $(OBJDIR)
	$(CXX) obj/main.o obj/application.o obj/sdlApp.o -lSDL2 -o $(OUT) $(CFLAGS)

# Compile and run
all: $(OUT) run

# Install as shared library
install: $(OBJDIR)
	$(CXX) src/sdlApp.cpp -c -fpic -o obj/sdlApp.o
	$(CXX) -shared -o /usr/lib/sdlApp.so obj/sdlApp.o


$(OBJDIR):
	mkdir -p $(OBJDIR)

.PHONY: run
run:
	./$(OUT)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $< -c -o $@ $(CFLAGS)

.PHONY: clean

clean:
	rm -rf $(OBJDIR)
	rm -rf $(OUT)

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
