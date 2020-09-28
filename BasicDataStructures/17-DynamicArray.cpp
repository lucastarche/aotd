//Dynamic Array
//An array which you can insert more elements, and you can resize on the go. In this case, it is implemented as a static array, which we double in size every time we run out of space.
//pop_back() works in O(1), and push_back() works in O(1), except when we need to move the elements to a new array, when it works in O(n). Given that we double in size each time, it works in amortized O(1).
//The creation of the Dynamic Array works in O(n)
//size() works in O(1)
#include <bits/stdc++.h>

using namespace std;

template <typename T>
class DynamicArray {
    private:
        int len, used;
        T *arr;

        int nextPow2(int n) {
            return pow(2, ceil(log(n)/log(2)));
        }
    public:
        DynamicArray<T>() {
            arr = new T[1];
            len = 1;
            used = 0;
        }

        DynamicArray<T>(int n) {
            n = nextPow2(n);
            arr = new T[n];
            len = n;
            used = 0;
        }

        DynamicArray<T>(int n, T val) {
            used = n;
            n = nextPow2(n);
            arr = new T[n];
            len = n;
            for (int i = 0; i < used; i++) {
                arr[i] = val;
            }
        }

        T operator[](int n) {
            return arr[n];
        }

        int size() {
            return used;
        }

        T pop_back() {
            T temp = arr[used - 1];
            arr[used - 1] = (T)0;
            used--;
            return temp;
        }

        void push_back(T val) {
            if (used == len) {
                len = len<<1;
                T *temp = arr;
                arr = new T[len];
                for (int i = 0; i < len / 2; i++) {
                    arr[i] = temp[i];
                }

                delete temp;
            }
            arr[used] = val;
            used++;
        }
};

int main() {
    int n;
    cin >> n;
    DynamicArray<int> arr;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    while (arr.size() > 0) {
        cout << arr.pop_back() << " ";
    }

    cout << '\n';
}
