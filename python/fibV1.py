#!/usr/bin/python

def fib(num):
    if(num == 0):
        print 0
        return
    fib = []
    fib.append(1)
    fib.append(1)
    print fib[0],' ', fib[1],' ',
    for i in range(2, num):
        fib.append(fib[i-1] + fib[i-2])
        print fib[i],' ',
    return

def main():
    num = raw_input('Fibonacci up to: ')
    print 'The fibonacci sequence : ',
    fib(int(num))
    return

if __name__ == '__main__':
    main()
