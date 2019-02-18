import time;
import itertools;

# Meminta input
def inputUser():
    print ('Masukkan input empat angka!')
    line = input()
    line = [int(i) for i in line.split()]
    return (line)

# Membuat himpunan setiap kemungkinan permutasi
def allPossibles(source):
    target = list(itertools.permutations(source))
    target = set(target)
    return (target)

# Membuat kemungkinan dari setiap operasi
def allOperators():
    source = ['+', '-', '*', '/', '+', '-', '*', '/', '+', '-', '*', '/']
    operates = list(itertools.permutations(source, 3))
    operates = set(operates)
    return (operates)

# Mencari semua kemungkinan dari operand dan operator yang tersedia
def count24(operands, operators):
    solution = []
    count = 0
    for a in operands:
        for b in operators:
            # ((a + b) + c) + d
            try:
                str1 = '((' + str(a[0]) + b[0] + str(a[1]) + ')' + b[1] + str(a[2]) + ')' + b[2] + str(a[3])
                if (eval(str1) == 24):
                    print(str1)
                    count = count + 1
            except:
                pass
            # (a + b) + (c + d)
            try:
                str2 = '(' + str(a[0]) + b[0] + str(a[1]) + ')' + b[1] + '(' + str(a[2]) + b[2] + str(a[3]) + ')'
                if (eval(str2) == 24):
                    print(str2)
                    count = count + 1
            except:
                pass
            # (a + (b + c)) + d
            try:
                str3 = '(' + str(a[0]) + b[0] + '(' + str(a[1]) + b[1] + str(a[2]) + '))' + b[2] + str(a[3])
                if (eval(str3) == 24):
                    print(str3)
                    count = count + 1
            except:
                pass
            # a + ((b + c) + d)
            try:
                str4 = str(a[0]) + b[0] + '((' + str(a[1]) + b[1] + str(a[2]) + ')' + b[2] + str(a[3]) + ')'
                if (eval(str4) == 24):
                    print(str4)
                    count = count + 1
            except:
                pass
            # a + (b + (c + d))
            try:
                str5 = str(a[0]) + b[0] + '(' + str(a[1]) + b[1] + '(' + str(a[2]) + b[2] + str(a[3]) + '))'
                if (eval(str5) == 24):
                    print(str5)
                    count = count + 1
            except:
                pass
    return (count)

# Program utama
def main():
    a = inputUser()
    print (a)
    b = allPossibles(a)
    print (b)
    c = allOperators()
    print(len(c))
    solutions = count24(b, c)
    print('Jumlah solusi yang ada:', solutions)

main()
