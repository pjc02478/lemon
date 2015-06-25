```C++
void periodic_refresh(){
  while(true){
    string result = http::request(SOME_URI).get();
    
    update_ui(result);

    flowcontrol::delay(time::second(1));
  }
}

void main(){
  auto handle =
    microthread::create(periodic_refresh)
    .schedule();
   
  while(true){
    ui_loop();
  }
}
```