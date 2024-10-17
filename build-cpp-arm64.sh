cd "${0%/*}" 
git clone git://github.molgen.mpg.de/git-mirror/glibc.git
./glibc/configure --enable-static-nss
g++ -no-pie XDisplayGetters.cpp ExampleUsage.cpp -Wl,-Bstatic -static-libstdc++ -static-libgcc -lXinerama -lXrandr -lXext -lXrender -lX11 -lxcb -lXau -lXdmcp -Wl,-Bdynamic -ldl -o xgetdisplay-cpp-arm64 -fPIC
