#include <vector>

struct Set
{
    int rep, size;
    Set() {}
    Set(int vertex)
    {
        rep = vertex;
        size = 1;
    }
};

struct Graph
{
    std::vector<Set> sets;
    int num_sets;
    Graph() {}
    Graph(int num_vertices)
    {
        num_sets = num_vertices;
        sets.resize(num_vertices);
        for (int i = 0; i < num_vertices; ++i)
        {
            sets[i] = Set(i);
        }
    }

    int find_set(int vertex)
    {
        int curr = vertex, next;
        while (sets[vertex].rep != vertex)
        {
            vertex = sets[vertex].rep;
        }
        while (sets[curr].rep != vertex)
        {
            next = sets[curr].rep;
            sets[curr].rep = vertex;
            curr = next;
        }
        return vertex;
    }

    void union_set(int vertex1, int vertex2)
    {
        int rep1 = find_set(vertex1), rep2 = find_set(vertex2);
        if (rep1 == rep2) { return; }
        if (sets[rep1].size >= sets[rep2].size)
        {
            sets[rep1].size += sets[rep2].size;
            sets[rep2].size = 0;
            sets[rep2].rep = rep1;
        }
        else
        {
            sets[rep2].size += sets[rep1].size;
            sets[rep1].size = 0;
            sets[rep1].rep = rep2;
        }
        --num_sets;
    }
};

int findCircleNum(std::vector<std::vector<int>>& isConnected) 
{
    Graph union_find(isConnected.size());
    for (int i = 0; i < isConnected.size(); ++i)
    {
        for (int j = 0; j < isConnected[i].size(); ++j)
        {
            if (i != j && isConnected[i][j]) 
            { 
                union_find.union_set(i, j); 
            }
        }
    }
    return union_find.num_sets;
}