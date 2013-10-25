#include <iostream>
#include <stdlib.h>


template <class T> void exch(T &, T &);
template <class T> void compexch(T &, T &, int&);
template<class T> void selection(T *, int, int, int&, int&);
template <class T> void insertion(T *, int, int, int&, int&);
template <class T> void bubble( T *, int, int, int&, int&);
//-----------------------
template <class T> void shiftRight(T *, int, int, int&, int& );
template <class T> void heapify(T *, int, int, int&, int&);
template <class T> void heapSort(T *, int, int, int&, int&);
//-----------------------
template <class T> int partition(T * , int, int, int&, int&);
template <class T> void quicksort(T * , int, int, int&, int&);
//-----------------------
template <class T> void mergesort(T *,T *, int, int , int&, int&);
template <class T> void merge(T *,T *, int, int, int, int&, int&);

//-----------------------
using namespace std;
int main(int argc, char *argv[])
{
    //int i, N = atoi(argv[1]), KaDaryt = atoi(argv[2]);
    int N=1000;

    int j,i,v,s,r;
    bool t=false;
    char ts;
    while(t==false)
    {
    int *a = new int[N];
    int *b = new int[N];
    int L=0, S=0;
   // int * op;
   // Op = &L;
   // Op = &S;
    cout<<"Parinkite sudetinguma [max](1),[min](2),[vid](3): ";
    cin>>s;
    if(s==1)
    {
            j=0;
        cout<<"Pirmas variantas"<<endl;
        for (i = N-1; i >= 0; i--)
                 {
                      a[j] = i;
                      j++;
                 }
    }
    else if(s==2)
    {
        cout<<"Antras variantas"<<endl;
        for (i = 0; i < N; i++)
        {
            a[i] = i;
        }
    }
    else if(s==3)
    {
        cout<<"Parinkite masyvo ivedimo buda auto(1)/rank(2): ";
        cin>>v;
        //if (KaDaryt) // Atsitiktinai sugeneruoja N skaičių intervale: 1,...,1000.
        if (v==1)
        for (i = 0; i < N; i++)
            a[i] = 1000*(1.0*rand()/RAND_MAX);
        else if (v==2) // Savo nuožiūra įvedame skaičius. Norėdami baigti įvedimą, įvedame bet kokį simbolį - ne skaičių.
        { N = 0; while (cin >> a[N]) N++; }
    }
    else
    {
        cout<<"Neteisingai nurotytas kintamasis generuojamas nulinis masyvas"<<endl;
        for (i = 0; i < N; i++)
            a[i] = 0;
    }
    cout << endl;
    cout << "Ivestas skaiciu masyvas yra:" << endl;
    for (i = 0; i < N; i++) 
    {cout << a[i] << " "; }
    cout << endl;
    cout<<"Parinkite rikiavimo algoritma [isrinkimo](1),[iterpimo](2),[burbulo](3), [kruvos)](4), [salajos)](5),[spartusis](6): ";
    cin>>r;
    if(r==1) selection(a,0,N-1,L,S);
    else if(r==2) insertion(a,0,N-1,L,S);
        else if (r==3) bubble(a,0,N-1,L,S);
             else if (r==4) heapSort(a,0,N-1,L,S);
                  else if (r==5) quicksort(a,0,N-1,L,S);
                       else if (r==6) mergesort(a,b,0,N-1,L,S);
                  else cout<<"Neteisingai nurodytas rusiavimo budas"<< endl;
      
    cout << "Surusiuotas skaiciu masyvas yra:" << endl;
    for (i = 0; i < N; i++) cout << a[i] << " ";
    cout << endl;
    cout << "Rusiuodamas algoritmas atlykto "<<S<<" lyginimo ir "<<L<<" sukeitimo operaciju:" << endl;
    cout << "Ar dar karta rusiuosit? y/(betkoks) : ";
    cin>>ts;
    if(ts=='y'){t=false;}else {t=true;}
}
    //cin>>r;
    cout << endl;
    return 0;
}
// Sukeičia elementus vietomis
template <class T>
  void exch(T &A, T &B)
    { T t = A ; A = B; B = t; }
// Sukeičia elementus vietomis tik jei patenkinta sąlyga
template <class T>
  void compexch(T &A, T &B, int &S)
    { if (B < A) {exch(A, B); S++;} }
// Išrinkimo algoritmo realizacija
template <class T>

  void selection(T a[], int l, int r, int &L, int &S)
  {
      for(int i = l;i<r;i++)
        {
            int min = i;
            for(int j=i+1;j<=r;j++)
                if(a[j]<a[min])
                {
                    min=j; L++;//Atlikome lyginimo operaciją
                }
            exch(a[i],a[min]);
            S++;//Atlikome sukeitimo operaciją 
        }
  }
// Įterpimo algoritmo realizacija
template <class T>
void insertion( T a[], int l, int r, int &L, int &S)
  { int i;
    for (i = r; i > l; i--) 
    {
        compexch(a[i-1], a[i],S);
        L++;
    }
    for (i = l+2; i <= r; i++)
      { 
           int j = i; 
           T v = a[i];
           while (v < a[j-1])
           { 
                 a[j] = a[j-1]; 
                 j--; 
                 
           }
        a[j] = v;
        
      }
  }
// Burbulo algoritmas
template <class T>
void bubble(T a[], int l, int r, int &L, int &S)
  { for (int i = l; i < r; i++)
      for (int j = r; j > i; j--)
        {
            compexch(a[j-1], a[j],S);
            L++;
        }
  }
//-------------------------------------------------------  
//Spartuji ru�iavimo algoritma (angla quick sort).
//-------------------------------------------------------
// The partition function
template <class T>
int partition(T a[], int l, int r, int &L, int &S)
{
    int pivot = a[r];

    while ( l < r )
    {
        while ( a[l] < pivot )
            l++;

        while ( a[r] > pivot )
            r--;

        if ( a[l] == a[r] )
            l++;
        else if ( l < r )
        { 
            int tmp = a[l];
            a[l] = a[r];
            a[r] = tmp;
            L++;
        }
        S++;
    }
    return r;
}

// The quicksort recursive function
template <class T>
void quicksort(T a[], int l, int r, int &L, int &S )
{
    if ( l < r )
    {
        int j = partition(a, l, r,L,S);        
        quicksort(a, l, j-1,L,S);
        quicksort(a, j+1, r,L,S);
    }
}
//-------------------------------------------------------
//Suliejimo(salajos) ru�iavimo algoritma (angl. merge sort).
//-------------------------------------------------------
template <class T>
void mergesort(T a[],T b[], int l, int r, int &L, int &S)
{
    int pivot;
    if(l<r)
    {
        pivot=(l+r)/2;
        mergesort(a,b,l,pivot,L,S);
        mergesort(a,b,pivot+1,r,L,S);
        merge(a,b,l,pivot,r,L,S);
    }
}
template <class T>
void merge(T a[],T b[], int l, int pivot, int r, int &L, int &S)
{
    int h,i,j,k;
    h=l;
    i=l;
    j=pivot+1;

    while((h<=pivot)&&(j<=r))
    {
        if(a[h]<=a[j])
        {
            b[i]=a[h];
            h++;
            
        }
        else
        {
            b[i]=a[j];
            j++;
            L++;
        }
        S++;
        i++;
    }
    if(h>pivot)
    {
        for(k=j; k<=r; k++)
        {
            b[i]=a[k];
            i++;
        }
    }
    else
    {
        for(k=h; k<=pivot; k++)
        {
            b[i]=a[k];
            i++;
        }
        
    }
    S++;
    for(k=l; k<=r; k++) a[k]=b[k];
}
//-------------------------------------------------------
//Piramidini (kruvos) ru�iavimo algoritma (angl. heap sort)
//-------------------------------------------------------
template <class T>
void shiftRight(T a[], int l, int r, int &L, int &S)
{
   ++S;
    while ((l*2)+1 <= r)
    {
        int leftChild = (l * 2) + 1;
        int rightChild = leftChild + 1;
        int swapIdx = l;
        ++S;
        if (a[swapIdx] < a[leftChild])
        {
            swapIdx = leftChild;
        }
        if ((rightChild <= r) && (a[swapIdx] < a[rightChild]))
        {
            swapIdx = rightChild;
        }
        if (swapIdx != l)
        {
            exch(a[l],a[swapIdx]); 
            l = swapIdx;
            ++L;
        }
        else
        {
            break;
        }
    }
    return;
}
template <class T>
void heapify(T a[], int l, int r, int &L, int &S)
{
    int midIdx = (r-1)/2;
    while (midIdx >= 0)
    {
        shiftRight(a, midIdx, r,L,S);
        --midIdx;
    }
    return;
}
template <class T>
void heapSort(T a[], int l, int r, int &L, int &S)
{
    assert(a);
    assert(r > 0);
    heapify(a, 0, r,L,S);
    while (r > 0)
    {
          exch(a[r],a[0]); 
          --r;
          shiftRight(a, 0, r,L,S);
    }
    return;
}
//-------------------------------------------------------------
//-------------------------------------------------------------


