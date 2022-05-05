# linux-kernel-driver

This project is a kernel module that lists all current tasks in a Linux system beginning from the init task. The output is given as task name (known as executable name), state and process id of each task in a tree structure.

Follow the below steps to run this in ubuntu terminal:
$ sudo apt install linux-headers-$(uname -r)
$ make
$ sudo insmod *.ko
$ lsmod
$ sudo dmesg
$ sudo apt-get install tree
$ tree
