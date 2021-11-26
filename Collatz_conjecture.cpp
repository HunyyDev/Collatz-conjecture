#include <iostream>
#include <string>
#include <cstring>
#define ft(i,a,b) for(int i=a; i<=b; ++i)

//https://khmt.uit.edu.vn/wecode/truonganpn/assignment/34/146

using namespace std;

int c = 0;

string a;

string cong1(string a) {
    int nho = 1;
    string re = "";
    for (int i = a.size() - 1; i >= 0; --i) {
        int tmp = (a[i] - '0') + nho;
        nho = tmp / 10;
        re = to_string(tmp % 10) + re;
    }
    if (nho != 0) re = "1" + re;
    return re;
}

string nhan3(string a) {
    int nho = 0;
    string re = "";
    for (int i = a.size() - 1; i >= 0; --i) {
        int tmp = (a[i] - '0') * 3 + nho;
        nho = tmp / 10;
        re = to_string(tmp % 10) + re;
    }
    if (nho != 0) re = to_string(nho) + re;
    return re;
}

string tru(string a, string b) {
    while (a.size() != b.size()) {
        if (a.size() > b.size()) b = "0" + b;
        else a = "0" + a;
    }
    int nho = 0;
    string re = "";
    for (int i = a.size() - 1; i >= 0; --i) {
        int tmp = (a[i] - '0') - (b[i] - '0' + nho);
        if (tmp < 0) {
            nho = 1;
            tmp += 10;
        }
        else nho = 0;
        re = to_string(tmp) + re;
    }
    return re;
}

bool compare(const string& a, const string& b) {
    if (a.size() > b.size()) {
        return true;
    } 
    else if (a.size() == b.size()) {
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] > b[i]) return true;
        }
    }
    return false;
}

string chia2(string a) {
    int nho = 0;
    string re = "";
    string _a = a.substr(0, 1);
    int b = 0, e = b + 1;
    ft(i, 0, a.size() - 1) {
        int tmp = (nho * 10 + (a[i] - '0')) / 2;
        nho = (nho * 10 + (a[i] - '0')) - tmp * 2;
        re = re + to_string(tmp);
    }
    while (re[0] == '0') re.erase(0, 1);
    return re;
}


void query(string a) {
    if (a == "1") return;
    c++;
    if ((a.back() - '0') & 1) {
        string new_a = cong1(nhan3(a));
        cout << new_a << " ";
        query(new_a);
    }
    else {
        string new_a = chia2(a);
        cout << new_a << " ";
        query(new_a);
    }
}

int main()
{
    cin >> a;
    query(a);
    cout << "\n" << c;
    return 0;
}
