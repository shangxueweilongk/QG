# numpy

+ ### 1、矩阵的基本属性

~~~
import numpy as np

array=np.array([[1,2,3],[3,4,5]])

#维数 2
print(array.ndim)

#行列数 （2,3）
print(array.shape)

#元素个数 6
print(array.size)
~~~

---

---

+ ### 2、创建array

~~~
import numpy as np

#1、array=np.array([[1,2,3],[3,4,5]],dtype=np.float或者dtype=np.int)后面一个参数可以定义整型或者浮点型#
a=np.array([[1,2,3],[3,4,5]])
print(a)

#2、零矩阵
a=np.zeros((3,4))#((行数，列数))
print(a)

#3、全为1的矩阵
a=np.ones((3,4))#((行数，列数))
print(a)

#4、空矩阵（元素接近0,若前面对a矩阵进行赋值,尽管np.empty元素的值也不为empty，为上一次的值）
a=np.empty((3,4))#((行数，列数))
print(a)

#用range创建
a=np.arange(2,14)#步长默认为1
print(a)

a=np.arange(2,14).reshape(3,4)
print(a)

#5、随机array
a=np.random.random((3,4))#np.random.random((行数,列数))

#6、linespace
a=np.linspace(1,10,6).reshape(2,3)#np.linspace(起始值,终止值（可以取到）,元素个数)
print(a)
~~~

---

---

+ ### 3、numpy基础运算

~~~
import numpy as np

a=np.arange(1,10).reshape((3,3))
b=np.array([[1,1,1],[1,1,1],[1,1,1]])
c=np.arange(9,0,-1).reshape((3,3))
d=np.array([[0,2],[2,4]])

#1、加减法(相同结构才可以)
print(a-b)
print(a+b)

#2、乘法和矩阵的乘法
print(a**2)#a**n表示a的n次方,每个数直接进行运算不是矩阵乘法

#两种矩阵乘法相同
print(np.dot(a,b))
print(a.dot(b))

#3、三角函数
print(10*np.sin(b))

#4、逻辑运算
print(b==1)
"""
结果
[[ True  True  True]
 [ True  True  True]
 [ True  True  True]]
"""

print(a>=5)
"""
结果
[[False False False]
 [False  True  True]
 [ True  True  True]]
"""

print(np.nonzero(a))
"""
结果(非0元素的行下标与列下标)
(array([0, 0, 0, 1, 1, 1, 2, 2, 2], dtype=int64), array([0, 1, 2, 0, 1, 2, 0, 1, 2], dtype=int64))
"""


#5、求矩阵所有元素值之和
print(np.sum(a))#整个array
print(np.sum(a,axis=1))#每一行的和
print(np.sum(a,axis=0))#每一列的和

#6、最大值和最小值
print(np.max(a))#整个array
print(np.min(a))#整个array
print(np.max(a,axis=1))#每一行的最大值
print(np.max(a,axis=0))#每一列的最大值

#7、平均值
print(np.mean(a))
print(a.mean())

print(np.average(a))

#8、中位数
print(np.median(a))

#9、累加和累差(累差是后一项与前一项的差)
print(np.cumsum(b))
"""
结果
[1 2 3 4 5 6 7 8 9]
"""
print(np.diff(a))
"""
结果
[[1 1]
 [1 1]
 [1 1]]
"""

#10、最大、小值元素下标索引(返回结果只有一个值，若有两个相同值则返回最小那个)
print(np.argmax(a))
print(np.argmin(a))

#11、对每一行进行升序排序
print(np.sort(c))

#12、转置
print(a.T)
print(np.transpose(a))

#13、clip()函数
print(np.clip(a,3,5))
"""
结果(将小于3的数变为3，将大于5的数变为5)
[[3 3 3]
 [4 5 5]
 [5 5 5]]
"""

#14、矩阵的逆和行列式(因为是浮点运算会有误差)
print(np.linalg.inv(d))#逆
print(np.linalg.det(d))#行列式

~~~

---

---

+ ### 4、索引

~~~
import numpy as np

a=np.arange(1,13).reshape(3,4)

#1、下标索引
print(a[2,1])
print(a[2][1])

#2、行、列索引（与列表相似）
print(a[1,:])
print(a[1,2:3])#不会取到3

#3、for将每一行依次打印出来
for row in a:
    print(row)

#4、for将每一列依次打印出来
for col in a.T:
    print(col)

#5、迭代每一个元素
print(a.flatten())#将所有元素放在一行
for item in a.flat:
    print(item)#输出每一个元素值

~~~

---

---

+ ### 5、array合并

```
import numpy as np

a=np.array([1,1,1])
b=np.array([2,2,2])
c=np.array([[1],[1],[1]])

#1、纵向合并
print(np.vstack((a,b)))

#2、横向合并
print(np.hstack((a,b)))

#3、纵向或横向合并
#print(np.concatenate((a,b),axis=1))#注意：因为只有一个维度所以此代码会报错
A=np.array([[1,2],[3,4]])
B=np.array([[1,2],[3,4]])
print(np.concatenate((A,B),axis=1))#横向合并


#4、newaxis增加维度
print(a)
print(a[np.newaxis,:])
print(a[:,np.newaxis])
"""
结果分别是
[1 1 1]

[[1 1 1]]

[[1]
 [1]
 [1]]
"""
```

---

---

+ ### 6、array分割

```
import numpy as np

a=np.arange(12).reshape(3,4)
print(a)

#1、对行、列进行均等分割
print(np.split(a,3,axis=0))#对行分成三部分
print(np.split(a,2,axis=1))#对列分成两部分

print(np.vsplit(a,3))#对行分成三部分
print(np.hsplit(a,2))#对列分成两部分

#2、对行、列进行不均等分割
print(np.array_split(a,2,axis=0))#对行分成两部分
print(np.array_split(a,3,axis=1))#对列分成三部分
```

---

---

+ ### 7、numpy的copy和deep copy

~~~
import numpy as np

b=2
a=b
b=3
print(b is a)#结果是false

#1、copy
a1=np.array([1,2,3])
b1=a1
a1[0]=10
print(b1 is a1)#结果是true
#可知在numpy的array之间的赋值是有关联的(改变a1，b1会改变；改变b1，a1也会改变)

#2、deep copy
a2=np.array([1,2,3])
b2=a2.copy()
a2[0]=10
print(b is a)#结果是false
#可知该操作只是赋值，没有将两者关联

~~~

