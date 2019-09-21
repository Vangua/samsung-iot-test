// Used compilier: g++ (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0

#include <iostream>
#include <vector>

#define SIZE 5

using std::cout;
using std::endl;
using std::vector;

bool contains(const vector<int>& vec, int val)
{
    for (const auto& item : vec)
        if (item == val)
            return true;
    return false;
}

// обход в ширину
void bf(bool matrix[SIZE][SIZE], int vertex)
{
    vector<int> used(1, vertex);
    vector<int> queue;

    for (int i = 0; i < SIZE; ++i)
        if (matrix[vertex][i])
            queue.push_back(i);

    while (queue.size())
    {
        vertex = queue.front();
        queue.erase(queue.begin());
        
        if ( contains(used, vertex) )
            continue;
        
        for (int i = 0; i < SIZE; ++i)
            if (matrix[vertex][i] and !contains(used, vertex))
                queue.push_back(i);
        
        used.push_back(vertex);
    }
 
    for (auto item : used)
        cout << item << " ";
    cout << endl;

}

// обход в глубину
void df(bool matrix[SIZE][SIZE], int vertex)
{
    vector<int> used(1, vertex);
    vector<int> stack;

    for (int i = 0; i < SIZE; ++i)
        if (matrix[vertex][i])
            stack.push_back(i);

    while (stack.size())
    {
        vertex = stack.back();
        stack.pop_back();
        
        if ( contains(used, vertex) )
            continue;
        
        for (int i = 0; i < SIZE; ++i)
            if (matrix[vertex][i] and !contains(used, vertex))
                stack.push_back(i);
        
        used.push_back(vertex);
    }

    for (auto item : used)
        cout << item << " ";
    cout << endl;
}

int main()
{
    bool vertex_matrix [SIZE][SIZE] = { 0, 1, 1, 1, 1,
                                        1, 0, 0, 0, 1,
                                        1, 0, 0, 1, 0,
                                        1, 0, 1, 0, 0,
                                        1, 1, 0, 0, 0 };
    bf(vertex_matrix, 1);
    df(vertex_matrix, 1);
    return 0;
}

