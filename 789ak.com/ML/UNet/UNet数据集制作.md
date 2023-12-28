# UNet网络模型：数据集制作

一般语义分割的原始图片和标记图片在以下目录下：

![image-20230924235329548](https://cdn.789ak.com/img/image-20230924235329548.png)

`SegmentationClass`：标记图片。

`JPEGImages`：原始图片。



数据集往往都是很多的图片等信息，对于数据集类来说，一个类里有所有数据的信息，并且可以用下标进行访问，就像访问数组一样。

在pytorch中有`Dataset`类，用于创建自定义数据集类。我们可以用继承`Dataset`类来实现数据集类。在一个数据集类中，需要确定数据集所在的位置，也要用`__getitem__`实现下标访问，用`__len__`实现数据集大小。

对于标记图片和原始图片可能大小或者格式不同，需要将这两个图片的格式统一。

> 代码参考[UNet数据集制作及代码实现_哔哩哔哩_bilibili](https://www.bilibili.com/video/BV11341127iK?p=1&vd_source=13dfbe5ed2deada83969fafa995ccff6)，根据该UP主的代码，加上我的个人整理和理解。（这个UP主的代码感觉很好，很规范

目录的树形结构：

```shell
data/ (path) 
 |
 |
 |------- SegmentationClass/
 |               |
 |               |-- 标记图像
 |               |-- ...
 |               |-- 标记图像
 |
 |
 |
 |
 |------- JPEGImages/
                |
                |-- 原始图像
                |-- ...
                |-- 原始图像
```

### 原始图像和标记图像处理

```cpp
from PIL import Image # 用于读取和处理图像

# 用于加载图像并保存图像大小一致
# path表示图像文件的路径，size表示需要调整的目标大小，默认为(256, 256)。
def keep_image_size_open(path, size = (256, 256)):

    # 通过Image.open(path)方法打开path路径的图像，并将返回的图像对象保存在变量img中。
    img = Image.open(path)
    # 获取输入图像的最大边长
    tmp = max(img.size)
    # 创建一个新的空白图像对象mask，大小为(tmp, tmp)，颜色为(0, 0, 0)，即黑色。
    mask = Image.new("RGB", (tmp, tmp), (0,0,0))
    # 将原始图像img粘贴到mask图像对象的左上角，使得原始图像位于黑色背景之上。
    mask.paste(img, (0,0))
    # 将图像调整为目标大小，并返回调整后的图像对象mask。
    mask = mask.resize(size)
    return mask
```

### 数据集制作

```cpp
import os # 路径操作
from torch.utils.data import Dataset # 继承 pytorch中的Dataset
from utils import * # 引入自己写的： 将原始图片和标记图片格式和规格统一
from torchvision import transforms # 用于数据预处理

################################################
#
#   transforms.Compose用于将多个变换操作组合在一起。
# 这里只有一个 ToTensor()，用于将图像数据转为张量格式
#
###############################################
transform = transforms.Compose([
    transforms.ToTensor()
])

##############################################
#
# 通过继承Dataset类，来实现自定义数据集类
#
##############################################
class MyDataset(Dataset):

    # path表示数据集的路径
    def __init__(self, path):
        self.path = path
        # path路径下的目录
        self.name = os.listdir(os.path.join(path, "SegmentationClass"))
    
    # 返回数据集长度
    def __len__(self):
        return len(self.name)
    
    # 实现下标访问
    def __getitem__(self, index):
        segment_name = self.name[index] # xx.png 得到的是：path/SegmentationClass/图像名字
        segment_path = os.path.join(self.path, "SegmentationClass", segment_name) # 得到标记图像路径
        # 得到原始图像路径。segment_name.replace(xxx,kkk) 表示如果标记图像和原始图像格式不同，进行后缀替代，进而得到正确的原始图像路径
        image_path = os.path.join(self.path, "JPEGImages", segment_name.replace("png", "jpg")) 

        # 将图像进行统一规格化
        segment_image = keep_image_size_open(segment_path)
        image = keep_image_size_open(image_path)

        # 返回经过transform处理后的图像张量
        return transform(image), transform(segment_image)

# 测试是否正确
if __name__ == "__main__":
    data = MyDataset(r"E:\Undergraduate\School\Scientific_research\ML\Machine_Learning\lab\图形分割\Unet模型总\data")
    print(data[0][0].shape)
    print(data[0][1].shape)
```





[UNet数据集制作及代码实现_哔哩哔哩_bilibili](https://www.bilibili.com/video/BV11341127iK?p=1&vd_source=13dfbe5ed2deada83969fafa995ccff6)