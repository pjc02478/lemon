auto f = microthread::task<int>([](){
  delay(time::second(2.0f));
  return 1234;
}).schedule();

/* join : 태스크가 완전히 종료될때까지 대기합니다.
 *        join명령도 delay와 같이 전체 흐름을 블럭하지 않습니다. */
f.join();

/* try acquire : 값을 가져올 수 있는 상태면 가져오고
 *               그렇지 않은 경우 false를 리턴합니다. */
f.try_get(dst);

/* join & acquire : 값을 가져올 수 있는 상태면 가져오고
 *                  그렇지 않은 경우 join을 수행하여 대기한 후 가져옵니다. */
cout<< f.get();

/* stop : 현재 실행중인 태스크를 정지합니다. */
f.stop();
