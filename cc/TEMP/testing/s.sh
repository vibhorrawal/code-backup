echo "[*] gen.cc"
g++ gen.cc -o gen

# echo "[*] brute.cc"
# g++ brute.cc -o brute

echo "[*] prog.cc"
g++ 53.cc -o prog

echo
for((i = 1; ; ++i)); do
    echo -ne  "\\r[*] Testing on case: ${i}\t"

    # echo $i
    ./gen $i > int
    # ./a < int > out1
    # ./brute < int > out2
    # diff -w out1 out2 || break
    diff -w <(python3 53.py < int) <(python3 54.py < int) || break
done