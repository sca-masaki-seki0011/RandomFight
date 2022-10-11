#include <iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
string playername;//playerの名前
//このプログラム(ゲーム)がアドベンチャーゲームになっているか
//は分からないので違ったら改めて違うものをコーディングするので
//そのときは教えていただけると助かります

int main()
{
    srand(static_cast<unsigned int >(time(0)));
    int playernumber;//playerの整数入力変数
    int enemycount= 0;//敵の撃破変数
    int playerHP =500;//playerのHP
    int playerAtack = 40;//playerの攻撃力
    int enemyHP = 20;//enemyのHP
    int enemyAtack = 20;//enemyの攻撃力
    
    cout << "ここは戦いが絶えないバトルコロシアム!"<<endl;
    cout << "君は迫りくる敵を何体倒すことができるかな?"<<endl;
    cout << "君の名前を英語かローマ字で教えてくれ"<<endl;
    cout << "PLAYERNAME: ";
    cin >> playername;//playerの名前入力
    cout << playername <<"よ、さあ行け!!" <<endl;
    cout << "バトルスタート!!!"<< endl;
    cout << "\n";
    while(playerHP != 0)//playerのHPが0じゃなかったら
  {
    //playerとenemyのHPが0じゃなかったら
    while(enemyHP != 0 || playerHP != 0){
    int enemyrandom = rand()%6+1;//enemyの整数を乱数で生成
    cout << "1~6までの整数を宣言しろ！！"<<endl;
    cout << "PLAYERNUMBER: ";
    cin >> playernumber;//playerの整数入力
    while(enemyrandom == playernumber || playernumber > 6)
      {
        int enemyrandom = rand()%6+1;//enemyの再度整数を乱数で生成
        cout << "もう一度1~6までの整数を宣言しろ！！"<<endl;
        cout << "PLAYERNUMBER: ";
        cin >> playernumber;//playerの再度整数入力
      }
    if(enemyrandom > playernumber)//enemyの整数がplayer整数より大きければ
    {
      cout << "Player: " << playernumber << " VS " << "Enemy: " << enemyrandom << endl;
      cout <<"敵の攻撃だ!"<<endl;
      playerHP -= enemyAtack;//playerのHPからenemyの攻撃変数分引く
      if(playerHP <= 0) //ここでplayerのHPが0じゃないかを確認
      {
        cout << playername << "の負けだ..." << endl;
        break;
      }
    }
    if(enemyrandom < playernumber)//enemyの整数がplayer整数より小さければ
    {
      cout << "Player: " << playernumber << " VS " << "Enemy: " << enemyrandom << endl;
      cout << playername <<"の攻撃だ!"<<endl;
      enemyHP -= playerAtack;//enemyのHPからplayerの攻撃変数分引く
      if(enemyHP <= 0)//enemyのHPが0じゃないかの確認
      {
        cout << playername << "の勝利だ!!" << endl;
        enemycount++;//enemy撃破変数に+1
        cout << enemycount << "体目撃破!!" << endl;
        //enemyは倒されるたびに強い敵が襲い掛かってくるという
        //設定なのでenemyのHPと攻撃変数を増やしていく
        enemyHP = 20*enemycount*2;//enemyのHPが0に減ってるから
                                  //改めて20を足してそれに
                                  //enemy撃破変数の2倍の値をかける
        enemyAtack += enemycount*2;//enemy撃破変数の2倍の値を
                                   //enemyの攻撃変数に足す
      }
    }
      }
    if(playerHP <= 0)//ここでもplayerのHPが0じゃないかの確認
    {
      break;
    }
    
  }
  cout << playername << ": " << " 撃破数: " << enemycount << "体"<<endl;
  if(enemycount >= 15)//enemy撃破数が15以上だったら
  {
      cout << "称号: 百戦錬磨を取得しました!"<<endl;
  }

  else if(enemycount >= 10)//enemy撃破数が10以上だったら
  {
      cout << "称号: 孤軍奮闘を取得しました!"<<endl;
  }
  else if(enemycount >= 5)//enemy撃破数が5以上だったら
  {
      cout << "称号: 力戦奮闘を取得しました!"<<endl;
  }
  else//そのほか
  {
     cout << "もう一度チャレンジだ!!"<<endl;
  }
  
  
 return 0;

}
