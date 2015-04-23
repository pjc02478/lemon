lemon::flowcontrol::signal
====

description
----
signal 오브젝트를 이용하면 다른 태스크로부터 신호가 올 때까지
현재 태스크를 대기 상태로 전환시키고, 신호가 온 이후부터 로직을 처리하도록
할 수 있습니다.

methods
----
* __notify_one__
* __notify_all__

properties
----

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
