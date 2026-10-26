#include<bits/stdc++.h>
#include"vector.h"
#include"cauhoi.h"
#include"exam.h"
using namespace std;
void demovector(){
    cout<<"=== Demo MyVector<int> ==="<<endl;
    vectorcuatoi<int> v;
    for (int i=1;i<=5;i++) v.push_back(i*10);
    cout<<"Duyet xuoi : ";
    for(auto it=v.begin();it!=v.end();it++) cout<<*it<< " ";
    cout<<endl;
    cout<<"Duyet nguoc: ";
    for(auto it=v.rbegin();it!=v.rend();it++) cout<<*it<< " ";
    cout<<"\n\n";
}
int main(){
    demovector();
    try {
        exam ex;
        ex.loadFromFile("questions.txt");
        cout<<"Da nap "<<ex.bankSize()<<" cau hoi tu file."<<endl;
        size_t k;
        cout<<"Nhap so cau hoi can thi (toi da "<<ex.bankSize()<<"): ";
        while(!(cin>>k) || k==0 || k>ex.bankSize()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"Khong hop le, nhap lai (1-"<<ex.bankSize()<<"): ";
        }
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        ex.generatePaper(k);
        std::cout<<"Da tao de thi gom "<<k<<" cau hoi ngau nhien."<<endl;
        ex.printPaperReversed();
        int correct=ex.takeExamInteractive();
        double score=ex.scoreOn10(correct);
        std::cout<<"\nSo cau dung: "<<correct << "/"<<ex.paperSize();
        std::cout<<"\nDiem: "<<score<<"/10"<<endl;
    }
    catch(const exception& ex){
        cerr<<"Loi: "<<ex.what()<<endl;
        return 1;
    }
    return 0;
}