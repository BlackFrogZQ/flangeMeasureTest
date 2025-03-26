#pragma once
/*
    参数服务接口：
    1.load方法可自动从xml文件中载入所有参数
    2.sava方法把当前的所有参数保存入xml文件中持久化
*/
namespace TIGER_Para
{
    class IParaService
    {
    public:
        virtual ~IParaService(){};
        void setFileName(QString p_basiceName);
        void openFilePath() const;
        virtual void load() = 0;
        virtual void save() = 0;

    protected:
        QString m_xmlFilePath; // 文件保存路径
    };
}

// const int *
// 指针变量的内容可以改变，但是该内容指向的内容不可改变！
//   const char *p = "Hello world!";
//   p[3] = '3';  //error C3892: “p”: 不能给常量赋值
//	p = "Hi!";
// int *const
//   char *const p = "Hello world!";
//	p[3] = '3';
//   p = "Hi!";  error C3892: “p”: 不能给常量赋值
TIGER_Para::IParaService *const paraService();
