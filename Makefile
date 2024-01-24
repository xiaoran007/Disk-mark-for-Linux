CC = gcc

VPATH := util:build
OUTPUT_DIR = build
vpath $(OBJECTS) build

OBJECTS = main.o
OBJECTS += utime.o diskio.o

.PHONY : init
init:
	mkdir -p "build"

main: init $(OBJECTS)
	$(CC) -o $(OUTPUT_DIR)/main $(addprefix build/, $(OBJECTS))


$(OBJECTS): %.o: %.c
	$(CC) -c $< -o $(OUTPUT_DIR)/$@


.PHONY : clean
clean:
	-rm $(OUTPUT_DIR)/main $(OUTPUT_DIR)/*.o
