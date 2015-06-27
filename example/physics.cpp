void process_physics(){
  int count = 0;
  for(auto obj : objs){
    /* 물리 계산
     * 충돌 검사, 힘 계산 등...
     */
    
    count ++;
    
    /* 남은 작업은 다음 프레임에 처리한다 */
    if(count % 10 == 0)
      flowcontrol::delay();
  }
}
