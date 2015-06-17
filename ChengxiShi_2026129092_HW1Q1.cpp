#include <iostream>
#define EPSILON 0.0000001
using namespace std;

double mySqrt(double x); // eg. mySqrt(4) will return 2

int main() {
  double s = mySqrt(5);
  cout << s << endl; // expect 2.236
  return 0;
}// main()

double mySqrt(double x){
    if (x==0)
        return 0;
    if (x<0)
        return NULL;
    double temp=1, prev = 1;
    do{
        prev = temp;
        temp = 0.5*(prev + x/prev);
    }while(temp - prev > EPSILON || prev - temp > EPSILON);
    return temp;
}
