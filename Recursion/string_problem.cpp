#include <iostream>
using namespace std;
// check palidrone
bool palindrome(string str, int start, int end)
{
    if (start >= end)
        return 1;
    if (str[start] != str[end])
        return 0;
    return palindrome(str, start + 1, end - 1);
}

// count vowels
int vowels(string str, int index)
{
    if (index == -1)
        return 0;
    if (str[index] == 'a' || str[index] == 'e' || str[index] == 'i' || str[index] == 'o' || str[index] == 'u')
        return 1 + vowels(str, index - 1);
    else
        return vowels(str, index - 1);
}

// reverse
void rev(string &str, int start, int end)
{
    if (start >= end)
        return;
    swap(str[start], str[end]);
    rev(str, start+1, end-1);
}

//LowertoUpper
void lowtoup(string &str,int index){
    if(index == -1)return;
    str[index] = 'A'+str[index]-'a';
    lowtoup(str,index-1);
}


int main()
{
    string str = "monii";
    // cout << "Enter a string";
    // cin >> str;
    int n = str.length();
    // cout << palindrome(str, 0, n - 1);
    // rev(str, 0, 5);
    lowtoup(str,n);
    cout<<str;
}
