#include <iostream>
#include <vector>

using namespace std;

template<typename T>
void merge(vector<T>& arr, T p,T q,T r){
  T x1= q-p+1;
  T x2= r-q;
  T L[x1],M[x2];
    for (T i=0;i<x1;i++){
        L[i]=arr[p+i];
    }
    for(T j=0;j<x2;j++){
        M[j]=arr[q+1+j];
            }

  T a=0,b=0,c=p;
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
template<typename T>
void mergesort(vector<T>& arr,T p,T r){
if(r>p){
  T q=((p+r)/2);
    mergesort(arr,p,q);
    mergesort(arr,q+1,r);
    merge(arr,p,q,r);

}
}
template<typename T>
void bubblesort(vector<T>& v){
T n=v.size();
for ( T i=0;i<n;i++){
  for ( T j=0;j<n-1;j++){
    if(v[j]>v[j+1]){
      T temp;
      temp=v[j];
      v[j]=v[j+1];
      v[j+1]=temp;
    }
  }
}
}

int main() {

   vector<int> numery= {1,3,9,4,33,10,15,21};
    cout<<"Tablica przed posortowaniem bubblesort:"<<" ";
      for (int l:numery){
      cout<<l<<" ";
  }
      cout<<endl;
  
    bubblesort(numery);

    cout<<"Tablica po posortowaniu bubblesort:"<<" ";
    for (int l:numery){
      cout<<l<<" ";
  }
  cout<<endl;

int n = numery.size();
  cout << "Tablica przed sortowaniem mergesort: " << endl;
    for (int i = 0; i < n; i++) {
        cout << numery[i] << " ";
    }
    cout << endl;

    mergesort(numery, 0, n - 1);
  cout << "Tablica po sortowaniu mergesort: " << endl;
    for (int i = 0; i < n; i++) {
        cout << numery[i] << " ";
    }
    cout << endl;

//SPRAWDZENIE (jeżeli tablica będzie nieposortowana wyświetli się error)
for(int i=0;i<n-1;i++){
  if(numery[i]<numery[i+1]){ 
  }
else{
  cout<<"error-tablica źle posortowana";
}} 
  return 0;
}
