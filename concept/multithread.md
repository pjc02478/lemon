```C++
auto handle = multithread::create([](){
  return http::request("www.naver.com");
});

cout<<handle.get();
```