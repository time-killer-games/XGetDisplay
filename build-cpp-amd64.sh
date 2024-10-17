cd "${0%/*}" 
git clone https://github.molgen.mpg.de/git-mirror/glibc.git
./glibc/configure --enable-static-nss --disable-sanity-checks
g++ -no-pie XDisplayGetters.cpp ExampleUsage.cpp -static-libstdc++ -static-libgcc -lXinerama -lXrandr -lXext -lXrender -lX11 -lxcb -lXau -lXdmcp -ldl -static -m64 -o xgetdisplay-cpp-amd64 -fPIC -m64
rm -fr glibc bits config.log config.h config.make config.status Makefile
