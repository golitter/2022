find命令：找文件。

- -type 按文件类型搜索 d/p/s/c/b/l/f

- -name 按文件名搜索

  `find ./ -name "a"`

- -maxdepth 指定搜索深度。**应作为第一个参数出现**。

  `find ./ -maxdepth 1 -name "a"`

- -size 按文件大小搜索。单位：k M G

  `find /home/golitter/ -size +20M -size -50M`

  这里要注意，两个size一个都不能少，文件单位对大小写敏感。

- -atime mtime ctime 天；-amin mmin cmin 分钟

  - a 表示最近访问的时间
  - m 表示最近更改的时间，指更改文件属性一类的
  - c 表示最近改动时间，指更改文件内容

- -exec 将find搜索的结果集执行某一指令命令

