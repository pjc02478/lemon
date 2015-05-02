#include "lemon.h"
#include "lemon-http.h"

#include <string>

using namespace std;
using namespace lemon;

void http_test_func(){
  const string url = "www.google.com";
  
  auto body = http::request(url);
  
  cout<< body;
}

void main(){
  initialize();
  
  microthread::task(http_test_func)
    .schedule();
  
  whlie(true){
    dispatcher::step();
    
    Sleep(10);
  }
}
