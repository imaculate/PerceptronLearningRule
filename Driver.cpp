#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <vector>
using namespace std;
double n = 0.01;
static double EPS = 0.00 ; //very small equaivalent to zero for floating point operations

double apply(double* p, double in1, double in2, double in3, double in4){
   double t = (in1 * p[0]) + (in2*p[1]) +(in3*p[2])+ (in4*p[3])+ p[4];
   if(t>0)
      return 1;
   
      return -1;
     
   
  
}
void  train(double* p, double in1, double in2, double in3, double in4,double error){
//threshold is the weight w0 with constant input w0.
    
  
   p[0] = p[0]+ (n* error* in1);
   p[1] = p[1]+ (n* error* in2);
   p[2] = p[2]+ (n* error* in3);
   p[3] = p[3]+ (n* error* in4);
   p[4] = p[4]+ (n* error);
   
    

    
}



void train(double* p, string filename){

   ifstream myfile(filename.c_str());
  
   vector<double> v;
   string line;
   double a, b,c,d;
   int   out;
   
   if (myfile.is_open()) {
  
      while(getline(myfile, line)){
         stringstream ss(line);
         ss>> a>>b>>c>>d>>out;
         v.push_back(a);v.push_back(b);v.push_back(c);v.push_back(d);v.push_back(out);
      }
       myfile.close();
   }
  
   
   //perceptron training rule
   int iterations= 0;
 int nSamples = (v.size())/5;
   while(true){
      iterations++;
      double error = 0; 
       
       double out[nSamples];
      for(int i = 0; i< nSamples ; i++){
         double o = apply(p, v.at(i*5), v.at((i*5) + 1), v.at((i*5) +2), v.at((i*5) +3) );
         
         out[i] = o;
          
                  
      }
      double data_error;
      for(int i = 0; i< nSamples ; i++){
         data_error =  v.at((i*5) +4) - out[i];
         train(p,v.at(i*5), v.at((i*5) + 1), v.at((i*5) +2), v.at((i*5) +3) ,data_error);

         error+= (data_error * data_error/2.0); 
         
                  
      }

      
      
      
      if(abs(error)<=EPS)
         break;
         
      
   }
   cout << "It took "<< iterations <<" iterations to converge to minimum error"<<endl;

   
}
int main(){
  
   
   
  //each array represents a perceptron with elements weight1, weight2 and bias respectively
   double p1[5] = {0.0,0.0, 0.0, 0.0, 0.0};
  

    
   train(p1, "data.txt");
   
 
   
 
    
   
      
   cout<<"The perceptron p1 has weights "<< p1[0] <<" , " <<p1[1] <<" , " <<p1[2]<<" , " <<p1[3] <<" and bias " << p1[4]<<endl;

   
   /*vector<double> test;
   test.push_back(1.0); test.push_back(1.0);test.push_back(0.0);
   test.push_back(1.0); test.push_back(0.0);test.push_back(1.0);
   test.push_back(0.0); test.push_back(1.0);test.push_back(1.0);
   test.push_back(0.0); test.push_back(0.0);test.push_back(0.0);
   for(int i =0 ; i< test.size()/3; i++){
      int or_output = apply(p1,test[3*i], test[(3*i)+1]);  
       int nand_output = apply(p2,test[3*i], test[(3*i)+1]); 
      int xor_output = apply(p3,or_output, nand_output);
       
      if(xor_output ==(int)test.at(2)){
         cout<<"Correct!"<<endl;
      }
      else{
         cout<<"Incorrect!"<<endl;
      }  
   }*/
   
   
   
}

