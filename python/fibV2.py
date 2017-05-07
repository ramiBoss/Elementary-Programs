#!/usr/bin/python

def fib(num):
    if(num == 0):
        return 0
    if(num == 1): 
        return 1
    return fib(num-1)+fib(num-2)

def main():
    num = raw_input('Fibonacci up to: ')
    print 'The fibonacci sequence : ',
    print fib(int(num))
    return

if __name__ == '__main__':
    main()
