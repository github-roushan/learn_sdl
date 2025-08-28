#include<SDL.h>
#include<iostream>

class SDLManager{
private:
    int width, height;
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Surface *surface;
public:
    SDLManager(int w, int h) {
        width = w; height = h;
        if(SDL_Init(SDL_INIT_VIDEO) != 0) {
            std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
            exit(1);
        }
        window = SDL_CreateWindow(
            "Sample App", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
            width, height, SDL_WINDOW_SHOWN
        );

        if(!window) {
            std::cerr << "[Fatal] SDL window couldn't be created" << std::endl;
        }

        surface = SDL_GetWindowSurface(window);
        SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0xFF, 0x20, 0xFF));
        SDL_UpdateWindowSurface( window );

        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );

        SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    }

    ~SDLManager() {
        SDL_DestroyRenderer(renderer);
        SDL_FreeSurface(surface);
        SDL_DestroyWindow(window);

        SDL_Quit();
    }
    
    void draw() {

    }
};


int main()
{
    SDLManager manager(800, 600);

    bool game_running = true;
    while (game_running)
    {
        SDL_Event e;

        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT || e.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
            {
                game_running = false;
            }
        }
        manager.draw();
    }
    return 0;
}