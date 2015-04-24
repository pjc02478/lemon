#include <lemon.h>

using namespace lemon;

void func(){
  printf("begin func\n");
    delay(time::frame<60>(120)); /* 120 프레임 대기 */
  printf("after 120 frames\n");
    delay(time::frame<60>(30)); /* 30 프레임 대기 */
  printf("after 30 frames\n");
}
void render(){
  /* 매 프레임마다 -를 출력하는것으로 렌더링을 대체 */
  printf("-");
}

void main(){
  /* 새로운 태스크를 만들고 실행 */
  auto t = microthread::task(func);
  t.schedule();
  
  while(true){
    render();
    
    /* 매 프레임마다 호출해주어야 한다 */
    dispatcher::step();
    
    /* 게임의 60fps를 시뮬레이트 */
    Sleep(time::frame<60>::mspf);
  }
}
