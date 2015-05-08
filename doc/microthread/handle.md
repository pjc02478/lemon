lemon::microthread::handle
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
  /* ... */
  printf("bye task!\n");
}
void main(){
  microthread::handle &h =
    microthread::create(func);
  
  h.schedule(); /* hello task! */
  h.schedule(); /* bye task! */
}
```
