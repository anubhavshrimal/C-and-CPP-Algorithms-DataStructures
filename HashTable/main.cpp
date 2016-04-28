#include <iostream>
#include<string.h>
#include<math.h>
#include<stdlib.h>
using namespace std;

typedef struct node
{
    struct node *next,*prev;
    string data;
}node;

int hashCode(string str)
{
    char arr[str.size()+1];
    strcpy(arr,str.c_str());
    int code=0;
    for(int i=0;i<str.size();i++)
    {
        code+=((i+1)*((int)arr[i]));
    }
    return code;
}

int compress(int k,int m)
{
    double a=(sqrt(5.0)-1)/2;
    return floor(m*(fmod(k*a,1)));
}

void display(node* hashTable[],int m)
{
    for(int i=0;i<m;i++)
    {
        cout<<i<<":\n";
        node* p=hashTable[i];
        while(p!=NULL)
        {
            cout<<p->data<<" , ";
        }
        cout<<"\n";
    }
}

void putInHash(string str,node* hashTable[],int m)
{
    int k=hashCode(str);
    int bucket=compress(k,m);
    if(hashTable[bucket]==NULL)
    {
        hashTable[bucket]=(node*)malloc(sizeof(node));
        hashTable[bucket]->prev=NULL;
        hashTable[bucket]->next=NULL;
        hashTable[bucket]->data=str;
    }
    else
    {
        node* temp=(node*)malloc(sizeof(node));
        temp->data=str;
        temp->next=hashTable[bucket];
        hashTable[bucket]->prev=temp;
        temp->prev=NULL;
        hashTable[bucket]=temp;
    }
}

int main()
{
    cout<<"Enter number of strings to add in hash table: ";
    long int n;
    cin>>n;
    cout<<"\n";
    int m=13;
    node* hashTable[m];
    for(int i=0;i<m;i++)
    {
        hashTable[i]=NULL;
    }

    string str;

    cout<<"Enter the strings:\n";
    for(int i=0;i<n;i++)
    {
        cin>>str;
        putInHash(str,hashTable,m);
    }

    display(hashTable,m);

    return 0;
}
