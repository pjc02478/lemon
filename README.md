lemon
====

see
----
  * [docs](doc/)
  * [example](example/)

pros
----
* 코드의 흐름과 프로그램의 흐름을 동기화 할 수 있습니다.
* 스케쥴링이 필요할 때, 별도의 스케쥴러가 필요없고 오브젝트 스스로가 자신을 스케쥴링 할 수 있도록 작성할 수 있습니다.

  ```C++
  void object::update(){
    printf("hello update!\n");
  }
  void object::schedule_update(){
    microthread::task([this](microthread::task *t){
      while(true){
        delay(frame<60>(1));
        update();
      }
    }).schedule();
  }
  ```
