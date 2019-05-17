#include <stdio.h>
#include <stdlib.h>
void swap(int* a, int* b)//yerdegistirme fonksiyonu
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void print(int a[],int n)//dizilerin ekrana basilmasi icin fonksiyon
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%3d",a[i]);
    }
    printf("\n\n");
}

void quickSort(int lock[],int key[],int low,int high, int n)
{
    srand(time(NULL));
    int randomsec;//key dizisinden secilen random eleman

    if(low<high)
    {
        randomsec=key[(rand()%(high-low+1)+low)];
        printf("Key dizisinden secilen rasgele eleman: %d\n",randomsec);
        int pivot = partition(lock, low, high, randomsec);
        partition(key, low, high, lock[pivot]);//partition fonksiyonuna bilgilerin gonderilmesi
        printf("\n");
        printf("Lock dizisi: ");
        print(lock,n);

        printf("Key dizisi: ");
        print(key,n);

        quickSort( lock,key, low, pivot-1,n);// [low..pivot-1] icin quickSort fonksiyonuna gonderme
        quickSort( lock,key, pivot+1, high,n);//[pivot+1..high] icin quickSort fonksiyonuna gonderme
    }
}

int partition( int a[], int low, int high, int pivot)
{
        int i = low;
        for (int j = low; j < high; j++)
        {
            if (a[j] < pivot)
            {
                swap(&a[i],&a[j]);//a[j] nin pivottan buyuk iken a[i]le yerdegistirmesi
                i++;
            }
            else if(a[j] == pivot)//a[j]nin pivota esit iken a[high]le yerdegistirmesi
            {
                swap(&a[j],&a[high]);
                j--;
            }
        }
        swap(&a[i],&a[high]);//a[i] ve a[high] nin yerdegistirmesi
        return i;
}

int main()
{
    int n,lock[100],key[100],i;
    printf("Lock ve Key adedini girin: ");//dizilerin boyutu
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&lock[i]);//lock dizisinin elemanlari
    }
    printf("\n");

    for(i=0;i<n;i++)
    {
        scanf("%d",&key[i]);//key dizisinin elemanlari
    }
    printf("\n\n");

    printf("Lock ve Key dizileri: \n");
    printf("Lock dizisi: ");
    print(lock,n);

    printf("Key dizisi: ");
    print(key,n);

    quickSort(lock,key,0,n-1,n); //quickSort fonksiyonuna gonderiliyor
    printf("\n\n");
    printf("\n==Lock ve Key dizileri==\n");//siralanmis diziler ekrana yazdiriliyor
    printf("Lock dizisi: ");
    print(lock,n);

    printf("Key dizisi: ");
    print(key,n);
    return 0;

}
