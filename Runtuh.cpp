#include <iostream>
using namespace std;

int main() {
    int R, C; 
    cin >> R >> C; 

    int array[R][C];

    // Perbaiki loop untuk membaca masukan
    for(int i = 0; i < R; i++) {
        string a; 
        cin >> a; 
        for(int j = 0; j < C; j++) { // Menggunakan j untuk iterasi kolom
            if(a[j] == '0') array[i][j] = 0; 
            else array[i][j] = 1;     
        }
    }

    bool done = false;
    while(!done) {
        done = true; 
        int fullB = R; 
        for(int i = R - 1; i >= 0; i--) {
            bool full = true; 
            for(int j = 0; j < C; j++) {
                if(array[i][j] == 0){
                    full = false; 
                    break;
                }
            }
            if(full) {
                done = false; 
                if(fullB == R) fullB = i;
                for(int j = 0; j < C; j++) array[i][j] = 0; 
            }
        }
        if (!done) {
            int atas[C];
            for(int i = 0; i < C; i++) {
                atas[i] = 0; 
                for(int j = 0; j < fullB; j++) {
                    atas[i] = atas[i] + array[j][i];
                    array[j][i] = 0 ; 
                }
                int bawah = fullB; 
                while(bawah < R - 1 && array[bawah + 1][i] == 0) bawah++; // Perbaiki indeks dan kondisi loop
                for(int j = 0; j < atas[i]; j++) array[bawah - j][i] = 1; 
            }
        }
    }

    // Menampilkan hasil akhir
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            cout << array[i][j];
        }
        cout << endl;
    }

    return 0; 
}
 
