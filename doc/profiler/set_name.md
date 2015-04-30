lemon::profiler::set_name
====

description
----
태스크에 이름을 설정합니다.<br>
이 이름은 프로파일러의 결과에서 태스크를 식별하기 쉽게 하기 위해서 사용됩니다.<br>
__NAME(x) 매크로 사용을 권장합니다

args
----
* __const std::string &name__<br>
  설정할 이름

usage
----
```C++
__NAME("hello-task")
microthread::task([](){
  printf("hello world!\n");
});
```
