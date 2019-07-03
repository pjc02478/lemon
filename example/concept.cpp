#include <lemon.h>

using namespace lemon;

void func(){
  printf("begin func\n");
    delay(time::frame<60>(120)); /* Wait for 120 frames */
  printf("after 120 frames\n");
    delay(time::frame<60>(30)); /* Wait for 30 frames */
  printf("after 30 frames\n");
}
void render(){
  /* Prints `-` every single frame to show process is being rendered. */
  printf("-");
}

void main(){
  /* Create a new microtask and schedule it */
  auto &handle = microthread::create(func)
    .schedule();
  
  while(true){
    render();
    
    /* Should be called every frame */
    dispatcher::step();
    
    /* This makes the program rendered in 60fps */
    /* `Sleep` is a win32api */
    Sleep(time::frame<60>::mspf);
  }
}
