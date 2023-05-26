#pragma once
#include "algo.hpp"
#include <_ctype.h>
#include <cctype>
#include <ctime>
using namespace std;
// header file used to test algorithms for functionality
class tester {
public:
  tester() {
    algo *alg = new algo();
    start = time(NULL);
  }

  void findpset() {
    int input;
    vector<int> vect;
    vector<vector<int> > nvect;
    int profit;
    cout << "Enter your list of numbers below. type 1978 when done.." << endl;
    while (cin >> input && input != 1978) {
      vect.push_back(input);
    }
    nvect = alg.pset(vect);
    int cardinality = pow(2, vect.size());
    cout << "ALL " << cardinality << " SUBSETS:" << endl;
    for (int i = 0; i < nvect.size(); i++) {
        cout << "PSET" << i + 1 << ":";
      if (i == nvect.size() - 1) {
        cout << "∅";
      }
      for (int k = 0; k < nvect[i].size(); k++) {
        cout << nvect[i][k] << ",";
      }
      cout << endl;
    }
  }

  void needlestack() {
    string stack;
    string needle;
    cout << "Enter your stack below:" << endl;
    cin >> stack;
    cout << "Enter needle:" << endl;
    cin >> needle;
    cout << alg.strStr(stack, needle) << endl;
  }
  bool isPrime(int number)
{
    for (int a = 2; a < number; a++) {
        if (number % a == 0) {
            return false;
        }
    }
    return true;
}
  void fio() {
    // file i/o
    string filename;
    vector<bitset<8> > out;
    cout << "Loading from ./txt/IN.TXT ...." << endl;
    out = alg.load();
    cout << "------ENCRYPTION----- " << endl;
    for (int i = 0; i < out.size(); i++) {
      cout << out[i] << endl;
    }
    cout << " ------DECRYPTION-----" << endl;
    cout << alg.decrypt(out) << endl;
    cout << "WRITING TO OUT.TXT ...." << endl;
    alg.print(out);
    return;
  }

  void encryptalgo() {
    uint hx;
    vector<bitset<8> > output;
    string buf;
    bool ex = true;
    while (ex) {
      cout << "Go? (y/n)" << endl;
      getline(cin, buf);
      // lowercase character converter
      alg.lowercase(buf);
      switch (buf[0]) {
      case 121: {
        fio();
        break;
      }
      default: {
        ex = false;
        break;
      }
      }
    }
    return;
  }

private:
  algo alg;
  time_t start;
  time_t end;
};