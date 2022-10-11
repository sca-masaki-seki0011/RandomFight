#include <iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
string playername;

int main()
{
    srand(static_cast<unsigned int >(time(0)));
    int playernumber;
    int enemycount= 0;
    int playerHP =500;
    int playerAtack = 40;
    int enemyHP = 20;
    int enemyAtack = 20;
    
    cout << "ここは戦いが絶えないバトルコロシアム!"<<endl;
    cout << "君は迫りくる敵を何体倒すことができるかな?"<<endl;
    cout << "君の名前を英語かローマ字で教えてくれ"<<endl;
    cout << "PLAYERNAME: ";
    cin >> playername;
    cout << playername <<"よ、さあ行け!!" <<endl;
    cout << "バトルスタート!!!"<< endl;
    cout << "\n";
    while(playerHP != 0)
  {
    
    while(enemyHP != 0 || playerHP != 0){
    int enemyrandom = rand()%6+1;
    cout << "1~6までの整数を宣言しろ！！"<<endl;
    cout << "PLAYERNUMBER: ";
    cin >> playernumber;
    while(enemyrandom == playernumber || playernumber > 6)
      {
        int enemyrandom = rand()%6+1;
        cout << "もう一度1~6までの整数を宣言しろ！！"<<endl;
        cout << "PLAYERNUMBER: ";
        cin >> playernumber;
      }
    if(enemyrandom > playernumber)
    {
      cout << "Player: " << playernumber << " VS " << "Enemy: " << enemyrandom << endl;
      cout <<"敵の攻撃だ!"<<endl;
      playerHP -= enemyAtack;
      if(playerHP <= 0)
      {
        cout << playername << "の負けだ..." << endl;
        break;
      }
    }
    if(enemyrandom < playernumber)
    {
      cout << "Player: " << playernumber << " VS " << "Enemy: " << enemyrandom << endl;
      cout << playername <<"の攻撃だ!"<<endl;
      enemyHP -= playerAtack;
      if(enemyHP <= 0)
      {
        cout << playername << "の勝利だ!!" << endl;
        enemycount++;
        cout << enemycount << "体目撃破!!" << endl;
        enemyHP = 20*enemycount*2;
        enemyAtack += enemycount*2;
      }
    }
      }
    if(playerHP <= 0)
    {
      break;
    }
    
  }
  cout << playername << ": " << " 撃破数: " << enemycount << "体"<<endl;
  if(enemycount >= 15)
  {
      cout << "称号: 百戦錬磨を取得しました!"<<endl;
  }

  else if(enemycount >= 10)
  {
      cout << "称号: 孤軍奮闘を取得しました!"<<endl;
  }
  else if(enemycount >= 5)
  {
      cout << "称号: 力戦奮闘を取得しました!"<<endl;
  }
  else
  {
     cout << "もう一度チャレンジだ!!"<<endl;
  }
  
  
 return 0;

}
