#include <iostream>
using namespace std;
int main() {
    int n = 0;
    cout << "幾個產品?";
    cin >> n;
    int goods[n];
    for(int a = 0; a < n; a ++){
	    goods[a] = 0;
	}
    for(int i = 0; i < n; i ++){
        cout << "第" << i + 1 << "個商品多少元?";
        cin >> goods[i];
        goods[i] = 100 - goods[i];
    }
	for (int i = 0; i < n; i ++){
	    for (int j = 0; j < n - i; j ++){
	        if(goods[i] > goods[i + j]){
	            int number = goods[i];
	            goods[i] = goods[i + j];
	            goods[i + j] = number;
	        }
	    }
	}
    int change1 = 0;
	for (int j = 0; j < n; j ++){
	    if (goods[0] + goods[j] < 100){
	        change1 = goods[0] + goods[j];
	    } else {
	        change1 = goods[0] + goods[j - 1];
	        break;
	    }
	}
	int total = 0;
	for(int i = 0; i < n; i ++){
	    total = total + goods[i];
	}
	int change2 = (total - change1);
    int people2 = 0;
    for(int i = 1; i < n; i++){
        if (goods[i] != change1 - goods[0]){
            people2 = goods[i];
            break;
        }
    }
    if (n <= 3){
        if (change1 != goods[0]){
            cout << "第一個人買" << 100 - goods[0] << "元和" << 100 - (change1 - goods[0]) << "元" << endl;
            cout << "第二個人買" << 100 - people2 << "元" << endl;
        } else {
            cout << "第一個人買" << 100 - goods[0] << "元" << endl;
            cout << "第二個人買" << 100 - people2 << "元和" << 100 - (change2 - people2) << "元" << endl;
        }
    }
    
    
    return 0;
}