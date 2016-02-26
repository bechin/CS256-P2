#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;

int main(){
  int input = 0;
  int **m1=0, **m2=0, rows1, cols1, rows2, cols2;
  while(input!=6){
    system("cls");
    if(m1){
      cout << "Matrix 1:\n";
      for(int i = 0; i < rows1; i++){
        for(int j = 0; j < cols1; j++){
          cout << *(*(m1+i)+j) << " ";
        }
        cout << "\n";
      }
      cout << "Matrix 2:\n";
      for(int i = 0; i < rows2; i++){
        for(int j = 0; j < cols2; j++){
          cout << *(*(m2+i)+j) << " ";
        }
        cout << "\n";
      }
    }
    cout << "MATRIX CALCULATOR__________\n"
         << "1. Obtain matrices from file.\n"
         << "2. Enter matrices from console.\n"
         << "3. Add matrices in memory.\n"
         << "4. Subtract matrices in memory.\n"
         << "5. Multiply matrices in memory.\n"
         << "6. Exit.\n\n";
    cin >> input;
    switch(input){
      case 1:{
        m1 = 0, m2 = 0;
        cout << "Please enter a filename: ";
        string file;
        cin >> file;
        ifstream fin(file.c_str());
        if(fin.fail()){
          cout << "File not opened!\n";
          system("PAUSE");
          break;
        }
        fin >> rows1 >> cols1;
        fin.get();
        m1 = new int*[rows1];
        for(int i = 0; i < rows1; i++)
          *(m1+i) = new int[cols1];
        for(int i = 0; i < rows1; i++){
          for(int j = 0; j < cols1; j++){
            fin >> *(*(m1+i)+j);
          }
          fin.get();
        }
        fin >> rows2 >> cols2;
        fin.get();
        m2 = new int*[rows2];
        for(int i = 0; i < rows2; i++){
          *(m2+i) = new int[cols2];
        }
        for(int i = 0; i < rows2; i++){
          for(int j = 0; j < cols2; j++){
            fin >> *(*(m2+i)+j);
          }
          fin.get();
        }
        fin.close();
        break;
      }
      case 2:{
        m1 = 0, m2 = 0;
        cout << "Enter dimensions (rows, columns) of first matrix:\n";
        cin >> rows1 >> cols1;
        m1 = new int*[rows1];
        for(int i = 0; i < rows1; i++)
          *(m1+i) = new int[cols1];
        cout << "Enter elements of first matrix\n"
             << "(Left-to-right, top-to-bottom):\n";
        for(int i = 0; i < rows1; i++){
          for(int j = 0; j < cols1; j++){
            cin >> *(*(m1+i)+j);
          }
        }
        cout << "Enter dimensions (rows, columns) of second matrix:\n";
        cin >> rows2 >> cols2;
        m2 = new int*[rows2];
        for(int i = 0; i < rows2; i++)
          *(m2+i) = new int[cols2];
        cout << "Enter elements of second matrix\n"
             << "(Left-to-right, top-to-bottom):\n";
        for(int i = 0; i < rows2; i++){
          for(int j = 0; j < cols2; j++){
            cin >> *(*(m2+i)+j);
          }
        }
        break;
      }
      case 3:{
        if(!m1){
          cout << "No matrices in memory!\n";
          system("PAUSE");
          break;
        }
        else if(rows1!=rows2||cols1!=cols2){
          cout << "Matrices not of same dimensions; cannot add!\n";
          system("PAUSE");
          break;
        }
        cout << "Result:\n";
        for(int i = 0; i < rows1; i++){
          for(int j = 0; j < cols1; j++){
            cout << (*(*(m1+i)+j))+(*(*(m2+i)+j)) << " ";
          }
          cout << "\n";
        }
        system("PAUSE");
        break;
      }
	  case 4:{
        if(!m1){
          cout << "No matrices in memory!\n";
          system("PAUSE");
          break;
        }
        else if(rows1!=rows2||cols1!=cols2){
          cout << "Matrices not of same dimensions; cannot subtract!\n";
          system("PAUSE");
          break;
        }
        cout << "Result:\n";
        for(int i = 0; i < rows1; i++){
          for(int j = 0; j < cols1; j++){
            cout << (*(*(m1+i)+j))-(*(*(m2+i)+j)) << " ";
          }
          cout << "\n";
        }
        system("PAUSE");
        break;
      }
      case 5:{
        if(!m1){
          cout << "No matrices in memory!\n";
          system("PAUSE");
          break;
        }
        else if(cols1!=rows2){
          cout << "Matrices not of appropriate dimensions; cannot multiply!\n";
          system("PAUSE");
          break;
        }
	//	int **r = new int*[rows1];
		//for(int i = 0; i < rows1; i++)
	      //*(r+i) = new int[cols2];
        cout << "Result:\n";
        for(int i = 0; i < rows1; i++){
			for(int j = 0; j < cols2; j++){
			  int tempSum = 0;
			  for(int k = 0; k < cols1; k++){
			  tempSum += (*(*(m1+i)+k))*(*(*(m2+k)+j));
			  }
			  cout << tempSum << " ";
			}
			cout << "\n";
		}
		system("PAUSE");
		break;
      }
      case 6:{
        if(m1){
          for(int i = 0; i < rows1; i++){
            delete[] *(m1+i);
          }
          delete[] m1;
          m1 = 0;
          for(int i = 0; i < rows2; i++){
            delete[] *(m2+i);
          }
          delete[] m2;
          m2 = 0;
        }
        system("PAUSE");
        break;
      }
      default:
        cout << "Invalid input!\n";
    }
  }
  return 0;
}


