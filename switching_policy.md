* policies
  * dispatcher::binding_policy::bind_current
    작업 이후 반드시 현재 스레드에 바인딩된다
  * dispatcher::binding_policy::bind_any_worker
    작업 이후 아무 워커 스레드에 바인딩된다
  * dispatcher::binding_policy::bind_main
    작업 이후 반드시 메인 스레드에 바인딩된다

* main thread<br>
 디폴트 : current
  
* worker thread<br>
 디폴트 : any_worker

```C++
dispatcher::current_dispatcher::set_binding_policy(
  dispatcher::binding_policy::bind_any_worker);

printf("hello\n");
flowcontrol::delay(time::second(1.5f));
printf("world\n");
```

실험실
----
* yield를 통한 강제 실행 컨텍스트 변경
```C++
/* main thread */
string result;

dispatcher::current_dispatcher::set_binding_policy(
  dispatcher::binding_policy::bind_any_worker);
flowcontrol::yield();

/* worker thread*/
result = http::request("www.naver.com");

dispatcher::current_dispatcher::set_binding_policy(
  dispatcher::binding_policy::bind_main);
flowcontrol::yield();

/* main thread*/
cout<<result;
```
