#include <iostream>
#include <SDL.h>

int main(int argc, char *argv[])
{
    if(SDL_Init(SDL_INIT_VIDEO) != 0){
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow(
        "Learning SDL", SDL_WINDOWPOS_CENTERED, 
        SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN
    );
    
    if(!window) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        // Clean UP  (just quit)
        SDL_Quit();
        return 1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    
    if(!renderer) {
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        // Clean UP  (window and quit)
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    SDL_SetRenderDrawColor(renderer, 255, 78, 37, 255);

    // Main Loop
    bool running = true;
    SDL_Event event;
    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                running = false;
        }

        // Clear the screen
        SDL_RenderClear(renderer);

        // Present the Renderer
        SDL_RenderPresent(renderer);
    }

    // Clean UP  (renderer, window and quit)
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}