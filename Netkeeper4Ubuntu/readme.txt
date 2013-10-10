[Outline]
每次上网前需要使用netkeeper脚本登陆
netkeeper会调用dialnetkeeper这个程序
dialnetkeeper是我们自己编译生成的文件


[detail]
1.运行前请修改netkeeper文件，在username=和
password=后面添加自己的账户密码，其他行请不要做任何修改。

2.将PPPOE.conf、dialnetkeeper、netkeeper三个文件移动到/usr/local/bin目录(或/usr/bin/):
sudo mv PPPOE.conf dialnetkeeper netkeeper /usr/local/bin

3.修改网络连接接口文件interfaces:
sudo gedit /etc/network/interfaces
然后将打开的文件修改为下面内容
auto lo
iface lo inet loopback 
  
iface dsl-provider inet ppp
pre-up /sbin/ifconfig eth0 up # line maintained by pppoeconf
provider dsl-provider
  
auto eth0
iface eth0 inet dhcp

4. 为netkeeper脚本增加权限:
sudo chmod 777 /usr/local/bin/netkeeper
sudo chmod 777 /usr/local/bin/dialnetkeeper

5.以后即可在终端中使用sudo netkeeper拨号，登出命令为sudo poff -a。


[memo]
  
1.由于本程序自带pppoe配置文件，故目前只适合拨号网卡默认为eth0的用户，适合绝大部分情况，个别发行版或者拨号网卡非eth0的同学请将PPPOE.conf中的相应eth0替换你的网卡。
     
2.本程序改编自32位程序"杭电人传我的netkeeper"
