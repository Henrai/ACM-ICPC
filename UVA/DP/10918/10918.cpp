#include <iostream>
using namespace std;

struct Matrix {
	int mat[10][10];
	int size;
	Matrix():size(8) {
		for(int i = 0; i < size; i++)
			for(int j = 0; j < size; j++) {
				mat[i][j] = 0;
			}
	}
	Matrix(const Matrix& matrix) {
		for(int i = 0; i < size; i++)
			for(int j = 0; j < size; j++) {
				mat[i][j] = matrix.mat[i][j];
			}
	}
	int identity() {
		for(int i = 0; i < size; i++)
			for(int j = 0; j < size; j++)
				mat[i][j] = (i==j ? 1 : 0);
	}
	int init() {
		mat[3][7] = 1; mat[6][7] = 1;
		mat[7][3] = 1; mat[7][6] = 1;
		for(int i = 0; i < size; i++)
			mat[i][size-i-1] = 1;
	}

	Matrix operator*(const Matrix& matrix) {
		Matrix result;
		for(int i = 0; i < size; i++)
			for(int j = 0; j < size; j++)
				for(int k = 0; k < size; k++) {
					result.mat[i][j] += mat[i][k] * matrix.mat[k][j]; 
					//cout<< i<<" "<<j<<" "<<k<<" "<< mat[i][k]<< " "<<matrix.mat[i][k]<<endl;
				}
		return result;
	}

	Matrix operator=(const Matrix& matrix) {
		for(int i = 0; i < size; i++)
			for(int j = 0; j < size; j++)
				mat[i][j] = matrix.mat[i][j];
	}

	Matrix operator^(int n) {
		Matrix result;
		Matrix A;
		A = *this;
		result.identity(); 
		while(n) {
			if(n&1) result = result*A;
			A = A*A;
			n = n >> 1;
		}
		return result;
	}
};

int main(){
	int n;
	while(cin>>n) {
		if(n == -1) break;
		Matrix a;

		a.init();

		a = a^n;
		
		cout<<a.mat[7][7]<<endl;
	}
	return 0;
}



