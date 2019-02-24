#include <iostream>
using namespace std;

class CMyString{
public:
    CMyString(char* pData = nullptr){
        if(pData== nullptr){
            m_pData = new char[1];
            m_pData[0] = '/0';
        }else{
            int length = strlen(pData);
            m_pData = new char[length + 1];
            strcpy(m_pData, pData);
        }
    }
    CMyString(const CMyString& str){
        int length = strlen(str.m_pData);
        m_pData = new char[length + 1];
        strcpy(m_pData, str.m_pData);
    }
    ~CMyString(){
        delete[] m_pData;
    }
    CMyString& operator=(const CMyString& str){
        if(this!=&str){
            CMyString strTemp(str);
            char* pTemp = strTemp.m_pData;
            strTemp.m_pData = m_pData;
            m_pData = pTemp;
        }
        return *this;
    }
    friend ostream& operator<< (ostream &os,const CMyString& str){
        os<<str.m_pData<<endl;
        return os;
    }
private:
    char* m_pData;
};

int main() {
    CMyString str("abc");
    CMyString test;
    test=str;
    cout<<test;
}