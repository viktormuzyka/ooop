#!/usr/bin/env python
# coding: utf-8

# 

# In[20]:


x = 5
y = 10
y > x * x or y >= 2 * x and x < y


# 
# 
# 

# In[21]:


a = True
b = False
print(a and b or not a and not b)


# In[19]:


a = True
b = False
print(a and b or not a and not b)


# In[25]:


A = int(input())
B = int(input())
H = int(input())
if H > A and H < B:
    print("Это нормально")
elif H < A:
    print("Недосып")
elif H > B:
    print("Пересып")


# In[31]:


A = int(input())
if ((A % 4 == 0) and (A % 100 != 0)or(A % 400==0)):
    print("Високосный")
else:
    print("Обычный")


# In[33]:


"239"<"30"


# In[36]:


A = int(input())
B = int(input())
C = int(input())
p=(A+B+C)/2
s=(p*(p-A)*(p-B)*(p-C))**0.5
print(s)


# In[37]:


A = int(input())
print( (A>-15 and A<=12)or(A>14 and A<17)or(A>=19))


# In[53]:


A = float(input())
B = float(input())
C = input()
if (((C=="mod") or (C=="/") or (C=="div")) and (B==0)):
    print("Деление на 0!")
elif (C=='+'):
    print (A + B )
elif (C=='-'):
    print (A - B )
elif (C=='/'):
    print (A / B )
elif (C=="*"):
    print (A * B )
elif (C=="pow"):
    print (A ** B )
elif (C=="div"):
    print (A // B )
elif (C=="mod"):
    print (A % B )


# In[ ]:


pi=3.14
a = float(input())
s = 1.000001
if (a=="треугольник"):
    A = int(input())
    B =  int(input())
    C =  int(input())
    p=(A+B+C)/2
    s=(p*(p-A)*(p-B)*(p-C))**0.5
elif (a=="прямоугольник"):
    A =  int(input())
    B =  int(input())
    s=A*B
elif (a=="круг"):
    r = int(input())
    s=pi*(r**2)
    
print(s)


# In[60]:


A = int(input())
B = int(input())
C = int(input())
maximus=max(A,B,C)
minimus=min(A,B,C)
xuinya = A+B+C-maximus-minimus
print(maximus)
print(minimus)
print(xuinya)


# In[ ]:





# In[65]:


number =input()
flag = int(number[0])+int(number[1])+int(number[2]) == int(number[3]) +int(number[4]) + int(number[5])
if flag:
    print("Счастливый")
else:
    print("Обычный")


# In[66]:


1+2+1+1+2+1+3+1+2+3


# In[68]:


a = int(input())
b=1
if a == 0:
    print(0)
else:
    while b!=0:
        b=int(input())
        a+=b
    print(a)


# In[73]:


A = int(input())
B = int(input())
maximus=max(A,B)
minimus=min(A,B)
nsd_1=1
nsd_2=1
if maximus%minimus==0:
    print (maximus)
else:
    while nsd_1!=0:
        nsd_2=nsd_1
        nsd_1=maximus % minimus
        maximus=minimus
        minimus=nsd_1
    print(A*B/nsd_2)


# In[84]:


a=15
suka = ""
while a<100:
    a=int(input())
    if (a>10 and a100):
        suka+=str(a)+"\n"
print(suka)


# ## 

# In[103]:


a=int(input())
b=int(input())
c=int(input())
d=int(input())
string=""
if c==d:
    print("\t"+str(c))
else:
    d+=1
    for k in range(c,d):
        string+="\t"+str(k)
    print(string)
b+=1
for i in range(a, b):
    string=str(i)+"\t"
    if c==d:
        print(i,i*c,sep="\t")
    else:
        for j in range(c,d):
             string+=str(i*j)+"\t"
        print(string)
    


# In[109]:


a=int(input())
b=int(input())
n=0
s=0
for i in range (int(a),int(b)+1):
    if (i%3==0):
        s+=i
        n+=1
print(s/n)
    


# In[124]:


s=input()
su=0
temp=0
for cal in s:
    if ((cal=='c') or (cal=="g")):
        temp+=1
    su+=1
print(temp/su*100)


# In[125]:


s = 'abcdefghijk'
print(s[3:6], s[:6], s[3:], s[::-1], s[-3:], s[:-6], s[-1:-10:-2], sep=" ")


# In[137]:


dnk=input()
temp=str(dnk[0])
cnt=0
ans=""
print(len(dnk))
for i in range(len(dnk)):
    if temp==dnk[i]:
        cnt+=1
    else:
        ans+=temp+str(cnt)
        cnt=1
        temp=dnk[i]
    if i==len(dnk)-1:
        #cnt+=1
        ans+=temp+str(cnt)
print(ans)


# In[140]:


students = ['Ivan', 'Masha', 'Sasha']
students += ['Olga']
students += 'Olga'
print(students)


# In[141]:


a = [1, 2, 3]
b = a
# значения списка b?
print(b)

a[1] = 10
# значения списка b?
print(b)
b[0] = 20
# значения списка a?
print(a)

a = [5, 6]
# значения списка b?
print(b)


# In[144]:


print(sum([int(i) for i in input().split()]))


# In[183]:


a=[int(i) for i in input().split()]
b=a.copy()
if len(a):
    print(a[0])
else:  
    a.append(a[0])
    q=len(a)-1
    a.insert(0, a[q-1])
    print(a);
    ans=""
    for i in range(1,q+1):
        b[i-1]=int(a[i-1])+int(a[i+1])
    for i in range (0,q):
        ans+=str(b[i])+" "
    
    print(ans)
  


# In[187]:


a=[int(i) for i in input().split()]
b=sorted(a)
ans=""
temp=b[0]
flag=True
for i in range(1,len(a)):
    if (temp==b[i] and flag):
        ans+=str(temp)+" "
        flag=False
    elif temp!=b[i]: 
        temp=b[i]
        flag=True
    else:
        flag=False
print(ans)
        


# In[197]:


summ=0
sqsum=0
flag=True
while (summ!=0 or flag):
    a=int(input())
    summ+=a
    sqsum+=a*a
    flag=False
print(sqsum)
    


# In[ ]:


1-3+5-6-10+13+4-8


# In[16]:


a=int(input())
ans=[]
end=""
for i in range(1,40):
    for j in range(i):
        ans.append(str(i))
#print(ans)
for i in range(0,a):
    #print(ans[i], " ", sep=" ")
    end+=ans[i]+" "
print(end)


# In[35]:


a=[int(i) for i in input().split()]
b=int(input())
flag = 0
end=""
for i in range(0, len(a)):
    if (a[i]==b): 
        end+=str(i)+" "
        flag = 1       
if flag == 1: 
    print(end)
else:
    print("Отсутствует")


# In[38]:


matrix = []
matrix = []
row = input()
while row != 'end':
    matrix.append([int(i) for i in row.split()])
    row = input()
#print(matrix)
    
new_matrix = [[int(0) for j in range(len(matrix[0]))] for i in range(len(matrix))] 
#print(new_matrix)
#for i in range(0, len(matrix[0])):
#    for j in range(0, len(matrix[0])):
#        print(matrix[i][j]," i=",i,"j=",j)
#print(len(matrix), len(matrix[0]))    
for i in range(0, len(matrix)):
    for j in range(0, len(matrix[0])):
        if (i-1<0):
            new_matrix[i][j]+=matrix[len(matrix)-1][j]
        else: 
            new_matrix[i][j]+=matrix[(i-1)][j]
            
        if (i+1==len(matrix)):
            new_matrix[i][j]+=matrix[0][j]
        else: 
            new_matrix[i][j]+=matrix[(i+1)][j]
            
        if (j-1<0):
            new_matrix[i][j]+=matrix[i][len(matrix[0])-1]
        else: 
            new_matrix[i][j]+=matrix[(i)][j-1]
            
        if (j+1==len(matrix[0])):
            new_matrix[i][j]+=matrix[i][0]
        else: 
            new_matrix[i][j]+=matrix[(i)][j+1]
            
for i in range(0, len(matrix)):
    for j in range(0, len(matrix[0])):
        print(new_matrix[i][j], end=' ')
    print()

#print(new_matrix)


# In[49]:


k = 1
i=0
j=0
step = 0
n = int(input())
matrix = [[int(0) for j in range(n)] for i in range(n)]
#print(matrix)
while (k<=n*n):
    while (j<=n-1-step):
        matrix[i][j]=k
        j+=1
        k+=1 
    j -= 1
    i += 1 
    while (i<=n-1-step):
        matrix[i][j] = k
        k+=1
        i+=1
    j -= 1
    i -= 1
    while (j>=step):
        matrix[i][j]=k
        j-=1
        k+=1 
    i -= 1
    j += 1
    step += 1
    while (i>=step):
        matrix[i][j] = k
        k+=1
        i-=1
    j+=1
    i+=1
for i in range(0, len(matrix)):
    for j in range(0, len(matrix[0])):
        print(matrix[i][j], end=' ')
    print()
        
        


# In[50]:


def f(n):
    return n * 10 + 5
f(f(f(10)))


# In[57]:


def foo(a):
    if a <= -2:
        return 1-(a+2)**2
    elif (a <= 2 and a>-2):
        return -a/2
    else:
        return (a-2)**2+1


# In[81]:


def modify_list(l):
    k = len(l)
    i = 0
    while(i<len(l)):
        if (l[i]%2==1):
            l.remove(l[i])
            l-=1
        i+=1 
    for j in range(len(l)):
        l[j]=int(l[j]/2)
    return None


# In[91]:


def update_dictionary(d, key, value):
        if key in d :
            d[key].append(value)
        else:
            if 2*key in d:
                d[2*key].append(value)
            else:
                d[2*key] = [value]
d = {}             
print(update_dictionary(d, 1, -1))  # None
print(d)                            # {2: [-1]}
update_dictionary(d, 2, -2)
print(d)                            # {2: [-1, -2]}
update_dictionary(d, 1, -3)
print(d)                            # {2: [-1, -2, -3]}


# In[120]:


count_dict = {}
for word in [w for w in input().lower().split()]:
    if word in count_dict:
        count_dict[word]+=1
    else:
        count_dict[word] = 1
#print(count_dict)
for (word, coun) in count_dict.items():
    print(word, coun)


# In[121]:


n = int(input())
dict = {}
for i in range(n):
    x = int(input())
    if(x not in dict):
        dict[x]=f(x)
    print(dict[x])


# In[145]:


row = input()
alpha_pos = []

for i in range(len(row)):
    if row[i].isalpha():
        alpha_pos += [i]
alpha_pos += [len(row)]
answer = ''
for i in range(len(alpha_pos)-1):
    answer += row[alpha_pos[i]] * int(row[alpha_pos[i]+1:alpha_pos[i+1]])

print(answer)


# In[151]:


count_dict = {}
list = []
for word in [w for w in input().lower().split()]:
    if word in count_dict:
        count_dict[word]+=1
    else:
        count_dict[word] = 1
#print(count_dict)
max=count_dict[word]
for (word, coun) in count_dict.items():
    #if (max==coun):
    print(word, coun)
        #max = coun


# In[155]:


import math
n = float(input())
print(math.pi*n*2)


# In[ ]:


import sys
s = ''
s2 = ''
for i in range(1,len(sys.argv)):
    s = s + sys.argv[i]+' '
s2 = s
print(s2,end=' ')


# In[ ]:


math_values = []
physics_values = []
russian_values = []
with open('dataset_3363_4.txt', 'r') as in_file:
    for line in in_file:
        current_line = line.strip().split(';')
        math_values.append(int(current_line[1]))
        physics_values.append(int(current_line[2]))
        russian_values.append(int(current_line[3]))
out_file = open('statistic.txt', 'w')
for i in range(len(math_values)):
    out_file.write(str((math_values[i] + physics_values[i] + russian_values[i]) / 3) + '\n')
if len(math_values) > 0:
    out_file.write(str(sum(math_values) / len(math_values)) + ' ' +
                   str(sum(physics_values) / len(physics_values)) + ' ' +
                   str(sum(russian_values) / len(russian_values)))
out_file.close()


# In[8]:


import requests
k = 0
r = requests.get("https://stepic.org/media/attachments/course67/3.6.2/289.txt")
for i in range(len(r.text.splitlines())):
    k += 1
print(k)


# In[ ]:


import requests

link = 'https://stepic.org/media/attachments/course67/3.6.3/'
with open('dataset_3378_3.txt') as inf:
    t = inf.readline().strip()

t = str(requests.get(t).text)
while 'we' not in t:
    print(t)
    t = requests.get(link + t).text
print(t)


# In[ ]:


n = int(input())
dict = {}
for i in range(n):
    current_line = input().split(';')
    cmd1=(current_line[0])
    #print(cmd1)
    value1=(int(current_line[1]))
    #print(value1)
    cmd2=(current_line[2])
    #print(cmd2)
    value2=(int(current_line[3]))
    #print(value2)
    if(cmd1 not in dict):
        dict[cmd1]=[0,0,0,0,0]
        
    if(cmd2 not in dict):
        dict[cmd2]=[0,0,0,0,0]
        
    dict[cmd2][0] += 1
    dict[cmd1][0] += 1
    if (value1>value2):
        dict[cmd1][1] += 1
        dict[cmd1][4] += 3
        dict[cmd2][3] += 1
    elif (value2>value1):
        dict[cmd2][1] += 1
        dict[cmd2][4] += 3
        dict[cmd1][3] += 1
    else:
        dict[cmd2][2] += 1
        dict[cmd1][2] += 1
        dict[cmd2][4] += 1
        dict[cmd1][4] += 1
for i in dict.keys():
    print(i,":", dict[i][0]," ",dict[i][1]," ",dict[i][2]," ",dict[i][3]," ",dict[i][4], sep="")


# In[1]:


first = input()
code = input()
in_1 = input()
in_2 = input()
out_1 = ""
out_2 = ""
dict_1 = {}
dict_2 = {}
for i in range(len(first)):
    dict_1[first[i]] = code[i]
    dict_2[code[i]] = first[i]
for i in range(len(in_1)):
    out_1 += dict_1[in_1[i]]
for i in range(len(in_2)):
    out_2 += dict_2[in_2[i]]
print(out_1)
print(out_2)


# In[ ]:


n = int(input())
dict = {}
for i in range(n):
    key = input().lower()
    dict[key] = 0
#print(dict)
words = {}
a = int(input())
for i in range(a):
    key = input().lower().split()
    #print(key)
    for x in key:
        if x in dict:
            dict[x] = 1
        else:
            if x not in words:
                words[x] = 1
for x in words:
    print(x)


# ## 

# In[ ]:


a = int(input())
x = 0
y = 0
for i in range(a):
    keys = input().split()
    if (keys[0]=="восток"):
        x += int(keys[1])
    elif (keys[0]=="запад"):
        x -= int(keys[1])
    elif (keys[0]=="север"):
        y += int(keys[1])
    else:
        y -= int(keys[1])
print(x,y)


# In[ ]:


dict = {'1': 0,'2': 0,'3': 0,'4': 0,'5': 0,'6': 0,'7': 0,'8': 0,'9': 0,'10': 0,'11': 0,}
with open('dataset_3363_4.txt', 'r') as in_file:
    for line in in_file:
        current_line = line.strip().split('\t')
        clas.append(current_line[0])
        surname.append(current_line[1])
        height.append(int(current_line[2]))
        dict[clas].append(height)
for x in dict.keys():
        print(x, sum(dic[x])/count(dic[x]))

