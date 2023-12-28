# UNet网络制作

> 代码参考[UNet数据集制作及代码实现_哔哩哔哩_bilibili](https://www.bilibili.com/video/BV11341127iK?p=1&vd_source=13dfbe5ed2deada83969fafa995ccff6)，根据该UP主的代码，加上我的个人整理和理解。（这个UP主的代码感觉很好，很规范

UNet网络由三部分组成：卷积块，下采样层，上采样层。

## 卷积块

UNet网络中卷积块进行了两次卷积。

```python
class Conv_Block(nn.Module):
    def __init__(self, in_channel, out_channel):
        super(Conv_Block, self).__init__()
        self.layer = nn.Sequential(
            # padding_mode = "reflect" 增强特征提取
            nn.Conv2d(in_channel,out_channel, 3, 1, 1, padding_mode="reflect", bias = False),
            nn.BatchNorm2d(out_channel), # 二维批归一化层，归一化卷积层的输出。用于加速训练和增强模型的泛化能力。
            nn.Dropout2d(0.3), # 二维随机失活层，以概率0.3随机抑制特征，用于防止过拟合。
            nn.LeakyReLU(), # 带有负斜率的修正线性单元激活函数，引入非线性变换。

            nn.Conv2d(out_channel, out_channel, 3, 1, 1, padding_mode="reflect", bias = False),
            nn.BatchNorm2d(out_channel),
            nn.Dropout(0.3),
            nn.LeakyReLU()
        )
    
    def forward(self, x):
        return self.layer(x) 
```

## 下采样层

UNet网络的下采样层中进行了一次卷积。下采样将图像大小减半，通道数不变，同时保留更多的重要特征。

```python
class DownSample(nn.Module):
    def __init__(self, channel):
        super(DownSample, self).__init__()
        self.layer = nn.Sequential(
            nn.Conv2d(channel, channel, 3, 2, 1, padding_mode="reflect", bias = False),
            nn.BatchNorm2d(channel),
            nn.LeakyReLU()
        )

    def forward(self, x):
        return self.layer(x)

```

## 上采样层

UNet网络的上采样层中进行了一次卷积操作和双线性插值上采样。卷积用于减低通道数，并将其与上一层的特征图进行拼接。用于恢复图像大小，同时提取更加精细的特征。

```python
class UpSample(nn.Module):
    def __init__(self, channel):
        super(UpSample, self).__init__()
        self.layer = nn.Conv2d(channel, channel // 2, 1, 1)

    def forward(self, x, feature_map):
        up = F.interpolate(x, scale_factor=2, mode="nearest")
        out = self.layer(up)
        return torch.cat((out, feature_map), dim = 1)

```

## 网络模型

UNet网络模型由编码器和解码器两部分组成。编码器包含了四个 Conv_Block 和四个 DownSample 层，用于逐步提取图像的高级特征。解码器包含了四个 UpSample 和四个 Conv_Block 层，用于通过上采样和特征融合从编码器中恢复图像的细节。最后通过一个卷积层和 Sigmoid 激活函数得到二分类输出，用于分割图像。

```python
class UNet(nn.Module):
    def __init__(self):
        super(UNet,self).__init__()
        self.c1 = Conv_Block(3, 64)
        self.d1 = DownSample(64)
        self.c2 = Conv_Block(64, 128)
        self.d2 = DownSample(128)
        self.c3 = Conv_Block(128, 256)
        self.d3 = DownSample(256)
        self.c4 = Conv_Block(256,512)
        self.d4 = DownSample(512)
        self.c5 = Conv_Block(512, 1024)

        self.u1 = UpSample(1024)
        self.c6 = Conv_Block(1024, 512)
        self.u2 = UpSample(512)
        self.c7 = Conv_Block(512, 256)
        self.u3 = UpSample(256)
        self.c8 = Conv_Block(256, 128)
        self.u4 = UpSample(128)
        self.c9 = Conv_Block(128, 64)
        self.out = nn.Conv2d(64,3,3,1,1)
        # 二分类
        self.Th = nn.Sigmoid()
    
    def forward(self, x):
        R1 = self.c1(x)
        R2 = self.c2(self.d1(R1))
        R3 = self.c3(self.d2(R2))
        R4 = self.c4(self.d3(R3))
        R5 = self.c5(self.d4(R4))

        O1 = self.c6(self.u1(R5, R4))
        O2 = self.c7(self.u2(O1, R3))
        O3 = self.c8(self.u3(O2, R2))
        O4 = self.c9(self.u4(O3, R1))

        return self.Th(self.out(O4))
 
```

## 测试

一致则正确。

```python

if __name__ == "__main__":
    x = torch.randn(2,3,256,256)
    net=UNet()
    print(net(x).shape)
```



