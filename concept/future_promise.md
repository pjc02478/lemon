```C++
promise<int> pr;

auto handle = multithread::create([&pr](){
  /* ... */
  pr.set_value(1234);
});

auto ft = pr.get_future();

cout<<ft.get();
```
