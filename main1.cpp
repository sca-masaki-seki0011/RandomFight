#include <algorithm>
#include <cctype>
#include <string>
#include <ctime>
#include <iostream>
#include <vector>
using namespace std;

const int MAX_WRONG = 10; //最大間違え可能回数
//各難易度の関数=====
void easy();
void normal();
void hard();
//==================

int main()
{
  vector<string>::iterator iter;
  vector<string> difficulty;
  difficulty.push_back("EASY");
  difficulty.push_back("NORMAL");
  difficulty.push_back("HARD");
  cout << "ようこそDon't Wrong WORDへ^-^\n";
  cout << "注意!!!!!!!" << "間違えた英文字はもう一度入力できるけど";
  cout << "[答え: ]という文字が表示されず[あなたの答え:]の次に英文字が表示";
  cout << "されたら間違えた英文字を入力してねの意味だから気を付けてね"<< endl;
  cout << "同じ問題も出るかもしれないから覚えたほうがいいかもよ~~~\n\n";

  cout << "======難易度=========" << endl;
    for (iter = difficulty.begin(); iter != difficulty.end(); ++iter) {
      cout << *iter << endl;
    }
    cout << "=====================" << endl;
    cout << "難易度を入力してください" << endl;
    string di;
    cout << "難易度: ";
    cin >> di;
    if (di == "EASY" || di == "easy") {
      easy();
    } else if (di == "NORMAL"|| di == "normal") {
      normal();
    } else if (di == "HARD"|| di == "hard") {
      hard();
    }
  return 0;
}

void easy() {
  int right = 0;        //playerの正解数
  int wrong = 0;        //playerの間違え回数
  vector<string> words; 
  words.push_back("BAG");
  words.push_back("CAMEL");
  words.push_back("BUILDING");
  int kaisuu = 1;
  

  cout << "3回正解すればEASYはクリアだよ"<< endl;
  // main loop
  while (right != 3) {
    cout << "第" << kaisuu << "問目はこれだ!!" << endl;
    srand(static_cast<unsigned int>(time(0)));
    random_shuffle(words.begin(), words.end());
    const string THE_WORD = words[0]; 
    int longer = THE_WORD.size();
    string soFar(THE_WORD.size(), '-'); 
    string used = "";    
    switch(longer) {
      case 3:
        cout << "問題: 出かけるときに持っていく物はな～んだ?" << endl;
       break;
     case 5:
        cout << "問題: 砂漠にすんでいる動物はな～んだ?" << endl;
      break;
      case 8:
        cout << "問題: 街中に聳え立っている建物はな～んだ?" << endl;
    break;
    }
    while ((wrong < MAX_WRONG) && (soFar != THE_WORD)) { 
      cout << "\n\n間違え可能回数: " << (MAX_WRONG - wrong) << "回";
      cout << "\n文字が表示されるよ\n" << used << endl;
      cout << "\n文字数は:　" << soFar << endl;
      

      char guess;
      cout << "あなたの答え: ";
      cin >> guess;
      guess = toupper(guess); 
      while (used.find(guess) != string::npos) {
        cout << "\nこの文字はすでに入力しているね" << guess << endl;
        cout << "もう一度入力してね: ";
        cin >> guess;
        guess = toupper(guess);
      }
      
      used += guess;
      if (THE_WORD.find(guess) != string::npos) {
        cout << guess << endl;
        for (int i = 0; i < THE_WORD.length(); ++i) {
          if (THE_WORD[i] == guess) {
            soFar[i] = guess;
            }
          }
        }
        else {
        cout << "ごめんね, " << guess << "は間違っている英文字だね\n";
        ++wrong;
        }
    }
   if(wrong == MAX_WRONG)
      {
        cout << "またチャレンジしてくれよな!!";
        break;
      }
      right++;
    kaisuu++;
    cout << "\n答えは: " << THE_WORD << "\n\n";
    }
  cout << "\nEASYクリアおめでとう!";
}


void normal() {
  int right = 0;        //playerの正解数
  int wrong = 0;        //playerの間違え回数
  vector<string> words; 
  words.push_back("DOCTOR");
  words.push_back("CALENDAR");
  words.push_back("CLASSROOM");
  words.push_back("COURTHOUSE");
  int kaisuu = 1;

  cout << "4回正解すればNORMALはクリアだよ"<< endl;
  // main loop
  while (right != 4) {
    cout << "第" << kaisuu << "問目はこれだ!!" << endl;
    srand(static_cast<unsigned int>(time(0)));
    random_shuffle(words.begin(), words.end());
    const string THE_WORD = words[0];
    int longer = THE_WORD.size();
    string soFar(THE_WORD.size(), '-'); 
    string used = "";    
    switch (longer) {
      case 6:
        cout << "問題: 悪い病気を治す人はな～んだ?" << endl;
        break;
      case 8:
        cout << "問題: 日付や曜日を確認する物はな～んだ?" << endl;

        break;
      case 9:
        cout << "問題: 学校で授業を受ける部屋はな～んだ?" << endl;
        break;
      case 10:
        cout << "問題: 裁判官がいる場所はな～んだ?"
             << endl;
        break;
      }
    while ((wrong < MAX_WRONG) && (soFar != THE_WORD)) { 
      cout << "\n\n間違え可能回数: " << (MAX_WRONG - wrong) << "回";
      cout << "\n文字が表示されるよ\n" << used << endl;
      cout << "\n文字数は:　" << soFar << endl;
      

      char guess;
      cout << "あなたの答え: ";
      cin >> guess;
      guess = toupper(guess); 
      while (used.find(guess) != string::npos) {
        cout << "\nこの文字はすでに入力しているね" << guess << endl;
        cout << "もう一度入力してね: ";
        cin >> guess;
        guess = toupper(guess);
      }
      
      used += guess;
      if (THE_WORD.find(guess) != string::npos) {
        cout << guess << endl;
        for (int i = 0; i < THE_WORD.length(); ++i) {
          if (THE_WORD[i] == guess) {
            soFar[i] = guess;
            }
          }
        }
        else {
        cout << "ごめんね, " << guess << "は間違っている英文字だね\n";
        ++wrong;
        }
    }
   if(wrong == MAX_WRONG)
      {
        cout << "またチャレンジしてくれよな!!";
        break;
      }
      right++;
    kaisuu++;
    cout << "\n答えは: " << THE_WORD << "\n\n";
    }
  cout << "\nNORMALクリアおめでとう!";
}

void hard() {
  int right = 0;        //playerの正解数
  int wrong = 0;        //playerの間違え回数
  vector<string> words; 
  words.push_back("HAT");
  words.push_back("GIRL");
  words.push_back("KNIFE");
  words.push_back("MUSEUM");
  words.push_back("MILLION");
  words.push_back("NOVEMBER");
  words.push_back("NEWSPAPER");
  words.push_back("ASSIGNMENT");
  int kaisuu = 1;

  cout << "8回正解すればHARDはクリアだよ"<< endl;
  
  // main loop
  while (right != 8) {
    cout << "第" << kaisuu << "問目はこれだ!!" << endl;
    srand(static_cast<unsigned int>(time(0)));
    random_shuffle(words.begin(), words.end());
    const string THE_WORD = words[0]; 
    int longer = THE_WORD.size();
    string soFar(THE_WORD.size(), '-'); 
    string used = "";    
    switch (longer) {
      case 3:
        cout << "問題: オシャレで頭にかぶる物はな～んだ?" << endl;
        break;
      case 4:
        cout << "問題: 男の子の反対の性別はな～んだ?" << endl;
        break;
      case 5:
        cout << "問題: 料理だどで使われる食材を切る物はな～んだ?" << endl;
        break;
      case 6:
        cout << "問題: 古い資料や美術品が展示している建物はな～んだ?" << endl;
        break;
      case 7:
        cout << "問題: 十万の次の単位はな～んだ?" << endl;
        break;
      case 8:
        cout << "問題: 10月の次の月はな～んだ?" << endl;
        break;
      case 9:
        cout << "問題: "
                "いろんな情報が載っており、よくお父さんが朝に読む物はな～んだ?"
             << endl;
        break;
      case 10:
        cout << "問題: 学校の先生から出されるやりたくない物はな～んだ?" << endl;
        break;
      }
    while ((wrong < MAX_WRONG) && (soFar != THE_WORD)) { 
      cout << "\n\n間違え可能回数: " << (MAX_WRONG - wrong) << "回";
      cout << "\n文字が表示されるよ\n" << used << endl;
      cout << "\n文字数は:　" << soFar << endl;
      

      char guess;
      cout << "あなたの答え: ";
      cin >> guess;
      guess = toupper(guess); 
      while (used.find(guess) != string::npos) {
        cout << "\nこの文字はすでに入力しているね" << guess << endl;
        cout << "もう一度入力してね: ";
        cin >> guess;
        guess = toupper(guess);
      }
      
      used += guess;
      if (THE_WORD.find(guess) != string::npos) {
        cout << guess << endl;
        for (int i = 0; i < THE_WORD.length(); ++i) {
          if (THE_WORD[i] == guess) {
            soFar[i] = guess;
            }
          }
        }
        else {
        cout << "ごめんね, " << guess << "は間違っている英文字だね\n";
        ++wrong;
        }
    }
   if(wrong == MAX_WRONG)
      {
        cout << "またチャレンジしてくれよな!!";
        break;
      }
      right++;
    kaisuu++;
    cout << "\n答えは: " << THE_WORD << "\n\n";
    }
  cout << "\nHARDクリアおめでとう!";
}