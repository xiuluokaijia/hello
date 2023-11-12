#笔记喵
***
##关于数据结构

>`int a[]`表示的是以int型为基础类型的数组，意思是其内部存储的数据的类型是int型，同理也可以创建自定义的数据类型并创建该类型的数组。那么这个数组所存放的数据的类型也就是创建的类型，结构体也可以。

><font color="green">对一个elementype a分配内存空间实际上是把它赋予了类似于数组的功能,而对于一个数组a来说，在声明数组a的同时，这个数组便已经被分配好了固定的空间，而a在这个时候作用接近于指针，什么样的指针？指向一个ele型空间的指针，而这个ele型的空间是什么？是数组的第一个空间。数组作为随机存储，它的存储结构是物理相邻的，数组名a实际上仅仅是指向数组第一个空间的指针。
<font>

##关于GitHub
>git fetch命令用于将远程仓库的更新，删改之类的获取到，使本地的给git库知道这些更新，但这本身不会改变本地的git库中的分支。使用方法也很简单，例如git fetch origin可以获取origin库当中的更改，但也仅仅是让本地git库知道这些更新。如何使用？使用merge将其看作分支与当前分支进行合并即可。其实也就是获取远程库中有而本地库中没有的部分。将这些更新到了本地的分支之后对它所更新的文件自然就可以进行版本的修改
>远程仓库的分支名应该与本地的分支名对应，这也就是当初创建远程仓库的时候为什么按照教程输入master时无法创建成功，因为我的本地主分支叫做master，远程仓库当中创建一个分支another，将他使用fetch命令，本地git库才会知道在远程创建了这个分支，而在vscode中这个**被识别**到的分支会直接显示出来，点击这个分支就会直接在本地也创建一个同名的分支。可以发现fetch是本地git与远程库连接的重要方法。