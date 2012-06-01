#include <iostream>

int main()
{
  bool a = false;
  int b = 2;
  bool c = true;
  if (a && (b || c))
    printf("ok\n");
  else 
    printf("fail\n");
  return 0;
}

