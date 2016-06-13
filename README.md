lemon
====

callback's flow
![callback1](imgs/callback1.png)
![callback2](imgs/callback2.png)<br>
lemon's
![lemon](imgs/lemon_flow.png)<br>
<br>
`lemon`은 C++에서 `코루틴/Fiber/Async&Await`등으로 불리는 기능을 사용할 수 있도록 해줍니다.<br>
(VS2015 이상 버전에서는 `await`기능을 실험적적으로 지원합니다. (https://github.com/pjc0247/c11url#with-__await-syntax))

todo
----
* [x] multithread::pool 구현
* [ ] concurrent_forward_list 구현
* [ ] dispatcher thread-safe 패치
* [ ] generator 구현

see
----
  * [docs](doc/)
  * [example](example/)

pros
----
* 코드의 흐름과 프로그램의 흐름을 동기화 할 수 있습니다.
 * 이전의 구현
 ```C++
 void pre_heavy_work(){
    printf("begin work\n");
   
    /* ... */

    work_pool.post_heavy_work();
 }
 void post_heavy_work(){
    printf("end work\n");
   
    /* ... */
   
    response();
 }
 ```
 * lemon을 이용하면
 
 ```C++
 void func(){
    printf("begin work\n");
      heavy_work();
    printf("end work\n");
    response();
 }
 ```
* 스케쥴링이 필요할 때, 별도의 스케쥴러가 필요없고 오브젝트 스스로가 자신을 스케쥴링 할 수 있도록 작성할 수 있습니다.

  ```C++
  void object::update(){
    printf("hello update!\n");
  }
  void object::schedule_update(){
    microthread::create([this](){
      while(true){
        flowcontrol::delay(time::frame<60>(1));
        update();
      }
    }).schedule();
  }
  ```
