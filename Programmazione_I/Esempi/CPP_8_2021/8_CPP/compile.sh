for f in `ls -1 *cpp`; do
  g++ -Wall $f -o `echo $f |  sed -e s/\.cpp//`
done
