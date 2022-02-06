#!/usr/bin/env python
# coding: utf-8

# In[1]:


print((2**9-12))


# In[2]:


1/120


# In[3]:


(0.95+0.7)/2


# In[4]:


0.6*0.95+0.4*0.7


# In[6]:


0.8*4000/(0.8*4000+0.9*6000)


# In[7]:


10**0.5


# In[1]:


a = int(input())
b = int(input())
print(a+b)
print(a-b)
print(b-a)
print(a*b)
print(a/b)
print(b%a)
print(a**b)


# In[ ]:


# put your python code he
a = int(input())
b = int(input())
c = int(input())
p=(a+b+c)/2
s=(p*(p-a)*(p-b)*(p-c))**0.5
print(2*p)
print(s)


# In[ ]:


l = int(input())
x1 = int(input())
x2 = int(input())
xm = int(input())
t = l/(x1+x2)
print(t*xm/l)


# In[ ]:


a = int(input())
b = int(input())
print(int(0.5*a*b))
print(round(0.5*a*b,1))
print(0.5*a*b)


# In[ ]:


a = int(input())
print(int(11*a*a*(3**0.5)/4))


# In[3]:


# put your python code here
a = input().split()
s=0
for i in range(len(a)):
    s+=int(a[i])
print(s)





# In[ ]:


a = input().split()
b = input().split()
s1=0
s2=0
for i in range(len(a)):
    s1+=int(a[i])
for i in range(len(a)):
    s2+=int(b[i])
print(a,b,sep="#")


# In[ ]:


a = input().split("&")
a=set(a)
print(*a)


# In[ ]:


a = input().split()
print(a[1],a[2],a[-2])


# In[5]:


a = input().split()
print(*a[::-1],sep="-$-")


# In[7]:


a = input().lower().split()
k=0
for i in a:
    if i=="one":
        k+=1
print(len(a),k)


# In[ ]:


a = input().split()
ans=0
for i in range(len(a)):
    ans+=int(a[i])
print(ans)


# In[ ]:


a=input()
b=input()
print(a,b,sep="$")


# In[ ]:


B2=""
for i in range(len(B1)):
    if i%2==1:
        B2 += B1[i]


# In[ ]:


B2=""
B2 += B1[len(B1)-2]


# In[29]:


a=[]
a=input().split("', '")
a[0]=a[0][2:len(a)]
x=len(a)-1
a[x]=a[x][0:len(a[x])-2]
L = a.copy() # your code
print(L)


# In[ ]:


a=int(input())
if a==0:
    print("Division by zero!")
else:
    b=int(input())
    print(b/a)


# In[30]:


a=input()
if a=="str":
    b=input()
    if b:
        print(b)
    else:
        print("Empty String")
elif a=="int":
    b=int(input())
    c=int(input())
    if b==0 and c==0:
        print(b+c)
    else:
        print("Empty Ints")
elif a=="list":
    b=input().split()
    if not b:
        print("Empty List")
    else:
        print(b[-1])
else:
    print("Unknown type")


# In[ ]:


a=input()
if a=="1":
    print("I")
elif a=="5":
    print("V")
elif a=="10":
    print("X")
elif a=="50":
    print("L")
elif a=="100":
    print()
elif a=="500":
    print("D")
elif a=="1000":
    print("M")


# In[ ]:


a = int(input())
k=0
while k<a:
    if k % 2 == 0:
        print(k*k)
    k+=1


# In[ ]:


a = ""
k=0
while a!="The End":
    a = input();
    k+=int(a)


# In[ ]:


a = input().split()
for i in a:
    if i[0]!='*':
        print(i)


# In[ ]:


a=int(input())
for i in range(2,a):
    if a%i==0:
        print(i)
        break


# In[ ]:


a = int(input())
k=1
while k<abs(a):
    print(k*k*k)
    k+=1


# In[ ]:


def dfactorial(n):
    if n ==0:
        return 1
    k=1
    flag=False
    if n%2==0:
        flag=True
    for i in range(1,n+1):
        if (flag and i%2==0):
            k*=i
        elif (not(flag)and i%2==1):
            k*=i
    return k


# In[ ]:


def Kfactorial(n,k):
    ans=1
    while n>0:
        ans*=n
        n-=k
    return(ans)


# In[ ]:


#your code
def convert(L):
    for i in range(len(L)):
        L[i]=int(L[i])
    return L


# In[51]:


def translate(n,s=2):
    list1=[]
    ans=""
    while n>0:
        k=n%s
        list1.append(k)
        n = int(n/s)
    mySeparator = ""
    print (mySeparator.join(list1[::-1]))
    return mySeparator.join(list1[::-1])
        
translate(19)


# In[ ]:


def factorial(n):
    k=1
    for i in range(1,n):
        k*=i
    return k
def sf(n):
    k=1
    for i in range(1,n):
        k*=factorial(i)
    return k


# In[ ]:


def convert(L):
    for i in range(len(L)):
        L[i]=int(L[i])
    return L

def maxId(L):
    convert(L)
    for i in range(len(L)):
        if (L[i]==max(L)):
            return i





# In[ ]:


# import libraries
import math
def f(x):
    return 2*math.atan(x)

lim = f(float('inf'))
print (round(lim,3))


# In[ ]:


import math# import libraries
def def_e(x):
    return round(math.exp(x),3)


# In[ ]:


def even_indeces(L):
    ans = []
    for i in range(len(L)):
        if i%2==0:
            ans.append(L[i])
    return ans


# In[ ]:


def even_elements(l):
    ans = []
    for i in range(len(l)):
        if l[i]%2==0:
            ans.append(l[i])
    return ans


# In[ ]:


def last_to_first(l):
    return l[::-1]


# In[ ]:


n = int(input()) # Input and convert to int
# Your code
sum = 0
for i in range(n+1):
    if (i%5==0 and i%3!=0):
        sum+=i
print(sum)


# In[ ]:


def common(list_a, list_b):
    ans = []
    for word in list_a:
        if word in list_b:
            ans.append(word)
    return ans
            
        





# In[ ]:


def front_x(words):
    list_x = []
    for word in words:
        if word:
            if word[0]=='x':
                list_x.append(word)
    for word in list_x:
        words.remove(word)
    words=sorted(words)
    list_x=sorted(list_x)
    for word in words:
        list_x.append(word)
    return list_x
               





# In[ ]:


def fib(n):
    if n==1:
        return 1
    elif n==2:
        return 2
    else:
        return fib(n-1)+fib(n-2)





# In[ ]:


def is_prime(n):
    flag = True
    for i in range(2,int(n**0.5)+1):
        if n%i==0:
            flag = False
    return flag


# In[ ]:


s = input()
def fix_start(s):
    k = s[0]
    ans = k
    for i in range(1,len(s)):
        if s[i]==k:
            ans+='*'
        else:
            ans+=s[i]
    return ans
        

print (fix_start(s))


# In[ ]:


def numerics(n):
    return *n
print(numerive)


# In[ ]:


def kaprekar_step(l):
    l=sorted(l)
    for i in range(4):
        l[i]=str(l[i])
    s="".join(l[::-1])
    s1=int(s)
    s="".join(l)
    s2=int(s)
    return abs(s1-s2)


# In[ ]:


def numerics(n):
    l=[]
    for i in str(n):
        l.append(int(i))    
    return l

def kaprekar_step(l):
    l=sorted(l)
    for i in range(4):
        l[i]=str(l[i])
    s="".join(l[::-1])
    s1=int(s)
    s="".join(l)
    s2=int(s)
    return abs(s1-s2)


def kaprekar_loop(n):
    if (n==1000):
        print("Ошибка! На вход подано число 1000")
    else:
        l = numerics(n)
        if l[0]==l[1] and l[1]==l[2] and l[2]==l[3]:
            print("Ошибка! На вход подано число", str(l[0])+str(l[1])+str(l[2])+str(l[3]) ,"- все цифры одинаковые")
        else:
            key = kaprekar_step(l)
            print(n)
            if key != 6174:
                kaprekar_loop(key)
            elif n!=key and key==6174:
                print (key)


# In[ ]:


def numerics(n):
    l = []
    while n>0:
        l.append(n%10)
        n=int(n/10)
    return l


# In[ ]:


# Recomendation to use numerics(n) and set() for counting
def numerics(n):
    l = []
    while n>0:
        l.append(n%10)
        n=int(n/10)
    return l

def kaprekar_check(n):
    if n<=100 or n==1000 or (n>=10000 and n<=100000) or n>=1000000 or len(set(numerics(n)))==1:
        return False
    else:
        return True


# In[ ]:


def kaprekar_step(l):
    def kaprekar_step(l):
    l=sorted(l)
    for i in range(len(l)):
        l[i]=str(l[i])
    s="".join(l[::-1])
    s1=int(s)
    s="".join(l)
    s2=int(s)
    return abs(s1-s2)






# In[ ]:


def numerics(n):
    l = []
    while n>0:
        l.append(n%10)
        n=int(n/10)
    return l

def kaprekar_check(n):
    if n<=100 or n==1000 or (n>=10000 and n<=100000) or n>=1000000 or len(set(numerics(n)))==1:
        return False
    else:
        return True
    
def kaprekar_step(l):
    l=sorted(l)
    for i in range(len(l)):
        l[i]=str(l[i])
    s="".join(l[::-1])
    s1=int(s)
    s="".join(l)
    s2=int(s)
    return abs(s1-s2)

def kaprekar_loop(n):
    if not(kaprekar_check(n)):
        print( "Ошибка! На вход подано число ",n,", не удовлетворяющее условиям процесса Капрекара",sep="")
    else:
        l = numerics(n)
        key = kaprekar_step(l)
        keys.append(n)
        if (key in keys) and n!=495 and n!=6174 and n!=549945 and n!=631764:
            print(n)
            print("Следующее число - ", key,", кажется процесс зациклился...",sep="")
        elif  n==495 or n==6174 or n==549945 or n==631764:
            print(n)
        else:
            print(n)
            kaprekar_loop(key)

keys = []



# In[ ]:


def luka(L0, L1, n):
    if n==0:
        return L0
    elif n==1:
        return L1
    else:
        for i in range(n):
            L0,L1=L1,L0+L1
        return L0


# In[ ]:


from decimal import *
getcontext().prec = 50

def fi(L0, L1, n):
    if n==0:
        return L0
    elif n==1:
        return L1
    else:
        for i in range(n-1):
            L0,L1=L1,L0+L1
        return Decimal(L1)/Decimal(L0)





# In[4]:


def kaprekar(n):
    key = str(n*n)
    flag = False
    for i in range(1,len(key)):
        if ((int(key[0:i])+int(key[i:len(key)-1])==int(key)) and  (i!=len(key)-1) and (int(key[i:len(key)])!=0)):
            flag=True
            a = int(key[0:i])
            b = int(key[i:len(key)])
    return flag
print(kaprekar(9))


# In[ ]:


# put your python code here
def f(x):
    return (2*x*x-3*x+5)/(3*x*x+x+1)
print(round(f(123456789),3))
print(round(f(123456789),3))


# In[ ]:


# put your python code here
import math
def f(x):
    return (math.sin(math.pi*x/2))/x
print(round(f(123456789),3))


