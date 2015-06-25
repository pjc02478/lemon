```C++
multithread::create([](){
  printf("worker thread\n");

  dispatcher::main_thread::dispatch([](){
    printf("main thread\n");
  });
});
```
