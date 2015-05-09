lemon::multithread::pool
====

description
----

static methods
----
* __set_max_workers__
  스레드 풀에서 사용할 최대 worker갯수를 지정합니다.<br>
  기본적으로는 core * 2입니다.
* lock
* unlock

usage
----
```C++
multithread::pool::set_max_workers(
  std::thread::hardware_concurrency() * 2);
```
