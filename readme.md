# Welcome to JOS

## Writeup

[JOS](http://www.fatwaer.store/en/categories/%E6%93%8D%E4%BD%9C%E7%B3%BB%E7%BB%9F/) is operating system kernel, supporting memory management, preemptive multitasking, file system and network !

1. [boot](http://www.fatwaer.store/en/posts/%E6%93%8D%E4%BD%9C%E7%B3%BB%E7%BB%9F/lab1/)
2. [memory management](http://www.fatwaer.store/en/posts/%E6%93%8D%E4%BD%9C%E7%B3%BB%E7%BB%9F/6-828-%E6%93%8D%E4%BD%9C%E7%B3%BB%E7%BB%9F%E5%B7%A5%E7%A8%8B-lab2-memory-management/)
3. [Process](http://www.fatwaer.store/en/posts/%E6%93%8D%E4%BD%9C%E7%B3%BB%E7%BB%9F/6-828-%E6%93%8D%E4%BD%9C%E7%B3%BB%E7%BB%9F%E5%B7%A5%E7%A8%8B-lab3-user-environments/)
4. [Multi-Tasking](http://www.fatwaer.store/en/posts/%E6%93%8D%E4%BD%9C%E7%B3%BB%E7%BB%9F/6-828-%E6%93%8D%E4%BD%9C%E7%B3%BB%E7%BB%9F%E5%B7%A5%E7%A8%8B-lab4-preemptive-multitasking/)
5. [file system](http://www.fatwaer.store/en/posts/%E6%93%8D%E4%BD%9C%E7%B3%BB%E7%BB%9F/6-828-%E6%93%8D%E4%BD%9C%E7%B3%BB%E7%BB%9F%E5%B7%A5%E7%A8%8B-lab5-file-system-spawn-and-shell/)
5. [network](http://www.fatwaer.store/en/posts/%E6%93%8D%E4%BD%9C%E7%B3%BB%E7%BB%9F/6-828-%E6%93%8D%E4%BD%9C%E7%B3%BB%E7%BB%9F%E5%B7%A5%E7%A8%8B-lab6-network-driver/)


## Make grade

### Boot

``` bash
running JOS: (1.5s) 
  printf: OK 
  backtrace count: OK 
  backtrace arguments: OK 
  backtrace symbols: OK 
  backtrace lines: OK 
Score: 50/50
```

### Memory Management

``` bash
divzero: OK (1.6s)
    (Old jos.out.divzero failure log removed)
softint: OK (2.2s)
    (Old jos.out.softint failure log removed)
badsegment: OK (1.9s)
    (Old jos.out.badsegment failure log removed)
Part A score: 30/30

faultread: OK (1.9s)
faultreadkernel: OK (2.1s)
faultwrite: OK (2.0s)
faultwritekernel: OK (1.9s)
breakpoint: OK (1.2s)
testbss: OK (1.8s)
hello: OK (2.1s)
buggyhello: OK (2.0s)
buggyhello2: OK (2.0s)
evilhello: OK (2.1s)
Part B score: 50/50

Score: 80/80
```

### User Environment

``` bash
divzero: OK (1.0s)
softint: OK (1.0s)
badsegment: OK (1.0s)
Part A score: 30/30

faultread: OK (1.0s)
faultreadkernel: OK (1.9s)
faultwrite: OK (1.2s)
faultwritekernel: OK (2.0s)
breakpoint: OK (1.9s)
testbss: OK (2.1s)
hello: OK (1.9s)
buggyhello: OK (2.2s)
    (Old jos.out.buggyhello failure log removed)
buggyhello2: OK (1.9s)
    (Old jos.out.buggyhello2 failure log removed)
evilhello: OK (2.1s)
    (Old jos.out.evilhello failure log removed)
Part B score: 50/50
```

### Preemptive Multitasking

``` bash
dumbfork: OK (2.1s)
Part A score: 5/5

faultread: OK (1.4s)
faultwrite: OK (1.9s)
faultdie: OK (1.9s)
faultregs: OK (2.0s)
faultalloc: OK (2.1s)
faultallocbad: OK (2.0s)
faultnostack: OK (2.0s)
faultbadhandler: OK (1.9s)
faultevilhandler: OK (1.2s)
forktree: OK (2.0s)
Part B score: 50/50

spin: OK (2.0s) 
stresssched: OK (2.4s)
sendpage: OK (2.0s)
pingpong: OK (2.0s)
primes: OK (4.4s)
Part C score: 25/25

Score: 80/80
```

### File System

``` bash
internal FS tests [fs/test.c]: OK (2.6s)
  fs i/o: OK
  check_bc: OK
  check_super: OK
  check_bitmap: OK
  alloc_block: OK
  file_open: OK
  file_get_block: OK
  file_flush/file_truncate/file rewrite: OK
testfile: OK (2.3s)
  serve_open/file_stat/file_close: OK
  file_read: OK
  file_write: OK
  file_read after file_write: OK
  open: OK
  large file: OK
spawn via spawnhello: OK (2.4s)
Protection I/O space: OK (2.4s)
    (Old jos.out.faultio failure log removed)
PTE_SHARE [testpteshare]: OK (2.3s)
PTE_SHARE [testfdsharing]: OK (1.4s)
start the shell [icode]: Timeout! OK (31.1s)
testshell: OK (4.0s)
primespipe: OK (6.7s)
Score: 150/150

```

### Network Driver

``` bash
testtime: OK (8.0s)
pci attach: OK (1.2s)
testoutput [5 packets]: OK (2.2s)
testoutput [100 packets]: OK (2.6s)
Part A score: 35/35

testinput [5 packets]: OK (2.7s)
testinput [100 packets]: OK (1.7s)
tcp echo server [echosrv]: OK (2.3s)
web server [httpd]:
  http://localhost:26002/: OK (1.4s)
  http://localhost:26002/index.html: OK (1.3s)
  http://localhost:26002/random_file.txt: OK (2.5s)
Part B score: 70/70

Score: 105/105
```
