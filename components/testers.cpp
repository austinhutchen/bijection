#pragma once
#include "algo.hpp"
#include <_ctype.h>
#include <ctime>
#include <iostream>
#include <vector>
#include <cctype>
using namespace std;
// header file used to test algorithms for functionality
class tester {
public:
  tester() {
    algo alg = algo();
    start = time(NULL);
  }
  void maxprofit() {
    int input;
    vector<int> vect;
    int profit;
    cout << "Enter your list of numbers below." << endl;
    while (cin >> input) {
      vect.push_back(input);
    }
    if (!cin.fail()) {
      profit = alg.maxProfit(vect);
    }
    cout << "MAXIMUM PROFIT ON TRADE INTERVAL IS: " << profit << endl;
  }
  void stringsearch() {
    bool ans = true;
    string search;
    char character;
    bool exit;
    while (exit != true) {
      cout << "ENTER THE STRING TO BE SEARCHED:" << endl;
      cout << "type EXIT to exit." << endl;
      cin >> search;
      if (search == "EXIT") {
        return;
      }
      search = alg.bubsort(search);
      cout << "SORTED:" << search << endl;
      while (character != '0') {
        cout << "Enter the character to be searched. Press 0 to exit. " << endl;
        cin >> character;
        if (character == '0') {
          return;
        }
        if (!cin.fail()) {
          if (alg.findchar(search, character) != 0) {
            cout << "Character " << character << " exists in the given string."<< endl;
          } else {
            cout << "Character not found inside of string." << endl;
          }
        } else {
          cout << "ONLY SINGLE LETTERS ALLOWED" << endl;
        }
      }
    }
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
    ;
  }
  void fio(){
    // file i/o
    string filename;
    vector <bitset <8> > out;
    cout << "Loading from IN.TXT ...." <<endl;
    out=alg.load();
     cout << "------ENCRYPTION----- " << endl;
      for (int i = 0; i < out.size(); i++) {
        cout << out[i] << endl;
      }
      cout << " ------DECRYPTION-----" << endl;
      cout << alg.decrypt(out) << endl;
      cout << "WRITING TO OUT.TXT ...." <<endl;
      alg.print(out);
      return;
  }
  

  
  void encryptalgo() {
    uint hx;
    vector<bitset<8> > output;
     string buf;
      bool ex=true;
      cin.ignore();
    while (ex) {
      cout << "---> ENTER INPUT <---" << endl;
     getline(cin,buf);
      output = alg.encrypt(buf, hx);
      cout << "------ENCRYPTION----- " << endl;
      for (int i = 0; i < output.size(); i++) {
        cout << output[i] << endl;
      }
      cout << " ------DECRYPTION-----" << endl;
      cout << alg.decrypt(output) << endl;
      cout << " ------HEX-----" << endl;
      cout << "0x" << hx << endl;
  cout << "Again? y (yes) /n (no) /f (file encrypt/decrypt)" << endl;
     getline(cin,buf);
      // lowercase character converter
      alg.lowercase(buf);
      switch (buf[0]) {
      case 121: {
        break;
      }
      case 102:{
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