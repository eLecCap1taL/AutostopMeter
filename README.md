English: [English](README_en.md)

# AutostopMeter
急停测试, 衡量急停距离以评估急停性能

## 使用方法
你需要首先修改 `queue.cfg` 的内容

这是它的结构：

```
clear
sleep 1000
echoln [begin];echoln " ";echoln " "
sleep 500
slot3

//START

//Your Test

//END

echoln [exit]
toggleconsole
```
你需要在 `//Your Test` 的地方放入你的 Autostop 测试代码块

> ### 测试代码块
> 测试代码块有固定的结构: 
> 
> ```
> initpos
> sleep 200
> echoln [TestStart]
> echoln [NAME]
> alias $cmd "+forward";runcmd
> sleep 1000
> alias $cmd "echoln [begin];-forward;echopos";runcmd
> sleep 1000
> alias $cmd "echoln [end];echopos";runcmd
> echoln [TestCompleted];echoln " ";echoln " ";
> ```
> 
> - 第四行的 `[NAME]` 是这个代码块的名字, 例如 `[my-autostop-sciprt]`, 具有相同名字的数据会在后期的数据分析过程中被合并处理
> - 第五行的 `+forward` 和第六行的 `-forward` 替换成你的对应代码, 例如 `+myautostop_forward` 和 `-myautostop_forward`

你可以把相同的代码块重复多次, 次数越多, 数据误差越小
也可以放入不同名称的代码块

现在进入游戏, 打开控制台, 进入 `de_nuke`, 在 console 输入 `exec AutostopMeter/main`, 控制台会自动关闭并开始测试, 请等待游戏再次开启控制台, 复制控制台的内容

> 如果控制台没有东西, 可以尝试 `echo 1`
> 不必担心有多余的控制台输出, 数据分析软件应该能够正确处理他们

进入 `data` 文件夹, 新建一个 `dat.txt`, 粘贴你刚才复制的控制台输出, 他们应该看起来是这样......

```
[begin]
 
[TestStart]
[desubtick-joy-0.0001]
[begin]
[coord1]
1221.946655
[coord2]
-1243.617065
[end]
[coord1]
1221.948364
[coord2]
-1254.566772
[TestCompleted]
 
 
[TestStart]
[desubtick-joy-0.0001]
[begin]
[coord1]
1221.946777
[coord2]
-1244.471558
[end]
[coord1]
1221.948364
[coord2]
-1254.566772
[TestCompleted]
 
[exit]
```

双击 `run.bat`, 查看 `data/res.txt` !

你应该能看到这样的分析结果 (这是我的 Autostop 脚本 Horizon 的分析结果, 请忽略中文)

```
Format Confirmed
[desubtick-Horizon-0.0001] [12 times]:
  [平均滑行距离 越小越好]:  9.745066
  [最大滑行距离]:  11.514282
  [最小滑行距离]:  7.983764
  [最值差]:  3.530518
  [方差]:  1.670534
  [标准差]:  1.292491
```

## 自定义

请查看 `data/analyze.cpp`, 需要有 C++ 基础 :)
