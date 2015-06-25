```C++
/* main thread */
string result;

dispatcher::switch_to_worker();
  result = http::request("www.naver.com");
dispatcher::switch_to_main();

cout<<result;
```