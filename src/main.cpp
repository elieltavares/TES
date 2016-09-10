#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

const char* Title = "";
const int SCREEN_W = 300;
const int SCREEN_h = 600;

int main(int arvc, char* argv[])
{
    SDL_Window* window = SDL_CreateWindow(
                                        Title,
                                        SDL_WINDOWPOS_UNDEFINED,
                                        SDL_WINDOWPOS_UNDEFINED,
                                        SCREEN_W,
                                        SCREEN_h,
                                        SDL_WINDOW_SHOWN
                                        );
    SDL_Renderer* renderer = SDL_CreateRenderer(
                                                window,
                                                -1,
                                                SDL_RENDERER_ACCELERATED
                                                );
    SDL_Event event;
    SDL_Surface* surface = IMG_Load("image.jpg");
    SDL_Texture* textura = SDL_CreateTextureFromSurface(renderer,surface);
    SDL_Rect rect;
    rect.x = 0;
    rect.y = 50;
    rect.w = 60;
    rect.h = 60;

    bool start = false;
        int num = 0;
    while(!start)
    {
        if(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
            {
                start = true;
            }
        }

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer,textura,NULL,NULL);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);


        for(int x = 0;x < 300;x+=60)
                SDL_RenderDrawLine(renderer,x,0,x,600);
        for(int x = 0;x < 600;x+=60)
                SDL_RenderDrawLine(renderer,0,x,300,x);


        SDL_SetRenderDrawColor(renderer, 0, 240, 240, 255);
        SDL_RenderFillRect(renderer, &rect);
        SDL_RenderDrawRect(renderer, &rect);





        num = num + 1;
        std::cout <<num<<std::endl;
        if(num == 50)
        {
            if(rect.y < 540){
            rect.y += 5;
            }
            num = 0;
        }

        switch(event.type)
        {
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    case SDLK_d:
                        if(rect.x < 240)
                        {
                        rect.x = rect.x + 60;
                        }
                        break;
                    case SDLK_a:
                        if(rect.x > 0)
                        {
                            rect.x = rect.x - 60;
                        }
                    case SDLK_s:
                        if(rect.y < 540)
                        {
                            rect.y += 5;
                        }
                        break;

                }
                break;
            case SDL_KEYUP:
                switch(event.key.keysym.sym)
                {
                    case SDLK_d:
                        rect.x = rect.x + 0;
                        break;
                }
                break;



        }


        SDL_RenderPresent(renderer);


    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_DestroyTexture(textura);
    SDL_FreeSurface(surface);


    return 0;
}
