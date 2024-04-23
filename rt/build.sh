set -e

if [ "$1" == "glamour" ]; then
    echo "glamour markdown renderer"
    go build -buildmode=c-archive
    patch -u < fixsrch.patch
    tcc -DUSE_GLAMOUR -c rt.c
    cp src.a rt.a
    ar -r rt.a rt.o
    echo "generated rt.a"
elif [ "$1" == "txt" ]; then
    echo "no markdown renderer"
    tcc -c rt.c
    ar -rs rt.a rt.o
    echo "generated rt.a"
else
    echo "Invalid usage! ./build.sh [glamour|txt]"
    exit 1
fi
