#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    vector<vector<bool>> dist(n, vector<bool>(n,false)),r_dist(n, vector<bool>(n,false));
    for(int i = 0; i< n; i++)
        r_dist[i][i] = dist[i][i] = true;
    for(auto i : results)
        dist[i[1]-1][i[0]-1] = r_dist[i[0]-1][i[1]-1]= true;
    for(int i = 0; i<n; i++)
        for(int j = 0; j< n; j++)
            if(i != j)
                for(int k = 0; k<n; k++)
                    if(k != i)
                    {
                        if(!dist[j][k]) dist[j][k] = (dist[j][i])&(dist[i][k]);
                        if(!r_dist[j][k]) r_dist[j][k] = r_dist[j][i]&r_dist[i][k];
                    }
    for(int i = 0; i<n; i++)
    {
        int sum = 0;
        for(int j = 0; j<n; j++)
            sum += dist[i][j] + r_dist[i][j];
        if(sum == n+1) answer++;
    }

    return answer;
}
