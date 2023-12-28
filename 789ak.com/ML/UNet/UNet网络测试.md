# UNet网络测试

用于测试UNet网络训练的。对输入的图像进行分割，并将分割结果保存为图像文件。

```python
import os
from torchvision.utils import save_image
from net import * 
from utils import *
from data import *

# 实例化网络
net = UNet().cpu() # 创建 UNet 模型的实例，并将模型移动到 CPU 上; 也可以用 cuda
# 加载权重
weights = "params/unet.pth"

# 检查是否存在预训练的模型权重文件，如果存在则加载权重到模型中，否则输出提示信息。
if os.path.exists(weights):
    net.load_state_dict(torch.load(weights))
    print("Successfully")
else:
    print("No Successfully")

# 输入图像路径。
_input = input("please input image path: ")

# 使用 keep_image_size_open 函数加载和调整图像大小。
img =  keep_image_size_open(_input)
# 图像预处理，将其转换为张量形式
img_data = transform(img).cpu()
#  torch.unsqueeze 函数在第0维增加一个维度，以适应网络的输入格式。
img_data = torch.unsqueeze(img_data, dim = 0)
out = net(img_data)
# 分割结果保存为图像文件。
save_image(out, "result/result.jpg")
print(out.shape)
```

