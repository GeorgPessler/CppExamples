int main(){

  int mut=0;
  auto mutableLambda= [=]() mutable {mut= 5;};
  // auto mutableLambda= [=]{mut= 5;};
  mutableLambda();

}
