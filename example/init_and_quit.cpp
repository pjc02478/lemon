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
  
  /* 시그널을 발생시켜 등록된 모든 종료 루틴을 처리시킨다 */
  on_quit.notify_all();
}
