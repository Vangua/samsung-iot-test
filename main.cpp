// g++ (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0

#include <iostream>

#define SIZE 5

using std::cout;
using std::endl;


int main()
{
    int vertex_matrix [SIZE][SIZE] =  { 0, 1, 1, 0, 0,
                                        1, 0, 0, 0, 0,
                                        1, 0, 0, 0, 1,
                                        0, 0, 0, 0, 1,
                                        0, 0, 1, 1, 0 };
    
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
            cout << vertex_matrix[i][j] << '\t';
        cout << endl;
    }
    return 0;
}
