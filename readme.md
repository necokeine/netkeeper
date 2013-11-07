包括Windows、路由器、Linex(Fedora,Ubuntu)版本的拨号程序

## Windows User
1. 下载、解压
2. 建议一个新的网络连接，取名为test_ras
2. 进入解压后的路径
3. 双击运行dial.exe

第一次运行，需要输入用户名和密码。建议在cmd中切换到解压后的路径中执行dial.exe，当登陆成功后显示“you win”。

## Linux User
### Ubuntu User:
1. 下载，解压
2. 修改netkeeper脚本中的用户名和密码
3. sudo权限下移netkeeper,dialnetkeeper,PPPOE.conf文件到/usr/local/bin/
4. 修改/etc/network/interfaces为如下内容：<pre><code>auto lo
		iface lo inet loopback 
  
		iface dsl-provider inet ppp
		pre-up /sbin/ifconfig eth0 up # line maintained by pppoeconf
		provider dsl-provider
  
		auto eth0
		iface eth0 inet dhcp
		</code></pre>
5. 改变刚刚复制的netkeeper,dialnetkeeper权限为777
6. 运行netkeeper脚本以连接：sudo netkeeper

###	Fedora User
见NetKeeper4Fedora文件夹
