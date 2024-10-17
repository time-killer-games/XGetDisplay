cd "${0%/*}" 
git clone https://github.molgen.mpg.de/git-mirror/glibc.git
./glibc/configure --enable-static-nss --disable-sanity-checks
gcc -no-pie XDisplayGetters.c ExampleUsage.c -static-libstdc++ -static-libgcc -lXinerama -lXrandr -lXext -lXrender -lX11 -lxcb -lXau -lXdmcp -ldl -static -o xgetdisplay-c-armhf -fPIC
rm -fr glibc bits config.log config.h config.make config.status Makefile
