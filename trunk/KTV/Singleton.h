#ifndef _SINGLETON_H_
#define _SINGLETON_H_

/**
单件模式声明宏.
这个宏有如下几个特点:
1、采用局部静态变量方式，以便在任何时候调用Instance都可以初始化实例并得到实例指针.
2、不依赖其他静态、全局变量，为自动注册提供条件。
3、线程安全，任何情况下都只会执行一次构造函数。
\warning 使用者需要把构造函数声明为私有的.
\author chenguodong
*/
#define DECLARE_SINGLETON(theClass)  \
    public: \
        static theClass *Instance() \
        { \
            static theClass *m_pInstance = NULL; /*指针赋值过程中任务切换，编译器如何处理? */\
            if (NULL == m_pInstance)  \
            { \
                static theClass inst; /*第一次使用的时候实例化，避免用到一个未实例化的对象*/\
                m_pInstance = &inst; \
            } \
            return m_pInstance; \
        } \
    private: \
        /*theClass(){} 使用此宏人为保证构造函数私有,不保证它私有也问题不大，析构私有同样不能生成栈变量*/ \
        theClass(theClass const &); \
        theClass &operator =(theClass &); \
        //~theClass(){} /*析构函数私有，避免生成栈变量; 单件模式生命周期是整个应用程序生命周期所以析构函数一般不会被调用*/
        
#endif
