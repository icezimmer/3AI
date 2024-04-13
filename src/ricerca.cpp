#include<iostream>
using namespace std;

bool ricercaLineare(int v[], int dim, int x) {
	for (int i=0; i<dim; i++){
		if (v[i]==x)
			return true;
	}
	return false;
}
