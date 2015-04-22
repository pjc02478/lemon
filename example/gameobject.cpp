class game_object {
public:
  virtual void update();
  void schedule_update();
  
  void move_to(const time::unit &duration, float x,float y);
  
private:
  float x = 0, y = 0;
};

void game_object::schedule_update(){
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

void game_object(const time::unit &duration, float _x,float _y){
  int iters = duration.to_ms() / frame<60>(1).to_ms();
  float step_x = x - _x;
  float step_y = y - _y;
  
  for(int i=0;i<iters;i++){
    x += step_x;
    y += step_y;
    
    delay(time::frame<60>(1));
  }
}
