#include<iostream>
#include<cstdlib>
#include<string>
#include<random>
#include<algorithm>
#include<chrono>
using namespace std;


int randnum()
{
  const bool ohm = false;

  string n = "0123456789";

  shuffle( n.begin(), n.end(),
    mt19937( chrono::high_resolution_clock::now().time_since_epoch().count() )
    );
    
  if (ohm && (n[ 0 ] == '0'))
    n = n.substr( 1, 4 );
  else 
    n.resize( 4 );
  int a;
  a=stoi(n);
  return a;
}
int randgen()
{
  int a;
  int b=0;
  while(b!=1)
  {
    a=randnum();
    if(a/1000!=0)b=1;
  }
  return a;
}

int main(){

  int opp_team_id;
  cin >> opp_team_id;

  int mynumber=randgen();
  bool answer;
  int reply,creply,breply;
  int mytemp,m1,m2,m3,m4;
  mytemp = mynumber;
  m4 = mytemp%10;
  mytemp = mytemp/10;
  m3 = mytemp%10;
  mytemp = mytemp/10;
  m2 = mytemp%10;
  mytemp = mytemp/10;
  m1 = mytemp%10;
  cout  <<mynumber<<endl;
  cin>>answer;

  int a,b,c,d;
  int count =0;
  int numbers[4536];        
  int index =0;

  for(int num=1001; num<=9999; num++){

    int i = num;
    d = i%10;
    a = i/1000;
    i = i/10;
    c = i%10;
    i = i/10;
    b = i%10;

    if (a !=b && a!= c && a!= d && b!=c && b!=d && c !=d){
      numbers[index] = num;  
      index++;
    }
  }
  int s, random=0, bulls, cows; 

  if(answer){
    while(bulls !=4&&random<=4536){
     if(numbers[random]==0){random++;} 
      else{
        cout<< numbers[random]<<endl;
        s= numbers[random];
        cin >> bulls >> cows;
        cin>>reply;
        int reptemp,rep1,rep2,rep3,rep4;
        reptemp=reply;
        rep4 = reptemp%10;
        reptemp = reptemp/10;
        rep3 = reptemp%10;
        reptemp = reptemp/10;
        rep2 = reptemp%10;
        reptemp = reptemp/10;  
        rep1 = reptemp%10;  
        creply=0;breply=0;

        if(m1==rep1){
          breply++;
          rep1=11;
          if(m1==rep2){
            rep2=11;
          }
          if(m1==rep3){
            rep3=11;
          } 
          if(m1==rep4){
           rep4=11;
          }
        }

        if(m2==rep2){
          breply++;
          rep2=11;
          if(m2==rep1){
            rep1=11;
          }
          if(m2==rep3){
            rep3=11;
          }
          if(m2==rep4){
            rep4=11;
          }
        }

        if(m3==rep3){
          breply++;
          rep3=11;
          if(m3==rep1){
            rep1=11;
          }
          if(m3==rep2){
            rep2=11;
          }
          if(m3==rep4){
            rep4=11;
          }
        }

        if(m4==rep4){
          breply++;
          rep4=11;
          if(m4==rep1){
            rep1=11;
          }
          if(m4==rep2){
            rep2=11;
          }
          if(m4==rep3){
            rep3=11;
          }
        }

        if(rep1==m2 || rep1 == m3 || rep1 == m4 ){
          creply++;
          if(rep2==rep1){
            rep2=11;
          }
          if(rep3==rep1){
            rep3=11;
          }
          if(rep4==rep1){
            rep4=11;
          }
        }
        if(rep2==m1 || rep2 == m3 || rep2 == m4 ){
          creply++;
          if(rep1==rep2){
            rep1=11;
          }
          if(rep3==rep2){
            rep3=11;
          }
          if(rep4==rep2){
            rep4=11;
          }
        }
        if(rep3==m1 || rep3 == m2 || rep3 == m4 ){
          creply++;
          if(rep1==rep3){
            rep1=11;
          }
          if(rep2==rep3){
            rep2=11;
          }
          if(rep4==rep3){
            rep4=11;
          }
        }
        if(rep4==m1 || rep4 == m2 || rep4 == m3 ){
          creply++;
          if(rep1==rep4){
            rep1=11;
          }
          if(rep2==rep4){
            rep2=11;
          }
          if(rep3==rep4){
            rep3=11;
          }
        }
        cout<<breply<<endl<<creply<<endl;

        int element=0;

        while(element!= 4536){

          int numofcows = 0;
          int temp,d1,d2,d3,d4;
          temp =s;
          d4 = temp%10;
          d1 = temp/1000;
          temp = temp/10;
          d3 = temp%10;
          temp = temp/10;
          d2 = temp%10;

          int key,v1,v2,v3,v4;
          key = numbers[element];
          v4 = key%10;
          v1 = key/1000;
          key = key/10;
          v3 = key%10;
          key = key/10;
          v2 = key%10;

          if(d1==v2 || d1 == v3 || d1 == v4 ){numofcows++;}
          if(d2==v1 || d2 == v3 || d2 == v4 ){numofcows++;}
          if(d3==v1 || d3 == v2 || d3 == v4 ){numofcows++;}
          if(d4==v1 || d4 == v2 || d4 == v3 ){numofcows++;}

          int numofbulls=0;

          if(d1==v1){numofbulls++;}
          if(d2==v2){numofbulls++;}
          if(d3==v3){numofbulls++;}
          if(d4==v4){numofbulls++;}
    
          if(numofcows != cows || numofbulls != bulls){
            numbers[element]= 0;
          }
          element++;
        }
        random++;
      }
    }
    
  }

  else{
    while(bulls !=4&&random<=4536){
      if(numbers[random]==0){random++;} 
      else{
        cin>>reply;
        int reptemp,rep1,rep2,rep3,rep4;
        reptemp=reply;
        rep4 = reptemp%10;
        reptemp = reptemp/10;
        rep3 = reptemp%10;
        reptemp = reptemp/10;
        rep2 = reptemp%10;
        reptemp = reptemp/10;  
        rep1 = reptemp%10;  
        creply=0;breply=0;

        if(m1==rep1){
         breply++;
         rep1=11;
          if(m1==rep2){
            rep2=11;
          }
          if(m1==rep3){
            rep3=11;
          } 
          if(m1==rep4){
           rep4=11;
          }
        }

        if(m2==rep2){
          breply++;
          rep2=11;
          if(m2==rep1){
            rep1=11;
          }
          if(m2==rep3){
            rep3=11;
          }
          if(m2==rep4){
            rep4=11;
          }
        }

        if(m3==rep3){
          breply++;
          rep3=11;
          if(m3==rep1){
            rep1=11;
          }
          if(m3==rep2){
            rep2=11;
          }
          if(m3==rep4){
            rep4=11;
          }
        }

        if(m4==rep4){
          breply++;
          rep4=11;
          if(m4==rep1){
            rep1=11;
          }
          if(m4==rep2){
            rep2=11;
          }
          if(m4==rep3){
            rep3=11;
          }
        }
      
        if(rep1==m2 || rep1 == m3 || rep1 == m4 ){
          creply++;
          if(rep2==rep1){
            rep2=11;
          }
          if(rep3==rep1){
            rep3=11;
          }
          if(rep4==rep1){
            rep4=11;
          }
        }
        if(rep2==m1 || rep2 == m3 || rep2 == m4 ){
          creply++;
          if(rep1==rep2){
            rep1=11;
          }
          if(rep3==rep2){
            rep3=11;
          }
          if(rep4==rep2){
            rep4=11;
          }
        }
        if(rep3==m1 || rep3 == m2 || rep3 == m4 ){
          creply++;
          if(rep1==rep3){
            rep1=11;
          }
          if(rep2==rep3){
            rep2=11;
          }
          if(rep4==rep3){
            rep4=11;
          }
        }
        if(rep4==m1 || rep4 == m2 || rep4 == m3 ){
          creply++;
          if(rep1==rep4){
            rep1=11;
          }
          if(rep2==rep4){
            rep2=11;
          }
          if(rep3==rep4){
            rep3=11;
          }
        }
        cout<<breply<<endl<<creply<<endl;
        cout<< numbers[random]<<endl;
        s= numbers[random];
        cin >> bulls >> cows;


        int element=0;

        while(element!= 4536){

          int numofcows = 0;
          int temp,d1,d2,d3,d4;
          temp =s;
          d4 = temp%10;
          d1 = temp/1000;
          temp = temp/10;
          d3 = temp%10;
          temp = temp/10;
          d2 = temp%10;

          int key,v1,v2,v3,v4;
          key = numbers[element];
          v4 = key%10;
          v1 = key/1000;
          key = key/10;
          v3 = key%10;
          key = key/10;
          v2 = key%10;

          if(d1==v2 || d1 == v3 || d1 == v4 ){numofcows++;}
          if(d2==v1 || d2 == v3 || d2 == v4 ){numofcows++;}
          if(d3==v1 || d3 == v2 || d3 == v4 ){numofcows++;}
          if(d4==v1 || d4 == v2 || d4 == v3 ){numofcows++;}

          int numofbulls=0;

          if(d1==v1){numofbulls++;}
          if(d2==v2){numofbulls++;}
          if(d3==v3){numofbulls++;}
          if(d4==v4){numofbulls++;}
      
          if(numofcows != cows || numofbulls != bulls){
            numbers[element]= 0;
          }
          element++;
        }
        random++;
      }
    }
    

  }
  return 0;
}