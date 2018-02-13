#include <iostream>
#include <vector>

using std::vector;

int main() {
    vector<int> n;
    vector<int> sum;
    int j = 0;
    int temp = 0;
    int m;
    
    while(std::cin >> m) {
        n.push_back(m);
        for (int i = 1; i <= n[j]; i++){
            temp += i;
        }
        sum.push_back(temp);
        j++;
        temp = 0;
    }
    for(int i = 0; i < j; i++) {
        std::cout << sum[i] << std::endl << std::endl;
    }
    
    return 0;
}
