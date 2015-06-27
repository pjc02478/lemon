void process_physics(){
  int count = 0;
  for(auto obj : objs){
    /* 물리 계산
     * 충돌 검사, 힘 계산 등...
     */
    
    count ++;
    
    if(count % 10 == 0)
      flowcontrol::delay();
  }
}
