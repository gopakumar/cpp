#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<map>
#include<vector>
#include<queue>
using namespace std;	

struct graphnode {
  int val;
  graphnode(int x):val{x}{};
};

typedef struct graphnode graphnode;
//This is the Grap reprecentation withe node and its vertices
map<graphnode *,vector<graphnode *>> graph;
 
//DS to locate a grap node addres using its value

map<int,graphnode*> nodearray;



int printGraphNodes(){

  for( auto it = nodearray.begin();it != nodearray.end();it++){
    cout<<"val:"<<  it->second->val;
  }
  return 0;
}


int printGraphNodeandEdges(){

  for( auto it = graph.begin();it != graph.end();it++){
    cout<<"Node:"<<(it->first)->val<<"\nEdges:";
    auto nodelist = it->second;
    for(int i=0; i< nodelist.size();i++){
      cout<<(nodelist[i])->val<<",";
    }
    cout<<"\n";
  }
  return 0;
}
  
void addGraphNode(int val){


  if( nodearray.find(val) == nodearray.end()){
    nodearray[val] = new graphnode(val);
  }else{
    cout<<"value alrady there not insearting"<<endl;
  }

  
}

void addEdge(int snode, int dnode){

  if(nodearray.find(snode)!=nodearray.end() && nodearray.find(dnode) != nodearray.end()){

    graph[nodearray[snode]].push_back(nodearray[dnode]);
    //  graph[nodearray[dnode]].push_back(nodearray[snode]);
  }else{
    cout<<"unable to add Edge"<<endl;
  }
  
}


int BFS(int startnodeval){

  graphnode *startnode = nodearray[startnodeval];
  map<graphnode*,bool> visitednodes;
  queue<graphnode *> nodequeue;

  nodequeue.push(startnode);
  cout<<endl<<"BFS:"<<startnodeval<<":";
  while(nodequeue.size() != 0){
    graphnode *currnode = nodequeue.front();
    nodequeue.pop();
    if(!(visitednodes[currnode])){
	cout<<" "<<currnode->val;
	visitednodes[currnode] = true;	
	for(auto it = graph[currnode].begin();it != graph[currnode].end();it++){
	  nodequeue.push(*it);
	}
    }
  }
  return 0;
}

graphnode * findnodeptr(int val){

  if(nodearray.find(val) != nodearray.end()){
    return (nodearray.find(val)->second);
  }
}

void debug_visitednodes(map<graphnode *, bool> &visitednodes){
  cout<<endl;
  for(auto it = visitednodes.begin();it != visitednodes.end();it++){
    cout<<(it->first)->val<<":"<<it->second<<",";
  }
  cout<<endl;
  
}

int DFS(int startnodeval,map<graphnode *, bool> &visitednodes){
  //  graphnode *currnode = nodearray[startnodeval];
  graphnode *currnode = findnodeptr(startnodeval);
  if(!(visitednodes[currnode])){
    visitednodes[currnode] = true;
    cout<<currnode->val<<">";
    //    debug_visitednodes(visitednodes);
    for(auto it = graph[currnode].begin();it != graph[currnode].end();it++){
      DFS((*it)->val,visitednodes);
    }
  }  
  return 0;
}


bool checkloop(int startnodeval,bool loop_present){//, map<graphnode *,bool> &graphpath){

    static   map<graphnode *,bool> graphpath;

  if(!loop_present){
    //  graphnode *currnode = nodearray[startnodeval];
    graphnode *currnode = findnodeptr(startnodeval);
    for(auto it = graph[currnode].begin();it != graph[currnode].end();it++){
      if(graphpath.find(*it)== graphpath.end()){
	graphpath[*(it)]= true;
	debug_visitednodes(graphpath);
	loop_present = checkloop((*it)->val,loop_present);//,graphpath);
	graphpath.erase(*it);
      }
      else
	loop_present = true;
    }
  }

  return loop_present;
 
}

int main (){

  addGraphNode(0);
  addGraphNode(1);
  addGraphNode(2);
  addGraphNode(3);
  //  addGraphNode(4);

  //addEdge(0,1);
  // addEdge(0,2);

  addEdge(0,0);
  // addEdge(2,3);

  //  addEdge(1,3);
  //  addEdge(3,3);

  //  addEdge(2,1);

  
  //  printGraphNodes();
  //    printGraphNodeandEdges();
    // DFS();
    BFS(2);
    BFS(1);
    BFS(0);
    BFS(3);
    cout<<endl;
    map<graphnode *, bool> visitednodes;
    DFS(2,visitednodes);
    map<graphnode *,bool> graphpath;
    bool loop_present = checkloop(0,false);//,graphpath);
    cout<<endl<<"loop Present:"<<loop_present<<endl;
  return 0;
}
