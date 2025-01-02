//HASHING
// #include <bits/stdc++.h>
// using namespace std;
// //1 2 3 4 4
// //q = 5 1 -> 1 2-> 1 3-> 1 4->2 5->0 //1 1 1 2 
// int main(){
//     int size;
//     cin>>size;
//     int arr[size];
//     for(int i = 0; i <size; i++){
//         cin>>arr[i];
//     }
//     cout<<"displaying the array"<<endl;
//     for(int i = 0; i <size; i++){
//         cout<<arr[i]<<" ";
//     }
//     //pre calculate
//     int hash[13]={0};
//     for(int i= 0; i<size;i++){
//         hash[arr[i]]=hash[arr[i]]+1;
//     }
//     //fetch
//     int q;
//     cin>>q;
//     do{
//         int number;
//         cin>>number;
//         cout<<hash[number]<<endl;
//     }while(--q);
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
int main(){
    //hash the string as array 'aaebioj' 26b elements 0....25
    //a 97
    //97-97 = 0 a 
    //98-97 = 1 b 
    //102-97 =5 f
    //formula : char - 'a'->corresponding index in the hash array 
    string s ;
    cin>>s;
    cout<<"displayign the string : "<<endl;
    cout<<s;
    int hash[26]={0};
    for(int i = 0 ; i<s.size(); i++){
        hash[s[i]-'a']++;
    }
    int q;
    cin>>q;
    do{
        char c;
        cin>>c;
        cout<<hash[c-'a']<<endl;
    }while(--q);
    return 0;
}
