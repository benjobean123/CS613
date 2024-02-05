#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;


int main()
{
    //declare constants
    string line; 
    int MSize = 512; //matrix size
    cout << "Writing random matrix1 values" << endl;
    ofstream matrix1Write;
    matrix1Write.open("matrix1.txt");
    matrix1Write << to_string(MSize) << endl;
    int sign;
    for(int i=0; i<MSize; i++){
        for(int j=0; j<MSize; j++){
            sign = rand() % 2;
            if(sign==0){
                matrix1Write << to_string(rand() % 11 + (-10)) <<',';
            }
            else if (sign==1){
                 matrix1Write << to_string(rand() % 11) <<',';
            }
            else{
                cout << "if statment broke" << endl;
                break;
            }
            
            
        }
        matrix1Write << endl;
    }
    matrix1Write.close();

    cout << "Writing random matrix2 values" << endl;
    ofstream matrix2Write;
    matrix2Write.open("matrix2.txt");
    matrix2Write << to_string(MSize) << endl;
    for(int i=0; i<MSize; i++){
        for(int j=0; j<MSize; j++){
            sign = rand() % 2;
            if(sign==0){
                matrix2Write << to_string(rand() % 11 + (-10)) <<',';
            }
            else if (sign==1){
                 matrix2Write << to_string(rand() % 11) <<',';
            }
            else{
                cout << "if statment broke" << endl;
                break;
            }
            
            
        }
        matrix2Write << endl;
    }
    matrix2Write.close();
    return 0;
}
