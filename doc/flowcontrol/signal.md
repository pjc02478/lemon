lemon::flowcontrol::signal
====

usage
----
```C++
flowcontrol::signal s;

void func(microthread::task *t){
  printf("begin func\n");
    delay_until(s);
  printf("end func\n");
}
void main(){
  /* ... */
  
  while(true){
    int ch = _getch();
    
    if(ch == 'a')
      s.notify_one();
  }
}
```
