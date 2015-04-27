class game_object {
public:
  virtual void update();
  void schedule_update();
  
  void move_to(const time::unit &duration, float x,float y);
  
private:
  float x = 0, y = 0;
};

void game_object::schedule_update(){
  /* 단순히 while(true)를 돌면서 update를 호출하고 1프레임 대기하는것을 */
  /* 반복하는것만으로도 업데이트를 스케쥴링 할 수 있다. */
  microthread::task([this](){
    while(true){
      update();
      delay(time::frame<60>(1));
    }
  }).schedule();
}
void game_object::update(){
  printf("on update\n");
}

void game_object::move_to(const time::unit &duration, float _x,float _y){
  int iters = duration.to_ms() / frame<60>(1).to_ms();
  float step_x = (x - _x) / iters;
  float step_y = (y - _y) / iters;
  
  for(int i=0;i<iters;i++){
    x += step_x;
    y += step_y;
    
    delay(time::frame<60>(1));
  }
}

game_object obj;
void some_func(){
  /* 이제 매 프레임마다 obj.update()가 호출된다. */
  obj.schedule_update();
  
  printf("begin move_to\n");
    obj.move_to(time::second(1.6f), 40,40));
  printf("end move_to\n"); /* 이 명령은 1.6초동안 move_to가 끝난 후 실행된다 */
  
  printf("begin move_to async\n");
    /* 새 태스크를 만들어 async하게 처리한다 */
    microthread::task([&obj](){
      obj.move_to(time::second(2.0f), 50,50);
    }).schedule();
  printf("end move_to async\n"); /* 이 명령은 move_to의 완료와 관계 없이 바로 실행된다. */
}
