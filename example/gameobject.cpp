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
  float step_x = x - _x;
  float step_y = y - _y;
  
  for(int i=0;i<iters;i++){
    x += step_x;
    y += step_y;
    
    delay(time::frame<60>(1));
  }
}