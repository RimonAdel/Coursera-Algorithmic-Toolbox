#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;


int SearchSmallerThanOrEqual(int value, int low, vector<int> & stops){
    int result = -1;
    for (;low<stops.size();low++){
        if(value >= stops[low]){
            result = low;
        }else{
            break;
        }
    }
    return result;
}

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    int maxConveredDist = 0;
    int converedDist = 0;
    int refileCount = 0;
    int nextPetrolStationIndex = 0;
    maxConveredDist += tank;
    while (dist > maxConveredDist){
        nextPetrolStationIndex = SearchSmallerThanOrEqual(converedDist+tank, nextPetrolStationIndex, stops);
        maxConveredDist = stops[nextPetrolStationIndex] + tank;
        if(nextPetrolStationIndex == -1){
            return -1;
        }
        converedDist = stops[nextPetrolStationIndex];
        nextPetrolStationIndex += 1; 
        refileCount += 1;
    }
    return refileCount;
}

int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);


    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";



    return 0;
}
