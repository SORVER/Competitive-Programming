# Dynamic-Programming
## 0/1 Knapsack

> it's an example, a theif entered the house , he decided to take the most valuable things becuase he has a limited storage in his bag so you have two arrays one for the weight and other for the value also the bag capacity.
 
![Screenshot_3](https://user-images.githubusercontent.com/60802724/200031172-2a596480-3d14-4950-b87d-b38f85b2f6ae.png)

> we will use memoziation to optimize the time by saving the maximum of the route for every index and remainder of the capacity in the bag.
```cpp
#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define clr(x) memset(x, -1, sizeof(x));

using namespace std;
const int MAX = 4;
int w[MAX] = {1,2,3,5};
int v[MAX] = {1,6,10,16};
int cap = 7;
int memo[5][8];
int knapsack(int i , int reminder){
      if(i == MAX) return 0;
      if(memo[i][reminder] != -1) return memo[i][reminder];
      int ch1 = knapsack(i +1, reminder);
      int ch2 = 0;
      if(reminder - w[i]  >= 0) ch2 = knapsack(i+1, reminder - w[i]) + v[i];
      return memo[i][reminder] = max(ch1,ch2);
}
int main() {
    clr(memo);
    cout << knapsack(0,cap);
}

```
<!---
SORVER/SORVER is a ✨ special ✨ repository because its `README.md` (this file) appears on your GitHub profile.
You can click the Preview link to take a look at your changes.
--->
