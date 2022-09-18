#include <iostream>
using namespace std;
#include "CircularDynamicArray.cpp"


int main(){
	CircularDynamicArray<int> A,B;
	for(int i=0; i<10;i++) A.addEnd(i);
	B = A;
    cout<<"A:"<<endl;
    for (int i=0; i< A.length();i++) cout << A[i] << " ";  cout << endl;
    cout<<"B:"<<endl;
    for (int i=0; i< B.length();i++) cout << B[i] << " ";  cout << endl;
	A.addEnd(15); A.addEnd(19);
    cout<<"A:"<<endl;
    for (int i=0; i< A.length();i++) cout << A[i] << " ";  cout << endl;
	// A => "0 1 2 3 4 5 6 7 8 9 15 19" 
	cout << "Select is " << A.linearSearch(5) << endl;
	// A => "0 1 2 3 4 5 6 7 8 9 15 19" Search => 5
	cout << "Select is " << A.binSearch(12) << endl;
	// A => "0 1 2 3 4 5 6 7 8 9 15 19" Search => -1
	cout << "Select is " << A.binSearch(15) << endl;
	// A => "0 1 2 3 4 5 6 7 8 9 15 19" Search => 10	
	A.addFront(10);
    cout<<"A:"<<endl;
    for (int i=0; i< A.length();i++) cout << A[i] << " ";  cout << endl; 
	// A => "10 0 1 2 3 4 5 6 7 8 9 15 19"
	cout << "Select is " << A.linearSearch(5) << endl;
	// A => "10 0 1 2 3 4 5 6 7 8 9 15 19" Search => 6
	A.stableSort();
    cout<<"A:"<<endl;
    for (int i=0; i< A.length();i++) cout << A[i] << " ";  cout << endl;
	// A => "0 1 2 3 4 5 6 7 8 9 10 15 19"
	A.addEnd(11); A.addFront(1); A.addFront(2);
	cout << "capacity is " << A.capacity() << endl;
    cout<<"A:"<<endl;
    for (int i=0; i< A.length();i++) cout << A[i] << " ";  cout << endl;
	// A => "3 2 1 0 1 2 3 4 5 6 7 8 9 10 15 19 11"	  capacity => 32
    A.addFront(3);
    cout << "capacity is " << A.capacity() << endl;
    cout<<"A:"<<endl;
    for (int i=0; i< A.length();i++) cout << A[i] << " ";  cout << endl;
	A.delFront(); A.delFront();
    cout<<"A:"<<endl;
    for (int i=0; i< A.length();i++) cout << A[i] << " ";  cout << endl;
	// A => "1 0 1 2 3 4 5 6 7 8 9 10 15 19 11"	  capacity => 32
    
    




    


}