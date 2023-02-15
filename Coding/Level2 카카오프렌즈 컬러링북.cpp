#include <vector>

using namespace std;

int space(int y, int x, vector<vector<int>> &pic, const int &m, const int &n){
    int num = 1;
    ++pic[y][x] *= -1;
    int comp = -1*pic[y][x]-1;
    if(x > 0 && comp == pic[y][x-1]) num += space(y, x-1, pic,m,n);
    if(y > 0 && comp == pic[y-1][x]) num += space(y-1, x, pic,m,n);
    if(x+1 < n && comp == pic[y][x+1]) num += space(y, x+1, pic,m,n);
    if(y+1 < m && comp == pic[y+1][x]) num += space(y+1, x, pic, m, n);
    return num;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    vector<vector<int>> pic(picture.begin(), picture.end());
    vector<int> answer(2);
    for(int i = 0; i< m; i++){
        for(int j = 0; j < n; j++){
            int cur = pic[i][j];
            if(cur <= 0) continue;
            number_of_area++;
            int sp = space(i,j,pic,m,n);
            if(sp > max_size_of_one_area) max_size_of_one_area = sp;
        }
    }
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
