#include "functions.h"

int fatt(int n){
  if (n <= 0) {
    return 1;
  }
  return n*fatt(n-1);
}
