<p class="EnlighterJSRAW" data-enlighter-language="generic">有两种方法解决这种问题。</p>

<h3 data-enlighter-language="generic">1.</h3>
<pre class="EnlighterJSRAW" data-enlighter-language="generic">pip3 install labelme -i https://pypi.tuna.tsinghua.edu.cn/simple/</pre>
&nbsp;
<h3>2.</h3>
错误：
<pre class="EnlighterJSRAW" data-enlighter-language="generic" data-enlighter-theme="atomic">To search for alternate channels that may provide the conda package you're
looking for, navigate to

    https://anaconda.org

and use the search bar at the top of the page.</pre>
&nbsp;

尝试：
<pre class="EnlighterJSRAW" data-enlighter-language="generic" data-enlighter-theme="atomic"> conda config --add channels conda-forge
 conda install labelme -c conda-forge</pre>
&nbsp;

如果产生："Solving environment: failed with repodata from current_repodata.json, will retry with next repodata source."

清除缓存。
<pre class="EnlighterJSRAW" data-enlighter-language="generic" data-enlighter-theme="atomic">conda clean -a</pre>
&nbsp;

遇到的labelme其他问题

File "C:\Users\Lenovo\AppData\Roaming\Python\Python310\Scripts\labelme_json_to_dataset.exe_<em>main</em>_.py", line 7, in &lt;module&gt; File "C:\Users\Lenovo\AppData\Roaming\Python\Python310\site-packages\labelme\cli\json_to_dataset.py", line 39, in main data = json.load(open(json_file)) File "E:\Anaconda\app\lib\json_<em>init</em>_.py", line 293, in load return loads(fp.read(), UnicodeDecodeError: 'gbk' codec can't decode byte 0x9c in position 2152: illegal multibyte sequence

解决：<img class="alignnone wp-image-759 size-full" src="https://789ak.com/wp-content/uploads/2023/03/Pasted-35.png" />

