lemon::multithread::pool
====

description
----

static methods
----
* set_max_workers

usage
----
```C++
multithread::pool::set_max_workers(
  std::thread::hardware_concurrency() * 2);
```
