#include <iostream>
using namespace std;
#include "CircularDynamicArray.cpp"


int main(){
	CircularDynamicArray<float> C(10);
	for (int i=0; i< C.length();i++) C[i] = i;
	for (int i=0; i< C.length();i++) cout << C[i] << " ";  cout << endl;
	// C => "0 1 2 3 4 5 6 7 8 9"
    cout<<"----"<<endl;
	C.addEnd(10);
	for (int i=0; i< C.length();i++) cout << C[i] << " ";  cout << endl;
    cout<<"----"<<endl;
    C.addFront(11);
    for (int i=0; i< C.length();i++) cout << C[i] << " ";  cout << endl;
    cout<<"----"<<endl;
    C.addFront(12);
    for (int i=0; i< C.length();i++) cout << C[i] << " ";  cout << endl;
    cout<<"----"<<endl;
    C.addEnd(13);
    for (int i=0; i< C.length();i++) cout << C[i] << " ";  cout << endl;
    cout<<"----"<<endl;
    C.delEnd();
    for (int i=0; i< C.length();i++) cout << C[i] << " ";  cout << endl;
    cout<<"----"<<endl;
    C.delFront();
    for (int i=0; i< C.length();i++) cout << C[i] << " ";  cout << endl;
    cout<<"----"<<endl;
    C.delFront();
    for (int i=0; i< C.length();i++) cout << C[i] << " ";  cout << endl;
    cout<<"----"<<endl;
    C.delEnd();
    for (int i=0; i< C.length();i++) cout << C[i] << " ";  cout << endl;
    cout<<"----"<<endl;
    C.addFront(11);
    for (int i=0; i< C.length();i++) cout << C[i] << " ";  cout << endl;
    cout<<"----"<<endl;
    
    




    


}