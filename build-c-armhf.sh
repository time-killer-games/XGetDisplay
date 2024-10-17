cd "${0%/*}" 
git clone https://github.molgen.mpg.de/git-mirror/glibc.git
./glibc/configure --enable-static-nss
gcc -no-pie XDisplayGetters.c ExampleUsage.c -Wl,-Bstatic -static-libstdc++ -static-libgcc -lXinerama -lXrandr -lXext -lXrender -lX11 -lxcb -lXau -lXdmcp -Wl,-Bdynamic -ldl -o xgetdisplay-c-armhf -fPIC
