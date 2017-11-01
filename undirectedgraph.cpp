#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<map>
#include<vector>
#include<queue>
#include<set>
using namespace std;	

struct graphedge {
  int sour;
  int dest;
  graphedge(int s,int d):sour{s},dest{d}{};
};

typedef struct graphedge graphedge;

  vector<graphedge> graph;

int addedge(int source,int dest){
  graph.push_back(graphedge(source,dest));
  return 0;
}

int printEdges(){
  for(auto it = graph.begin();it!=graph.end();it++){
    cout<<it->sour<<" "<<it->dest<<endl;
  }
  return 0;
}


bool checkloop(){

   map<int,set<int>> edgesets;
  for(auto it = graph.begin();it!=graph.end();it++){
    if(edgesets.find(it->sour) == edgesets.end()){
      edgesets[it->sour].insert(it->sour);
    }
    if(edgesets.find(it->dest) == edgesets.end()){
      edgesets[it->dest].insert(it->dest);
    }
  }  
  for(auto it = graph.begin();it!=graph.end();it++){
    if(edgesets.find(it->sour) != edgesets.end()){
      if(edgesets[it->sour].find(it->dest) != edgesets[it->sour].end()){
	return true;
      }
    }
    if(edgesets.find(it->dest) != edgesets.end()){
      if(edgesets[it->dest].find(it->sour) != edgesets[it->dest].end()){

	return true;
      }
    }
    if((edgesets.find(it->sour) != edgesets.end()) && (edgesets.find(it->dest) != edgesets.end())){
      edgesets[it->sour].insert(edgesets[it->dest].begin(),edgesets[it->dest].end());
      edgesets[it->dest].insert(edgesets[it->sour].begin(),edgesets[it->sour].end());
    }
    
  }

return false;


}
int main (){
  addedge(1,2);
  //  addedge(2,0);
  addedge(1,0);
  addedge(0,3);
  addedge(3,4);
  /*  addedge(1,2);
  addedge(1,3);
  addedge(1,4);
  addedge(1,5);*/
  printEdges();
  bool loop=   checkloop();
  cout<<"loop "<<loop<<endl;
  return 0;
}





  
