#ifndef _SINGLETON_H_
#define _SINGLETON_H_

/**
����ģʽ������.
����������¼����ص�:
1�����þֲ���̬������ʽ���Ա����κ�ʱ�����Instance�����Գ�ʼ��ʵ��õ�ʵ��ָ��.
2������������̬��ȫ�ֱ�����Ϊ�Զ�ע���ṩ������
3���̰߳�ȫ���κ�����¶�ֻ��ִ��һ�ι��캯��
\warning ʹ������Ҫ�ѹ��캯������Ϊ˽�е�.
\author chenguodong
*/
#define DECLARE_SINGLETON(theClass)  \
    public: \
        static theClass *Instance() \
        { \
            static theClass *m_pInstance = NULL; /*ָ�븳ֵ����������л�����������δ���? */\
            if (NULL == m_pInstance)  \
            { \
            	static theClass inst;\
                m_pInstance = &inst; \
            } \
            return m_pInstance; \
        } \
    private: \
        /*theClass(){} ʹ�ô˺���Ϊ��֤���캯��˽��,����֤��˽��Ҳ���ⲻ������˽��ͬ�������ջ����*/ \
        theClass(theClass const &); \
        theClass &operator =(theClass &); \
        //~theClass(){} /*��������˽�У��������ջ����; ����ģʽ�������������Ӧ�ó�����������������������һ�㲻�ᱻ����*/
        
#endif
