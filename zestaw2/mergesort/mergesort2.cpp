#include <iostream>
#include <vector>


using namespace std;


void merge(vector<int> &arr,int p,int q,int r){
    int x1= q-p+1;
    int x2= r-q;
    int L[x1],M[x2];
    for (int i=0;i<x1;i++){
        L[i]=arr[p+i];
    }
    for(int j=0;j<x2;j++){
        M[j]=arr[q+1+j];
            }

    int a=0,b=0,c=p;
    while(a<x1 && b<x2){
        if (L[a]<=M[b]){
            arr[c]=L[a];
            a++;
        }
        else{
            arr[c]=M[b];
            b++;
        }
        c++;
    }  
    while (a<x1){
        arr[c]=L[a];
        a++;
        c++;
    }   
    while (b<x2){
        arr[c]=M[b];
        b++;
        c++;
    }   
}

void mergesort(vector <int> &arr,int p,int r){
if(r>p){
    int q=((p+r)/2);
    mergesort(arr,p,q);
    mergesort(arr,q+1,r);
    merge(arr,p,q,r);

}
}

int main() {
    vector<int> arr = {1, 2, 44, 3, 18, 19, 5, 9, 7};
    int n = arr.size();

    cout << "Tablica przed sortowaniem: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    mergesort(arr, 0, n - 1);

    cout << "Tablica po sortowaniu: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}