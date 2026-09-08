# include <iostream>
using namespace std;
int main()
{

int book[5];
cout<<"enter 5 Book ID's : \n";
for (int i = 0; i < 5; i++)
{
 cin >> book[i];

}
//Sorting

for (int i = 0; i < 4; i++)   // i is  number of passes, number of passes are  one less than the index
{
        for (int j = 0; j < 4 - i; j++)
        {
                if (book[j] > book[j +  1])
                 {
                        int temp = book[j];
                        book[j]= book[j+1];
                        book[j+1]= temp;
                 }
        }
}
 cout<<"\nBook IDs After sorting : \n";
for (int i = 0; i < 5; i++)
{
cout<<book[i]<<" ";
}   
return 0;

}