CC = clang 
INCLUDE = -I/Library/Frameworks/SDL.framework/Headers 
INCLUDE +=-I/Library/Frameworks/SDL_gfx.framework/Headers 
INCLUDE +=-I/Library/Frameworks/SDL_ttf.framework/Headers 
INCLUDE +=-I/Library/Frameworks/SDL_image.framework/Headers 
SOURCE = test3.c 
SOURCE +=SDLMain.m 
FRAMEWORK =-framework SDL 
FRAMEWORK +=-framework SDL_gfx 
FRAMEWORK +=-framework SDL_ttf 
FRAMEWORK +=-framework SDL_image 
FRAMEWORK +=-framework Cocoa 
BIN = test3

all: test3.c
	$(CC) $(INCLUDE) $(SOURCE) $(FRAMEWORK) -o $(BIN)

clean:
	rm -f $(BIN)
