lemon::microthread::task
====

description
----

methods
----
* schedule
* yield
* join
* stop
* get
* try_get

properties
----

usage
----
```C++

void func(){
  printf("hello task!\n");
  t->yield();
  printf("bye task!\n");
}
void main(){
  auto t = task(func);
  
  t.schedule(); /* hello task! */
  t.schedule(); /* bye task! */
}
```
