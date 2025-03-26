para.h
	参数服务接口：
	1.load方法可自动从xml文件中载入所有参数
	2.sava方法把当前的所有参数保存入xml文件中持久化

define\paraDef.h
	参数自动持久化：
	1.在para\define文件夹里生成一个cpp文件
	2.在该文件中定义一个继承CParas类的子类
	3.重写其构造函数，在构造函数里面写保存的数据和对应的字段
	4.声明一个该类的静态变量
	5.把该cpp文件引用到cmakeLists.txt
	6.参看ncDef.h和ncDef.cpp