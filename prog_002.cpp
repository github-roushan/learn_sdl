#include <iostream>
#include <SDL.h>

class SDLManager
{
    int width, height;
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Surface *surface;

public:
    SDLManager(int w, int h) : width(w), height(h)
    {
        if (SDL_Init(SDL_INIT_VIDEO) != 0) {
            std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
            exit(1);
        }

        window = SDL_CreateWindow(
            "Manager", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
            width, height, SDL_WINDOW_SHOWN
        );

        if(!window) {
            std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
            SDL_Quit();
            exit(1);
        }

        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        
        if(!renderer) {
            std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
            SDL_DestroyWindow(window);
            SDL_Quit();
            exit(1);
        }
    }

    ~SDLManager() {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }

    // Member function to overload operator<<
    friend std::ostream &operator<<(std::ostream &os, const SDLManager &sdl) {
        os << "[SDL Window] Width: " << sdl.width << ", Height: " << sdl.height;
        return os;
    }

    void draw() {
        SDL_SetRenderDrawColor(renderer, 0, 255, 123, 21);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    }
};

int main()
{
    SDLManager manager(800, 600);
    std::cout << manager << std::endl;

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