#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<map>
#include<vector>
#include<queue>
#include<set>
#include<list>
#include<stack>
using namespace std;	


map <int,list<int>> graph;

int addedge(int sn, int dn){
  //  list<int> emptylist;
    graph[sn].push_back(dn);
    if(graph.find(dn) == graph.end()){
      graph[dn];// = emptylist;
    }
    return 0;
}

int printGraph(){

  auto it = graph.begin();
  while(it != graph.end()){
    cout<<it->first<<"\n";
    for(auto lit = it->second.begin();lit != it->second.end();lit++){
      cout<<*lit<<" ";    
    }
    cout<<"\n";
    it++;
  }
}


int helptopsort(int val,map<int,bool> &visited,stack <int> &sorted){

  if(visited.find(val) == visited.end()){
    visited[val] = true;
    //cout<<val<<" ";
    for(auto it = graph[val].begin();it != graph[val].end();it++){

      helptopsort(*it,visited,sorted);      
    }

    sorted.push(val);
    
  }
  return 0;
   
}

int topologicalsort(){

  map<int,bool> visited;
  stack <int> sorted;
  auto it = graph.begin();
  auto lit = it->second.begin();

  while(it != graph.end()){

        helptopsort(it->first,visited,sorted);
	//    helptopsort(3,visited,sorted);
    it++;
  }
  
 
  while (!sorted.empty()) {
    cout <<" " << sorted.top();
    sorted.pop();
  }
    
  return 0;  
}



int main (){

    addedge(5, 2);
    addedge(5, 0);
    addedge(4, 0);
    addedge(4, 1);
    addedge(2, 3);
    addedge(3, 1);
    printGraph();
    //    topologicalsort();

  return 0;  
}
