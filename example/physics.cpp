void process_physics(){
  int count = 0;
  for(auto obj : objs){
    /* long-running physics calculations
     * 충돌 검사, 힘 계산 등...
     */
    
    count ++;
    
    /* Defers remaning tasks to next frame */
    if(count % 10 == 0)
      flowcontrol::delay();
  }
}
