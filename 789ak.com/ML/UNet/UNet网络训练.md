# UNet网络训练

## 训练资源

构建好UNet网络模型后，需要进行训练。但是训练需要特别多的原始图像和标签图像，对于一般而言这一步特别繁琐，不过在网上有一些免费的数据集可以让我们省略这一步，直接进行训练测试。

> VOC（Visual Object Classes）数据集是一个广泛使用的计算机视觉数据集，主要用于目标检测、图像分割和图像分类等任务。VOC数据集最初由英国牛津大学的计算机视觉小组创建，并在PASCAL VOC挑战赛中使用。
>
> VOC数据集包含各种不同类别的标记图像，每个图像都有与之相关联的边界框（bounding box）和对象类别的标签。数据集中包括了20个常见的目标类别，例如人、汽车、猫、狗等。此外，VOC数据集还提供了用于图像分割任务的像素级标注。
>
> VOC数据集涵盖了多个年度的发布，每个年度的数据集包含训练集、验证集和测试集。训练集用于模型的训练和参数优化，验证集用于模型的调参和性能评估，而测试集则用于最终模型的性能评估和比较。



VOC数据集：https://host.robots.ox.ac.uk/pascal/VOC/voc2007/

![image-20230925130121998](https://cdn.789ak.com/img/image-20230925130121998.png)

![image-20230925130229417](https://cdn.789ak.com/img/image-20230925130229417.png)

一般目标检测**只需用到Annotations、ImageSets、JPEGImages这3个文件夹**，剩下的可以删掉。

`Annotations`：存放xml格式的标注文件

`JPEGImages`：该文件夹存储了 VOC 数据集中的图像数据。

`ImageSets`：该文件夹包含了几个用于数据集划分和评估的文本文件。

`SegmentationClass`：包含了每个图像像素的语义类别标注信息。

## 训练

创建一个Dataloader对象用来加载自定义数据集。

进入训练循环，每个 epoch 遍历一遍数据集。对于每个 batch，将输入数据和真实标签拷贝到计算设备上，并进行前向推理得到输出结果。计算输出结果与真实标签之间的交叉熵损失，并计算梯度并反向传播。每隔一定的周期，打印当前的训练损失并保存模型权重。另外，在每个 batch 中，将输入、真实标签和输出结果合并成一张图像，保存到指定的路径中，用于观察训练效果。

```python
from torch import nn,optim # 优化器
import torch 
from torch.utils.data import DataLoader # 用于加载自定义数据集类
from data import * # 导入自定义类
from net import * # 导入UNet网络模型
from torchvision.utils import save_image # 导入保存图像方法


# 如果有cuda，就用；否则就用cpu
device = torch.device('cuda' if torch.cuda.is_available() else 'cpu')
# 权重 用于存储和加载训练好的Unet深度学习模型的权重或参数。".pth" 是PyTorch模型文件的命名约定。
weight_path = "params/unet.pth"
# 数据集路径
data_path = r"E:\Undergraduate\School\Scientific_research\ML\Machine_Learning\lab\图形分割\Unet模型总\VOCdevkit\VOC2012"
# 训练结果图像保存路径
save_path = "train_image"

# 在主程序中运行
if __name__ == "__main__":
    # 创建数据加载器对象，MyDataset 是自定义的数据集类，用于加载训练数据，batch_size=2 表示每次训练使用的图像数量为 2。
    data_loader = DataLoader(MyDataset(data_path), batch_size=2, shuffle=True)
    # 实例化UNet网络模型 通过 .to(device) 将模型移动到指定的设备上。
    net = UNet().to(device)

    # 检查是否存在预训练的模型权重文件，如果存在则加载权重到模型中，否则输出提示信息。
    if os.path.exists(weight_path):
        net.load_state_dict(torch.load(weight_path))
        print("Successful load weight!")
    else:
        print("Not successful load weight")
    
    # 创建优化器和损失函数对象
    opt = optim.Adam(net.parameters())
    loss_fun = nn.BCELoss()

    # 设置起始训练轮数，并开始训练
    epoch = 1
    while True:
        # 遍历数据加载器中的每个批次，将图像数据和分割图像数据移动到指定设备上。
        for i, (image, segment_image) in enumerate(data_loader):
            image, segment_image = image.to(device), segment_image.to(device)

            # 前向传播计算网络输出结果，并计算训练损失。
            out_image = net(image)
            train_loss = loss_fun(out_image, segment_image)

            # 梯度清零，反向传播计算梯度。
            opt.zero_grad()
            train_loss.backward()

            # 隔一段时间进行打印信息
            if i%5 == 0:
                print(f"{epoch} {i} - train_loss ==>{train_loss.item()}")

            if i%50 == 0:
                torch.save(net.state_dict(), weight_path)
            
            # 从批次中取出第一张图像、分割图像和网络输出结果。将图像、分割图像和网络输出结果按顺序堆叠，并保存为图像文件。
            _image = image[0]
            _segment_image = segment_image[0]
            _out_image = out_image[0]
            
            img = torch.stack([_image, _segment_image, _out_image],dim = 0)
            save_image(img, f"{save_path}/{i}.png")
            
        epoch += 1

```

![img](https://cdn.789ak.com/img/(RC~1%606NEB4H%5BLR)X@TX3FD.png)