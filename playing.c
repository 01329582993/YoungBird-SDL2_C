#include "header.h"





typedef struct music{
    Mix_Music *backGround;
    Mix_Chunk *jump;
    Mix_Chunk *laser;
}music;



int RandomObjectPosition(){
    int y=rand()%((600-210)+1)+210;
    return y;
}




void DisplayObject(bool *pipe1,bool *pipe2,bool *pipe3,bool *pipe4,bool *pipe5,bool continu,SDL_Rect *PipeDimg,SDL_Rect *PipeUimg,SDL_Rect *PipeDscr,SDL_Rect *PipeUscr,SDL_Texture *PipeDTexture,SDL_Texture *PipeUTexture,SDL_Renderer *renderer){
    int opening=200;
    int spacing=260;
    if(*pipe1){
        if(continu)
          PipeDscr[0].x--;
        PipeUscr[0].x=PipeDscr[0].x;
        if((PipeDscr[0].x+91)==WindowWidth-spacing){
            *pipe2=true;
            PipeDscr[1].y=RandomObjectPosition();
            PipeDscr[1].h= WindowHeight-PipeDscr[1].y;
            PipeDimg[1].h= PipeDscr[1].h;
            PipeUscr[1].h=PipeDscr[1].y-opening;
            PipeUimg[1].y=600-PipeUscr[1].h;
        }
        if(PipeDscr[0].x+91<0){
          *pipe1=false;
          PipeDscr[0].x=WindowWidth;
        }
        SDL_RenderCopy(renderer,PipeDTexture,&PipeDimg[0],&PipeDscr[0]);
        SDL_RenderCopy(renderer,PipeUTexture,&PipeUimg[0],&PipeUscr[0]);
    }
    if(*pipe2){
        if(continu)
           PipeDscr[1].x--;
        PipeUscr[1].x=PipeDscr[1].x;
        if((PipeDscr[1].x+91)==WindowWidth-spacing){
            *pipe3=true;
            PipeDscr[2].y=RandomObjectPosition();
            PipeDscr[2].h= WindowHeight-PipeDscr[2].y;
            PipeDimg[2].h= PipeDscr[2].h;
            PipeUscr[2].h=PipeDscr[2].y-opening;
            PipeUimg[2].y=600-PipeUscr[2].h;
        }
        if(PipeDscr[1].x+91<0){
          *pipe2=false;
          PipeDscr[1].x=WindowWidth;
        }
        SDL_RenderCopy(renderer,PipeDTexture,&PipeDimg[1],&PipeDscr[1]);
        SDL_RenderCopy(renderer,PipeUTexture,&PipeUimg[1],&PipeUscr[1]);
    }
    if(*pipe3){
        if(continu)
           PipeDscr[2].x--;
        PipeUscr[2].x=PipeDscr[2].x;
        if((PipeDscr[2].x+91)==WindowWidth-spacing){
            *pipe4=true;
            PipeDscr[3].y=RandomObjectPosition();
            PipeDscr[3].h= WindowHeight-PipeDscr[3].y;
            PipeDimg[3].h= PipeDscr[3].h;
            PipeUscr[3].h=PipeDscr[3].y-opening;
            PipeUimg[3].y=600-PipeUscr[3].h;
        }
        if(PipeDscr[2].x+91<0){
          *pipe3=false;
          PipeDscr[2].x=WindowWidth;
        }
        SDL_RenderCopy(renderer,PipeDTexture,&PipeDimg[2],&PipeDscr[2]);
        SDL_RenderCopy(renderer,PipeUTexture,&PipeUimg[2],&PipeUscr[2]);
    }
    if(*pipe4){
        if(continu)
           PipeDscr[3].x--;
        PipeUscr[3].x=PipeDscr[3].x;
        if((PipeDscr[3].x+91)==WindowWidth-spacing){
            *pipe5=true;
            PipeDscr[4].y=RandomObjectPosition();
            PipeDscr[4].h= WindowHeight-PipeDscr[4].y;
            PipeDimg[4].h= PipeDscr[4].h;
            PipeUscr[4].h=PipeDscr[4].y-opening;
            PipeUimg[4].y=600-PipeUscr[4].h;
        }
        if(PipeDscr[3].x+91<0){
          *pipe4=false;
          PipeDscr[3].x=WindowWidth;
        }
        SDL_RenderCopy(renderer,PipeDTexture,&PipeDimg[3],&PipeDscr[3]);
        SDL_RenderCopy(renderer,PipeUTexture,&PipeUimg[3],&PipeUscr[3]);
    }
    if(*pipe5){
        if(continu)
           PipeDscr[4].x--;
        PipeUscr[4].x=PipeDscr[4].x;
        if((PipeDscr[4].x+91)==WindowWidth-spacing){
            *pipe1=true;
            PipeDscr[0].y=RandomObjectPosition();
            PipeDscr[0].h= WindowHeight-PipeDscr[0].y;
            PipeDimg[0].h= PipeDscr[0].h;
            PipeUscr[0].h=PipeDscr[0].y-opening;
            PipeUimg[0].y=600-PipeUscr[0].h;
        }
        if(PipeDscr[4].x+91<0){
          *pipe5=false;
          PipeDscr[4].x=WindowWidth;
        }
        SDL_RenderCopy(renderer,PipeDTexture,&PipeDimg[4],&PipeDscr[4]);
        SDL_RenderCopy(renderer,PipeUTexture,&PipeUimg[4],&PipeUscr[4]);
    }
}






void InitializeValues(SDL_Rect *Backgroundimg,SDL_Rect *Backgroundscr,SDL_Rect *PipeDimg,SDL_Rect *PipeUimg,SDL_Rect *PipeUscr,SDL_Rect *PipeDscr,SDL_Rect *Birdimg,SDL_Rect *Birdscr){

    Backgroundimg->x=0;
    Backgroundimg->y=0;
    Backgroundimg->w=800;
    Backgroundimg->h=600;
    Backgroundscr->x=0;
    Backgroundscr->y=0;
    Backgroundscr->w=WindowWidth;
    Backgroundscr->h=WindowHeight;
    Birdscr->x=200;
    Birdscr->y=200;
    Birdscr->w=40;
    Birdscr->h=40;
    Birdimg->x=0;
    Birdimg->y=0;
    Birdimg->w=50;
    Birdimg->h=40;
    PipeDscr[0].y=400;
    PipeDscr[0].h= WindowHeight-PipeDscr[0].y;
    for(int i=0;i<5;i++){
        PipeDscr[i].x=WindowWidth;
        PipeDscr[i].w= 50;
    }
    PipeDimg[0].h=PipeDscr[0].h;
    for(int i=0;i<5;i++){
        PipeDimg[i].x=0;
        PipeDimg[i].y=0;
        PipeDimg[i].w= 91;
    }
    PipeUscr[0].h=PipeDscr[0].y-200;
    for(int i=0;i<5;i++){
        PipeUscr[i].x=WindowWidth;
        PipeUscr[i].y=0;
        PipeUscr[i].w= 50;
    }
    PipeUimg[0].y=PipeUscr[0].h;
    for(int i=0;i<5;i++){
        PipeUimg[i].x=0;
        PipeUimg[i].h=600;
        PipeUimg[i].w= 91;
    }
}




void destroy(SDL_Window *window,SDL_Renderer *renderer,SDL_Texture *BackgroundTexture,SDL_Texture *BirdTexture,SDL_Texture *PipeUTexture,SDL_Texture *PipeDTexture,music *sound){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyTexture(BackgroundTexture);
    SDL_DestroyTexture(BirdTexture);
    SDL_DestroyTexture(PipeDTexture);
    SDL_DestroyTexture(PipeUTexture);
    Mix_FreeChunk(sound->jump);
    Mix_FreeMusic(sound->backGround);
    Mix_FreeChunk(sound->laser);
}









char **CreateMask(const char* path) {
    SDL_Surface* image = IMG_Load(path);
    if (!image) {
        fprintf(stderr, "Unable to load image %s! SDL_image Error: %s\n", path, IMG_GetError());
        return NULL;
    }
    char **mask = (char**)malloc(image->h * sizeof(char*));
    if (!mask) {
        fprintf(stderr, "Failed to allocate memory for mask array!\n");
        SDL_FreeSurface(image);
        return NULL;
    }
    for (int i = 0; i < image->h; i++) {
        mask[i] = (char*)malloc(image->w * sizeof(char));
        if (!mask[i]) {
            fprintf(stderr, "Failed to allocate memory for mask row!\n");
            for (int j = 0; j < i; j++) {
                free(mask[j]);
            }
            free(mask);
            SDL_FreeSurface(image);
            return NULL;
        }
    }
    for (int i = 0; i < image->h; i++) {
        for (int j = 0; j < image->w; j++) {
            Uint32 pixel = *((Uint32*)image->pixels + i * image->pitch / sizeof(Uint32) + j);
            mask[i][j] = (pixel & 0xFF000000) != 0 ? '1' : '0';
        }
    }

    SDL_FreeSurface(image);

    return mask;
}

void FreeMask(char **mask,int height){
    for(int i=0;i<height;i++){
        free(mask[i]);
    }
    free(mask);
}





SDL_Texture* CreateTexture(SDL_Renderer* renderer, const char* path) {
    SDL_Surface* image = IMG_Load(path);
    if (!image) {
        fprintf(stderr, "Unable to load image %s! SDL_image Error: %s\n", path, IMG_GetError());
        return NULL;
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, image);
    if (!texture) {
        fprintf(stderr, "Unable to create texture from %s! SDL Error: %s\n", path, SDL_GetError());
        SDL_FreeSurface(image);
        return NULL;
    }
    SDL_FreeSurface(image);

    return texture;
}





void fall(SDL_Rect *Birdscr,float *t){
    Birdscr->y+=0.5*9.8**t**t;
}


void fly(SDL_Rect *Birdscr,float *t,int *flyDistance,bool *flap){
    Birdscr->y-=0.5*5*(1-*t);
    if(Birdscr->y<=*flyDistance){
        *flap=false;
        *t=0.4;
    }
}




//void poll(SDL_Event *events,bool *running,bool *flap,music sound,int *flyDistance,int BirdYpos,float *t ){
//    while(SDL_PollEvent(events)){
//        switch(events->type){
//        case SDL_QUIT:
//            *running=false;
//            return;
//            break;
//        case SDL_KEYDOWN:
//            if(events->key.keysym.sym==SDLK_ESCAPE){
//                *running=false;
//                return;
//            }
//            else if(events->key.keysym.sym==SDLK_SPACE){
//                Mix_PlayChannel(1,sound.jump,0);
//
//                Mix_PlayChannel(1,sound.laser,0);
//
//                *flap=true;    as
//                *flyDistance=BirdYpos-80;
//                *t=0.4;
//            }
//            break;
//        case SDL_WINDOWEVENT:
//            if(events->window.event==SDL_WINDOWEVENT_RESIZED){
//                //DONT KNOW
//            }
//            break;
//        default:
//            break;
//        }
//    }
//}
void clear(SDL_Renderer *renderer){
    SDL_SetRenderDrawColor(renderer,0,0,0,255);
    SDL_RenderClear(renderer);
}
bool BoundBoxCollision(SDL_Rect Birdscr, SDL_Rect *PipeUscr, SDL_Rect *PipeDscr) {
    bool collide=false;
    for(int i = 0; i < 5; i++) {
        int left1 = Birdscr.x;
        int right1 = Birdscr.x + Birdscr.w;
        int top1 = Birdscr.y;
        int bottom1 = Birdscr.y + Birdscr.h;

        int left2 = PipeDscr[i].x;
        int right2 = PipeDscr[i].x + PipeDscr[i].w;
        int top2 = PipeDscr[i].y;
        int bottom2 = PipeDscr[i].y + PipeDscr[i].h;

        int left3 = PipeUscr[i].x;
        int right3 = PipeUscr[i].x + PipeUscr[i].w;
        int top3 = PipeUscr[i].y;
        int bottom3 = PipeUscr[i].y + PipeUscr[i].h;

        if (!((bottom1 <= top2 || top1 >= bottom2 || right1 <= left2 || left1 >= right2) &&
            (bottom1 <= top3 || top1 >= bottom3 || right1 <= left3 || left1 >= right3))) {

          collide=true;
      }
    }
    return collide;
}




void run(SDL_Renderer *renderer,SDL_Rect Backgroundimg,SDL_Rect Backgroundscr,SDL_Rect *PipeDimg,SDL_Rect *PipeUimg,SDL_Rect *PipeUscr,SDL_Rect *PipeDscr,SDL_Texture *BackgroundTexture,SDL_Texture *PipeDTexture,SDL_Texture *PipeUTexture,SDL_Texture *BirdTexture,SDL_Rect Birdimg,SDL_Rect Birdscr,music sound, bool *flap,int *flyDistance, int *BirdYpos,float *t){
    int spritex[6]={0,51,51,0,51,51};
    int spritey[6]={0,0,41,41,41,0};

    int p=0;
    bool pipe1,pipe2,pipe3,pipe4,pipe5;
    bool continu=true;
    pipe1=true;
    pipe2=pipe3=pipe4=pipe5=false;
    float deltaT;
    Uint32 currentTime,prevTime;
    int time1=0;

    prevTime=SDL_GetTicks();

        clear(renderer);
       // poll(&events, &running,&flap,sound,&flyDistance,Birdscr.y,&t);
        currentTime=SDL_GetTicks();
        deltaT=(currentTime-prevTime)/1000.0f;
        prevTime=currentTime;
        if(BoundBoxCollision(Birdscr,PipeUscr,PipeDscr)){
            continu=false;
       }
        if(continu){
            *t+=deltaT;
            Uint32 time2=SDL_GetTicks();
            if(!*flap){
               fall(&Birdscr,t);

            }
            else{
               fly(&Birdscr,t,flyDistance,flap);

            }
            if(time2-time1>20){
               p++;
               time1=time2;
               if(p==6)
                 p=0;
               Birdimg.x=spritex[p];
               Birdimg.y=spritey[p];
            }


           Backgroundimg.x++;
           if(Backgroundimg.x+Backgroundimg.w>4800)
               Backgroundimg.x=0;
    }
    else{
        if(Birdscr.y<700)
        Birdscr.y++;

    }
    SDL_RenderCopy(renderer,BackgroundTexture,&Backgroundimg,&Backgroundscr);
    DisplayObject(&pipe1,&pipe2,&pipe3,&pipe4,&pipe5,continu,PipeDimg,PipeUimg,PipeDscr,PipeUscr,PipeDTexture,PipeUTexture,renderer);
    SDL_RenderCopy(renderer,BirdTexture,&Birdimg,&Birdscr);
    SDL_RenderPresent(renderer);
    SDL_Delay(1);


}






















void  playing(SDL_Renderer *renderer, SDL_Window *window, bool *flap, int *flyDistance, int *BirdYpos, float *t){
  printf("NO");

    SDL_RenderClear(renderer);

    srand(time(NULL));


    SDL_Rect Backgroundimg,Backgroundscr;
    SDL_Rect Birdimg,Birdscr;
    SDL_Rect PipeUimg[5],PipeUscr[5];
    SDL_Rect PipeDimg[5], PipeDscr[5];
    music sound;
    SDL_Texture *BackgroundTexture,*PipeDTexture=NULL,*PipeUTexture,*BirdTexture;

    BackgroundTexture=CreateTexture(renderer,"C:/Users/HP/Desktop/Projets_CSE/project-0/Demo/src/frame_061.png");
    PipeDTexture=CreateTexture(renderer,"C:/Users/HP/Desktop/Projets_CSE/project-0/Demo/src/frame_059.png");
    PipeUTexture=CreateTexture(renderer,"C:/Users/HP/Desktop/Projets_CSE/project-0/Demo/src/frame_058.png");
    BirdTexture=CreateTexture(renderer,"C:/Users/HP/Desktop/Projets_CSE/project-0/Demo/src/frame_060.png");
//    char **Birdmask=CreateMask("C:/Users/HP/Desktop/Projets_CSE/project-0/Demo/src/frame_060.png");
//    char **PipeUmask=CreateMask("C:/Users/HP/Desktop/Projets_CSE/project-0/Demo/src/frame_058.png");
//    char **PipeDmask=CreateMask("C:/Users/HP/Desktop/Projets_CSE/project-0/Demo/src/frame_059.png");
//    char BirdMaskFeame[4][40][50];


//    for(int i=0,l=0;i<40;i++,l++){
//            for(int j=0,m=0;j<50;j++,m++){
//                BirdMaskFeame[0][l][m]=Birdmask[i][j];
//            }
//    }
//
//
//     for(int i=41,l=0;i<=80;i++,l++){
//            for(int j=0,m=0;j<50;j++,m++){
//                BirdMaskFeame[3][l][m]=Birdmask[i][j];
//            }
//    }
//
//
//    for(int i=0,l=0;i<40;i++,l++){
//            for(int j=51,m=0;j<=100;j++,m++){
//               BirdMaskFeame[1][l][m]=Birdmask[i][j];
//            }
//    }
//
//     for(int i=41,l=0;i<=80;i++,l++){
//            for(int j=51,m=0;j<=100;j++,m++){
//                BirdMaskFeame[2][l][m]=Birdmask[i][j];
//            }
//    }

    InitializeValues(&Backgroundimg,&Backgroundscr,PipeDimg,PipeUimg,PipeUscr,PipeDscr,&Birdimg,&Birdscr);
    run(renderer,Backgroundimg,Backgroundscr,PipeDimg,PipeUimg,PipeUscr,PipeDscr,BackgroundTexture,PipeDTexture,PipeUTexture,BirdTexture,Birdimg,Birdscr,sound,flap,flyDistance,BirdYpos, t/*,PipeUmask,PipeDmask,bbb*/);
    //destroy(window,renderer,BackgroundTexture,BirdTexture,PipeUTexture,PipeDTexture,&sound);
//    for(int k=0;k<4;k++){
//    for(int i=0;i<40;i++){
//            for(int j=0;j<50;j++){
//                printf("%c",BirdMaskFeame[k][i][j]);
//            }
//            printf("\n");
//    }
//    printf("\n\n\n\n");
//    }
//    FreeMask(PipeUmask,601);
  //  FreeMask(PipeDmask,601);
  //  FreeMask(Birdmask,81);



}
