#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <algorithm>



struct Graf {
    std::map <std::string,std::vector<std::string>> adj_list;
};

void add_edge(Graf& graf, cont std::string& a, const std::string& b){
    graf.adj_list[a].push_back(b);
    graf.adj_list[b].push_back(a);
}

std::vector<std::string> znajdz_najkrotsza_droge(const Graf& graf, const std::string& poczatek,const std::string& koniec) {
    std::map<std::string, bool> odwiedzone;
    std::map<std::string, bool> rodzic;
    std::queue<std::string> q;

    for(const auto& pair : graf.adj_list){
        odwiedzone[pair.first]= false;
    }
    odwiedzone[poczatek]=true;
    q.push(poczatek);
    while (!q.empty()){
        std::string current = q.front();
        q.pop();
        if (current==koniec){
            std::vector<std::string> path;
            while (current != poczatek){
                path.push_back(current);
                current = rodzic[current];
            }
            path.push_back (poczatek);
            reverse(path.begin(), path.end());
            return path;
        }
        for(const auto& neighbor : graf.adj_list.at(current)){
            if(!odwiedzone[neighbor]){
                odwiedzone[neighbor]=true;
                rodzic[neighbor]=current;
                q.push(neighbor);
            }
        }
    }
    return std::vector<std::string>();
}

int main(){

    int n;
    std::cin>> n; 
    Graf graf;

    for(int i=0;i<n;i++){
        std::string przystanek;
        std::cin >> przystanek;
        graf.adj_list[przystanek] = std::vector<std::string> ();
    }

    int m;
    std::cin>>m;

    for(int i=0;i<m;i++){
        std::string linia;
        std::cin>> linia;
        std::string przystanek;
        while(std::cin>>przystanek && przystanek!=linia){
            add_edge(graf,linia,przystanek);
        }
    }

    std::string poczatek, koniec;
    std::cin >> poczatek >> koniec;

    std::vector<std::string> najkrotsza_droga = znajdz_najkrotsza_droge (graf,poczatek,koniec);
    
    if(najkrotsza_droga.empty()){
        std::cout<< "NO ROUTE" << std::endl;
    } else {
        for(const auto& koniec : najkrotsza_droga){
            std::cout << koniec << " ";
        }
        std::cout<<std::endl;
    }

    return 0;
    
    }