# 1、skleran

+ ![](https://shangxueweilong.oss-cn-guangzhou.aliyuncs.com/20230209084242.png)

---

+ ![](https://shangxueweilong.oss-cn-guangzhou.aliyuncs.com/20230209084613.png)

---

+ ![](https://shangxueweilong.oss-cn-guangzhou.aliyuncs.com/20230209085428.png)

---

~~~
from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split

def demo():
    # 获取数据集
    iris=load_iris()
    print("鸢尾花数据集：\n",iris)

    #数据划分
    x_train,x_tesy,y_train,y_test=train_test_split(iris.data,iris.target,test_size=0.2,random_state=22)
    print("训练集特征值：\n",x_train,x_train.shape)#shape查看数据集行列数
    return None

if __name__ =="__main__":
    demo()

~~~

---

---

---

# 2、字典特征抽取

---

### 代码演示

~~~
#字典特征提取
from sklearn.feature_extraction import DictVectorizer

def dict_demo():
    data=[{'city':'北京','temperature':100},{'city':'上海','temperature':60},{'city':'广州','temperature':20}]
    #1、实例化一个转换器类
    transfer=DictVectorizer(sparse=False)
    #sparse默认为true，当sparse为true时返回一个稀疏矩阵

    #2、调用fit_transform()
    data_new=transfer.fit_transform(data)
    print(data_new)
    print(transfer.get_feature_names_out())#打印特征名字

if __name__ =="__main__":
    dict_demo()
~~~

---

### 总结

![](https://shangxueweilong.oss-cn-guangzhou.aliyuncs.com/20230217195239.png)

---

---

---



# 3、文本特征抽取CountVectorizer

---

+ ### 代码演示

~~~
#文本特征提取1
from sklearn.feature_extraction.text import  CountVectorizer
#统计各个词出现的次数，其中单个字母不计入统计
def count_demo():
    data=['life is a movie','why not to be me']
    #1、实例化一个转换器类
    transfer=CountVectorizer() #CountVectorizer(stop_words=[])可以将一些词不纳入统计

    #2、调用fit_transform()
    data_new=transfer.fit_transform(data)
    print(transfer.get_feature_names_out())  # 打印特征名字
    print(data_new.toarray()) #toarray()转化为二维数组

if __name__ =="__main__":
    count_demo()

~~~

---

+ ### 中文文本特征抽取代码演示

~~~
from sklearn.feature_extraction.text import CountVectorizer
import jieba

def cut_word(text): #进行分词
    return " ".join(list(jieba.cut(text)))
#转换为列表再将列表转为字符串

#中文文本特征提取
def count_Chinese_demo():
    #转换
    data=["这是一个最好的时代也是一个最坏的时代","这是一个智慧的年代，这是一个愚蠢的年代","这是一个信任的时期，这是一个怀疑的时期。",

"这是一个光明的季节，这是一个黑暗的季节","这是希望之春，这是失望之冬","人们面前应有尽有，人们面前一无所有；人们正踏上天堂之路，人们正走向地狱之门"]

    data_new=[]
    for sentence in data:
       data_new.append (cut_word(sentence))

    #1、实例化一个转换器类
    transfer=CountVectorizer(stop_words=["愚蠢"])

    #2、调用fit_transform()
    data_new1=transfer.fit_transform(data_new)
    print(transfer.get_feature_names_out())  # 打印特征名字
    print(data_new1.toarray()) #toarray()转化为二维数组



if __name__ =="__main__":
    count_Chinese_demo()
~~~

---

---

---

#  4、文本特征抽取TfidfVectorizer

+ ### 意义与原理

![](https://shangxueweilong.oss-cn-guangzhou.aliyuncs.com/20230219161953.png)

---

+ ### 实例

![](https://shangxueweilong.oss-cn-guangzhou.aliyuncs.com/20230219162320.png)

---

+ ### 代码演示

~~~
from sklearn.feature_extraction.text import TfidfVectorizer
import jieba

def cut_word(text): #进行分词
    return " ".join(list(jieba.cut(text)))
#转换为列表再将列表转为字符串

#中文文本特征提取
def count_Chinese_demo():
    #转换
    data=["这是一个最好的时代也是一个最坏的时代","这是一个智慧的年代，这是一个愚蠢的年代","这是一个信任的时期，这是一个怀疑的时期。",

"这是一个光明的季节，这是一个黑暗的季节","这是希望之春，这是失望之冬","人们面前应有尽有，人们面前一无所有；人们正踏上天堂之路，人们正走向地狱之门"]
    data_new=[]
    for sentence in data:
       data_new.append (cut_word(sentence))

    #1、实例化一个转换器类
    transfer=TfidfVectorizer(stop_words=["愚蠢"])

    #2、调用fit_transform()
    data_new1=transfer.fit_transform(data_new)
    print(transfer.get_feature_names_out())  # 打印特征名字
    print(data_new1.toarray()) #toarray()转化为二维数组

if __name__ =="__main__":
    count_Chinese_demo()
~~~

---

---

---

# 5、数据处理-归一化

+ ### 意义

![](https://shangxueweilong.oss-cn-guangzhou.aliyuncs.com/20230219164339.png)

---

+ ### 例子

![](https://shangxueweilong.oss-cn-guangzhou.aliyuncs.com/20230219164426.png)

---

+ ### 定义与公式

![](https://shangxueweilong.oss-cn-guangzhou.aliyuncs.com/20230219164516.png)

---

+ ### API

![](https://shangxueweilong.oss-cn-guangzhou.aliyuncs.com/20230219164645.png)

---



+ ### 代码演示

~~~
from sklearn.preprocessing import MinMaxScaler

def minimax_demo():
    #获取数据
    data = np.array([[1000, 200, 30, 4], [900, 100, 31, 5], [1200, 600, 20, 1]])

    #实例化一个转换器类
    transfer=MinMaxScaler(feature_range=[0,1])

    #调用fit_transform()
    data_new=transfer.fit_transform(data)

    print(data_new)

if __name__=="__main__":
    minimax_demo()
~~~

---



+ ### 局限

![](https://shangxueweilong.oss-cn-guangzhou.aliyuncs.com/20230219170733.png)

---

---

---



# 6、数据处理-标准化

---

+ ### 定义与公式

![](https://shangxueweilong.oss-cn-guangzhou.aliyuncs.com/20230219171334.png)

---

+ ### 意义

![](https://shangxueweilong.oss-cn-guangzhou.aliyuncs.com/20230219171509.png)

---

+ ### 代码演示

~~~
from sklearn.preprocessing import StandardScaler

def stand_demo():
    #获取数据
    data = np.array([[1000, 200, 30, 4], [900, 100, 31, 5], [1200, 600, 20, 1]])

    #实例化一个转换器类
    transfer=StandardScaler()

    #调用fit_transform()
    data_new=transfer.fit_transform(data)

    print(data_new)

if __name__=="__main__":
    stand_demo()

~~~

---

---

---



# 7、删除低方差特征

+ ### 定义

![](https://shangxueweilong.oss-cn-guangzhou.aliyuncs.com/20230304084851.png)

---

+ ### 代码

~~~
from sklearn.feature_selection import VarianceThreshold

def variance_demo():
    data = ([[1000, 200, 30, 4], [900, 100, 31, 5], [1200, 600, 20, 1]])

    transfer=VarianceThreshold(threshold=2)

    data_new=transfer.fit_transform(data)

    print(data_new)

if __name__ =="__main__":
    variance_demo()
~~~

---

---

---



# 8、相关系数

+ ### 原理

![](https://shangxueweilong.oss-cn-guangzhou.aliyuncs.com/20230304091304.png)

---

+ ### 特点

![](https://shangxueweilong.oss-cn-guangzhou.aliyuncs.com/20230304091530.png)

---

+ ### 代码

~~~
from scipy.stats import pearsonr

def pearsonr_demo():
    data_1 = [1,2,3,4]
    data_2 = [2,2,3,4]
    data_3 = [9,200,30,400]

    r1=pearsonr(data_1,data_2)
    r2=pearsonr(data_1,data_3)

    print(r1,r2)

if __name__ =="__main__":
    pearsonr_demo()
~~~

---

---

---



# 9、主成分分析

+ ### API

![](https://shangxueweilong.oss-cn-guangzhou.aliyuncs.com/20230304101743.png)

---

+ ### 代码

~~~
from sklearn.decomposition import PCA

def pca_demo():
    data=[[2,8,4,5],[2,31,2,3],[2,3,11,19],[23,11,6,10]]

    transfer=PCA(n_components=2)
    data_new=transfer.fit_transform(data)

    print(data_new)

if __name__=="__main__":
    pca_demo()
~~~

---

---

---



# 10、sklearn转换器与预估器

![](https://shangxueweilong.oss-cn-guangzhou.aliyuncs.com/20230304103253.png)

---

---

---



# 11、KNN算法

+ ### 原理

![](https://shangxueweilong.oss-cn-guangzhou.aliyuncs.com/20230305104828.png)

---

---

+ ### 代码

~~~
from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.neighbors import KNeighborsClassifier

def knn_iris():

    iris=load_iris()

    #划分数据集
    x_train,x_test,y_train,y_test=train_test_split(iris.data,iris.target,random_state=6)

    #标准化，因变量一般不需要标准化
    transfer=StandardScaler()
    x_train=transfer.fit_transform(x_train)
    x_test=transfer.transform(x_test)


    #KNN算法预估器
    estimator=KNeighborsClassifier(n_neighbors=3)
    estimator.fit(x_train,y_train)

    #模型评估
    #1）真实值与预测值比对
    y_predict=estimator.predict(x_test)
    print(y_test==y_predict)

    #2）计算准确率
    score=estimator.score(x_test,y_test)
    print("准确率",score)

if __name__ == "__main__":
    knn_iris()
~~~

---

+ ### 总结

![](https://shangxueweilong.oss-cn-guangzhou.aliyuncs.com/20230305105301.png)

---

---

---



# 12、模型选择与调优

+ ### 交叉训练集

![](https://shangxueweilong.oss-cn-guangzhou.aliyuncs.com/20230305113936.png)

---

+ ### 超参数搜索——网格搜索（找到合适k值）

![](https://shangxueweilong.oss-cn-guangzhou.aliyuncs.com/20230305114238.png)

---

+ ### API

![](https://shangxueweilong.oss-cn-guangzhou.aliyuncs.com/20230305114218.png)

---

+ ### 代码演示

~~~
from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.neighbors import KNeighborsClassifier
from sklearn.model_selection import GridSearchCV

def knn_iris():

    iris=load_iris()

    #划分数据集
    x_train,x_test,y_train,y_test=train_test_split(iris.data,iris.target,random_state=6)

    #标准化，因变量一般不需要标准化
    transfer=StandardScaler()
    x_train=transfer.fit_transform(x_train)
    x_test=transfer.transform(x_test)


    #KNN算法预估器（网格搜索）
    estimator=KNeighborsClassifier()
    param_dict={"n_neighbors":[1,3,5,7,9,11]}
    estimator=GridSearchCV(estimator,param_grid=param_dict,cv=10)
    estimator.fit(x_train,y_train)

    #模型评估
    #1）真实值与预测值比对
    y_predict=estimator.predict(x_test)
    print(y_test==y_predict)

    #2）计算准确率
    score=estimator.score(x_test,y_test)
    print("准确率",score)

    #3)最佳参数
    print("最佳参数",estimator.best_params_)

    #4)最佳结果
    print("最佳结果", estimator.best_score_)

    # 5)最佳估计器
    print("最佳估计器", estimator.best_estimator_)

    # 6)交叉验证结果
    print("交叉验证结果", estimator.cv_results_)

if __name__ == "__main__":
    knn_iris()
~~~

---

---

---



# 13、朴素贝叶斯

+ ### 概率基础定义

![](https://shangxueweilong.oss-cn-guangzhou.aliyuncs.com/20230306090535.png)

---

+ ### 贝叶斯公式

![](https://shangxueweilong.oss-cn-guangzhou.aliyuncs.com/20230306090713.png)

---

+ ### 朴素贝叶斯

![](https://shangxueweilong.oss-cn-guangzhou.aliyuncs.com/20230306090919.png)

---

+ ### 朴素贝叶斯公式

![](https://shangxueweilong.oss-cn-guangzhou.aliyuncs.com/20230306091420.png)

---

+ ### 拉普拉斯平滑系数

![](https://shangxueweilong.oss-cn-guangzhou.aliyuncs.com/20230306091602.png)

---

+ 代码

```
from sklearn.datasets import fetch_20newsgroups
from sklearn.model_selection import train_test_split
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.naive_bayes import MultinomialNB

def news():
    news=fetch_20newsgroups(subset="all")

    x_train,x_test,y_train,y_test=train_test_split(news.data,news.target)

    #特征工程
    transfer=TfidfVectorizer()
    x_train=transfer.fit_transform(x_train)
    x_test=transfer.transform(x_test)

    #朴素贝叶斯
    estimator=MultinomialNB()
    estimator.fit(x_train,y_train)

    # 模型评估
    #1）真实值与预测值比对
    y_predict=estimator.predict(x_test)
    print(y_test==y_predict)

    #2）计算准确率
    score=estimator.score(x_test,y_test)
    print("准确率",score)

if __name__=="__main__":
    news()
```

---

---

---



# 14、决策树

+ ### 信息熵

![](https://shangxueweilong.oss-cn-guangzhou.aliyuncs.com/20230307201306.png)

---

+ ### 信息增益

![](https://shangxueweilong.oss-cn-guangzhou.aliyuncs.com/20230307201427.png)

---

+ ### API

![](https://shangxueweilong.oss-cn-guangzhou.aliyuncs.com/20230307201531.png)

---

+ ### 代码(鸢尾花)

~~~
from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split
from sklearn.tree import DecisionTreeClassifier,export_graphviz

def tree_iris():
    #获取数据
    iris=load_iris()

    #划分数据集
    x_train,x_test,y_train,y_test=train_test_split(iris.data,iris.target,random_state=6)

    #决策树预估器
    estimator=DecisionTreeClassifier(criterion="entropy")
    estimator.fit(x_train,y_train)

    #模型评估
    #1）真实值与预测值比对
    y_predict=estimator.predict(x_test)
    print(y_test==y_predict)

    #2）计算准确率
    score=estimator.score(x_test,y_test)
    print("准确率",score)

    #可视化
    export_graphviz(estimator,out_file="tree_iris.dot")

if __name__=="__main__":
    tree_iris()
~~~

---

+ ### 可视化文件（鸢尾花）

~~~
digraph Tree {
node [shape=box, fontname="helvetica"] ;
edge [fontname="helvetica"] ;
0 [label="X[3] <= 0.8\nentropy = 1.584\nsamples = 112\nvalue = [38, 38, 36]"] ;
1 [label="entropy = 0.0\nsamples = 38\nvalue = [38, 0, 0]"] ;
0 -> 1 [labeldistance=2.5, labelangle=45, headlabel="True"] ;
2 [label="X[3] <= 1.65\nentropy = 0.999\nsamples = 74\nvalue = [0, 38, 36]"] ;
0 -> 2 [labeldistance=2.5, labelangle=-45, headlabel="False"] ;
3 [label="X[2] <= 5.45\nentropy = 0.179\nsamples = 37\nvalue = [0, 36, 1]"] ;
2 -> 3 ;
4 [label="entropy = 0.0\nsamples = 36\nvalue = [0, 36, 0]"] ;
3 -> 4 ;
5 [label="entropy = 0.0\nsamples = 1\nvalue = [0, 0, 1]"] ;
3 -> 5 ;
6 [label="X[2] <= 5.05\nentropy = 0.303\nsamples = 37\nvalue = [0, 2, 35]"] ;
2 -> 6 ;
7 [label="X[1] <= 2.9\nentropy = 0.863\nsamples = 7\nvalue = [0, 2, 5]"] ;
6 -> 7 ;
8 [label="entropy = 0.0\nsamples = 4\nvalue = [0, 0, 4]"] ;
7 -> 8 ;
9 [label="X[3] <= 1.75\nentropy = 0.918\nsamples = 3\nvalue = [0, 2, 1]"] ;
7 -> 9 ;
10 [label="entropy = 0.0\nsamples = 1\nvalue = [0, 1, 0]"] ;
9 -> 10 ;
11 [label="X[0] <= 5.95\nentropy = 1.0\nsamples = 2\nvalue = [0, 1, 1]"] ;
9 -> 11 ;
12 [label="entropy = 0.0\nsamples = 1\nvalue = [0, 1, 0]"] ;
11 -> 12 ;
13 [label="entropy = 0.0\nsamples = 1\nvalue = [0, 0, 1]"] ;
11 -> 13 ;
14 [label="entropy = 0.0\nsamples = 30\nvalue = [0, 0, 30]"] ;
6 -> 14 ;
}
~~~

---

+ ### 可视化视图[文件转为图片](https://dreampuf.github.io/GraphvizOnline)

![](https://shangxueweilong.oss-cn-guangzhou.aliyuncs.com/20230307203846.png)

---

+ ### 泰坦尼克号

```
import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.tree import DecisionTreeClassifier,export_graphviz
from sklearn.feature_extraction import DictVectorizer

def titanic_demo():
    #获取数据
    data=train = pd.read_excel(r"data.xlsx")

    #筛选特征值和目标值
    x=data[["Pclass","Age","Sex"]]
    y=data["Survived"]

    #处理数据
    #1）缺失值处理
    x["Age"].fillna(x["Age"].mean(),inplace=True)
    #2)转换成字典
    x=x.to_dict(orient="records")
    #3)划分数据集
    x_train,x_test,y_train,y_test=train_test_split(x,y,random_state=6)
    #4)字典特征抽取
    transfer=DictVectorizer()
    x_train=transfer.fit_transform(x_train)
    x_test=transfer.transform(x_test)

    # 决策树预估器
    estimator=DecisionTreeClassifier(criterion="entropy",max_depth=8)
    estimator.fit(x_train,y_train)

    #模型评估
    #1）真实值与预测值比对
    y_predict=estimator.predict(x_test)
    print(y_test==y_predict)

    #2）计算准确率
    score=estimator.score(x_test,y_test)
    print("准确率",score)

    #可视化
    export_graphviz(estimator,out_file="titanic_iris.dot")


if __name__=="__main__":
    titanic_demo()
```

---

---

---



# 15、随机森林

+ ### 集成学习方法

![](https://shangxueweilong.oss-cn-guangzhou.aliyuncs.com/20230308185938.png)

---

+ ### 随机森林定义

![](https://shangxueweilong.oss-cn-guangzhou.aliyuncs.com/20230308190105.png)

---

+ ### 原理

![](https://shangxueweilong.oss-cn-guangzhou.aliyuncs.com/20230308190200.png)

---

+ ### API

![](https://shangxueweilong.oss-cn-guangzhou.aliyuncs.com/20230308190540.png)

+ ### 代码

~~~
import pandas as pd
from sklearn.model_selection import train_test_split,GridSearchCV
from sklearn.tree import export_graphviz
from sklearn.feature_extraction import DictVectorizer
from sklearn.ensemble import RandomForestClassifier

def titanic_random():
    #获取数据
    data=train = pd.read_excel(r"data.xlsx")

    #筛选特征值和目标值
    x=data[["Pclass","Age","Sex"]]
    y=data["Survived"]

    #处理数据
    #1）缺失值处理
    x["Age"].fillna(x["Age"].mean(),inplace=True)
    #2)转换成字典
    x=x.to_dict(orient="records")
    #3)划分数据集
    x_train,x_test,y_train,y_test=train_test_split(x,y,random_state=6)
    #4)字典特征抽取
    transfer=DictVectorizer()
    x_train=transfer.fit_transform(x_train)
    x_test=transfer.transform(x_test)

    # 决策树预估器(网格搜索)
    estimator = RandomForestClassifier()
    param_dict = {"n_estimators": [120,200,300,500,800,1200],"max_depth":[5,8,15,25,30]}
    estimator = GridSearchCV(estimator, param_grid=param_dict, cv=3)
    estimator.fit(x_train, y_train)

    # 模型评估
    # 1）真实值与预测值比对
    y_predict = estimator.predict(x_test)
    print(y_test == y_predict)

    # 2）计算准确率
    score = estimator.score(x_test, y_test)
    print("准确率", score)

    # 3)最佳参数
    print("最佳参数", estimator.best_params_)

    # 4)最佳结果
    print("最佳结果", estimator.best_score_)

    # 5)最佳估计器
    print("最佳估计器", estimator.best_estimator_)

    # 6)交叉验证结果
    print("交叉验证结果", estimator.cv_results_)

    #可视化
    export_graphviz(estimator,out_file="titanic_random.dot")


if __name__=="__main__":
    titanic_random()
~~~

---

+ ### 总结

![](https://shangxueweilong.oss-cn-guangzhou.aliyuncs.com/20230308194151.png)

---

---

---



# 16、线性回归

+ ### 应用场景

![](https://shangxueweilong.oss-cn-guangzhou.aliyuncs.com/20230309161906.png)

---

+ ### 线性关系定义

![](https://shangxueweilong.oss-cn-guangzhou.aliyuncs.com/20230309162028.png)

---

+ ### 线性模型

![](https://shangxueweilong.oss-cn-guangzhou.aliyuncs.com/20230309162213.png)

---

---

---



# 17、损失函数(最小二乘法)及优化方法

+ ### 损失函数定义

![1678350255670](C:\Users\k\AppData\Roaming\Typora\typora-user-images\1678350255670.png)

---

+ ### 正规方程

![](https://shangxueweilong.oss-cn-guangzhou.aliyuncs.com/20230309162605.png)

---

+ ### 梯度下降

![](https://shangxueweilong.oss-cn-guangzhou.aliyuncs.com/20230309164031.png)

---

+ ### API

![](https://shangxueweilong.oss-cn-guangzhou.aliyuncs.com/20230309164153.png)

---

+ ### 回归性能评估

![](https://shangxueweilong.oss-cn-guangzhou.aliyuncs.com/20230309184739.png)

---

+ ### 代码

~~~
from sklearn.datasets import load_boston
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.linear_model import LinearRegression,SGDRegressor
from sklearn.metrics import mean_squared_error

def linear():
    #获取数据
    boston=load_boston()

    #划分数据集
    x_train,x_test,y_train,y_test=train_test_split(boston.data,boston.target,random_state=6)

    #标准化
    transfer=StandardScaler()
    x_train=transfer.fit_transform(x_train)
    x_test=transfer.transform(x_test)

    #预估器
    #1)正规方程
    estimator_1=LinearRegression()
    estimator_1.fit(x_train,y_train)
    #2)梯度下降
    estimator_2=SGDRegressor()
    estimator_2.fit(x_train,y_train)


    #得出模型
    print("正规方程权重系数",estimator_1.coef_)
    print("正规方程偏置",estimator_1.intercept_)
    print("梯度下降权重系数", estimator_2.coef_)
    print("梯度下降偏置", estimator_2.intercept_)

    #模型评估
    y_predict_1=estimator_1.predict(x_test)
    y_predict_2=estimator_2.predict(x_test)
    print("正规方程预测房价",y_predict_1)
    print("梯度下降预测房价",y_predict_2)

    error_1=mean_squared_error(y_test,y_predict_1)
    error_2=mean_squared_error(y_test,y_predict_2)
    print("正规方程均方误差",error_1)
    print("梯度下降均方误差",error_2)

if __name__=="__main__":
    linear()
~~~

---

+ ### 总结

![](https://shangxueweilong.oss-cn-guangzhou.aliyuncs.com/20230309185625.png)

---

---

---



# 18、过拟合欠拟合

+ ### 定义

![](https://shangxueweilong.oss-cn-guangzhou.aliyuncs.com/20230309190435.png)

---

+ ### 原因及解决方案

![](https://shangxueweilong.oss-cn-guangzhou.aliyuncs.com/20230309190626.png)

---

+ ### 正则化

![](https://shangxueweilong.oss-cn-guangzhou.aliyuncs.com/20230309190752.png)

---

---

---



# 19、岭回归

+ ### 定义

![](https://shangxueweilong.oss-cn-guangzhou.aliyuncs.com/20230309191114.png)

---

+ ### API

![](https://shangxueweilong.oss-cn-guangzhou.aliyuncs.com/20230309192651.png)

---

+ ### 正则化与权重系数

![](https://shangxueweilong.oss-cn-guangzhou.aliyuncs.com/20230309192849.png)



