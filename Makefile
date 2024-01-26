CC = gcc

VPATH := util:gtkUI:build
OUTPUT_DIR = build
vpath $(OBJECTS) build

OBJECTS = main.o
OBJECTS += utime.o diskio.o

GUI_OBJECTS = gui.o

.PHONY : init
init:
	mkdir -p "build"

main: init $(OBJECTS)
	$(CC) -o $(OUTPUT_DIR)/main $(addprefix build/, $(OBJECTS))

$(OBJECTS): %.o: %.c
	$(CC) -c $< -o $(OUTPUT_DIR)/$@

test: init main
	cd build; ./main

gui: init $(GUI_OBJECTS)
	$(CC) -o $(OUTPUT_DIR)/gui $(addprefix build/, $(GUI_OBJECTS)) `pkg-config --cflags gtk4` `pkg-config --libs gtk4`

$(GUI_OBJECTS): %.o: %.c
	$(CC) -c $< -o $(OUTPUT_DIR)/$@ `pkg-config --cflags gtk4` `pkg-config --libs gtk4`

gui-test: init gui
	cd build; ./gui

.PHONY : clean
clean:
	-rm -r $(OUTPUT_DIR)
	-rm *.datL
