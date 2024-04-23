set -e
set -o xtrace

if [ "$1" == "glamour" ]; then
    echo "glamour markdown renderer"
    go build -buildmode=c-archive
    patch -u < fixsrch.patch 1>/dev/null 2>/dev/null || true
    $CC -DUSE_GLAMOUR=1 $CFLAGS -c ../rt.c -o rt.o
    cp src.a rt.a
    ar -r rt.a rt.o
    echo "generated rt.a"
elif [ "$1" == "txt" ]; then
    echo "no markdown renderer"
    $CC $CFLAGS -c ../rt.c -o rt.o
    ar -rs rt.a rt.o
    echo "generated rt.a"
else
    echo "Invalid usage! ./build.sh [glamour|txt]"
    exit 1
fi
