bool isBipartite(vector<vector<int>> graph) 
{ 
    int numOfVertices = graph.size();
    vector<int> colorArr(numOfVertices, -1); 
    queue<int> myQueue; 

    for (int start = 0; start < numOfVertices; ++start) {
        if (colorArr[start] == -1) {
            colorArr[start] = 1;
            myQueue.push(start); 

            while (!myQueue.empty()) 
            { 
                int u = myQueue.front(); 
                myQueue.pop();

                for (int v : graph[u]) 
                { 
                    if (colorArr[v] == -1) 
                    { 
                        colorArr[v] = 1 - colorArr[u]; 
                        myQueue.push(v); 
                    } 
                    else if (colorArr[v] == colorArr[u]) 
                        return false; 
                }
            }
        }
    } 
    return true; 
}
