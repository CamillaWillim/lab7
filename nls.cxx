#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;



void Kvalues(double* K, double* y, const double a);



int main(){
  
  const double eta = 0.5;
  const int N = 1000;
  const double dx = 100.0/N;
  
  ofstream out("d2.txt");
  
  double y[2], k1[2], k2[2], k3[2], temp[2];
  
  y[0] = 1e-5;
  y[1] = sqrt(eta)*y[0];
  
 
  
  for(int i=0;i<N;i++){
   out << i*dx << "\t" << y[0] << "\t" << y[1] << endl;
    
    Kvalues(k1,y,eta);
    temp[0] = y[0]+(dx/2)*k1[0];
    temp[1] = y[1]+(dx/2)*k1[1];
    Kvalues(k2, temp ,eta);
    temp[0] = y[0]+dx*(2*k2[0]-k1[0]);
    temp[1] = y[1]+dx*(2*k2[1]-k1[1]);
    Kvalues(k3, temp, eta);
    
    y[0] = y[0] + (dx/6.0)*(k1[0]+4*k2[0]+k3[0]);
    y[1] = y[1] + (dx/6.0)*(k1[1]+4*k2[1]+k3[1]);
    
    
  }
    
  out.close();
  return 0;
  
}



void Kvalues(double* K, double* y, const double a){
 K[0] =  y[1];
 K[1] = (a-pow(y[0],2))*y[0];
 
}