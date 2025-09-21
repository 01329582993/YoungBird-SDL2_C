#include "header.h"




bool isplaying = false;
bool ismenu = true;
bool isstart = false;
bool isabout = false;
bool issettings = false;

bool flap=false;

int frame = 0;
int BirdYpos;
int flyDistance ;
float t;


typedef struct
{
    SDL_Rect rect;
    SDL_Texture* normalTexture;
    SDL_Texture* hoverTexture;
    bool isHovered;
} Button;

typedef struct music{
    Mix_Music *backGround;
    Mix_Chunk *jump;
    Mix_Chunk *laser;
}music;





bool isPointInsideRect(int x, int y, SDL_Rect rect)
{
    return (x >= rect.x && x < rect.x + rect.w && y >= rect.y && y < rect.y + rect.h);
}


SDL_Texture* loadTexture(SDL_Renderer* renderer, const char* filePath)
{
    SDL_Surface* surface = IMG_Load(filePath);
    if (!surface)
    {
        printf("Failed to load image: %s\n", IMG_GetError());
        return NULL;
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}


void updateButtonState(Button* button, int mouseX, int mouseY)
{
    button->isHovered = isPointInsideRect(mouseX, mouseY, button->rect);
}







int main(int argc, char **argv)
{

    SDL_Init(SDL_INIT_VIDEO);
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_JPG|IMG_INIT_PNG);
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

    SDL_Window* window = SDL_CreateWindow("YOUNG BIRD", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WindowWidth, WindowHeight,  SDL_WINDOW_RESIZABLE);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_Texture* backgroundTexture = loadTexture(renderer, "C:/Users/HP/Desktop/Projets_CSE/project-0/Demo/src/frame_045.png");

    SDL_Texture* startNormalTexture = loadTexture(renderer, "C:/Users/HP/Desktop/Projets_CSE/project-0/Demo/src/frame_030.1.png");
    SDL_Texture* startHoverTexture = loadTexture(renderer, "C:/Users/HP/Desktop/Projets_CSE/project-0/Demo/src/frame_030.png");

    SDL_Texture* settingsNormalTexture = loadTexture(renderer, "C:/Users/HP/Desktop/Projets_CSE/project-0/Demo/src/frame_046.1.png");
    SDL_Texture* settingsHoverTexture = loadTexture(renderer, "C:/Users/HP/Desktop/Projets_CSE/project-0/Demo/src/frame_046.png");

    SDL_Texture* aboutNormalTexture = loadTexture(renderer, "C:/Users/HP/Desktop/Projets_CSE/project-0/Demo/src/frame_032.1.png");
    SDL_Texture* aboutHoverTexture = loadTexture(renderer, "C:/Users/HP/Desktop/Projets_CSE/project-0/Demo/src/frame_032.png");

    SDL_Texture* exitNormalTexture = loadTexture(renderer, "C:/Users/HP/Desktop/Projets_CSE/project-0/Demo/src/frame_031.1.png");
    SDL_Texture* exitHoverTexture = loadTexture(renderer, "C:/Users/HP/Desktop/Projets_CSE/project-0/Demo/src/frame_031.png");

    SDL_Texture* leftNormalTexture = loadTexture(renderer, "C:/Users/HP/Desktop/Projets_CSE/project-0/Demo/src/frame_051.png");
    SDL_Texture* leftHoverTexture = loadTexture(renderer, "C:/Users/HP/Desktop/Projets_CSE/project-0/Demo/src/frame_051.1.png");

    SDL_Texture* rightNormalTexture = loadTexture(renderer, "C:/Users/HP/Desktop/Projets_CSE/project-0/Demo/src/frame_050.png");
    SDL_Texture* rightHoverTexture = loadTexture(renderer, "C:/Users/HP/Desktop/Projets_CSE/project-0/Demo/src/frame_050.1.png");

    SDL_Texture* menuNormalTexture = loadTexture(renderer, "C:/Users/HP/Desktop/Projets_CSE/project-0/Demo/src/frame_028.png");
    SDL_Texture* menuHoverTexture = loadTexture(renderer, "C:/Users/HP/Desktop/Projets_CSE/project-0/Demo/src/frame_028.1.png");

    SDL_Texture* backNormalTexture = loadTexture(renderer, "C:/Users/HP/Desktop/Projets_CSE/project-0/Demo/src/frame_052.png");
    SDL_Texture* backHoverTexture = loadTexture(renderer, "C:/Users/HP/Desktop/Projets_CSE/project-0/Demo/src/frame_052.1.png");

    SDL_Texture* playNormalTexture = loadTexture(renderer, "C:/Users/HP/Desktop/Projets_CSE/project-0/Demo/src/frame_053.1.png");
    SDL_Texture* playHoverTexture = loadTexture(renderer, "C:/Users/HP/Desktop/Projets_CSE/project-0/Demo/src/frame_053.png");












    Button startButton;
    startButton.rect.x = 500;
    startButton.rect.y = 100;
    SDL_QueryTexture(startNormalTexture, NULL, NULL, &startButton.rect.w, &startButton.rect.h);
    startButton.normalTexture = startNormalTexture;
    startButton.hoverTexture = startHoverTexture;
    startButton.isHovered = false;

    Button settingsButton;
    settingsButton.rect.x = 460;
    settingsButton.rect.y = 200;
    SDL_QueryTexture(settingsNormalTexture, NULL, NULL, &settingsButton.rect.w, &settingsButton.rect.h);
    settingsButton.normalTexture = settingsNormalTexture;
    settingsButton.hoverTexture = settingsHoverTexture;
    settingsButton.isHovered = false;

    Button aboutButton;
    aboutButton.rect.x = 485;
    aboutButton.rect.y = 300;
    SDL_QueryTexture(aboutNormalTexture, NULL, NULL, &aboutButton.rect.w, &aboutButton.rect.h);
    aboutButton.normalTexture = aboutNormalTexture;
    aboutButton.hoverTexture = aboutHoverTexture;
    aboutButton.isHovered = false;

    Button exitButton;
    exitButton.rect.x = 530;
    exitButton.rect.y = 400;
    SDL_QueryTexture(exitNormalTexture, NULL, NULL, &exitButton.rect.w, &exitButton.rect.h);
    exitButton.normalTexture = exitNormalTexture;
    exitButton.hoverTexture = exitHoverTexture;
    exitButton.isHovered = false;


    Button leftButton;
    leftButton.rect.x = 257;
    leftButton.rect.y = 90;
    SDL_QueryTexture(leftNormalTexture, NULL, NULL, &leftButton.rect.w, &leftButton.rect.h);
    leftButton.normalTexture =  leftNormalTexture;
    leftButton.hoverTexture =  leftHoverTexture;
    leftButton.isHovered = false;


    Button rightButton;
    rightButton.rect.x = 903;
    rightButton.rect.y = 90;
    SDL_QueryTexture(rightNormalTexture, NULL, NULL, &rightButton.rect.w, &rightButton.rect.h);
    rightButton.normalTexture =  rightNormalTexture;
    rightButton.hoverTexture =  rightHoverTexture;
    rightButton.isHovered = false;

    Button menuButton;
    menuButton.rect.x = 10;
    menuButton.rect.y = 10;
    SDL_QueryTexture(menuNormalTexture, NULL, NULL, &menuButton.rect.w, &menuButton.rect.h);
    menuButton.normalTexture =  menuNormalTexture;
    menuButton.hoverTexture =  menuHoverTexture;
    menuButton.isHovered = false;

    Button backButton;
    backButton.rect.x = 10;
    backButton.rect.y = 30;
    SDL_QueryTexture(backNormalTexture, NULL, NULL, &backButton.rect.w, &backButton.rect.h);
    backButton.normalTexture =  backNormalTexture;
    backButton.hoverTexture =  backHoverTexture;
    backButton.isHovered = false;


    Button playButton;
    playButton.rect.x = 490;
    playButton.rect.y = 350;
    SDL_QueryTexture(playNormalTexture, NULL, NULL, &playButton.rect.w, &playButton.rect.h);
    playButton.normalTexture =  playNormalTexture;
    playButton.hoverTexture =  playHoverTexture;
    playButton.isHovered = false;





    music sound;
    sound.backGround=Mix_LoadMUS("C:/Users/HP/Desktop/Projets_CSE/project-0/Demo/src/sounds004.wav");
    sound.jump=Mix_LoadWAV("C:/Users/HP/Desktop/Projets_CSE/project-0/Demo/src/sounds002.wav");
    sound.laser=Mix_LoadWAV("C:/Users/HP/Desktop/Projets_CSE/project-0/Demo/src/sounds003.wav");
    bool quit = false;
    SDL_Event event;
    while (!quit)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                quit = true;
            }



            if (event.type == SDL_MOUSEMOTION)
            {
                int mouseX, mouseY;
                SDL_GetMouseState(&mouseX, &mouseY);
                updateButtonState(&startButton, mouseX, mouseY);
                updateButtonState(&settingsButton, mouseX, mouseY);
                updateButtonState(&aboutButton, mouseX, mouseY);
                updateButtonState(&exitButton, mouseX, mouseY);
                updateButtonState(&menuButton, mouseX, mouseY);
                updateButtonState(&backButton, mouseX, mouseY);
                updateButtonState(&leftButton, mouseX, mouseY);
                updateButtonState(&rightButton, mouseX, mouseY);
                updateButtonState(&playButton, mouseX, mouseY);

            }


            else if (event.type == SDL_MOUSEBUTTONDOWN)
            {
                int mouseX, mouseY;
                SDL_GetMouseState(&mouseX, &mouseY);




                if(ismenu){

                if (isPointInsideRect(mouseX, mouseY, startButton.rect))
                {
                    printf("Button clicked!\n");

                    isstart = true;
                    isabout = false;
                    ismenu = false;
                    issettings = false;
                   // isplaying = false;



                }

                else if (isPointInsideRect(mouseX, mouseY, settingsButton.rect))
                {
                    printf("Settings clicked");


                    issettings = true;
                    isstart = false ;
                    isabout = false;
                    ismenu = false;
                  //  isplaying = false;


                }

                else if (isPointInsideRect(mouseX, mouseY, aboutButton.rect))
                {
                    printf("About clicked");

                    isabout = true ;
                    isstart  = false;
                    ismenu = false;
                    issettings = false;
                   // isplaying = false;

                }

                else if (isPointInsideRect(mouseX, mouseY, exitButton.rect))
                {
                    printf("exit clicked");
                    return 1;


                }
            }

                if(isstart) {

                    if (isPointInsideRect(mouseX, mouseY, menuButton.rect))
                {
                    printf("menu cliked ");



                    isabout = false ;
                    isstart  = false;
                    ismenu = true;
                    issettings = false;
                  //  isplaying = false;


                }

                 else if (isPointInsideRect(mouseX, mouseY, leftButton.rect))
                {
                    printf("left button cliked ");

                    if(frame > 0)
                    {
                        frame --;
                    }

                }


                else if (isPointInsideRect(mouseX, mouseY, playButton.rect))
                {
                    printf("play button cliked ");

                    isabout = false ;
                    isstart  = false;
                    ismenu = false;
                    issettings = false;
                    isplaying = true;



                }

                 else if (isPointInsideRect(mouseX, mouseY, rightButton.rect))
                {
                    printf("right Button cliked ");

                    if(frame < 5)
                    {
                        frame ++;
                    }


                }
            }

                if(issettings || isabout){


                 if (isPointInsideRect(mouseX, mouseY, backButton.rect))
                {
                    printf("About clicked ");

                    isabout = false ;
                    isstart  = false;
                    ismenu = true;
                    issettings = false;
                    //isplaying = false;


                }


        }




        }
             if (event.type == SDL_MOUSEBUTTONUP)
            {
                int mouseX, mouseY;
                updateButtonState(&startButton, mouseX, mouseY);
                updateButtonState(&settingsButton, mouseX, mouseY);
                updateButtonState(&aboutButton, mouseX, mouseY);
                updateButtonState(&menuButton, mouseX, mouseY);
                updateButtonState(&leftButton, mouseX, mouseY);
                updateButtonState(&rightButton, mouseX, mouseY);

            }


        }


        if ( ismenu )
        {


            //SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderClear(renderer);


            SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);


            SDL_Texture* startButtonTexture = startButton.isHovered ? startButton.hoverTexture : startButton.normalTexture;
            SDL_RenderCopy(renderer, startButtonTexture, NULL, &startButton.rect);

            SDL_Texture* settingsButtonTexture = settingsButton.isHovered ? settingsButton.hoverTexture : settingsButton.normalTexture;
            SDL_RenderCopy(renderer, settingsButtonTexture, NULL, &settingsButton.rect);

            SDL_Texture* aboutButtonTexture = aboutButton.isHovered ? aboutButton.hoverTexture : aboutButton.normalTexture;
            SDL_RenderCopy(renderer, aboutButtonTexture, NULL, &aboutButton.rect);

            SDL_Texture* exitButtonTexture = exitButton.isHovered ? exitButton.hoverTexture : exitButton.normalTexture;
            SDL_RenderCopy(renderer, exitButtonTexture, NULL, &exitButton.rect);


            SDL_RenderPresent(renderer);
        }
        if(isabout)
        {
            about(renderer, window, backButton);
        }

        if(isstart)
        {
            SelectBird(renderer, window, leftButton, rightButton, menuButton, playButton, frame);
        }

        if(issettings)
        {
            Settings(renderer, window, backButton);

        }

        if(isplaying)
        {
           Mix_PlayMusic(sound.backGround,-1);
            if(event.type== SDL_KEYDOWN){
              if(event.key.keysym.sym==SDLK_SPACE){
                Mix_PlayChannel(1,sound.jump,0);

                Mix_PlayChannel(1,sound.laser,0);

                 flap=true;
                flyDistance=BirdYpos-80;
                t=0.4;
            }


        }
        printf("Yes");
        playing(renderer, window, &flap,&flyDistance, &BirdYpos, &t);


        }
    }


    // Clean up
    SDL_DestroyTexture(startNormalTexture);
    SDL_DestroyTexture(startHoverTexture);
    SDL_DestroyTexture(menuNormalTexture);
    SDL_DestroyTexture(menuHoverTexture);
    SDL_DestroyTexture(aboutNormalTexture);
    SDL_DestroyTexture(aboutHoverTexture);
    SDL_DestroyTexture(settingsNormalTexture);
    SDL_DestroyTexture(settingsHoverTexture);
    SDL_DestroyTexture(exitNormalTexture);
    SDL_DestroyTexture(exitHoverTexture);
    SDL_DestroyTexture(leftNormalTexture);
    SDL_DestroyTexture(leftHoverTexture);
    SDL_DestroyTexture(rightNormalTexture);
    SDL_DestroyTexture(rightHoverTexture);





    SDL_DestroyTexture(backgroundTexture);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;
}
