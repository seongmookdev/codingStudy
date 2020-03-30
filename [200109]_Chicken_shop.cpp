#include <iostream>
#include <vector>

using namespace std;

struct INFO{
    int y;
    int x;
};

vector<INFO> home, shop, pick;

int n, m, ret;

void dfs(int pos){
    if(pick.size() == m){
        int candi=0;
        for(int i=0; i<home.size(); ++i){
            int min_dist = 1e9;
            for(int j=0; j<pick.size(); ++j){
                min_dist = min(min_dist, abs(home[i].y-pick[j].y)+
                                         abs(home[i].x-pick[j].x));
            }
            candi += min_dist;
        }

        if(ret>candi) ret = candi;
        return;
    }

    for(int i=pos; i<shop.size(); ++i){
        pick.push_back(shop[i]);
        dfs(i+1);
        pick.pop_back();
    }
}

int main(){

    int type;
    INFO target;
    scanf("%d %d", &n, &m);
    for(int y=0; y<n; ++y){
        for(int x=0; x<n; ++x){
            scanf("%d", &type);
            if(type == 1){
                target.y = y;
                target.x = x;
                home.push_back(target);
            }
            else if(type == 2){
                target.y = y;
                target.x = x;
                shop.push_back(target);
            }
        }
    }

    ret = 1e9;
    dfs(0);
    printf("%d\n", ret);

    return 0;
}
