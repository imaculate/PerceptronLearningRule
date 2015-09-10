Author: Imaculate Mosha

Date: 28th August 2015
Name: Artificial Neural Network Perceptron training with 2 activation functions .


Description: 
This assignment is written to in responce to Lab 3 of Machine Learning.  

Instructions: Extract the tar file. Navigate to the destination folder from the command line. 
Enter "make"
Run  the command "Driver"
As per instruction:
"Enter L/l for linear or T/t for threshold activation"

Follow the instruction for the respective activation function.
The output will be reproduced in 'output.txt'
 
	 

List of files: 
Driver.cpp  - source code
Training data files
data.txt

Output files
From prior runs
output-linear.txt
output-threshold.txt

For reproduced run
output.txt

Answers to Questions:
Question 1: How many iterations of the percep-
tron learning rule does it take before an error = 0 is achieved?
For a linear activation function it took 2815 iterations to converge to minimum error

Question 2: Change the activation function to a threshold function and re-
run the perceptron learning rule. Is an error = 0 achieved in the same number
of iterations? 
The minimum error is obtained in 6 iterations. The threshold function converges in 
fewer iterations because the threshold function has a steeper curve at the step than the linear function, making the partial
derivatives hence faster convergence . 



 