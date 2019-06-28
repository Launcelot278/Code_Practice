#include<iostream>
#include<vector>

using namespace std;

class MinHeap{
public:
    MinHeap(int k);
    void createMinHeap(int a[]);
    void insert(int val);
    int getTop();
    vector<int> getHeap();
private:
    int maxsize;
    void filterdown(vector<int>::size_type x);
    vector<int> arr;
};

MinHeap::MinHeap(int k){
    maxsize = k;
}

void MinHeap::createMinHeap(int *a){
    for (int i=0;i<maxsize;i++)
        arr.push_back(*(a+i));
    for (vector<int>::size_type i=(arr.size()-1)/2;i>0;i--)
        filterdown(i);
    filterdown(0);
}

void MinHeap::insert(int val){
    if (val>getTop()){
        arr[0] = val;
        filterdown(0);
    }
}

void MinHeap::filterdown(vector<int>::size_type x){
    vector<int>::size_type end = arr.size()-1;
    vector<int>::size_type child = x*2+1;
    int val = arr[x];
    while (child<=end){
        if (child<end && arr[child+1]<arr[child]) child++;
        if (val<arr[child]) break;
        else {
            arr[x]=arr[child];
            x=child;
            child = child*2+1;
        }
    }
    arr[x]=val;
}

int MinHeap::getTop(){
    if (arr.size()!=0) return(arr[0]);
    else return NULL;
}

vector<int> MinHeap::getHeap(){
    vector<int> heap;
    for (vector<int>::size_type i=0;i!=arr.size();i++)
        heap.push_back(arr[i]);
    return heap;
}


int main()
{
    int a[]={1,4,6,7,2,9,8,3,5,0};
    int k=4;
    MinHeap heap(k);
    heap.createMinHeap(a);
    for (int i=k;i<10;i++){
        heap.insert(a[i]);
    }
    vector<int> ans=heap.getHeap();
    for (vector<int>::size_type i=0;i!=ans.size();i++)
        cout << ans[i] << endl;
}
