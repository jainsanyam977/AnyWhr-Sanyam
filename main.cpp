#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct hash_pair { 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const
    { 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    } 
}; 

pair<int, int> get_head(int x, int y, int side){
   if(side==0){
       return {x, y-2};
   }
   else if(side==1){
       return {x+2, y-1};
   }
    else if(side==2){
       return {x+2, y+1};
   }
    else if(side==3){
       return {x, y+2};
   }
    else if(side==4){
       return {x-2, y+1};
   }
    else if(side==5){
       return {x-2, y-1};
   }
}

struct Hex{
    pair<int, int> head;
    string name;
};

int main()
{  
    //maps
    unordered_map<string, Hex *>um1;
    unordered_map<pair<int, int>, Hex *, hash_pair>um2;
    
    
    //side teller
    vector<int>sider(6);
    sider[0] = 3;
    sider[1] = 4;
    sider[2] = 5;
    sider[3] = 0;
    sider[4] = 1;
    sider[5] = 2;
    

    //1 - neighbors
    //2 - old new side
    
    
    while(true){
        int qu; cin>>qu;

        //to fetch neighbors
        if(qu==1){
            string s; cin>>s;
            if(!um1[s]){
                cout<<"INVALID QUERY"<<endl;
                continue;
            }
            Hex *temp = um1[s];
            pair<int, int>cor = temp->head;
            cout<<"Neighbors of "<<s<<" are:"<<endl;
            for(int i=0; i<6; i++){
                 pair<int, int>new_cor = get_head(cor.first,cor.second,i);
                 if(um2[new_cor]){
                     cout<<i<<" "<<um2[new_cor]->name<<endl;
                 }
            }
        }
        else if(qu==2){
            string old, nnew; int side;
            cin>>old>>nnew>>side;
            //first Hexagon
            if(old==nnew){
                Hex * temp = new Hex;
    			temp->head = {0, 0};
                temp->name = old;
    			um1[old] = temp;
    			um2[{0, 0}] = temp;
            }
            //not first
            else{
                pair<int, int>new_cor = get_head(um1[old]->head.first,um1[old]->head.second,side);
                Hex * temp = new Hex;
    			temp->head = {new_cor.first, new_cor.second};
                temp->name = nnew;
    			um1[nnew] = temp;
    			um2[{new_cor.first, new_cor.second}] = temp;
            }
            
            cout<<"Added "<<nnew<<"!"<<endl;
        }
        else{
            cout<<"Restart Program"<<endl;
            break;
        }
    }
    
	return 0;
}