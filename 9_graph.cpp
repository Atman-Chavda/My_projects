#include <bits/stdc++.h>
using namespace std;
class graph
{
    unordered_map<string, unordered_set<string>> adjlist;

public:
    bool addv(string vertex)
    {
        if (adjlist.count(vertex) == 0)
        {
            adjlist[vertex];
            return true;
        }
        return false;
    }
    bool adde(string vertex1, string vertex2)
    {
        if (adjlist.count(vertex1) != 0 && adjlist.count(vertex2) != 0)
        {
            adjlist.at(vertex1).insert(vertex2);
            adjlist.at(vertex2).insert(vertex1);
            return true;
        }
        return false;
    }
    bool remedge(string vertex1, string vertex2)
    {
        if (adjlist.count(vertex1) != 0 && adjlist.count(vertex2) != 0)
        {
            adjlist.at(vertex1).erase(vertex2);
            adjlist.at(vertex2).erase(vertex1);
            return true;
        }
        return false;
    }
    void display()
    {
        for (auto vertex = adjlist.begin(); vertex != adjlist.end(); vertex++)
        {
            cout << vertex->first << ": [ "; // prints vertex
            for (auto edge = vertex->second.begin(); edge != vertex->second.end(); edge++)
            {
                cout << edge->data() << " "; // prints edge
            }
            cout << "]" << endl;
        }
    }
    bool remvertex(string vertex)
    {
        if(adjlist.count(vertex)!=0)
        {
            for(auto othervertex:adjlist.at(vertex))
            {
                adjlist.at(othervertex).erase(vertex);
            }
            adjlist.erase(vertex);
            return true;
        }
        return false;
    }
};
int main()
{
    graph* g=new graph();
    g->addv("A");
    g->addv("B");
    g->display();
    g->adde("A","B");
    g->display();
    g->remedge("A","B");
    g->display();
    g->remvertex("A");
    g->display();
    return 0;
}