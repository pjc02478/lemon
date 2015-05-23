example
====

* [Basic Concept](concept.cpp)<br>
  lemon의 가장 간단한 예제입니다.<br>
  delay함수를 사용해 전체 프로그램의 흐름을 멈추지 않고 함수의 진행 흐름을 일시적으로 멈추는 것을 보여줍니다.
* [GameObject 구현하기](gameobject.cpp)<br>
  게임 오브젝트에 사용되는 업데이트 스케쥴링과 액션을 어떻게 처리하는지 보여줍니다.
* [future](future.cpp)<br>
  future오브젝트를 이용해서 태스크가 반환한 값을 가져오거나, 태스크를 제어하는 법을 보여줍니다.
  * 이름 변경(?)
* [signal](signal.cpp)<br>
  signal오브젝트를 이용해서 특정 조건이 만족될 때 까지
  태스크를 대기시키는 방법을 보여줍니다.
  * 이름 변경(?)
* [init_and_quit](init_and_quit.cpp)<br>
  lemon을 사용해서 초기화와 정리 루틴을 한개의 함수에 직렬적으로 작성하는 방법을 보여줍니다.
