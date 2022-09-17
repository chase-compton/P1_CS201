#include <iostream>
using namespace std;
#include "CircularDynamicArray.cpp"


int main(){
    CircularDynamicArray<float> C(10);
	for (int i=0; i< C.length();i++) C[i] = i;
	for (int i=0; i< C.length();i++) cout << C[i] << " ";  cout << endl;
    C.addEnd(300.0);
	C.addEnd(400.0);
    for (int i=0; i< C.length();i++) cout << C[i] << " ";  cout << endl;
    cout<<"----"<<endl;
    cout<<C[5]<<endl;
}