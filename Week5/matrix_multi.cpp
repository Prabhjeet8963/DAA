#include <iostream>
using namespace std;

int main() {
   int r1, c1, r2, c2;

   cout << "Enter rows and columns for Matrix A: ";
   cin >> r1 >> c1;

   cout << "Enter rows and columns for Matrix B: ";
   cin >> r2 >> c2;

   //Check if multiplication is possible
   if (c1 != r2) {
      cout << "Matrix multiplication not possible!" << endl;
      return 0;
   }

   int matrixA[r1][c1];
   int matrixB[r2][c2];
   int resultMatrix[r1][c2];

   //Input elements
   cout << "Enter elements for Matrix A:" << endl;
   for (int i = 0; i < r1; ++i) {
      for (int j = 0; j < c1; ++j) {
         cin >> matrixA[i][j];
      }
   }

   cout << "Enter elements for Matrix B:" << endl;
   for (int i = 0; i < r2; ++i) {
      for (int j = 0; j < c2; ++j) {
         cin >> matrixB[i][j];
      }
   }


   //Multiplication
   for(int i=0;i<r1;i++)
   {
      for(int j=0;j<c2;j++)
      {
         resultMatrix[i][j] = 0;
         for(int k=0;k<c1;k++)
         {
            resultMatrix[i][j] += matrixA[i][k] * matrixB[k][j]; 
         }
      }
   }

   //Display matrices
   cout << "Matrix A" << endl;
   for (int i = 0; i < r1; ++i) 
   {
      cout << "| ";
      for (int j = 0; j < c1; ++j) 
      {
         cout << matrixA[i][j] << " ";
      }
      cout << "|" << endl;
   }
   cout << endl;

   cout << "Matrix B" << endl;
   for (int i = 0; i < r2; ++i) 
   {
      cout << "| ";
      for (int j = 0; j < c2; ++j) 
      {
         cout << matrixB[i][j] << " ";
      }
      cout << "|" << endl;
   }
   cout << endl;

   cout << "Result Matrix" << endl;
   for (int i = 0; i < r1; ++i) 
   {
      cout << "| ";
      for (int j = 0; j < c2; ++j) 
      {
         cout << resultMatrix[i][j] << " ";
      }
      cout << "|" << endl;
   }
   cout << endl;

   return 0;
}
