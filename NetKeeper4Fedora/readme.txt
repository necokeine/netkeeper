本目录下的zshanxun是编译生成的obj文件，一般需要放到/usr/bin（或/usr/local/bin)目录下。
auto脚本中需要填写自己的username和password；
执行auto脚本即可上网。

经过测试fedora19x86_64下可以运行。如果无法运行请做注意修改：
sudo chmod 777 /usr/bin/zshanxun
sudo chown root /usr/bin/zshanxun
sudo chgrp root /usr/bin/zshanxun
