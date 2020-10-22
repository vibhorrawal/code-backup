echo "[*] gen.cc"
g++ gen.cc -o gen

echo "[*] brute.cc"
g++ brute.cc -o brute

echo "[*] prog.cc"
g++ cc-AMCS03.cc -o prog

echo
for((i = 1; ; ++i)); do
    echo -ne  "\\r[*] Testing on case: ${i}\t"

    # echo $i
    ./gen $i > int
    # ./a < int > out1
    # ./brute < int > out2
    # diff -w out1 out2 || break
    diff -w <(./brute < int) <(./prog < int) || break
done
