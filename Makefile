CC = gcc

VPATH := util:gtkUI:build
OUTPUT_DIR = build
vpath $(OBJECTS) build

GUI_OBJECTS = gui.o main.o

RESOURCES_FILES = ui.xml menubar.xml style.css 

.PHONY : init
init:
	mkdir -p "build"

gui: init $(GUI_OBJECTS) resources.o
	$(CC) -o $(OUTPUT_DIR)/gui $(addprefix build/, $(GUI_OBJECTS)) build/resources.o `pkg-config --cflags gtk4` `pkg-config --libs gtk4`

$(GUI_OBJECTS): %.o: %.c
	$(CC) -c $< -o $(OUTPUT_DIR)/$@ `pkg-config --cflags gtk4` `pkg-config --libs gtk4`

gui-test: init gui
	cd build; ./gui


resources.c: resources.xml $(RESOURCES_FILES)
	cd gtkUI; glib-compile-resources resources.xml --target=resources.c --generate-source

resources.o: resources.c
	$(CC) -c gtkUI/$< -o $(OUTPUT_DIR)/$@ `pkg-config --cflags gtk4` `pkg-config --libs gtk4`

.PHONY : clean
clean:
	-rm -r $(OUTPUT_DIR)
	-rm *.datL
	-rm gtkUI/resources.c
