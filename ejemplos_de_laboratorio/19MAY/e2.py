def recur_fibo(n):
    if n <=2:
        return n

    else:
        return(recur_fibo(n-1) + recur_fibo(n-2))

nterms = 13

if nterms <= 0:
    print("Ingrese un numero positivo ")
else:
    print("Secuencia Fibonacci: ")    
    for i in range(nterms):
        print(recur_fibo(i))
