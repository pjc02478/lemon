lemon::microthread::task
====

description
----

methods
----

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
