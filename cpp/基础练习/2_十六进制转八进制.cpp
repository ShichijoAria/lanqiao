//
// Created by aria on 18-2-3.
//

#include <iostream>
#include <map>
using namespace std;

string hexadecimalToBinary(string hexadecimal){
    string binary;
    string arr[16]={"0000","0001","0010","0011",
                    "0100","0101","0110","0111",
                    "1000","1001","1010","1011",
                    "1100","1101","1110","1111"};
    for (int i = 0; i < hexadecimal.length(); ++i) {
        if(hexadecimal[i]>'9')
            binary+=arr[hexadecimal[i]-'A'+10];
        else
            binary+=arr[hexadecimal[i]-'0'];
    }
    return binary;
}


string binaryToOctonary(string binary){
    string octonary;
    map <string,string> m;
    m["000"]="0",m["001"]="1";m["010"]="2",m["011"]="3";
    m["100"]="4",m["101"]="5";m["110"]="6",m["111"]="7";
    if(binary.length()%3==1)
        binary="00"+binary;
    else if(binary.length()%3==2)
        binary="0"+binary;
    bool flag;
    for (int i = 0; i < binary.length(); i+=3) {
        string temp = binary.substr(i, 3);
        string t=m[temp];
        if(i==0&&t=="0"){
            flag= true;
            continue;
        } else if(i==3&&flag&&t=="0")
            continue;
        octonary+=t;
    }
    return octonary;
}

int main() {
    int n;
    string *octonary;
    cin>>n;
    octonary=new string[n];
    for (int i = 0; i < n; ++i) {
        string hexadecimal;
        cin>>hexadecimal;
        octonary[i]=binaryToOctonary(hexadecimalToBinary(hexadecimal));
    }

    for (int j = 0; j < n; ++j) {
        cout<<octonary[j]<<endl;//又吃了没打回车的亏
    }

}