#include <iostream>
#include <vector>
#include <list>
#include <queue>

struct WeightedEdge
{
    int vertex;
    double cost;
    WeightedEdge(int vertex, double cost) : vertex(vertex), cost(cost){}
};

class Graph
{
 private:
  std::vector<std::list<WeightedEdge> > graph;
 public:
  
   Graph(std::vector<std::list<WeightedEdge> > v) : graph(v)
  {
    
  }
   

   void addVertex()
   {
      std::list<WeightedEdge> dummy;
      graph.push_back( dummy );
   }


   void removeVertex(int vertex)
   {
       graph[vertex].clear();
       graph.erase(graph.begin() + vertex);
   }

   void print(int start)
   {
       std::vector<bool> used(graph.size(), false);
       used[start] = true;
       std::queue<int> q;
       q.push(start);

       while(!q.empty())
       {
           int u = q.front();
           q.pop();
           std::cout << u << ' ';
           for(auto it = graph[u].begin(); it != graph[u].end(); ++it)
           {
               if(!used[it->vertex])
               {
                   used[it->vertex] = true;
                   q.push(it->vertex);
               }
           }
       }
   }
};

int main()
{
    std::list<WeightedEdge> lis1{ {2, 3}, {3, 4}};
    std::list<WeightedEdge> lis2{{3, 1}, {4, 2}};
    std::list<WeightedEdge> lis3{{0, 5}, {1, 2}};
    std::list<WeightedEdge> lis4{{2, 1}};
    std::list<WeightedEdge> lis5{{3, 4}};

   std::vector<std::list<WeightedEdge>> v;
   v.push_back(lis1);
   v.push_back(lis2);
   v.push_back(lis3);
   v.push_back(lis4);
   v.push_back(lis5);
    // 
    // 
    Graph gr(v);
    gr.print(0);
}