#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    string filename = "matrix1.txt";
    string line;
    //open matrix file
    ifstream matrix1Read;

    matrix1Read.open(filename);
    getline(matrix1Read, line);
    int MSize = stoi(line);
    // int myMatrix1[MSize][MSize];
    int i=0;
    int* bla[MSize];
    for(i=0; i<MSize; i++){
        bla[i]=new int[MSize];
    }
    int* myMatrix1[MSize];
    for(i=0; i<MSize; i++){
        myMatrix1[i]=new int[MSize];
    }
    int j=0;
    
    while(getline(matrix1Read, line)){
        istringstream matrix1Line(line);
        string matrix1Value;
        while (getline(matrix1Line, matrix1Value, ','))
        {
            myMatrix1[i][j] = stoi(matrix1Value); //place values in matrix
            j++;
        }
        j=0;
        i++;
    }
    string filename2 = "matrix2.txt";
    //open matrix file
    ifstream matrix2Read;
    matrix1Read.close();

    matrix2Read.open(filename2);
    getline(matrix2Read, line);
    int MSize2 = stoi(line);
    cout<<MSize2<<endl;
    int* myMatrix2[MSize2];
    for(i=0; i<MSize2; i++){
        myMatrix2[i]=new int[MSize2];
    }
    i=0;
    j=0;
    
    while(getline(matrix2Read, line)){
        istringstream matrix2Line(line);
        string matrix2Value;
        while (getline(matrix2Line, matrix2Value, ','))
        {
            myMatrix2[i][j] = stoi(matrix2Value); //place values in matrix
            
            j++;
        }
        j=0;
        i++;
    }
    matrix2Read.close();


    
    // Multiply matricies
    int* matrixMul[MSize];
    for(i=0; i<MSize; i++){
        matrixMul[i]=new int[MSize];
    }
    //start clock
    clock_t mulTime;
    clock_t mulTimeDif;
    mulTime = clock();
    for(i=0; i<MSize; i++){
        for(j=0; j<MSize; j++){
            for(int k=0; k<MSize; k++){
                matrixMul[i][j] += myMatrix1[i][k] * myMatrix2[k][j];
            }
        }
    }
    //end clock
    mulTimeDif = clock() - mulTime;
    cout << "clock time: " << (float)mulTime/CLOCKS_PER_SEC;





    //output to file
    

    ofstream matrixWrite;
    matrixWrite.open("matrixOutput.txt");
    matrixWrite << to_string(MSize) << endl;
    for(int i=1; i<=MSize; i++){
        for(int j=1; j<=MSize; j++){
            matrixWrite << matrixMul[i][j] <<',';
                    
        }
        matrixWrite << endl;
    }
    matrixWrite.close();
    



    return 0;
}