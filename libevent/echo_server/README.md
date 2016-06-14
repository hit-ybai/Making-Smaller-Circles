## Setup Testing Environment:
### Download, untar the source code and enter the directory:
```
wget github.com/downloads/libevent/libevent/libevent-2.0.20-stable.tar.gz
tar -xzvf libevent-2.0.20-stable.tar.gz
cd libevent-2.0.20-stable
```
### Configure, make and install the libraries:
```
./configure
make
sudo make install
```
### Compiling and Testing
```
gcc -Wall -levent main.c -o server
./server

echo -n 'test' | nc -U /tmp/mysocket1
```
