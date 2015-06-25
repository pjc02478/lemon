```C++
stream<int> producer(){
  return microthread::create_stream([](generator<int> g){
    for(int i=0;i<5;i++){
      g.produce(i);

      flowcontrol::delay(time::second(1));
    } 
  });
}

void main(){
  for(int v : producer()){
    cout<<v;
  }
}
```