#include<iostream>
#include<unordered_set>
#include<vector>

using namespace std;

int main() {
    
    int n;
    cout << "Enter the size of the first set" << endl;
    cin >> n;

    int array1[n];
    cout << "Enter the elements in the set" << endl;

    for (int i = 0; i < n; i++) {
        cin >> array1[i];
    }

    int z;
    cout << "Enter the size of the second set" << endl;
    cin >> z;

    int array2[z];
    cout << "Enter the elements in the set" << endl;

    for (int j = 0; j < z; j++) {
        cin >> array2[j];
    }

    cout << "Enter 1 for intersection" << endl;
    cout << "Enter 2 for union" << endl;
    cout << "Enter 3 for subtraction (first set - second set)" << endl;
    
    int q;
    cin >> q;

    if (q == 1) {
        // Calculate intersection
        unordered_set<int> set1(array1, array1 + n);
        vector<int> intersection;

        for (int i = 0; i < z; i++) {
            if (set1.find(array2[i]) != set1.end()) {
                intersection.push_back(array2[i]);
            }
        }

        cout << "Intersection: ";
        for (int i : intersection) {
            cout << i << " ";
        }
    } else if (q == 2) {
        // Calculate union
        unordered_set<int> set_union(array1, array1 + n);
        set_union.insert(array2, array2 + z);

        cout << "Union: ";
        for (int i : set_union) {
            cout << i << " ";
        }
    } else if (q == 3) {
        // Calculate subtraction (first set - second set)
        unordered_set<int> set1(array1, array1 + n);
        unordered_set<int> set2(array2, array2 + z);
        vector<int> subtraction;

        for (int i : set1) {
            if (set2.find(i) == set2.end()) {
                subtraction.push_back(i);
            }
        }

        cout << "Subtraction (first set - second set): ";
        for (int i : subtraction) {
            cout << i << " ";
        }
    } else {
        cout << "Invalid input. Please enter 1, 2, or 3 for intersection, union, or subtraction." << endl;
    }

    return 0;
}
