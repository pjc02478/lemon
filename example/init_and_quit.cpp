#include "lemon.h"

flowcontrol::signal on_quit;

void videosystem(){
  SDL_Init();
  SDL_CreateRenderer( ... );
    delay_until(on_quit);
  SDL_DestroyRenderer( ... );
  SDL_Quit();
}
void soundsystem(){
  MCI_Init();
    delay_until(on_quit);
  MCI_Quit();
}

void main(){
  microthread::create(videosystem);
  microthread::create(soundsystem);
  
  while(!quit){
    /* game loop */
  }
  
  /* Notifies to execute all pending destruction routines. */
  on_quit.notify_all();
}
