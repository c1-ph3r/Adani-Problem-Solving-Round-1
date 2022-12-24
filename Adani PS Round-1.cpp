#include<bits/stdc++.h>
using namespace std;

//Q1: function to generate random matrix
vector<vector<int>> randMatrix(int nRows, int nColumns){
	vector<vector<int>> Matrix(nRows,vector<int>(nColumns,0));
	for(int i=0; i<nRows; ++i){
		for(int j=0; j<nColumns; ++j){
			Matrix[i][j]=1+(rand()%100);
		}
	}
	return Matrix;
}

//merging different rows of the matrix
void merge(vector<vector<int>>& arr, int i, int u, int mid, int d){
    int n = arr.size();
    int m = arr[0].size();
    
    int u_size = mid - u + 1;
    int d_size = d-mid;
    
    vector<vector<int>> u_arr, d_arr;
    
    for(int j=0; j<u_size; j++){
        u_arr.push_back(arr[u+j]);
    }
    for(int j=0; j<d_size; j++){
        d_arr.push_back(arr[mid+1+j]);
    }
    
    int u_pointer = 0, d_pointer = 0, k = u;
    
    while(u_pointer<u_size & d_pointer<d_size){
        if(u_arr[u_pointer][i] <= d_arr[d_pointer][i]){
            for(int j=0; j<m; j++){
                arr[k][j] = u_arr[u_pointer][j];
            }
            k++;
            u_pointer++;
        }
        else{
            for(int j=0; j<m; j++){
                arr[k][j] = d_arr[d_pointer][j];
            }
            k++;
            d_pointer++;
        }
    }
    while(u_pointer<u_size){
        for(int j=0; j<m; j++){
                arr[k][j] = u_arr[u_pointer][j];
        }
        k++;
        u_pointer++;
    }
    while(d_pointer<d_size){
        for(int j=0; j<m; j++){
            arr[k][j] = d_arr[d_pointer][j];
        }
        k++;
        d_pointer++;
    }
    return;
}

//merge sort function
void mergeSort(vector<vector<int>>& arr, int i, int u, int d){
    if(u>=d) return;
    int mid = u + (d-u)/2;
    mergeSort(arr, i, u, mid);
    mergeSort(arr, i, mid+1, d);
    merge(arr, i, u, mid, d);
    return;
}

//Q2. function to sort the required column
void sortCol(vector<vector<int>>& arr,int i){
    int n = arr.size();
    int m = arr[0].size();
    
    // apply mergeSort
    mergeSort(arr, i, 0, n-1);
    return;
}

int main(){
	int m,n,k;
	cin>>m>>n>>k;
	vector<vector<int>>v;
	v=randMatrix(m,n);
	//random Matrix
	cout<<"Generated random matrix is:"<<endl;
	for(int i=0; i<m; ++i){
		for(int j=0; j<n; ++j){
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}
	sortCol(v,k);
	//sorted Matrix
	cout<<"Sorted matrix is:"<<endl;
	for(int i=0; i<m; ++i){
		for(int j=0; j<n; ++j){
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}
}
