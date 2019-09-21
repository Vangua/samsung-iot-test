// Used compilier: g++ (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

using Matrix = vector<vector<bool>>;

enum class TravelType
{
    depth,  // обход в глубину
    breadth // обход в ширину
};

bool contains(const vector<int>& vec, int val)
{
    for (const auto& item : vec)
        if (item == val)
            return true;
    return false;
}

void travel(Matrix matrix, int vertex, TravelType type)
{
    vector<int> used(1, vertex);
    vector<int> container;
    auto getVertex = type == TravelType::breadth ? 
        [] (vector<int>& container) {
            int vrtx = container.front();
            container.erase(container.begin());
            return vrtx;}
       :[] (vector<int>& container) {
            int vertex = container.back();
            container.pop_back();
            return vertex;};

    for (int i = 0; i < matrix.size(); ++i)
        if (matrix[vertex][i])
            container.push_back(i);

    while (container.size())
    {
        vertex = getVertex(container);
        if ( contains(used, vertex) )
            continue;

        for (int i = 0; i < matrix.size(); ++i)
            if (matrix[vertex][i] and !contains(used, i))
                container.push_back(i);
        used.push_back(vertex);
    }

    for (auto item : used)
        cout << item << " ";
    cout << endl;
}

int main()
{
    Matrix vertex_matrix = {{ 0, 1, 1, 1, 1 },
                            { 1, 0, 0, 0, 1 },
                            { 1, 0, 0, 1, 0 },
                            { 1, 0, 1, 0, 0 },
                            { 1, 1, 0, 0, 0 } };
    travel(vertex_matrix, 1, TravelType::breadth);
    travel(vertex_matrix, 1, TravelType::depth);
    return 0;
}
