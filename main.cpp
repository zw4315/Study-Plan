//
//  main.cpp
//  schedule
//
//  Created by Edward WU on 2018/9/1.
//  Copyright © 2018年 Edward WU. All rights reserved.

#include <iostream>
#include <vector>
#include <string>

using namespace std;
string Day[7];
int year, month,date,day,StartPosition,amount,EndPosition,TTimePeriod;
int NdaysOfMonth;
string Xingqi,name;
vector<int> Basic;
vector<vector<int>> Total;
bool valid = false;



int nyear(int year)//判断是平年，还是润年
{
    if(year%400==0||(year%4==0&&year%100!=0))
        return 366;
    else
        return 365;
}

int nmonth(int m,int y)  //根据年份和月份，判断是那一个月的天数
{
    if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
        return 31;
    else if(nyear(y)==366&&m==2)
        return 29;
    else if(nyear(y)==365&&m==2)
        return 28;
    else
        return 30;
}

string DayOfWeek(int d){
    d = d-1;
    Day[0] = "星期一" ;
    Day[1] = "星期二" ;
    Day[2] = "星期三" ;
    Day[3] = "星期四" ;
    Day[4] = "星期五" ;
    Day[5] = "星期六" ;
    Day[6] = "星期日" ;
    return Day[d];
}

int main() {
    int NOfWeek = 1;
    cout << " Hey!!!!! @_@  你从何年何月何日开始学习呢？" <<endl;
    cin >> year >> month >> date;
    cout << " Hey!!!!! @_@  这一天是周几" <<endl;
    cin >> day;
    cout << " Hey!!!!! @_@  学习什么科目呀？ " <<endl;
    cin>> name;
    cout << " Hey!!!!! @_@ 第几章开始学习至第几章呀？？？ " <<endl;
    cin >>StartPosition >> EndPosition ;
    cout << " Hey!!!!! @_@ 预计多少天完成呢？？ " <<endl;
    cin >> TTimePeriod;
    
        cout <<"                    《"<< name <<"》"<<" 学习计划 "<<endl;
        cout <<"第 "<<NOfWeek<<" 周" <<endl;
        NdaysOfMonth = nmonth( month, year);
        Xingqi = DayOfWeek(day);
        amount =((EndPosition - StartPosition)/TTimePeriod)+1;
        
        
        int index = 0;
        int count = 0;
        int TimePeriod = 0;
        
        
        while( TimePeriod<TTimePeriod ){
            while (date <= NdaysOfMonth) {
                for(int i = 0; i < amount; i++){
                    Basic.push_back(StartPosition);
                    StartPosition = StartPosition+1;
                }
                
                if(index >0){                               //day 2
                    for(int i= 0; i<amount;i++){
                        Basic.push_back(Total[index-1][i]);
                    }
                }
                
                if(index >1){                          // day 3
                    for(int i= 0; i<amount;i++){
                        Basic.push_back(Total[index-2][i]);
                    }
                }
                
                if(index >3){                             //day 5
                    for(int i= 0; i<amount;i++){
                        Basic.push_back(Total[index-4][i]);
                    }
                }
                
                if(index >6){                                   //day 8
                    for(int i= 0; i<amount;i++){
                        Basic.push_back(Total[index-7][i]);
                    }
                }
                
                
                if(index >14){                                   //day 16
                    for(int i= 0; i<amount;i++){
                        Basic.push_back(Total[index-15][i]);
                    }
                }
                
                Total.push_back(Basic);
                Basic.clear();
                
                for(int j=0; j<Total[index].size();j++){
                    if(Total[index][j] <= EndPosition){
                        valid = true;
                    }
                }
                
                if(valid){
                    if(day ==1){
                            cout <<"第 "<<NOfWeek<<" 周" <<endl;
                    }
                    cout << year << "年" << month << "月" << date << "日" << "    " << Xingqi <<"    " ;
                }
                
                
                
                
                for(int j=0; j<Total[index].size();j++){
                    if(Total[index][j] <= EndPosition){
                        cout << "第" <<Total[index][j] << "课" <<"   ";
                        count++;
                    }
                }
                
                
                if(valid){
                    cout <<"    "<< "总共有 " << count <<" 课"<< endl;
                }
                count = 0;
                index++;
                day++;
                TimePeriod++;
                
                
                if(day == 8){
                    day = 1;
                    NOfWeek++;
                    cout <<endl <<endl <<endl;
                }
                
                Xingqi = DayOfWeek(day);
                date++;
                valid = false;
            }
            
            date = 1;
            month++;
            NdaysOfMonth = nmonth( month, year);
        }
    
    return 0;
}


