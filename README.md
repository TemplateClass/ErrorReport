# ErrorReport
A funny program to make fake error. Bad code, just of personal fun. :)

# Only support zh-cn

### 使用方法

运行 `RunErrorReport.vbs`。

#### 0. 配置文件

配置文件的第 $1$ 行应为报错类型的编号。

目前可以使用的编号有：

1. MEMORY_ERROR。
2. DLL_MISSING_ERROR

接下来的几行（可选的，不写则使用默认参数），你应输入该报错类型所需的参数，程序会按顺序从配置文件中依次读取，失败的则使用默认参数。

每行表示一个参数，**记得要按顺序**。

#### 1. MEMORY_ERROR

该错误模拟的是“内存不能为 XXX”的弹窗，程序将会弹出：

> 标题：[ErrorProgram] - 应用程序错误
> 
> "[Operate]" 指令引用的 "[Address]" 内存。该内存不能为 "[CannotBe]"。
>  
> 要终止程序，请单击“确定”。  
> 要调试程序，请单击“取消”。

该功能的 4 个参数默认值如下（按配置文件读取顺序排序）：

- Operate: `0x00000000`
- Address: `0x00000000`
- CannotBe: `read`
- ErrorProgram: `svchost.exe`

配置文件示例：

```plain
1
0x00000000
0x00000000
read
svchost.exe
```

#### 2. DLL_MISSING_ERROR

该错误模拟的是“DLL 文件缺失”的弹窗，程序将会弹出：

> 标题：[ErrorProgram] - 系统错误
> 
> 无法启动此程序，因为计算机中丢失 [MissingDll]。尝试重新安装该程序以解决此问题。

该功能的 2 个参数默认值如下（按配置文件读取顺序排序）：

- MissingDll: `coredpus.dll`
- ErrorProgram: `svchost.exe`

配置文件示例：

```plain
2
coredpus.dll
svchost.exe
```
