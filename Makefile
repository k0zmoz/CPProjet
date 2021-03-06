CC = g++
CFLAGS := -std=c++11 -Wall -Wfatal-errors -c -ggdb -O0
LDFLAGS := -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
BIN = rpg
OBJ = main.o game.o character.o playable_char.o npc.o object.o arrow.o crystal.o map.o music_manager.o boss.o combat_manager.o button.o menu.o hud.o

all: .depend $(BIN)

$(BIN): $(OBJ)
	$(CC) $^ -o $@ $(LDFLAGS)

%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@

.depend: *.hpp *.cpp
	@echo -n > .depend
	@$(foreach obj,$(OBJ), g++ $(CFLGAS) -MM $(subst .o,.cpp,$(obj)) >> .depend;)

-include .depend

clean::
	rm -f $(OBJ) $(BIN) .depend
