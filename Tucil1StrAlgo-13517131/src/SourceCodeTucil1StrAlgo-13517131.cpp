/* NIM          : 13517131
   Nama         : Jan Meyer Saragih
   Mata Kuliah  : Strategi Algoritma
   Kelas        : K-02              */

#include <iostream>   // Input dan output
#include <time.h>     // Menghitung waktu eksekusi
using namespace std;

// GLOBAL VARIABLES
float a, b, c, d;
int count = 0;

int e[25], f[25], g[25], h[25];
int Neff = 0;

// DECLARE VOIDS AND FUNCTIONS
void AddtoArray(int a, int b, int c, int d);
// Mencari tahu apakah susunan angka a, b, c, dan d terdapat dalam array
// Jika ada, maka angka tersebut tidak dimasukkan ke dalam array
// Jika tidak, maka angka tersebut dimasukkan ke dalam array dan Neff ditambah 1

void readNumbers();
// Membaca keempat angka untuk permainian 24

void check24 (int w, int x, int y, int z);
// Mengecek apakah hasilnya dapat mendapatkan angka 24 atau tidak

void countResult (int w, int x, int y, int z, int i, int j, int k);
// Menghitung hasil dari kombinasi angka dan operator yang direpresentasikan oleh angka
// w, x, y, z adalah keempat angka positif yang telah diinput
// i, j, k adalah operator-operator yang dihasilkan dari for di count24

float calculate (float a, float b, int sign);
// Menghitung operasi dengan 2 buah float dan 1 operator yang diwakili angka

char represent (int sign);
// Mengembalikan char yang direpresentasikan oleh angka
// Berfungsi untuk print solusi yang mungkin

// MAIN PROGRAM
int main()
{
  // KAMUS
  int i;

  // ALGORITMA

  // Input keempat angka
  cout << "TUGAS KECIL 1 STRATEGI ALGORITMA" << endl;
  cout << "Nama: Jan Meyer Saragih" << endl;
  cout << "NIM: 13517131" << endl;
  cout << "Kelas: K-02" << endl;
  cout << "Permainan 24" << endl << endl;
  readNumbers();

  // Mencari solusi
  cout << "Mencari solusi..." << endl;
  clock_t start = clock();

  // Karena terdapat 4 buah angka, maka terdapat 4! = 24 buah kemungkinan
  // susunanan angka
  // Jika terdapat angka yang berbeda, maka terdapat solusi yang sama
  AddtoArray(a, b, c, d);
  AddtoArray(a, b, d, c);
  AddtoArray(a, c, b, d);
  AddtoArray(a, c, d, b);
  AddtoArray(a, d, b, c);
  AddtoArray(a, d, c, b);
  AddtoArray(b, a, c, d);
  AddtoArray(b, a, d, c);
  AddtoArray(b, c, a, d);
  AddtoArray(b, c, d, a);
  AddtoArray(b, d, a, c);
  AddtoArray(b, d, c, a);
  AddtoArray(c, a, b, d);
  AddtoArray(c, a, d, b);
  AddtoArray(c, b, a, d);
  AddtoArray(c, b, d, a);
  AddtoArray(c, d, a, b);
  AddtoArray(c, d, b, a);
  AddtoArray(d, a, b, c);
  AddtoArray(d, a, c, b);
  AddtoArray(d, b, a, c);
  AddtoArray(d, b, c, a);
  AddtoArray(d, c, a, b);
  AddtoArray(d, c, b, a);

  for (i = 1; i <= Neff; i++)
  {
    check24(e[i], f[i], g[i], h[i]);
  }
  cout << endl << "Terdapat " << count << " buah solusi" << endl;

  // Print lama waktu eksekusi
  printf("Waktu eksekusi: %.5fs\n", (float)(clock() - start)/CLOCKS_PER_SEC);

  return 0;
}

void readNumbers()
// Membaca keempat angka untuk permainian 24
{
  cout << "Masukkan keempat angka yang mungkin" << endl;
  cin >> a >> b >> c >> d;
  cout << "Angka yang diproses adalah..." << endl;
  cout << a << ", " << b << ", " << c << ", dan " << d << endl << endl;
}

void AddtoArray(int a, int b, int c, int d)
// Mencari tahu apakah susunan angka a, b, c, dan d terdapat dalam array
// Jika ada, maka angka tersebut tidak dimasukkan ke dalam array
// Jika tidak, maka angka tersebut dimasukkan ke dalam array dan Neff ditambah 1
{
  // Kamus lokal
  int i;
  bool found;

  // Algoritma
  found = false;
  i = 1;

  while (i <= Neff && not found)
  {
    if (a == e[i] && b == f[i] && c == g[i] && d == h[i])
    {
      found = true;
    }
    else
    {
      i++;
    }
  }
  if (not found)
  {
    Neff++;
    e[Neff] = a;
    f[Neff] = b;
    g[Neff] = c;
    h[Neff] = d;
  }
}

void check24 (int w, int x, int y, int z)
// Mengecek apakah hasilnya dapat mendapatkan angka 24 atau tidak
{
  // Berfungsi sebagai operator
  int i, j, k;

  // Terdapat 3 buah operator yang membatasi keempat angka karena
  // di antara 2 angka, terdapat 1 operator
  for (i = 1; i <= 4; i++)
  {
    for (j = 1; j <= 4; j++)
    {
      for (k = 1; k <= 4; k++)
      {
        countResult (w, x, y, z, i, j, k);
      }
    }
  }
}

void countResult (int w, int x, int y, int z, int i, int j, int k)
// Menghitung hasil dari kombinasi angka dan operator yang direpresentasikan oleh angka
// w, x, y, z adalah keempat angka positif yang telah diinput
// i, j, k adalah operator-operator yang dihasilkan dari for di count24
{
  // Float ini berfungsi menyimpan hasil perhitungan
  float a;

  // ((w + x) + y) + z
  a = calculate(calculate(calculate((float)w, (float)x, i), (float) y, j), (float)z, k);
  if (a > 23.99999 && a < 24.00001)
  {
    count++;
    cout << "((" << w << " " << represent(i) << " " << x << ") " <<
      represent(j) << " " << y << ") " << represent(k) << " " << z << endl;
  }
  // (w + x) + (y + z)
  a = calculate(calculate((float)w, (float)x, i), calculate((float) y, (float) z, k), j);
  if (a > 23.99999 && a < 24.00001)
  {
    count++;
    cout << "(" << w << " " << represent(i) << " " << x << ") " <<
      represent(j) << " (" << y << " " << represent(k) << " " << z << ")" << endl;
  }
  // (w + (x + y)) + z
  a = calculate(calculate((float)w, calculate((float)x, (float)y, j), i), (float) z, k);
  if (a > 23.99999 && a < 24.00001)
  {
    count++;
    cout << "(" << w << " " << represent(i) << " (" << x << " " << represent(j) <<
      " " << y << ")) " << represent(k) << " " << z << endl;
  }
  // w + ((x + y) + z)
  a = calculate((float)w, calculate(calculate((float)x, (float)y, j), (float)z, k), i);
  if (a > 23.99999 && a < 24.00001)
  {
    count++;
    cout << w << " " << represent(i) << " ((" << x << " " << represent(j) << " " <<
      y << ") " << represent(k) << " " << z << ")" << endl;
  }
  // w + (x + (y + z))
  a = calculate((float)w, calculate((float)x, calculate((float)y, (float)z, k), j), i);
  if (a > 23.99999 && a < 24.00001)
  {
    count++;
    cout << w << " " << represent(i) << " (" << x << " " << represent(j) << " (" <<
      y << " " << represent(k) << " " << z << "))" << endl;
  }
}

float calculate (float a, float b, int sign)
// Menghitung operasi dengan 2 buah float dan 1 operator yang diwakili angka
{
  if (sign == 1)
  {
    return (a + b);
  }
  else if (sign == 2)
  {
    return (a - b);
  }
  else if (sign == 3)
  {
    return (a * b);
  }
  else if (sign == 4)
  {
    return ((float)a / (float)b);
  }
}

char represent (int sign)
// Mengembalikan char yang direpresentasikan oleh angka
// Berfungsi untuk print solusi yang mungkin
{
  if (sign == 1)
  {
    return ('+');
  }
  if (sign == 2)
  {
    return ('-');
  }
  if (sign == 3)
  {
    return ('*');
  }
  if (sign == 4)
  {
    return ('/');
  }
}
